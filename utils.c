/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:01:29 by bde-koni          #+#    #+#             */
/*   Updated: 2025/02/20 18:19:21 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Print the list (both value and sorted index)
void	print_list(t_node *head)
{
	while (head)
	{
		ft_printf("Value: %d, Index: %zd Sorted Index: %zd\n", head->value, head->index, head->sorted_index);
		head = head->next;
	}
}

// Free the linked list
void free_list(t_node *head)
{
	t_node *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}