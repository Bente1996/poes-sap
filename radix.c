/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:02:35 by bde-koni          #+#    #+#             */
/*   Updated: 2025/02/18 17:12:45 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_node **stack_a, t_node **stack_b)
{
	size_t	max_bits;
	size_t	bit_position;
	size_t	size;
	size_t	elements;
	
	max_bits = find_max_bits(*stack_a);
	bit_position = 0;
	size = stack_size(*stack_a); // hoeveel elementel zijn er in totaal
	while (bit_position < max_bits) // zoland we nog niet alle digits af zijn gegaan
	{
		elements = 0;
		while (elements < size) // ga elementen af
		{
			if ((((*stack_a)->value >> bit_position) & 1) == 0) // check steeds laatste digit door steeds meer te verschuiven, kijk de hele tijd naar head
				pb(stack_a, stack_b); // als het 0 is, push naar stapel B
			else
				ra(stack_a); // anders zet onderaan A
			elements++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		bit_position++;
	}
}

int	find_max_bits(t_node *stack_a)
{
	int	max;
	int	max_bits;

	max = 0;
	max_bits = 0;
	while (stack_a)
	{
		if (stack_a->value > max) //wanneer we in een node een hogere value vinden
			max = stack_a->value; // benoem een nieuwe max value
		stack_a = stack_a->next; // move to next node and check again untill stack_a (stack_a) is checked
	}
	while ((max >> max_bits) > 0) // shifts max , max_bits positions to the right (starts at max in binary and ends when there are only 0's left)
		max_bits++;
	return (max_bits); // max in binary digits
}

size_t	stack_size(t_node *stack_a)
{
	size_t	size;

	size = 0;
	while (stack_a)
	{
		size++;
		stack_a = stack_a->next;
	}
	return (size);
}