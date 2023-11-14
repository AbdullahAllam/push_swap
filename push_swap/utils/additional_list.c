/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <abali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:53:06 by abali             #+#    #+#             */
/*   Updated: 2023/10/24 18:53:07 by abali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *first)
{
	size_t	size;
	t_list	*dummy;

	dummy = first;
	size = 0;
	while (dummy)
	{
		dummy = dummy->next;
		size++;
	}
	return (size);
}

t_list	*ft_lstlast(t_list *first)
{
	t_list	*last;

	last = first;
	while (last->next)
	{
		last = last->next;
		if (last->next == NULL)
			return (last);
	}
	return (last);
}

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **list, t_list *node)
{
	t_list	*n;

	if (*list)
	{
		n = ft_lstlast(*list);
		n->next = node;
		node->next = NULL;
	}
	else
	{
		*list = node;
		(*list)->next = NULL;
	}
}

void	type_list(t_list *first)
{
	t_list	*dummy;

	dummy = first;
	while (dummy != NULL)
	{
		ft_putnbr_fd(dummy->value, 1);
		ft_putchar_fd(' ', 1);
		dummy = dummy->next;
	}
	ft_putendl_fd(" ", 1);
}
