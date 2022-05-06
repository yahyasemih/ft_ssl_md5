/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:49:45 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/06 22:30:00 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA512_H
# define SHA512_H

# include <stdlib.h>
# include "libc_utils.h"
# include "sha64bits_functions.h"
# include "ft_ssl.h"
# include "sha64bits.h"

char		*sha512(const char *str, uint64_t len);
char		*sha512_from_stream(int fd, int is_quite);
void		sha512_init_ctx(t_sha64bits_context *ctx);

#endif
