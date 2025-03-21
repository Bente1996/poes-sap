/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:37:09 by bde-koni          #+#    #+#             */
/*   Updated: 2025/03/21 18:54:01 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_node
{
	int				value;
	int				index;
	int				sorted_index;
	struct s_node	*next;
}	t_node;

int		main(int argc, char *argv[]);
int		count_operations(void);
t_node	*parse_input(int argc, char **argv);
int		is_already_sorted(t_node *head);
int		has_duplicate(t_node *head, int value);
int		is_number(char *str);
t_node	*new_node(int value, int index);
t_node	*append_node(t_node **head, int value, int index);
void	decide_sort(t_node **stack_a, t_node **stack_b);
void	two(t_node **stack_a);
void	three(t_node **stack_a);
int		find_smallest(t_node *stack_a);
void	move_smallest_to_top(t_node **stack_a);
void	selection_sort(t_node **stack_a, t_node **stack_b);
void	bubble_sort(t_node **head);
void	swap_ints(int *a, int *b);
void	sorted_indices(t_node *head);
void	bubble_unsort(t_node **head);
void	radix_sort(t_node **stack_a, t_node **stack_b);
int		find_max_bits(t_node *stack_a);
int		stack_size(t_node *stack_a);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	sa(t_node **stack_a);
void	ra(t_node **stack_a);
void	rra(t_node **stack_a);
void	print_list(t_node *head, char *str);
void	free_list(t_node *head);

#endif