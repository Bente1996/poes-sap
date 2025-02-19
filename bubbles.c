/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubbles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:02:15 by bde-koni          #+#    #+#             */
/*   Updated: 2025/02/19 15:47:40 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void bubble_sort(t_node **head) // moving the largest number to the end
{
	t_node	*compare;
	t_node	*sorted;
	int	swapped;
	
	sorted = NULL; // doesnt point to anything yet
	if (*head == NULL)
		return;
	swapped = 1;
	while (swapped == 1)
	{
		swapped = 0;
		compare = *head; // compare points to first node
		while (compare->next != sorted) // first round always true, go through list until sorted part
		{
			if (compare->value > compare->next->value) // swap when value is bigger than next value
			{
				swap_values(compare, compare->next); // swap pointers
				swapped = 1;
			}
			compare = compare->next; // move to next node
		}
		sorted = compare; // is swapped
	}
}

void swap_values(t_node *a, t_node *b)
{
	
}

void sorted_indices(t_node *head)
{
	
}