/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:09:58 by ggualerz          #+#    #+#             */
/*   Updated: 2024/02/14 18:44:28 by ggualerz         ###   ########.fr       */
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

/*Check if the current line is the beginining of the map 
(it only contain WS and 1 char) return true if its the begining*/
bool ft_is_begin_of_map(char *gnl_str)
{
	size_t i;

	i = 0;
	while (gnl_str[i])
	{
		if (gnl_str[i] != ' ' && gnl_str[i] != '1' && gnl_str[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}
