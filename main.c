/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:00:11 by bde-koni          #+#    #+#             */
/*   Updated: 2025/02/21 11:52:38 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*list;

	list = NULL;
	
	list = parse_input(argc, argv);
	// print_list(list);
	// small_sort();
	bubble_sort(&list); // make list ready for sorted indeces
	// print_list(list);
	sorted_indices(list); // assign sorted indeces to list
	print_list(list);
	bubble_unsort(&list); // values back to original, normalized and ready for radix
	// radix_sort(); // use operations to sort
	free_list(list);
	return (0);
}
