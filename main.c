/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:00:11 by bde-koni          #+#    #+#             */
/*   Updated: 2025/02/27 18:30:25 by bde-koni         ###   ########.fr       */
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
		return (-1);
	ft_printf("Parsed list:\n");
	print_list(list);
	if (is_already_sorted(list) == 1)
	{
		ft_printf("Error: List was already sorted \n");
		free_list(list);
		exit(1);
	}
	decide_sort(&list, &stack_b);
	ft_printf("Sorted list:\n");
	print_list(list);
	ft_printf("%d \n", get_operations());
	free_list(list);
	return (0);
}
