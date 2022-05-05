/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512-224.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:50:37 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/05 18:47:28 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha512.h"

void	sha512_224_init_ctx(t_sha64bits_context *ctx)
{
	ctx->big_h[0] = 0x8C3D37C819544DA2;
	ctx->big_h[1] = 0x73E1996689DCD4D6;
	ctx->big_h[2] = 0x1DFAB7AE32FF9C82;
	ctx->big_h[3] = 0x679DD514582F9FCF;
	ctx->big_h[4] = 0x0F6D2B697BD44DA8;
	ctx->big_h[5] = 0x77E36F7304C48942;
	ctx->big_h[6] = 0x3F9D85A86A1D36C8;
	ctx->big_h[7] = 0x1112E6AD91D692A1;
}

char	*sha512_224(const char *str, uint64_t len)
{
	t_sha64bits_context	ctx;
	uint64_t			i;
	uint64_t			t;

	sha512_224_init_ctx(&ctx);
	i = 0;
	while (i < len)
	{
		t = 0;
		while (t < 16)
		{
			ctx.w[t] = *(uint64_t *)(str + i + t * 8);
			swap_bytes(&ctx.w[t], sizeof(ctx.w[t]));
			++t;
		}
		while (t < 80)
		{
			ctx.w[t] = small_sigma_64(ctx.w[t - 2], 1) + ctx.w[t - 7]
				+ small_sigma_64(ctx.w[t - 15], 0) + ctx.w[t - 16];
			++t;
		}
		sha64bits_block_iteration(&ctx);
		i += 128;
	}
	return (sha64bits_fill_result(&ctx, malloc(29 * sizeof(char)), 7));
}

static char	*sha512_224_last_stream_block(t_sha64bits_context *ctx, char *buff,
	int r, __uint128_t total_len)
{
	char		*s;
	uint64_t	new_len;
	__int128_t	bits_len;

	buff[r] = (char)128;
	bits_len = 8ULL * total_len;
	swap_bytes(&bits_len, sizeof(bits_len));
	new_len = ((((r + 16) / 128) + 1) * 128) - 16;
	ft_memcpy(buff + new_len, &bits_len, sizeof(__int128_t));
	sha64bits_process_block((uint64_t *)(buff), ctx);
	if (new_len + 16 > 128)
		sha64bits_process_block((uint64_t *)(buff + 128), ctx);
	s = malloc(29 * sizeof(char));
	if (s == NULL)
		return (NULL);
	sha64bits_fill_result(ctx, s, 7);
	return (s);
}

char	*sha512_224_from_stream(int fd)
{
	char				buff[256];
	uint64_t			r;
	t_sha64bits_context	ctx;
	uint64_t			total_len;

	r = 1;
	total_len = 0;
	sha512_224_init_ctx(&ctx);
	while (r > 0)
	{
		r = read(fd, buff, 128);
		if (r < 0)
			return (NULL);
		ft_memset(buff + r, 0, 256 - r);
		total_len += r;
		if (fd == 0)
			write(1, buff, r);
		if (r < 128)
			break ;
		sha64bits_process_block((uint64_t *)(buff), &ctx);
	}
	return (sha512_224_last_stream_block(&ctx, buff, r, total_len));
}
