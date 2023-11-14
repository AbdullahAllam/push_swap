/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_extra_instructions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <abali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:05:22 by abali             #+#    #+#             */
/*   Updated: 2023/10/24 19:06:18 by abali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rrr(t_list **list_a, t_list **list_b)
{
	if ((ft_lstsize(*list_a) < 2) || (ft_lstsize(*list_b) < 2))
		return (-1);
	reverserotate_general(list_a);
	reverserotate_general(list_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}

int	swap_general(t_list **list)
{
	t_list	*first;
	t_list	*next;
	int		dummy_val;
	int		dummy_index;

	if (ft_lstsize(*list) <= 1)
		return (-1);
	first = *list;
	next = first->next;
	if (!next && !first)
		ft_error("Error");
	dummy_val = first->value;
	dummy_index = first->index;
	first->value = next->value;
	first->index = next->index;
	next->value = dummy_val;
	next->index = dummy_index;
	return (0);
}

int	push_general(t_list **list_to, t_list **list_from)
{
	t_list	*dummy;
	t_list	*first_to;
	t_list	*first_from;

	if (ft_lstsize(*list_from) == 0)
		return (-1);
	first_to = *list_to;
	first_from = *list_from;
	dummy = first_from;
	first_from = first_from->next;
	*list_from = first_from;
	if (!first_to)
	{
		first_to = dummy;
		first_to->next = NULL;
		*list_to = first_to;
	}
	else
	{
		dummy->next = first_to;
		*list_to = dummy;
	}
	return (0);
}

int	rotate_general(t_list **list)
{
	t_list	*first;
	t_list	*last;

	if (ft_lstsize(*list) < 2)
		return (-1);
	first = *list;
	last = ft_lstlast(first);
	*list = first->next;
	first->next = NULL;
	last->next = first;
	return (0);
}

int	reverserotate_general(t_list **list)
{
	t_list	*first;
	t_list	*last;

	if (ft_lstsize(*list) < 2)
		return (-1);
	first = *list;
	last = ft_lstlast(first);
	while (first)
	{
		if (first->next->next == NULL)
		{
			first->next = NULL;
			break ;
		}
		first = first->next;
	}
	last->next = *list;
	*list = last;
	return (0);
}
