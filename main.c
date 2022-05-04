/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:15:29 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/04 07:05:35 by yez-zain         ###   ########.fr       */
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
	else
		return (NULL);
}

static int	get_len(t_hash_function hash_function)
{
	if (hash_function == md5)
		return (16);
	else if (hash_function == sha256)
		return (32);
	else if (hash_function == sha224)
		return (28);
	else
		return (0);
}

int	main(int argc, char *argv[])
{
	t_ft_ssl_context	ctx;

	if (argc <= 2)
	{
		write(1, "usage: ft_ssl command [flags] [file/string]\n", 44);
		return (0);
	}
	else if (is_valid_command(argv[1]) == 0)
	{
		write(2, "ft_ssl: Error: '", 16);
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, "' is an invalid command.\n", 25);
		return (1);
	}
	ft_memset(&ctx, 0, sizeof(ctx));
	ctx.cmd = argv[1];
	ctx.argc = argc;
	ctx.argv = argv;
	ctx.curr_arg = 2;
	ctx.hash_function = str_to_hash_function(ctx.cmd);
	ctx.stream_hash_function = str_to_stream_hash_function(ctx.cmd);
	ctx.len = get_len(ctx.hash_function);
	return (process_arguments(&ctx));
}
