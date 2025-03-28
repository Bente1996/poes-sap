/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:02:11 by bde-koni          #+#    #+#             */
/*   Updated: 2025/03/27 16:11:50 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (*stack_b == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	ft_printf("pa\n");
	count_operations();
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (*stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	if (stack_b == NULL)
		*stack_b = temp;
	else
	{
		temp->next = *stack_b;
		*stack_b = temp;
	}
	ft_printf("pb\n");
	count_operations();
}

void	sa(t_node **stack_a)
{
	t_node	*first;
	t_node	*second;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = (*stack_a)->next;
	first->next = second->next;
	second->next = (*stack_a);
	*stack_a = second;
	ft_printf("sa\n");
	count_operations();
}

void	ra(t_node **stack_a)
{
	t_node	*first;
	t_node	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	last = *stack_a;
	while (last->next)
		last = last->next;
	*stack_a = first->next;
	last->next = first;
	first->next = NULL;
	ft_printf("ra\n");
	count_operations();
}

void	rra(t_node **stack_a)
{
	t_node	*second_last;
	t_node	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	second_last = *stack_a;
	last = *stack_a;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	ft_printf("rra\n");
	count_operations();
}
