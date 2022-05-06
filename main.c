/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:15:29 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/06 22:32:27 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "hash_functions_utils.h"

static int	print_usage(void)
{
	write(1, "usage: ft_ssl command [flags] [file/string]\n", 44);
	return (0);
}

static int	handle_invalid_command(const char *cmd)
{
	write(2, "ft_ssl: Error: '", 16);
	write(2, cmd, ft_strlen(cmd));
	write(2, "' is an invalid command.\n", 25);
	write(2, "\nCommands:\n", 11);
	write(2, "md5\n", 4);
	write(2, "sha224\n", 7);
	write(2, "sha384\n", 7);
	write(2, "sha256\n", 7);
	write(2, "sha512\n", 7);
	write(2, "sha512/224\n", 11);
	write(2, "sha512/256\n", 11);
	write(2, "\nFlags:\n", 8);
	write(2, "-p -q -r -s\n", 12);
	return (1);
}

int	process_stdin(t_ft_ssl_context *ctx)
{
	char	*s;
	int		fd;

	fd = open("/dev/stdin", O_RDONLY);
	if (fd >= 0)
	{
		s = ctx->stream_hash_function(fd, (ctx->flags & F_QUIET) != 0);
		ctx->is_file = 1;
		print_result(ctx, s, "stdin", 5);
		free(s);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_ft_ssl_context	ctx;

	if (argc < 2)
		return (print_usage());
	else if (is_valid_command(argv[1]) == 0)
		return (handle_invalid_command(argv[1]));
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
	ctx.use_stdin = 1;
	if (argc == 2)
		return (process_stdin(&ctx));
	else
		return (process_arguments(&ctx));
}
