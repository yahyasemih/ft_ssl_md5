/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha32bits_functions.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:26:31 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/05 14:14:59 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA32BITS_FUNCTIONS_H
# define SHA32BITS_FUNCTIONS_H

# include <stdlib.h>

uint32_t	ch_32(uint32_t x, uint32_t y, uint32_t z);
uint32_t	maj_32(uint32_t x, uint32_t y, uint32_t z);
uint32_t	rotr_32(uint32_t x, uint32_t n);
uint32_t	big_sigma_32(uint32_t x, int i);
uint32_t	small_sigma_32(uint32_t x, int i);

#endif
