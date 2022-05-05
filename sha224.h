/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:49:02 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/05 11:47:31 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA224_H
# define SHA224_H

# include <stdlib.h>
# include "libc_utils.h"
# include "sha32bits_functions.h"
# include "ft_ssl.h"
# include "sha32bits.h"

char		*sha224(const char *str, uint32_t len);
char		*sha224_from_stream(int fd);
void		sha224_init_ctx(t_sha32bits_context *ctx);

#endif
