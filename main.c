/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:15:29 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/05 16:31:05 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static t_hash_function	str_to_hash_function(const char *str)
{
	if (ft_strcmp(str, "md5") == 0)
		return (md5);
	else if (ft_strcmp(str, "sha256") == 0)
		return (sha256);
	else if (ft_strcmp(str, "sha224") == 0)
		return (sha224);
	else if (ft_strcmp(str, "sha512") == 0)
		return (sha512);
	else if (ft_strcmp(str, "sha384") == 0)
		return (sha384);
	else
		return (NULL);
}

static t_stream_hash_function	str_to_stream_hash_function(const char *str)
{
	if (ft_strcmp(str, "md5") == 0)
		return (md5_from_stream);
	else if (ft_strcmp(str, "sha256") == 0)
		return (sha256_from_stream);
	else if (ft_strcmp(str, "sha224") == 0)
		return (sha224_from_stream);
	else if (ft_strcmp(str, "sha512") == 0)
		return (sha512_from_stream);
	else if (ft_strcmp(str, "sha384") == 0)
		return (sha384_from_stream);
	else
		return (NULL);
}

static const char	*get_hash_prefix(t_hash_function hash_function)
{
	if (hash_function == sha256)
		return ("SHA256 (");
	else if (hash_function == sha224)
		return ("SHA224 (");
	else if (hash_function == sha512)
		return ("SHA512 (");
	else if (hash_function == sha384)
		return ("SHA384 (");
	else if (hash_function == md5)
		return ("MD5 (");
	else
		return ("");
}

static int	get_len(t_hash_function hash_function)
{
	if (hash_function == md5)
		return (16);
	else if (hash_function == sha256)
		return (32);
	else if (hash_function == sha224)
		return (28);
	else if (hash_function == sha512)
		return (64);
	else if (hash_function == sha384)
		return (48);
	else
		return (0);
}

int	main(int argc, char *argv[])
{
	t_ft_ssl_context	ctx;

	if (argc <= 2)
		return (write(1, "usage: ft_ssl command [flags] [file/string]\n", 44));
	else if (is_valid_command(argv[1]) == 0)
	{
		write(2, "ft_ssl: Error: '", 16);
		write(2, argv[1], ft_strlen(argv[1]));
		return (write(2, "' is an invalid command.\n", 25));
	}
	ft_memset(&ctx, 0, sizeof(ctx));
	ctx.cmd = argv[1];
	ctx.argc = argc;
	ctx.argv = argv;
	ctx.curr_arg = 2;
	ctx.hash_function = str_to_hash_function(ctx.cmd);
	ctx.stream_hash_function = str_to_stream_hash_function(ctx.cmd);
	ctx.len = get_len(ctx.hash_function);
	ctx.hash_prefix = get_hash_prefix(ctx.hash_function);
	ctx.is_big_endian = ctx.hash_function != md5;
	if (ctx.hash_function == sha512 || ctx.hash_function == sha384)
		ctx.process_function = process_str_input_64;
	else
		ctx.process_function = process_str_input;
	return (process_arguments(&ctx));
}
