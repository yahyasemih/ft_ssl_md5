/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:49:02 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/04 08:18:12 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA224_H
# define SHA224_H

# include <stdlib.h>
# include "libc_utils.h"
# include "sha2xx_functions.h"
# include "ft_ssl.h"
# include "sha2xx.h"

char		*sha224(const char *str, uint32_t len);
char		*sha224_from_stream(int fd);
void		sha224_init_ctx(t_sha2xx_context *ctx);

#endif
