/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:40:40 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/03 17:45:53 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void	do_f(t_md5_context *ctx, uint32_t i)
{
	ctx->f = (ctx->b & ctx->c) | ((~ctx->b) & ctx->d);
	ctx->g = i;
}

void	do_g(t_md5_context *ctx, uint32_t i)
{
	ctx->f = (ctx->d & ctx->b) | ((~ctx->d) & ctx->c);
	ctx->g = (5 * i + 1) % 16;
}

void	do_h(t_md5_context *ctx, uint32_t i)
{
	ctx->f = ctx->b ^ ctx->c ^ ctx->d;
	ctx->g = (3 * i + 5) % 16;
}

void	do_i(t_md5_context *ctx, uint32_t i)
{
	ctx->f = ctx->c ^ (ctx->b | (~ctx->d));
	ctx->g = (7 * i) % 16;
}

void	fill_result(t_md5_context *ctx, char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (i < 4)
	{
		j = 0;
		s = (char *)(ctx->h + i);
		while (j < 4)
		{
			str[i * 4 + j] = s[j];
			++j;
		}
		++i;
	}
	str[16] = '\0';
}
