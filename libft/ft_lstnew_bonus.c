/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:43:24 by ggualerz          #+#    #+#             */
/*   Updated: 2024/02/14 18:34:29 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*out_list;

	out_list = malloc(sizeof(t_list));
	if (out_list == NULL)
		return (NULL);
	out_list->content = content;
	out_list->next = NULL;
	return (out_list);
}
