/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 06:34:17 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/03 11:31:22 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	write_in_hex(const char *str)
{
	int		i;
	char	c;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	while (i < 16)
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
		write_in_hex(s);
	else if ((ctx->flags & F_REVERSE) != 0)
	{
		write_in_hex(s);
		write(1, " ", 1);
		if (ctx->is_file == 0)
			write(1, "\"", 1);
		write(1, src, src_len);
		if (ctx->is_file == 0)
			write(1, "\"", 1);
	}
	else
	{
		write (1, "MD5 (", 5);
		if (ctx->is_file == 0)
			write(1, "\"", 1);
		write(1, src, src_len);
		if (ctx->is_file == 0)
			write(1, "\"", 1);
		write (1, ") = ", 4);
		write_in_hex(s);
	}
	write(1, "\n", 1);
}

int	is_valid_command(const char *cmd)
{
	return (ft_strcmp(cmd, "md5") == 0 || ft_strcmp(cmd, "sha256") == 0);
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
	buff = malloc(new_len + 64);
	if (buff == NULL)
		return (NULL);
	ft_memset(buff, 0, new_len + 64);
	ft_memcpy(buff, str, r);
	buff[r] = (char)128;
	bits_len = 8ULL * r;
	ft_memcpy(buff + new_len, &bits_len, sizeof(uint64_t));
	s = ctx->hash_function(buff, new_len);
	free(buff);
	return (s);
}
