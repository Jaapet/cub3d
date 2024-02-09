/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 06:21:59 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/14 17:23:03 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*out_str;

	out_str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (out_str == NULL)
		return (NULL);
	ft_strlcpy(out_str, s1, ft_strlen(s1) + 1);
	ft_strlcpy(out_str + (ft_strlen(s1)), s2, ft_strlen(s2) + 1);
	free(s1);
	free(s2);
	return (out_str);
}