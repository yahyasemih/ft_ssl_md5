/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_functions_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:43:34 by yez-zain          #+#    #+#             */
/*   Updated: 2022/05/05 18:43:45 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_functions_utils.h"

t_hash_function	str_to_hash_function(const char *str)
{
	if (ft_strcmp(str, "md5") == 0)
		return (md5);
	else if (ft_strcmp(str, "sha256") == 0)
		return (sha256);
	else if (ft_strcmp(str, "sha224") == 0)
		return (sha224);
	else if (ft_strcmp(str, "sha512") == 0)
		return (sha512);
	else if (ft_strcmp(str, "sha512/224") == 0)
		return (sha512_224);
	else if (ft_strcmp(str, "sha512/256") == 0)
		return (sha512_256);
	else if (ft_strcmp(str, "sha384") == 0)
		return (sha384);
	else
		return (NULL);
}

t_stream_hash_function	str_to_stream_hash_function(const char *str)
{
	if (ft_strcmp(str, "md5") == 0)
		return (md5_from_stream);
	else if (ft_strcmp(str, "sha256") == 0)
		return (sha256_from_stream);
	else if (ft_strcmp(str, "sha224") == 0)
		return (sha224_from_stream);
	else if (ft_strcmp(str, "sha512") == 0)
		return (sha512_from_stream);
	else if (ft_strcmp(str, "sha512/224") == 0)
		return (sha512_224_from_stream);
	else if (ft_strcmp(str, "sha512/256") == 0)
		return (sha512_256_from_stream);
	else if (ft_strcmp(str, "sha384") == 0)
		return (sha384_from_stream);
	else
		return (NULL);
}

const char	*get_hash_prefix(t_hash_function hash_function)
{
	if (hash_function == sha256)
		return ("SHA256 (");
	else if (hash_function == sha224)
		return ("SHA224 (");
	else if (hash_function == sha512)
		return ("SHA512 (");
	else if (hash_function == sha512_224)
		return ("SHA512/224 (");
	else if (hash_function == sha512_256)
		return ("SHA512/256 (");
	else if (hash_function == sha384)
		return ("SHA384 (");
	else if (hash_function == md5)
		return ("MD5 (");
	else
		return ("");
}

int	get_len(t_hash_function hash_function)
{
	if (hash_function == md5)
		return (16);
	else if (hash_function == sha256)
		return (32);
	else if (hash_function == sha224)
		return (28);
	else if (hash_function == sha512)
		return (64);
	else if (hash_function == sha512_224)
		return (28);
	else if (hash_function == sha512_256)
		return (32);
	else if (hash_function == sha384)
		return (48);
	else
		return (0);
}

int	is_64bits(t_hash_function hash_function)
{
	return (hash_function == sha384
		|| hash_function == sha512
		|| hash_function == sha512_224
		|| hash_function == sha512_256);
}
