/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:21:11 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/06 22:30:40 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void	rotate_states(uint32_t *bloc, uint32_t i, t_md5_context *ctx)
{
	uint32_t	tmp;
	uint32_t	left_rotate;
	uint32_t	a;

	tmp = ctx->d;
	ctx->d = ctx->c;
	ctx->c = ctx->b;
	a = ctx->a + ctx->f + g_k[i] + bloc[ctx->g];
	left_rotate = ((a << g_r[i]) | (a >> (32 - g_r[i])));
	ctx->b += left_rotate;
	ctx->a = tmp;
}

void	process_block(uint32_t *bloc, t_md5_context *ctx)
{
	uint32_t	i;

	ctx->a = ctx->h[0];
	ctx->b = ctx->h[1];
	ctx->c = ctx->h[2];
	ctx->d = ctx->h[3];
	i = 0;
	while (i < 64)
	{
		if (i <= 15)
			do_f(ctx, i);
		else if (i <= 31)
			do_g(ctx, i);
		else if (i <= 47)
			do_h(ctx, i);
		else
			do_i(ctx, i);
		rotate_states(bloc, i, ctx);
		++i;
	}
	ctx->h[0] += ctx->a;
	ctx->h[1] += ctx->b;
	ctx->h[2] += ctx->c;
	ctx->h[3] += ctx->d;
}

char	*md5(const char *str, uint64_t len)
{
	t_md5_context	ctx;
	uint32_t		offset;
	char			*s;

	ctx.h[0] = 0x67452301;
	ctx.h[1] = 0xEFCDAB89;
	ctx.h[2] = 0x98BADCFE;
	ctx.h[3] = 0x10325476;
	offset = 0;
	while (offset < len)
	{
		process_block((uint32_t *)(str + offset), &ctx);
		offset += 64;
	}
	s = malloc(17 * sizeof(char));
	if (s == NULL)
		return (NULL);
	fill_result(&ctx, s);
	return (s);
}

static char	*last_stream_block(t_md5_context *ctx, char *buff, int r,
	uint64_t total_len)
{
	char		*s;
	uint32_t	new_len;
	uint64_t	bits_len;

	buff[r] = (char)128;
	bits_len = 8ULL * total_len;
	new_len = ((((r + 8) / 64) + 1) * 64) - 8;
	ft_memcpy(buff + new_len, &bits_len, sizeof(uint64_t));
	process_block((uint32_t *)(buff), ctx);
	if (new_len + 8 > 64)
		process_block((uint32_t *)(buff + 64), ctx);
	s = malloc(17 * sizeof(char));
	if (s == NULL)
		return (NULL);
	fill_result(ctx, s);
	return (s);
}

char	*md5_from_stream(int fd, int is_quite)
{
	char			buff[128];
	uint32_t		r;
	t_md5_context	ctx;
	uint64_t		total_len;

	r = 1;
	total_len = 0;
	ctx.h[0] = 0x67452301;
	ctx.h[1] = 0xEFCDAB89;
	ctx.h[2] = 0x98BADCFE;
	ctx.h[3] = 0x10325476;
	while (r > 0)
	{
		r = ft_read_block(fd, buff, 64);
		if (r < 0)
			return (NULL);
		ft_memset(buff + r, 0, 128 - r);
		total_len += r;
		if (fd == 0)
			write(1, buff, r - (r > 0 && !is_quite && buff[r - 1] == '\n'));
		if (r < 64)
			break ;
		process_block((uint32_t *)(buff), &ctx);
	}
	return (last_stream_block(&ctx, buff, r, total_len));
}
