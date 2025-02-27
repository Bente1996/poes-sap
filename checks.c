/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:00:35 by bde-koni          #+#    #+#             */
/*   Updated: 2025/02/27 16:34:16 by bde-koni         ###   ########.fr       */
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
	printf("Stack size: %d\n", stack_size(*stack_a));

	if (stack_a == NULL || *stack_a == NULL) // overbodig?
		return;
	if (stack_size(*stack_a) == 2) // GOED
		two(stack_a);
	else if (stack_size(*stack_a) == 3) // GOED
	 	three(stack_a);
	// else if (stack_size(*stack_a) == 4 || stack_size(*stack_a) == 5) // segfault
	//    	four_five(stack_a, stack_b);
	else if (stack_size(*stack_a) > 3 && stack_size(*stack_a) < 51) // segfault
		selection_sort(stack_a, stack_b);
	else                                           // GOED
	{
		bubble_sort(stack_a);
		ft_printf("After bubble sort (sorted values):\n");
		print_list(*stack_a);
		sorted_indices(*stack_a); // assign sorted indeces to list
		ft_printf("With sorted indeces:\n");
		print_list(*stack_a);
		bubble_unsort(stack_a); // values back to original, normalized and ready for radix
		ft_printf("After bubble unsort (back to original):\n");
		print_list(*stack_a);
		radix_sort(stack_a, stack_b); // use operations to sort
		ft_printf("After radix (sorted again):\n");
		print_list(*stack_a);
		radix_sort(stack_a, stack_b);
	}
}

// int	is_already_sorted()
// {

// }