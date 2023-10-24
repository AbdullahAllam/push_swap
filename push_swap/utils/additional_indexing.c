/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_indexing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <abali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:50:33 by abali             #+#    #+#             */
/*   Updated: 2023/10/24 18:50:34 by abali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_next(t_list **list)
{
	t_list	*head;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *list;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->value < min->value))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	index_list(t_list **list)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_next(list);
	while (head)
	{
		head->index = index++;
		head = get_next(list);
	}
}
