/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_block.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:25:20 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/06 20:48:20 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read_block.h"

int	ft_read_block(int fd, char *block_buff, int block_size)
{
	int	r;
	int	total_r;

	total_r = 0;
	r = 1;
	while (r > 0)
	{
		r = read(fd, block_buff + total_r, block_size - total_r);
		if (r < 0)
			return (-1);
		total_r += r;
		block_buff[total_r] = '\0';
		if (total_r == block_size)
			break ;
	}
	return (total_r);
}
