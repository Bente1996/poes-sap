/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:02:11 by bde-koni          #+#    #+#             */
/*   Updated: 2025/02/24 17:17:12 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_node **stack_a, t_node **stack_b) // put first element B on top of A
{
	if (*stack_b == NULL) // Nothing to push
		return;

	t_node *temp = *stack_b;  // Store the first node of B
	*stack_b = (*stack_b)->next; // Move B's head forward
	temp->next = *stack_a; // Attach B's old head to A
	*stack_a = temp; // A's head now points to the new node
}

void pb(t_node **stack_a, t_node **stack_b) //put first element A on top of B
{
	if (*stack_a == NULL) // Nothing to push
		return;

	t_node *temp = *stack_a;  // Store the first node of A in temp
	*stack_a = (*stack_a)->next; // Make head move to next node
	temp->next = *stack_b; // Attach A's old head (temp) to B
	*stack_b = temp; // B's head now points to the new node
}

void sa(t_node **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return;
	t_node *first = *stack_a;
	t_node *second = (*stack_a)->next;
	
	first->next = second->next;
	second->next = (*stack_a);
	*stack_a = second;
}

void	ra(t_node **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return;
	
	t_node *first = *stack_a;
	t_node *last = *stack_a;

	while (last->next) // look for last node
		last = last->next;

	*stack_a = first->next; // make new head
	last->next = first;
	first->next = NULL;
}

void	rra(t_node **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return;
	
	t_node *second_last = *stack_a;
	t_node *last = *stack_a;

	while (last->next) // look for last node
	{	
		second_last = last;
		last = last->next;
	}
	
	second_last->next = NULL; 
	last->next = *stack_a;
	*stack_a = last;
}
