/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 08:46:59 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/03 17:19:38 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	process_files(t_ft_ssl_context *ctx, int i)
{
	int		fd;
	char	*s;

	while (i < ctx->argc)
	{
		fd = open(ctx->argv[i], O_RDONLY);
		if (fd < 0)
		{
			write(2, "ft_ssl: ", 8);
			write(2, ctx->cmd, ft_strlen(ctx->cmd));
			write(2, ": ", 2);
			write(2, ctx->argv[i], ft_strlen(ctx->argv[i]));
			write(2, ": ", 2);
			write(2, strerror(errno), ft_strlen(strerror(errno)));
			write(2, "\n", 1);
		}
		else
		{
			s = ctx->stream_hash_function(fd);
			print_result(ctx, s, ctx->argv[i], ft_strlen(ctx->argv[i]));
			free(s);
			close(fd);
		}
		++i;
	}
}

static int	unknown_option_error(char c)
{
	write(2, "ft_ssl: Error: unknown option '", 31);
	write(2, &c, 1);
	write(2, "'\n", 2);
	return (1);
}

static void	handle_prepand_option(t_ft_ssl_context *ctx)
{
	char	*s;

	s = ctx->stream_hash_function(0);
	if (s == NULL)
		return ;
	write_in_hex(s, ctx->len);
	write(1, "\n", 1);
	free(s);
}

static int	process_option(t_ft_ssl_context *ctx, int j)
{
	char	*input;
	char	*s;

	if (ctx->argv[ctx->curr_arg][j] == 'q')
		ctx->flags |= F_QUIET;
	else if (ctx->argv[ctx->curr_arg][j] == 'r')
		ctx->flags |= F_REVERSE;
	else if (ctx->argv[ctx->curr_arg][j] == 'p')
		handle_prepand_option(ctx);
	else if (ctx->argv[ctx->curr_arg][j] == 's')
	{
		if (ctx->argv[ctx->curr_arg][j + 1] != '\0')
			input = ctx->argv[ctx->curr_arg] + j + 1;
		else if (ctx->curr_arg + 1 < ctx->argc)
			input = ctx->argv[++ctx->curr_arg];
		else
			return (write(2, "ft_ssl: Error: '-s' requires argument\n", 45), 0);
		s = process_str_input(input, ctx);
		if (s == NULL)
			return (0);
		print_result(ctx, s, input, ft_strlen(input));
		free(s);
		return (0);
	}
	return (1);
}

int	process_arguments(t_ft_ssl_context *ctx)
{
	int		j;
	int		must_continue;

	while (ctx->curr_arg < ctx->argc)
	{
		if (ctx->argv[ctx->curr_arg][0] == '-')
		{
			j = 1;
			must_continue = 1;
			while (must_continue == 1 && ctx->argv[ctx->curr_arg][j] != '\0')
			{
				if (ft_strchr("pqrs", ctx->argv[ctx->curr_arg][j]) != NULL)
					must_continue = process_option(ctx, j);
				else
					return (unknown_option_error(ctx->argv[ctx->curr_arg][j]));
				++j;
			}
			++ctx->curr_arg;
		}
		else
			break ;
	}
	ctx->is_file = 1;
	process_files(ctx, ctx->curr_arg);
	return (0);
}
