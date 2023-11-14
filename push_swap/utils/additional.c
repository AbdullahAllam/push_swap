/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <abali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:45:39 by abali             #+#    #+#             */
/*   Updated: 2023/10/24 18:45:40 by abali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(0);
}

int	check_sorted(t_list **list)
{
	t_list	*first;

	first = *list;
	while (first && first->next)
	{
		if (first->value > first->next->value)
			return (0);
		first = first->next;
	}
	return (1);
}

void	free_list(t_list **list)
{
	t_list	*first;
	t_list	*dummy;

	first = *list;
	while (first)
	{
		dummy = first;
		first = first->next;
		free(dummy);
	}
	free(list);
}

void	free_args(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

int	get_location(t_list **list, int index)
{
	t_list	*first;
	int		location;

	location = 0;
	first = *list;
	while (first)
	{
		if (first->index == index)
			break ;
		location++;
		first = first->next;
	}
	return (location);
}
