/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <abali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:14:58 by abali             #+#    #+#             */
/*   Updated: 2023/10/25 14:39:56 by abali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute(char *command, t_list **list_a, t_list **list_b)
{
	if (reduce_lines_one(command, list_a, list_b) == 0)
		return (0);
	if (reduce_lines_two(command, list_a, list_b) == 0)
		return (0);
	if (!(ft_strcmp(command, "rra")))
	{
		reverserotate_general(list_a);
		return (0);
	}
	if (!(ft_strcmp(command, "rrb")))
	{
		reverserotate_general(list_b);
		return (0);
	}
	if (!(ft_strcmp(command, "rrr")))
	{
		reverserotate_general(list_a);
		reverserotate_general(list_b);
		return (0);
	}
	return (1);
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

void	type_result(t_list **list_a, t_list **list_b)
{
	if (check_sorted(list_a))
		ft_putendl_fd("OK\n", 1);
	else
		ft_putendl_fd("KO\n", 1);
	if (*list_a)
		free_list(list_a);
	if (*list_b)
		free_list(list_b);
}

int	main(int argc, char **argv)
{
	t_list	**list_a;
	t_list	**list_b;
	char	*command;

	if (argc < 2)
		return (0);
	list_a = (t_list **)malloc(sizeof(t_list));
	list_b = (t_list **)malloc(sizeof(t_list));
	*list_a = NULL;
	*list_b = NULL;
	ft_validate_args(argc, argv);
	fill_list(list_a, argc, argv);
	while (get_next_line(0, &command))
	{
		if (execute(command, list_a, list_b))
		{
			ft_error("Error");
			return (-1);
		}
		free(command);
	}
	type_result(list_a, list_b);
	return (0);
}
