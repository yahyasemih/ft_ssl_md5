/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha64bits_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:47:34 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/05 14:35:08 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha64bits_functions.h"

uint64_t	ch_64(uint64_t x, uint64_t y, uint64_t z)
{
	return ((x & y) ^ ((~x) & z));
}

uint64_t	maj_64(uint64_t x, uint64_t y, uint64_t z)
{
	return ((x & y) ^ (x & z) ^ (y & z));
}

uint64_t	rotr_64(uint64_t x, uint64_t n)
{
	return ((x >> n) | (x << (64 - n)));
}

uint64_t	big_sigma_64(uint64_t x, int i)
{
	if (i == 0)
		return (rotr_64(x, 28) ^ rotr_64(x, 34) ^ rotr_64(x, 39));
	else
		return (rotr_64(x, 14) ^ rotr_64(x, 18) ^ rotr_64(x, 41));
}

uint64_t	small_sigma_64(uint64_t x, int i)
{
	if (i == 0)
		return (rotr_64(x, 1) ^ rotr_64(x, 8) ^ (x >> 7));
	else
		return (rotr_64(x, 19) ^ rotr_64(x, 61) ^ (x >> 6));
}
