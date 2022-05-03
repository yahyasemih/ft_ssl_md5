/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libc_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 07:43:05 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/03 11:33:36 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBC_UTILS_H
# define LIBC_UTILS_H

# include <stdlib.h>

int		ft_strcmp(const char *s1, const char *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);

#endif
