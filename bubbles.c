/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubbles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:02:15 by bde-koni          #+#    #+#             */
/*   Updated: 2025/02/20 16:48:53 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void bubble_sort(t_node **head) // swapping the largest number till the end (sorted part)
{
	t_node	*compare;
	t_node	*sorted;
	int	swapped;
	
	sorted = NULL; // doesnt point to anything yet
	if (*head == NULL)
		return;
	swapped = 1;
	while (swapped == 1) // every time we were able to swap something
	{
		swapped = 0;
		compare = *head; // start comparing at beginning of list again
		while (compare->next != sorted) // sorted part starts at NULL and grows with each swapped == 1 loop (check if what we are gonna compare isnt sorted yet)
		{
			if (compare->value > compare->next->value) // swap when value is bigger than next value
			{
				swap_values(compare, compare->next); // swap pointers
				swapped = 1;
			}
			compare = compare->next; // move to next node until sorted part
		}
		sorted = compare; // is swapped
	}
}

void	bubble_unsort(t_node **head) // grapje niet nodig
{
	t_node	*compare;
	t_node	*sorted;
	int	swapped;

	sorted = NULL;
	if (*head == NULL)
		return;
	swapped = 1;
	while (swapped == 1)
	{
		swapped = 0;
		compare = *head;
		while (compare->next != sorted)
		{
			if (compare->index > compare->next->index)
			{
				swap_
			}
		}
	}
}

void swap_values(t_node *a, t_node *b)
{
	t_node	*temp;

	temp->value = a->value;
	a->value = b->value;
	b->value = temp->value;
}

void sorted_indices(t_node *head)
{
	int i;
	
	i = 0;
	while (head)
	{
		head->sorted_index = i;
		i++;
		head = head->next;
	}
}