/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:49:37 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/06 22:30:40 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha224.h"

void	sha224_init_ctx(t_sha32bits_context *ctx)
{
	ctx->big_h[0] = 0xC1059ED8;
	ctx->big_h[1] = 0x367CD507;
	ctx->big_h[2] = 0x3070DD17;
	ctx->big_h[3] = 0xF70E5939;
	ctx->big_h[4] = 0xFFC00B31;
	ctx->big_h[5] = 0x68581511;
	ctx->big_h[6] = 0x64F98FA7;
	ctx->big_h[7] = 0xBEFA4FA4;
}

char	*sha224(const char *str, uint64_t len)
{
	t_sha32bits_context	ctx;
	uint32_t			i;
	uint32_t			t;

	sha224_init_ctx(&ctx);
	i = 0;
	while (i < len)
	{
		t = 0;
		while (t < 16)
		{
			ctx.w[t] = *(uint32_t *)(str + i + t * 4);
			swap_bytes(&ctx.w[t], sizeof(ctx.w[t]));
			++t;
		}
		while (t < 64)
		{
			ctx.w[t] = small_sigma_32(ctx.w[t - 2], 1) + ctx.w[t - 7]
				+ small_sigma_32(ctx.w[t - 15], 0) + ctx.w[t - 16];
			++t;
		}
		sha32bits_block_iteration(&ctx);
		i += 64;
	}
	return (sha32bits_fill_result(&ctx, malloc(29 * sizeof(char)), 7));
}

static char	*sha224_last_stream_block(t_sha32bits_context *ctx, char *buff,
	int r, uint64_t total_len)
{
	char		*s;
	uint32_t	new_len;
	uint64_t	bits_len;

	buff[r] = (char)128;
	bits_len = 8ULL * total_len;
	swap_bytes(&bits_len, sizeof(bits_len));
	new_len = ((((r + 8) / 64) + 1) * 64) - 8;
	ft_memcpy(buff + new_len, &bits_len, sizeof(uint64_t));
	sha32bits_process_block((uint32_t *)(buff), ctx);
	if (new_len + 8 > 64)
		sha32bits_process_block((uint32_t *)(buff + 64), ctx);
	s = malloc(29 * sizeof(char));
	if (s == NULL)
		return (NULL);
	sha32bits_fill_result(ctx, s, 7);
	return (s);
}

char	*sha224_from_stream(int fd, int is_quite)
{
	char				buff[128];
	uint32_t			r;
	t_sha32bits_context	ctx;
	uint64_t			total_len;

	r = 1;
	total_len = 0;
	sha224_init_ctx(&ctx);
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
		sha32bits_process_block((uint32_t *)(buff), &ctx);
	}
	return (sha224_last_stream_block(&ctx, buff, r, total_len));
}
