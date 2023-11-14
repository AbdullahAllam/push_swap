/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_extra_instructions_2.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <abali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:07:10 by abali             #+#    #+#             */
/*   Updated: 2023/10/24 19:07:46 by abali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_list **list_a)
{
	if (rotate_general(list_a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(t_list **list_b)
{
	if (rotate_general(list_b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rr(t_list **list_a, t_list **list_b)
{
	if ((ft_lstsize(*list_a) < 2) || (ft_lstsize(*list_b) < 2))
		return (-1);
	rotate_general(list_a);
	rotate_general(list_b);
	ft_putendl_fd("rr", 1);
	return (0);
}

int	rra(t_list **list_a)
{
	if (reverserotate_general(list_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_list **list_b)
{
	if (reverserotate_general(list_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}
