/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 06:34:17 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/05 15:39:34 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	write_in_hex(const char *str, int len)
{
	int		i;
	char	c;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	while (i < len)
	{
		c = hex[(str[i] & 0xF0) >> 4];
		write(1, &c, 1);
		c = hex[str[i] & 0x0F];
		write(1, &c, 1);
		++i;
	}
}

void	print_result(t_ft_ssl_context *ctx, const char *s, const char *src,
	int src_len)
{
	if ((ctx->flags & F_QUIET) != 0)
		write_in_hex(s, ctx->len);
	else if ((ctx->flags & F_REVERSE) != 0)
	{
		write_in_hex(s, ctx->len);
		write(1, " ", 1);
		if (ctx->is_file == 0)
			write(1, "\"", 1);
		write(1, src, src_len);
		if (ctx->is_file == 0)
			write(1, "\"", 1);
	}
	else
	{
		write (1, ctx->hash_prefix, ft_strlen(ctx->hash_prefix));
		if (ctx->is_file == 0)
			write(1, "\"", 1);
		write(1, src, src_len);
		if (ctx->is_file == 0)
			write(1, "\"", 1);
		write (1, ") = ", 4);
		write_in_hex(s, ctx->len);
	}
	write(1, "\n", 1);
}

int	is_valid_command(const char *cmd)
{
	return (ft_strcmp(cmd, "md5") == 0 || ft_strcmp(cmd, "sha256") == 0
		|| ft_strcmp(cmd, "sha224") == 0 || ft_strcmp(cmd, "sha512") == 0);
}

char	*process_str_input(const char *str, t_ft_ssl_context *ctx)
{
	char		*buff;
	char		*s;
	uint32_t	r;
	uint64_t	bits_len;
	uint32_t	new_len;

	r = ft_strlen(str);
	new_len = ((((r + 8) / 64) + 1) * 64) - 8;
	buff = malloc(new_len + 8);
	if (buff == NULL)
		return (NULL);
	ft_memset(buff, 0, new_len);
	ft_memcpy(buff, str, r);
	buff[r] = (char)128;
	bits_len = 8ULL * r;
	if (ctx->hash_function == sha256 || ctx->hash_function == sha224)
		swap_bytes(&bits_len, sizeof(bits_len));
	ft_memcpy(buff + new_len, &bits_len, sizeof(uint64_t));
	s = ctx->hash_function(buff, new_len + 8);
	free(buff);
	return (s);
}

char	*process_str_input_64(const char *str, t_ft_ssl_context *ctx)
{
	char		*buff;
	char		*s;
	uint64_t	r;
	__uint128_t	bits_len;
	uint64_t	new_len;

	r = ft_strlen(str);
	new_len = ((((r + 16) / 128) + 1) * 128) - 16;
	buff = malloc(new_len + 16);
	if (buff == NULL)
		return (NULL);
	ft_memset(buff, 0, new_len);
	ft_memcpy(buff, str, r);
	buff[r] = (char)128;
	bits_len = 8ULL * (__uint128_t)r;
	swap_bytes(&bits_len, sizeof(bits_len));
	ft_memcpy(buff + new_len, &bits_len, sizeof(__uint128_t));
	s = ctx->hash_function(buff, new_len + 16);
	free(buff);
	return (s);
}
