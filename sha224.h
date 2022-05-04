/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:49:02 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/04 08:08:53 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA224_H
# define SHA224_H

# include <stdlib.h>
# include "libc_utils.h"
# include "sha256_functions.h"
# include "ft_ssl.h"
# include "sha2xx.h"

char		*sha224(const char *str, uint32_t len);
char		*sha224_from_stream(int fd);
char		*sha224_fill_result(t_sha2xx_context *ctx, char *str);
void		sha224_init_ctx(t_sha2xx_context *ctx);
void		sha224_update_ctx(t_sha2xx_context *ctx, int update_hash);
void		sha224_block_iteration(t_sha2xx_context *ctx);

#endif
