/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:49:02 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/04 08:17:05 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA256_H
# define SHA256_H

# include <stdlib.h>
# include "libc_utils.h"
# include "sha2xx_functions.h"
# include "ft_ssl.h"
# include "sha2xx.h"

char		*sha256(const char *str, uint32_t len);
char		*sha256_from_stream(int fd);
void		sha256_init_ctx(t_sha2xx_context *ctx);

#endif
