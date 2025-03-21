/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:01:29 by bde-koni          #+#    #+#             */
/*   Updated: 2025/03/21 17:45:38 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_node *head, char *str)
{
	ft_printf("%s\n", str);
	while (head)
	{
		ft_printf("Value: %d, Index: %d Sorted Index: %d\n", \
		head->value, head->index, head->sorted_index);
		head = head->next;
	}
	ft_printf("\n");
}

void	free_list(t_node *head)
{
	t_node	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

int	stack_size(t_node *stack_a)
{
	int	size;

	size = 0;
	while (stack_a)
	{
		size++;
		stack_a = stack_a->next;
	}
	return (size);
}

int	count_operations(void)
{
	static int	operation_count;

	operation_count++;
	return (operation_count);
}
