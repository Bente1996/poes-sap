/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:00:35 by bde-koni          #+#    #+#             */
/*   Updated: 2025/02/18 17:29:33 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	args_check(int argc, char *argv[])
{
	if (argc < 2) // if only ./push_swap is input return
		return (1);
	return (0);

	while (1 < argc)
	{
		
	}
	return ();
}

int	

int has_duplicate(t_node *head, int value)
{
	while (head)
	{
		if (head->value == value)
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