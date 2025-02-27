/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_ones.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:16:11 by bde-koni          #+#    #+#             */
/*   Updated: 2025/02/27 17:19:44 by bde-koni         ###   ########.fr       */
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

void	three(t_node **stack_a)  // sa ra rra
{
	if (*stack_a == NULL)
		return;
	if (((*stack_a)->value > (*stack_a)->next->value) && \
		((*stack_a)->next->value > (*stack_a)->next->next->value)) // 321,  als eertse groter is dan tweede, en tweede groter dan derde
	{
		ra(stack_a);
		sa(stack_a);
	}
	if (((*stack_a)->value > (*stack_a)->next->value) && \
		(*stack_a)->next->value < (*stack_a)->next->next->value) // 312, als eertse groter is dan tweede, en tweede kleiner dan derde
		ra(stack_a);
	if (((*stack_a)->value < (*stack_a)->next->value) && ((*stack_a)->next->next->value < (*stack_a)->value)) // 231, eerste kleiner dan tweede, en derde kleiner dan eerste
		rra(stack_a);
	if (((*stack_a)->value > (*stack_a)->next->value) && ((*stack_a)->next->next->value > (*stack_a)->value)) // 213, eerste groter dan tweede, en derde groter dan eerste 
		sa(stack_a);
	if (((*stack_a)->value < (*stack_a)->next->next->value) && ((*stack_a)->next->next->value < (*stack_a)->next->value)) // 132, als eerste kleiner dan derde en derde kleiner dan tweede
	{
		rra(stack_a);
		sa(stack_a);
	}
}

// void	three(t_node **stack_a)
// {
// 	int first;
// 	int second;
// 	int third;
// 	if (*stack_a == NULL)
// 		return;
// 	first = (*stack_a)->value;
// 	second = (*stack_a)->next->value;
// 	third = (*stack_a)->next->next->value;
// 	if (first > second && second > third) 
// 	{
// 		ra(stack_a);
// 		sa(stack_a);
// 	}
// 	else if (first > second && second < third) 
// 		ra(stack_a);
// 	else if (first < second && third < first) 
// 		rra(stack_a);
// 	else if (first > second && third > first) 
// 		sa(stack_a);
// 	else if (first < third && third < second) 
// 	{
// 		rra(stack_a);
// 		sa(stack_a);
// 	}
// }


// if (a > b && b > c) // 3 2 1
// 	sa(stack); rra(stack);
// else if (a > c && c > b) // 3 1 2
// 	ra(stack);
// else if (b > a && a > c) // 2 3 1
// 	sa(stack); ra(stack);
// else if (b > c && c > a) // 2 1 3
// 	sa(stack);
// else if (c > a && a > b) // 1 3 2
// 	rra(stack);

    // versimpelde code