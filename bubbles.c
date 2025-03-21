/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubbles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:02:15 by bde-koni          #+#    #+#             */
/*   Updated: 2025/03/21 18:52:41 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_node **head)
{
	t_node	*compare;
	t_node	*sorted;
	int		swapped;

	sorted = NULL;
	swapped = 1;
	while (swapped == 1)
	{
		swapped = 0;
		compare = *head;
		while (compare->next != sorted)
		{
			if (compare->value > compare->next->value)
			{
				swap_ints(&compare->value, &compare->next->value);
				swap_ints(&compare->index, &compare->next->index);
				swapped = 1;
			}
			compare = compare->next;
		}
		sorted = compare;
	}
}

void	bubble_unsort(t_node **head)
{
	t_node	*compare;
	t_node	*sorted;
	int		swapped;

	sorted = NULL;
	swapped = 1;
	while (swapped == 1)
	{
		swapped = 0;
		compare = *head;
		while (compare->next != sorted)
		{
			if (compare->index > compare->next->index)
			{
				swap_ints(&compare->value, &compare->next->value);
				swap_ints(&compare->index, &compare->next->index);
				swap_ints(&compare->sorted_index, &compare->next->sorted_index);
				swapped = 1;
			}
			compare = compare->next;
		}
		sorted = compare;
	}
}

void	swap_ints(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sorted_indices(t_node *head)
{
	int	i;

	i = 0;
	while (head)
	{
		head->sorted_index = i;
		i++;
		head = head->next;
	}
}
