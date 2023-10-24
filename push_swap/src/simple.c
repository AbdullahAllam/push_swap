/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <abali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:31:04 by abali             #+#    #+#             */
/*   Updated: 2023/10/24 18:42:23 by abali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min(t_list **list, int current_min)
{
	t_list	*first;
	int		min;

	first = *list;
	min = first->index;
	while (first->next)
	{
		first = first->next;
		if ((first->index < min) && first->index != current_min)
			min = first->index;
	}
	return (min);
}

static void	sort_three(t_list **list_a)
{
	t_list	*first;
	int		min;
	int		next_minimum;

	first = *list_a;
	min = get_min(list_a, -1);
	next_minimum = get_min(list_a, min);
	if (first->index == min && first->next->index != next_minimum)
		do_1(list_a);
	else if (first->index == next_minimum)
	{
		if (first->next->index == min)
			sa(list_a);
		else
			rra(list_a);
	}
	else
	{
		if (first->next->index == min)
			ra(list_a);
		else
			do_2(list_a);
	}
}

static void	sort_four(t_list **list_a, t_list **list_b)
{
	int	location;

	location = get_location(list_a, get_min(list_a, -1));
	if (location == 1)
		ra(list_a);
	else if (location == 2)
	{
		ra(list_a);
		ra(list_a);
	}
	else if (location == 3)
		rra(list_a);
	if (check_sorted(list_a))
		return ;
	pb(list_a, list_b);
	sort_three(list_a);
	pa(list_a, list_b);
}

static void	sort_five(t_list **list_a, t_list **list_b)
{
	int	location;

	location = get_location(list_a, get_min(list_a, -1));
	if (location == 1)
		ra(list_a);
	else if (location == 2)
	{
		ra(list_a);
		ra(list_a);
	}
	else if (location == 3)
	{
		rra(list_a);
		rra(list_a);
	}
	else if (location == 4)
		rra(list_a);
	if (check_sorted(list_a))
		return ;
	pb(list_a, list_b);
	sort_four(list_a, list_b);
	pa(list_a, list_b);
}

void	simple(t_list **list_a, t_list **list_b)
{
	int	size;

	if (check_sorted(list_a) || ft_lstsize(*list_a) == 0
		|| ft_lstsize(*list_a) == 1)
		return ;
	size = ft_lstsize(*list_a);
	if (size == 2)
		sa(list_a);
	else if (size == 3)
		sort_three(list_a);
	else if (size == 4)
		sort_four(list_a, list_b);
	else if (size == 5)
		sort_five(list_a, list_b);
}
