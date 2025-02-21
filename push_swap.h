/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:37:09 by bde-koni          #+#    #+#             */
/*   Updated: 2025/02/21 12:19:51 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>
# include <stdio.h>
# include "ft_printf/Libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_node
{
	int value;
	size_t	index;
	ssize_t	sorted_index;
	struct s_node *next;
}
t_node;

int	main(int argc, char *argv[]);
t_node *parse_input(int argc, char **argv);
int has_duplicate(t_node *head, int value);
int	is_number(char *str);
t_node *new_node(int value,int index);
t_node *append_node(t_node **head, int value, int index);
void bubble_sort(t_node **head);
void swap_values(t_node *a, t_node *b);
void sorted_indices(t_node *head);
void bubble_unsort(t_node **head);
void	swap_sorted_indeces(t_node *a, t_node *b);
void	radix_sort(t_node **stack_a, t_node **stack_b);
int	find_max_bits(t_node *stack_a);
size_t	stack_size(t_node *stack_a);
void pa(t_node **stack_a, t_node **stack_b);
void pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void print_list(t_node *head);
void free_list(t_node *head);

#endif