/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:37:09 by bde-koni          #+#    #+#             */
/*   Updated: 2025/02/18 17:13:11 by bde-koni         ###   ########.fr       */
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
	long long value;
	int sorted_index;
	struct s_node *next;
}
t_node;

int	main(int argc, char *argv[]);
int has_duplicate(t_node *head, int value);
int	is_number(char *str);
t_node *parse_input(int argc, char **argv);
t_node *new_node(long long value);
void append_node(t_node **head, long long value);
void pa(t_node **stack_a, t_node **stack_b);
void pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	radix(t_node **stack_a, t_node **stack_b);
int	find_max_bits(t_node *stack_a);
size_t	stack_size(t_node *stack_a);
void bubble_sort(t_node **head);
void swap_values(t_node *a, t_node *b);
void assign_indices(t_node *head);
void print_list(t_node *head);
void free_list(t_node *head);
int	ft_errors(char *argv[], char *endptr, int i, t_node *list);

#endif