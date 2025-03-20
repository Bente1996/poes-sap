/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:02:35 by bde-koni          #+#    #+#             */
/*   Updated: 2025/03/19 17:14:55 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	size_t	max_bits;
	size_t	bit_position;
	int		size;
	int		elements;

	max_bits = find_max_bits(*stack_a);
	bit_position = 0;
	size = stack_size(*stack_a);
	while (bit_position < max_bits)
	{
		elements = 0;
		while (elements < size)
		{
			if ((((*stack_a)->sorted_index >> bit_position) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
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
		if (stack_a->sorted_index > max)
			max = stack_a->sorted_index;
		stack_a = stack_a->next;
	}
	while ((max >> max_bits) > 0)
		max_bits++;
	return (max_bits);
}
