/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512-224.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:49:45 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/05 18:47:02 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA512_224_H
# define SHA512_224_H

# include <stdlib.h>
# include "libc_utils.h"
# include "sha64bits_functions.h"
# include "ft_ssl.h"
# include "sha64bits.h"

char		*sha512_224(const char *str, uint64_t len);
char		*sha512_224_from_stream(int fd);
void		sha512_224_init_ctx(t_sha64bits_context *ctx);

#endif
