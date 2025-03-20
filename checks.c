/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:00:35 by bde-koni          #+#    #+#             */
/*   Updated: 2025/03/20 15:56:04 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_already_sorted(t_node *head)
{
	while (head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicate(t_node *head, int value)
{
	while (head)
	{
		if (head->value == value)
			return (1);
		head = head->next;
	}
	return (0);
}

void	decide_sort(t_node **stack_a, t_node **stack_b)
{
	if (stack_a == NULL || *stack_a == NULL)
		return ;
	if (stack_size(*stack_a) == 2)
		two(stack_a);
	else if (stack_size(*stack_a) == 3)
		three(stack_a);
	else if (stack_size(*stack_a) > 3 && stack_size(*stack_a) < 51)
		selection_sort(stack_a, stack_b);
	else
	{
		bubble_sort(stack_a);
		sorted_indices(*stack_a);
		bubble_unsort(stack_a);
		radix_sort(stack_a, stack_b);
	}
}
