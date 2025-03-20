/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubbles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:02:15 by bde-koni          #+#    #+#             */
/*   Updated: 2025/03/19 16:56:11 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_node **head)
{
	t_node	*compare;
	t_node	*sorted;
	int		swapped;

	sorted = NULL;
	if (*head == NULL)
		return ;
	swapped = 1;
	while (swapped == 1)
	{
		swapped = 0;
		compare = *head;
		while (compare->next != sorted)
		{
			if (compare->value > compare->next->value)
			{
				swap_values(compare, compare->next);
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
	if (*head == NULL)
		return ;
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
	t_node	*temp;

	if (a == NULL || b == NULL)
		return ;
	temp = malloc(sizeof(t_node));
	if (temp == NULL)
		return ;
	temp->sorted_index = a->sorted_index;
	a->sorted_index = b->sorted_index;
	b->sorted_index = temp->sorted_index;
	free(temp);
}

void	swap_values(t_node *a, t_node *b)
{
	t_node	*temp;

	if (a == NULL || b == NULL)
		return ;
	temp = malloc(sizeof(t_node));
	if (temp == NULL)
		return ;
	temp->value = a->value;
	a->value = b->value;
	b->value = temp->value;
	temp->index = a->index;
	a->index = b->index;
	b->index = temp->index;
	free(temp);
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
