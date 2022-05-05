/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha32bits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 08:10:50 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/04 08:21:41 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha32bits.h"
#include "sha32bits_functions.h"

void	sha32bits_update_ctx(t_sha32bits_context *ctx, int update_hash)
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

void	sha32bits_block_iteration(t_sha32bits_context *ctx)
{
	uint32_t	t;

	sha32bits_update_ctx(ctx, 0);
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
	sha32bits_update_ctx(ctx, 1);
}

char	*sha32bits_fill_result(t_sha32bits_context *ctx, char *str, int hash_nbr)
{
	int		i;
	int		j;
	char	*s;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < hash_nbr)
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
	str[hash_nbr * 8] = '\0';
	return (str);
}

void	sha32bits_process_block(uint32_t *bloc, t_sha32bits_context *ctx)
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
	sha32bits_block_iteration(ctx);
}
