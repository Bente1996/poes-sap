/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubbles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:02:15 by bde-koni          #+#    #+#             */
/*   Updated: 2025/02/24 15:09:02 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void bubble_sort(t_node **head) // swapping the largest number till the end (sorted part), change value with index
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
				swap_values(compare, compare->next); // swap value and index
				swapped = 1;
			}
			compare = compare->next; // move to next node until sorted part
		}
		sorted = compare; // is swapped
	}
}

void	bubble_unsort(t_node **head) // bubble sort based on index instead of value
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
				swap_values(compare, compare->next);
				swap_sorted_indeces(compare, compare->next);
				swapped = 1;
			}
			compare = compare->next;
		}
		sorted = compare;
	}
}

void	swap_sorted_indeces(t_node *a, t_node *b)
{
	t_node *temp;                             // hoeft dit niet bij de ANDERE temps??: nee , we bewaren hier alle data van node en niet alleen pointer. zoek beter uit

	if (a == NULL || b == NULL)
	{
		printf("Error: Attempted to swap NULL nodes.\n");
		return;
	}

	temp = malloc(sizeof(t_node));  // Allocate memory for temp
	if (temp == NULL)
	{
		printf("Memory allocation failed!\n");
		return;  // Exit the function if allocation fails
	}
	
	temp->sorted_index = a->sorted_index;
	a->sorted_index = b->sorted_index;
	b->sorted_index = temp->sorted_index; 

	free(temp);  // Free temp after use
}

void swap_values(t_node *a, t_node *b)
{
	t_node *temp;

	if (a == NULL || b == NULL)
	{
		printf("Error: Attempted to swap NULL nodes.\n");
		return;
	}

	temp = malloc(sizeof(t_node));  // Allocate memory for temp
	if (temp == NULL)
	{
		printf("Memory allocation failed!\n");
		return;  // Exit the function if allocation fails
	}

	temp->value = a->value;
	a->value = b->value;
	b->value = temp->value;

	temp->index = a->index;
	a->index = b->index;
	b->index = temp->index; 

	free(temp);  // Free temp after use
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