/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:00:11 by bde-koni          #+#    #+#             */
/*   Updated: 2025/02/26 18:37:02 by bde-koni         ###   ########.fr       */
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
	ft_printf("Parsed input:\n");
	print_list(list);
	decide_sort(&list, &stack_b);
	print_list(list);
	free_list(list);
	return (0);
}

// int	main(int argc, char *argv[]) // voor selection sort
// {
// 	t_node	*list;
// 	t_node	*stack_b;

// 	list = NULL;
// 	stack_b = NULL;	
// 	list = parse_input(argc, argv);
// 	ft_printf("Parsed input:\n");
// 	print_list(list);
// 	if (stack_size(list) < 50)
// 	{
// 		small_sort(&list, &stack_b);
// 		ft_printf("After small sort (sorted values):\n");
// 		print_list(list);
// 	}
// 	else
// 	{
// 		bubble_sort(&list); // make list ready for sorted indeces
// 		ft_printf("After bubble sort (sorted values):\n");
// 		print_list(list);
// 		sorted_indices(list); // assign sorted indeces to list
// 		ft_printf("With sorted indeces:\n");
// 		print_list(list);
// 		bubble_unsort(&list); // values back to original, normalized and ready for radix
// 		ft_printf("After bubble unsort (back to original):\n");
// 		print_list(list);
// 		radix_sort(&list, &stack_b); // use operations to sort
// 		ft_printf("After radix (sorted again):\n");
// 		print_list(list);
// 	}
// 	free_list(list);
// 	return (0);
// }
