/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:00:11 by bde-koni          #+#    #+#             */
/*   Updated: 2025/03/18 16:39:53 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*list;
	t_node	*stack_b;

	stack_b = NULL;
	list = parse_input(argc, argv);
	if (list == NULL)
		return (1);
	// print_list(list, "Parsed list:");
	if (is_already_sorted(list) == 1)
	{
		ft_printf("Error: List was already sorted \n");
		free_list(list);
		return (1);
	}
	decide_sort(&list, &stack_b);
	//print_list(list, "\nSorted list:");
	// ft_printf("Operation count: %d \n\n", count_operations() - 1);
	free_list(list);
	// ft_printf("\n");
	return (0);
}

// pas error messages aan naar "Error \n"