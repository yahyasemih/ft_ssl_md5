/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:49:02 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/06 22:30:00 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA224_H
# define SHA224_H

# include <stdlib.h>
# include "libc_utils.h"
# include "sha32bits_functions.h"
# include "ft_ssl.h"
# include "sha32bits.h"

char		*sha224(const char *str, uint64_t len);
char		*sha224_from_stream(int fd, int is_quite);
void		sha224_init_ctx(t_sha32bits_context *ctx);

#endif
