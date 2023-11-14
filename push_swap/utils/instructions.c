/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <abali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:56:48 by abali             #+#    #+#             */
/*   Updated: 2023/10/24 19:07:42 by abali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_list **list_a)
{
	if (swap_general(list_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_list **list_b)
{
	if (swap_general(list_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_list **list_a, t_list **list_b)
{
	if ((ft_lstsize(*list_a) <= 1) || (ft_lstsize(*list_b) <= 1))
		return (-1);
	swap_general(list_a);
	swap_general(list_b);
	ft_putendl_fd("ss", 1);
	return (0);
}

int	pa(t_list **list_a, t_list **list_b)
{
	if (push_general(list_a, list_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_list **list_a, t_list **list_b)
{
	if (push_general(list_b, list_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}
