/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:06:24 by bde-koni          #+#    #+#             */
/*   Updated: 2025/02/21 12:12:58 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// t_node	*append_node(t_node **head, int value, size_t index) // we want to adjust head and give value of new node
// {
// 	t_node	*new;
// 	t_node	*temp;

// 	new = new_node(value, index); //malloc and assign value, index and next
// 	if (new == NULL) // malloc check
// 	{
//         printf("Memory allocation failed!\n");
//         exit(1);
// 	}
// 	// if (has_duplicate(*head, value)) // check value in new node with rest of the nodes
// 	// {
// 	// 	ft_printf("Duplicate number found");
// 	// 	exit (1); // ??
// 	// }
// 	if (*head == NULL)  // If the list is empty, set head to new node
// 		*head = new; // head will point to new node now
// 	else
// 	{
// 		temp = *head; // if there already was a node, temp points to the same node as head, we use temp to go to the last node
// 		while (temp->next) // Find the last node 
// 			temp = temp->next;
// 		temp->next = new; // Attach the new node at the end (temp->next == NULL)
// 	}
// 	return (new);
// }

// t_node *new_node(int value, size_t index)
// {
// 	t_node *new;
	
// 	new = malloc(sizeof(t_node));
// 	if (new == NULL)
// 		return (NULL);
// 	new->value = value;
// 	new->index = index;
// 	new->sorted_index = -1; //default easy to recognise
// 	new->next = NULL;
// 	return (new);
// }

t_node *append_node(t_node **head, int value, int index)
{
    t_node *new = malloc(sizeof(t_node));
    if (!new)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new->value = value;
    new->index = index;
    new->sorted_index = -1;
    new->next = NULL;

    printf("Appending node: Value=%d, Index=%d\n", value, index);

    if (!(*head))
        *head = new;
    else
    {
        t_node *temp = *head;
        while (temp->next)
            temp = temp->next;
        temp->next = new;
    }
    return new;
}