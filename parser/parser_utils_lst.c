/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:16:27 by ggualerz          #+#    #+#             */
/*   Updated: 2024/03/11 14:25:34 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*map_lst functions*/
t_map_lst	*ft_maplstnew(char *content)
{
	t_map_lst	*out_list;

	out_list = malloc(sizeof(t_map_lst));
	if (out_list == NULL)
		return (NULL);
	out_list->content = content;
	out_list->next = NULL;
	return (out_list);
}

t_map_lst	*ft_maplstlast(t_map_lst *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_maplstadd_back(t_map_lst **lst, t_map_lst *new)
{
	if (lst)
	{
		if (*lst)
			(ft_maplstlast(*lst))->next = new;
		else
			*lst = new;
	}
}

void	ft_mapls_free(t_map_lst *lst)
{
	t_map_lst	*cur_lst;
	t_map_lst	*next_lst;

	cur_lst = lst;
	while (cur_lst->next)
	{
		next_lst = cur_lst->next;
		free(cur_lst->content);
		free(cur_lst);
		cur_lst = next_lst;
	}
	free(cur_lst->content);
	free(cur_lst);
}
