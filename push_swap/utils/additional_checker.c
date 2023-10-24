/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <abali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:16:55 by abali             #+#    #+#             */
/*   Updated: 2023/10/24 20:18:03 by abali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reduce_lines_one(char *command, t_list **list_a, t_list **list_b)
{
	if (!(ft_strcmp(command, "sa")))
	{
		swap_general(list_a);
		return (0);
	}
	if (!(ft_strcmp(command, "sb")))
	{
		swap_general(list_b);
		return (0);
	}
	if (!(ft_strcmp(command, "ss")))
	{
		swap_general(list_a);
		swap_general(list_b);
		return (0);
	}
	if (!(ft_strcmp(command, "pa")))
	{
		push_general(list_a, list_b);
		return (0);
	}
	return (1);
}

int	reduce_lines_two(char *command, t_list **list_a, t_list **list_b)
{
	if (!(ft_strcmp(command, "pb")))
	{
		push_general(list_b, list_a);
		return (0);
	}
	if (!(ft_strcmp(command, "ra")))
	{
		rotate_general(list_a);
		return (0);
	}
	if (!(ft_strcmp(command, "rb")))
	{
		rotate_general(list_b);
		return (0);
	}
	if (!(ft_strcmp(command, "rr")))
	{
		rotate_general(list_a);
		rotate_general(list_b);
		return (0);
	}
	return (1);
}
