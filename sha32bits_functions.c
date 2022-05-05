/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha32bits_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:39:34 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/04 08:25:38 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha32bits_functions.h"

uint32_t	ch(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) ^ ((~x) & z));
}

uint32_t	maj(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) ^ (x & z) ^ (y & z));
}

uint32_t	rotr(uint32_t x, uint32_t n)
{
	return ((x >> n) | (x << (32 - n)));
}

uint32_t	big_sigma(uint32_t x, int i)
{
	if (i == 0)
		return (rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22));
	else
		return (rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25));
}

uint32_t	small_sigma(uint32_t x, int i)
{
	if (i == 0)
		return (rotr(x, 7) ^ rotr(x, 18) ^ (x >> 3));
	else
		return (rotr(x, 17) ^ rotr(x, 19) ^ (x >> 10));
}
