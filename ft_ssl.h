/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 08:46:20 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/05 12:09:52 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <errno.h>
# include <string.h>
# include <unistd.h>
# include "libc_utils.h"
# include "md5.h"
# include "sha256.h"
# include "sha224.h"

# define F_QUIET 0x1
# define F_REVERSE 0x2

typedef char	*(*t_hash_function)(const char *str, uint32_t len);
typedef char	*(*t_stream_hash_function)(int fd);

typedef struct s_ft_ssl_context {
	const char				*cmd;
	const char				*hash_prefix;
	t_hash_function			hash_function;
	t_stream_hash_function	stream_hash_function;
	uint32_t				flags;
	int						is_file;
	char					**argv;
	int						argc;
	int						curr_arg;
	int						len;
}	t_ft_ssl_context;

void		write_in_hex(const char *str, int len);
void		print_result(t_ft_ssl_context *ctx, const char *s, const char *src,
				int src_len);
int			is_valid_command(const char *cmd);
uint64_t	swap_bytes(uint64_t x);
char		*process_str_input(const char *str, t_ft_ssl_context *ctx);
int			process_arguments(t_ft_ssl_context *ctx);

#endif
