/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:26:31 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/03 19:41:28 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA256_FUNCTIONS_H
# define SHA256_FUNCTIONS_H

# include "sha256.h"

uint32_t	ch(uint32_t x, uint32_t y, uint32_t z);
uint32_t	maj(uint32_t x, uint32_t y, uint32_t z);
uint32_t	rotr(uint32_t x, uint32_t n);
uint32_t	big_sigma(uint32_t x, int i);
uint32_t	small_sigma(uint32_t x, int i);

#endif
