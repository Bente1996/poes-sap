/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:06:24 by bde-koni          #+#    #+#             */
/*   Updated: 2025/03/19 17:02:56 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*append_node(t_node **head, int value, int index)
{
	t_node	*new;
	t_node	*temp;

	new = new_node(value, index);
	if (new == NULL)
		exit(1);
	if (has_duplicate(*head, value))
	{
		ft_printf("Error\n", value);
		exit (1);
	}
	if (*head == NULL)
		*head = new;
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	return (new);
}

t_node	*new_node(int value, int index)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->value = value;
	new->index = index;
	new->sorted_index = -1;
	new->next = NULL;
	return (new);
}
