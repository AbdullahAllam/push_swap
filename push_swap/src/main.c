/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <abali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:30:27 by abali             #+#    #+#             */
/*   Updated: 2023/10/24 18:32:16 by abali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_in_order(t_list **list_a, t_list **list_b)
{
	if (ft_lstsize(*list_a) <= 5)
		simple(list_a, list_b);
	else
		radix(list_a, list_b);
}

static void	fill_list(t_list **list, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(list, new);
		i++;
	}
	index_list(list);
	if (argc == 2)
		free_args(args);
}

int	main(int argc, char **argv)
{
	t_list	**list_a;
	t_list	**list_b;

	if (argc < 2)
		return (-1);
	ft_validate_args(argc, argv);
	list_a = (t_list **)malloc(sizeof(t_list));
	list_b = (t_list **)malloc(sizeof(t_list));
	*list_a = NULL;
	*list_b = NULL;
	fill_list(list_a, argc, argv);
	if (check_sorted(list_a))
	{
		free_list(list_a);
		free_list(list_b);
		return (0);
	}
	put_in_order(list_a, list_b);
	free_list(list_a);
	free_list(list_b);
	return (0);
}
