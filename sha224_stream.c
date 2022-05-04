/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224_stream.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:20:08 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/04 06:58:45 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha224.h"

void	sha224_process_block(uint32_t *bloc, t_sha224_context *ctx)
{
	uint32_t	t;

	t = 0;
	while (t < 16)
	{
		ctx->w[t] = swap_bytes(bloc[t]) >> 32;
		++t;
	}
	while (t < 64)
	{
		ctx->w[t] = small_sigma(ctx->w[t - 2], 1) + ctx->w[t - 7]
			+ small_sigma(ctx->w[t - 15], 0) + ctx->w[t - 16];
		++t;
	}
	sha224_block_iteration(ctx);
}

char	*sha224_last_stream_block(t_sha224_context *ctx, char *buff, int r,
	int total_len)
{
	char		*s;
	uint32_t	new_len;
	uint64_t	bits_len;

	buff[r] = (char)128;
	bits_len = 8ULL * total_len;
	bits_len = swap_bytes(bits_len);
	new_len = ((((r + 8) / 64) + 1) * 64) - 8;
	ft_memcpy(buff + new_len, &bits_len, sizeof(uint64_t));
	sha224_process_block((uint32_t *)(buff), ctx);
	if (new_len + 8 > 64)
		sha224_process_block((uint32_t *)(buff + 64), ctx);
	s = malloc(25 * sizeof(char));
	if (s == NULL)
		return (NULL);
	sha224_fill_result(ctx, s);
	return (s);
}

char	*sha224_from_stream(int fd)
{
	char				buff[128];
	uint32_t			r;
	t_sha224_context	ctx;
	uint64_t			total_len;

	r = 1;
	total_len = 0;
	sha224_init_ctx(&ctx);
	while (r > 0)
	{
		r = read(fd, buff, 64);
		if (r < 0)
			return (NULL);
		ft_memset(buff + r, 0, 128 - r);
		total_len += r;
		if (fd == 0)
			write(1, buff, r);
		if (r < 64)
			break ;
		sha224_process_block((uint32_t *)(buff), &ctx);
	}
	return (sha224_last_stream_block(&ctx, buff, r, total_len));
}
