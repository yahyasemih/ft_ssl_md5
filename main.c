/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:15:29 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/05 18:43:24 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "hash_functions_utils.h"

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
	if (is_64bits(ctx.hash_function))
		ctx.process_function = process_str_input_64;
	else
		ctx.process_function = process_str_input;
	return (process_arguments(&ctx));
}
