/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:50:55 by yoonsele          #+#    #+#             */
/*   Updated: 2023/07/11 14:50:55 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_list	*create_linkedlist(void)
{
	t_list	*linked_list;

	linked_list = ft_calloc(1, sizeof(t_list));
	if (linked_list == NULL)
		exit(EXIT_FAILURE);
	return (linked_list);
}

t_node	*create_new_node(void *object, int type)
{
	t_node	*new_node;

	new_node = ft_calloc(1, sizeof(t_node));
	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->object = object;
	new_node->type = type;
	return (new_node);
}

t_node	*get_node(t_list *linked_list, size_t index)
{
	size_t	i;
	t_node	*dummy;

	i = 0;
	if (linked_list == NULL)
	{
		printf("Error: linked list is null\n");
		return (NULL);
	}
	dummy = linked_list->headnode;
	if (dummy == NULL)
		return (NULL);
	while ((i < index) && dummy->next)
	{
		dummy = dummy->next;
		i++;
	}
	if (i == index)
		return (dummy);
	else
	{
		printf("Error: index out of range\n");
		return (NULL);
	}
}

int	add_node(t_list **linked_list, void *object, int type)
{
	t_node	*dummy;
	t_node	*new_node;

	if (linked_list == NULL || *linked_list == NULL)
		return (0);
	dummy = (*linked_list)->headnode;
	new_node = create_new_node(object, type);
	if (dummy == NULL)
	{
		(*linked_list)->headnode = new_node;
		(*linked_list)->size = 1;
		return (1);
	}
	while (dummy && dummy->next)
		dummy = dummy->next;
	dummy->next = new_node;
	(*linked_list)->size += 1;
	return (1);
}

void	destroy_list(t_list **linked_list)
{
	t_node	*dummy;
	t_node	*remove;

	if (!*linked_list)
		return ;
	dummy = (*linked_list)->headnode;
	while (dummy)
	{
		remove = dummy;
		free(remove->object);
		dummy = dummy->next;
		free(remove);
		remove = NULL;
	}
	free(*linked_list);
	*linked_list = NULL;
}
