/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:00:11 by bde-koni          #+#    #+#             */
/*   Updated: 2025/03/28 19:27:52 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*list;
	t_node	*stack_b;

	stack_b = NULL;
	if (argc < 3)
		return (1);
	list = parse_input(argc, argv);
	if (list == NULL)
		return (1);
	if (is_already_sorted(list) == 0)
		decide_sort(&list, &stack_b);
	free_list(list);
	return (0);
}
