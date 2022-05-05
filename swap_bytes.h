/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bytes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:40:05 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/05 15:42:38 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_BYTES_H
# define SWAP_BYTES_H

# include <stdlib.h>
# include "libc_utils.h"

void	swap_bytes(void *x, uint32_t size);

#endif
