/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:06:24 by bde-koni          #+#    #+#             */
/*   Updated: 2025/02/19 13:27:45 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void append_node(t_node **head, long long value) // we want to adjust head and give value of new node
{
	t_node	*new;
	t_node	*temp;

	new = new_node(value); //malloc and assign value, index and next
	if (new == NULL) // malloc check
		free(new); // nodig?
		return;	
	if (has_duplicate(*head, value)) // check value in new node with rest of the nodes
	{
		ft_printf("Duplicate number found %s");
		exit (1); // ??
	}
	if (*head == NULL)  // If the list is empty, set head to new node
		*head = new; // head will point to new node now
	else
	{
		temp = *head; // if there already was a node, temp points to the same node as head
		while (temp->next) // Find the last node 
			temp = temp->next;
		temp->next = new; // Attach the new node at the end (temp->next == NULL)
	}
}

t_node *new_node(long long value)
{
	t_node *new;
	
	new = malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->value = value;
	new->index_sorted = -1; //default?
	new->next = NULL;
	return (new);
}