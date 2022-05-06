/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha384.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:49:45 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/06 22:30:00 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA384_H
# define SHA384_H

# include <stdlib.h>
# include "libc_utils.h"
# include "sha64bits_functions.h"
# include "ft_ssl.h"
# include "sha64bits.h"

char		*sha384(const char *str, uint64_t len);
char		*sha384_from_stream(int fd, int is_quite);
void		sha384_init_ctx(t_sha64bits_context *ctx);

#endif
