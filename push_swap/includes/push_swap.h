/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <abali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:44:02 by abali             #+#    #+#             */
/*   Updated: 2023/10/24 20:47:48 by abali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

int		sa(t_list **list_a);
int		sb(t_list **list_b);
int		ss(t_list **list_a, t_list **list_b);
int		pa(t_list **list_a, t_list **list_b);
int		pb(t_list **list_b, t_list **list_a);
int		ra(t_list **list_a);
int		rb(t_list **list_b);
int		rr(t_list **list_a, t_list **list_b);
int		rra(t_list **list_a);
int		rrb(t_list **list_b);
int		rrr(t_list **list_a, t_list **list_b);

int		swap_general(t_list **list);
int		push_general(t_list **list_to, t_list **list_from);
int		rotate_general(t_list **list);
int		reverserotate_general(t_list **list);

void	ft_error(char *msg);
int		check_sorted(t_list **list);
void	free_list(t_list **list);
void	free_args(char **str);
int		get_location(t_list **list, int index);

void	ft_validate_args(int argc, char **argv);

t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *first);
void	ft_lstadd_back(t_list **list, t_list *node);
void	type_list(t_list *first);
int		ft_lstsize(t_list *first);

void	radix(t_list **list_a, t_list **list_b);
void	simple(t_list **list_a, t_list **list_b);

void	index_list(t_list **list);

void	do_1(t_list **list_a);
void	do_2(t_list **list_a);

int		reduce_lines_one(char *command, t_list **list_a, t_list **list_b);
int		reduce_lines_two(char *command, t_list **list_a, t_list **list_b);

#endif
