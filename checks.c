/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:00:35 by bde-koni          #+#    #+#             */
/*   Updated: 2025/02/19 13:30:55 by bde-koni         ###   ########.fr       */
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