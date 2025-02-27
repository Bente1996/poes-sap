/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_ones.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:16:11 by bde-koni          #+#    #+#             */
/*   Updated: 2025/02/27 17:23:15 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two(t_node **stack_a)
{
	if (*stack_a == NULL)
		return;
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	three(t_node **stack_a)
{
	int first;
	int second;
	int third;
	if (*stack_a == NULL)
		return;
	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first > second && second > third) 
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (first > second && second < third) 
		ra(stack_a);
	else if (first < second && third < first) 
		rra(stack_a);
	else if (first > second && third > first) 
		sa(stack_a);
	else if (first < third && third < second) 
	{
		rra(stack_a);
		sa(stack_a);
	}
}
