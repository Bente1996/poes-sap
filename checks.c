/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:00:35 by bde-koni          #+#    #+#             */
/*   Updated: 2025/03/18 16:26:39 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//boolians?

int has_duplicate(t_node *head, int value) // head points to first node
{
	while (head)
	{
		if (head->value == value) // check value in node with given value, move through whole list
			return (1); // Duplicate found
		head = head->next;
	}
	return (0); // No duplicates
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	decide_sort(t_node **stack_a, t_node **stack_b)
{
	// printf("Stack size: %d\n\n", stack_size(*stack_a));

	if (stack_a == NULL || *stack_a == NULL) // overbodig?
		return;
	if (stack_size(*stack_a) == 2)
		two(stack_a);
	else if (stack_size(*stack_a) == 3)
	 	three(stack_a);
	else if (stack_size(*stack_a) > 3 && stack_size(*stack_a) < 51)
		selection_sort(stack_a, stack_b);
	else
	{
		bubble_sort(stack_a);
		// print_list(*stack_a, "After bubble sort (sorted values):");
		sorted_indices(*stack_a); // assign sorted indeces to list
		// print_list(*stack_a, "With sorted indeces:");
		bubble_unsort(stack_a); // values back to original, normalized and ready for radix
		//print_list(*stack_a, "After bubble unsort (back to original):");
		radix_sort(stack_a, stack_b); // use operations to sort
		// print_list(*stack_a, "After radix (sorted again):");
		radix_sort(stack_a, stack_b);
	}
}

int	is_already_sorted(t_node *head)
{
	while (head)
	{
		if (head->value > head->next->value)
			return(0);
		head = head->next;
	}
	return (1);
}