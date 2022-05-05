/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_functions_utils.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:41:03 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/05 18:46:38 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_FUNCTIONS_UTILS_H
# define HASH_FUNCTIONS_UTILS_H

# include "ft_ssl.h"

t_hash_function			str_to_hash_function(const char *str);
t_stream_hash_function	str_to_stream_hash_function(const char *str);
const char				*get_hash_prefix(t_hash_function hash_function);
int						get_len(t_hash_function hash_function);
int						is_64bits(t_hash_function hash_function);

#endif
