/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:49:37 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/04 08:09:17 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha256.h"

char	*sha256_fill_result(t_sha2xx_context *ctx, char *str)
{
	int		i;
	int		j;
	char	*s;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < 8)
	{
		j = 0;
		s = (char *)(ctx->big_h + i);
		while (j < 4)
		{
			str[i * 4 + j] = s[3 - j];
			++j;
		}
		++i;
	}
	str[32] = '\0';
	return (str);
}

void	init_ctx(t_sha2xx_context *ctx)
{
	ctx->big_h[0] = 0x6a09e667;
	ctx->big_h[1] = 0xbb67ae85;
	ctx->big_h[2] = 0x3c6ef372;
	ctx->big_h[3] = 0xa54ff53a;
	ctx->big_h[4] = 0x510e527f;
	ctx->big_h[5] = 0x9b05688c;
	ctx->big_h[6] = 0x1f83d9ab;
	ctx->big_h[7] = 0x5be0cd19;
}

void	update_ctx(t_sha2xx_context *ctx, int update_hash)
{
	if (update_hash == 1)
	{
		ctx->big_h[0] += ctx->a;
		ctx->big_h[1] += ctx->b;
		ctx->big_h[2] += ctx->c;
		ctx->big_h[3] += ctx->d;
		ctx->big_h[4] += ctx->e;
		ctx->big_h[5] += ctx->f;
		ctx->big_h[6] += ctx->g;
		ctx->big_h[7] += ctx->h;
	}
	else
	{
		ctx->a = ctx->big_h[0];
		ctx->b = ctx->big_h[1];
		ctx->c = ctx->big_h[2];
		ctx->d = ctx->big_h[3];
		ctx->e = ctx->big_h[4];
		ctx->f = ctx->big_h[5];
		ctx->g = ctx->big_h[6];
		ctx->h = ctx->big_h[7];
	}
}

void	block_iteration(t_sha2xx_context *ctx)
{
	uint32_t	t;

	update_ctx(ctx, 0);
	t = 0;
	while (t < 64)
	{
		ctx->t1 = ctx->h + big_sigma(ctx->e, 1) + ch(ctx->e, ctx->f, ctx->g)
			+ g_sha_k[t] + ctx->w[t];
		ctx->t2 = big_sigma(ctx->a, 0) + maj(ctx->a, ctx->b, ctx->c);
		ctx->h = ctx->g;
		ctx->g = ctx->f;
		ctx->f = ctx->e;
		ctx->e = ctx->d + ctx->t1;
		ctx->d = ctx->c;
		ctx->c = ctx->b;
		ctx->b = ctx->a;
		ctx->a = ctx->t1 + ctx->t2;
		++t;
	}
	update_ctx(ctx, 1);
}

char	*sha256(const char *str, uint32_t len)
{
	t_sha2xx_context	ctx;
	uint32_t			i;
	uint32_t			t;

	init_ctx(&ctx);
	i = 0;
	while (i < len)
	{
		t = 0;
		while (t < 16)
		{
			ctx.w[t] = swap_bytes(*(uint32_t *)(str + i + t * 4)) >> 32;
			++t;
		}
		while (t < 64)
		{
			ctx.w[t] = small_sigma(ctx.w[t - 2], 1) + ctx.w[t - 7]
				+ small_sigma(ctx.w[t - 15], 0) + ctx.w[t - 16];
			++t;
		}
		block_iteration(&ctx);
		i += 64;
	}
	return (sha256_fill_result(&ctx, malloc(33 * sizeof(char))));
}
