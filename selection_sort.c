/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:55:56 by bde-koni          #+#    #+#             */
/*   Updated: 2025/03/21 18:03:57 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_node *stack_a)
{
	int		pos;
	int		smallest_pos;
	t_node	*smallest;

	pos = 1;
	smallest_pos = 1;
	smallest = stack_a;
	while (stack_a)
	{
		if (stack_a->value < smallest->value)
		{
			smallest = stack_a;
			smallest_pos = pos;
		}
		stack_a = stack_a->next;
		pos++;
	}
	return (smallest_pos);
}

void	move_smallest_to_top(t_node **stack_a)
{
	int	mid_stack;
	int	smallest_pos;

	smallest_pos = find_smallest(*stack_a);
	mid_stack = stack_size(*stack_a) / 2;
	if (mid_stack < smallest_pos)
	{
		while (smallest_pos <= stack_size(*stack_a))
		{
			rra(stack_a);
			smallest_pos++;
		}
	}
	else
	{
		while (smallest_pos > 1)
		{
			ra(stack_a);
			smallest_pos--;
		}
	}
}

void	selection_sort(t_node **stack_a, t_node **stack_b)
{
	while (stack_size(*stack_a) > 3)
	{
		move_smallest_to_top(stack_a);
		pb(stack_a, stack_b);
	}
	three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
