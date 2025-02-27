/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:02:11 by bde-koni          #+#    #+#             */
/*   Updated: 2025/02/27 15:58:25 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_node **stack_a, t_node **stack_b) // put first element B on top of A
{
	if (*stack_b == NULL) // Nothing to push
		return;

	t_node *temp = *stack_b;	 // Store the first node of B
	*stack_b = (*stack_b)->next; // Move B's head forward
	temp->next = *stack_a;		 // Attach B's old head to A
	*stack_a = temp;			 // A's head now points to the new node
}

void pb(t_node **stack_a, t_node **stack_b) // put first element A on top of B
{
	if (stack_a == NULL || *stack_a == NULL) // Nothing to push
	{
		printf("Error: stack_a is NULL, cannot push\n");
		return;
	}
	t_node *temp = *stack_a;	 // Store the first node of A in temp
	*stack_a = (*stack_a)->next; // Move stack A head to the next node
	temp->next = NULL;			 // Disconnect temp from stack_a before attaching to stack_b
	if (stack_b == NULL)		 // Ensure stack_b is initialized
	{
		printf("Error: stack_b is NULL, initializing...\n");
		*stack_b = temp;
	}
	else
	{
		temp->next = *stack_b; // Attach old head of A to stack B
		*stack_b = temp;	   // Move stack B head to new node
	}
}

// void pb(t_node **stack_a, t_node **stack_b) // Put first element A on top of B
// {
//     if (stack_a == NULL)
//     {
//         printf("Error: stack_a is NULL\n");
//         return;
//     }
//     if (*stack_a == NULL)
//     {
//         printf("Error: *stack_a is NULL (empty stack)\n");
//         return;
//     }

//     printf("Before pb: stack_a head = %d\n", (*stack_a)->value);

//     t_node *temp = *stack_a; // Store the first node of A in temp
//     *stack_a = (*stack_a)->next; // Move A's head to next node

//     temp->next = *stack_b; // Attach A's old head (temp) to B
//     *stack_b = temp; // B's head now points to the new node

//     if (*stack_a)
//         printf("After pb: new stack_a head = %d\n", (*stack_a)->value);
//     else
//         printf("After pb: stack_a is now empty\n");

//     if (*stack_b)
//         printf("After pb: new stack_b head = %d\n", (*stack_b)->value);
// }

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

void ra(t_node **stack_a)
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

void rra(t_node **stack_a)
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
