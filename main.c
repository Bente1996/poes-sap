/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:00:11 by bde-koni          #+#    #+#             */
/*   Updated: 2025/02/21 17:47:34 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*list;
	t_node	*stack_b;

	list = NULL;
	stack_b = NULL;	
	list = parse_input(argc, argv);
	//print_list(list); // GOED
	// small_sort();
	bubble_sort(&list); // make list ready for sorted indeces // GOED
	//print_list(list);
	sorted_indices(list); // assign sorted indeces to list // GOED
	//print_list(list);
	bubble_unsort(&list); // values back to original, normalized and ready for radix  // value fout, index goed, sorted index fout
	print_list(list);
	radix_sort(&list, &stack_b); // use operations to sort
	//print_list(list);
	free_list(list);
	return (0);
}
