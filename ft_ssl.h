/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 08:46:20 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/03 11:28:08 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <errno.h>
# include <string.h>
# include <unistd.h>
# include "libc_utils.h"
# include "md5.h"

# define F_QUIET 0x1
# define F_REVERSE 0x2

typedef char	*(*t_hash_function)(const char *str, uint32_t len);
typedef char	*(*t_stream_hash_function)(int fd);

typedef struct s_ft_ssl_context {
	const char				*cmd;
	t_hash_function			hash_function;
	t_stream_hash_function	stream_hash_function;
	uint32_t				flags;
	int						is_file;
	char					**argv;
	int						argc;
	int						curr_arg;
}	t_ft_ssl_context;

void	write_in_hex(const char *str);
void	print_result(t_ft_ssl_context *ctx, const char *s, const char *src,
			int src_len);
int		is_valid_command(const char *cmd);
char	*process_str_input(const char *str, t_ft_ssl_context *ctx);
int		process_arguments(t_ft_ssl_context *ctx);

#endif
