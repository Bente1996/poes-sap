/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:00:11 by bde-koni          #+#    #+#             */
/*   Updated: 2025/03/27 14:53:18 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*list;
	t_node	*stack_b;

	stack_b = NULL;
	if (argc < 3)
	{
		ft_printf("Error\n");
		return(1);
	}
	list = parse_input(argc, argv);
	if (list == NULL)
		return (1);
	if (is_already_sorted(list) == 1)
	{
		ft_printf("Error\n");
		free_list(list);
		return (1);
	}
	decide_sort(&list, &stack_b);
	free_list(list);
	return (0);
}
