/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <abali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:54:13 by abali             #+#    #+#             */
/*   Updated: 2023/10/24 18:54:14 by abali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_num(char *digit)
{
	int	i;

	i = 0;
	if (digit[0] == '-')
		i++;
	while (digit[i])
	{
		if (!ft_isdigit(digit[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check_redundant(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

void	ft_validate_args(int argc, char **argv)
{
	int		i;
	long	dummy;
	char	**args;	

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
		dummy = ft_atoi(args[i]);
		if (!ft_check_num(args[i]))
			ft_error("Error");
		if (ft_check_redundant(dummy, args, i))
			ft_error("Error");
		if (dummy < -2147483648 || dummy > 2147483647)
			ft_error("Error");
		i++;
	}
	if (argc == 2)
		free_args(args);
}
