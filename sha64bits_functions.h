/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha64bits_functions.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:46:53 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/05 14:14:49 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA64BITS_FUNCTIONS_H
# define SHA64BITS_FUNCTIONS_H

# include <stdlib.h>

uint64_t	ch_64(uint64_t x, uint64_t y, uint64_t z);
uint64_t	maj_64(uint64_t x, uint64_t y, uint64_t z);
uint64_t	rotr_64(uint64_t x, uint64_t n);
uint64_t	big_sigma_64(uint64_t x, int i);
uint64_t	small_sigma_64(uint64_t x, int i);

#endif
