/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_block.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:24:09 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/06 20:27:08 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READ_BLOCK_H
# define FT_READ_BLOCK_H

# include <unistd.h>

int	ft_read_block(int fd, char *block_buff, int bock_size);

#endif
