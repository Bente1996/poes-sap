/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_ones.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:16:11 by bde-koni          #+#    #+#             */
/*   Updated: 2025/02/26 18:27:20 by bde-koni         ###   ########.fr       */
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

void	four_five(t_node **stack_a, t_node **stack_b)
{
	if (*stack_a == NULL)
		return;
	print_list(*stack_a);
	// while (stack_size(*stack_a) > 3)
	// {
	// 	move_smallest_to_top(stack_a);
	// 	pb(stack_a, stack_b);
	// }
	three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

// void	four_five(t_node **stack_a, t_node **stack_b) // find smallest number, push to b (pb) (look whether closer to top or bottom) until a is empty, pa. 3 numbers: use three()
// {
// 	t_node	*lowest;
// 	t_node	*temp;

// 	if (*stack_a == NULL)
// 		return;

// 	while (stack_size(stack_a) > 3)
// 	{
// 		lowest = *stack_a; // Start search from the beginning
// 		temp = *stack_a; // make temp so we wont lose head

// 		// Find the node with the smallest value
// 		while (temp)
// 		{
// 			if (temp->value < lowest->value)
// 				lowest = temp;
// 			temp = temp->next;
// 		}

// 		// Move lowest node to top
// 		while (*stack_a != lowest)
// 		{
// 			if (find_smallest(*stack_a) < (stack_size(*stack_a) / 2))
// 				ra(stack_a); // Rotate up if it's in the first half
// 			else
// 				rra(stack_a); // Rotate down if it's in the second half
// 		}

// 		pb(stack_a, stack_b); // Push lowest node to B
// 	}

// 	// Push everything back to A
// 	while (*stack_b)
// 		pa(stack_a, stack_b);
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