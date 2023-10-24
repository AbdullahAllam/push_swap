/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <abali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:30:59 by abali             #+#    #+#             */
/*   Updated: 2023/10/24 18:31:00 by abali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_length_bits(t_list **list)
{
	t_list	*first;
	int		max;
	int		length_bits;

	first = *list;
	max = first->index;
	length_bits = 0;
	while (first)
	{
		if (first->index > max)
			max = first->index;
		first = first->next;
	}
	while ((max >> length_bits) != 0)
		length_bits++;
	return (length_bits);
}

void	radix(t_list **list_a, t_list **list_b)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size_list;
	int		length_bits;

	i = 0;
	head_a = *list_a;
	size_list = ft_lstsize(head_a);
	length_bits = get_length_bits(list_a);
	while (i < length_bits)
	{
		j = 0;
		while (j++ < size_list)
		{
			head_a = *list_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(list_a);
			else
				pb(list_a, list_b);
		}
		while (ft_lstsize(*list_b) != 0)
			pa(list_a, list_b);
		i++;
	}
}
