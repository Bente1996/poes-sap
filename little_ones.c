/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_ones.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:16:11 by bde-koni          #+#    #+#             */
/*   Updated: 2025/03/21 18:03:24 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two(t_node **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	three(t_node **stack_a)
{
	if (((*stack_a)->value > (*stack_a)->next->value) && \
		((*stack_a)->next->value > (*stack_a)->next->next->value))
	{
		ra(stack_a);
		sa(stack_a);
	}
	if (((*stack_a)->value > (*stack_a)->next->value) && \
		(*stack_a)->next->value < (*stack_a)->next->next->value)
		ra(stack_a);
	if (((*stack_a)->value < (*stack_a)->next->value) && \
		((*stack_a)->next->next->value < (*stack_a)->value))
		rra(stack_a);
	if (((*stack_a)->value > (*stack_a)->next->value) && \
		((*stack_a)->next->next->value > (*stack_a)->value))
		sa(stack_a);
	if (((*stack_a)->value < (*stack_a)->next->next->value) && \
		((*stack_a)->next->next->value < (*stack_a)->next->value))
	{
		rra(stack_a);
		sa(stack_a);
	}
}
