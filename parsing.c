/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:01:51 by bde-koni          #+#    #+#             */
/*   Updated: 2025/03/28 19:26:51 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*parse_input(int argc, char **argv)
{
	t_node	*stack_a;
	int		i;

	i = 1;
	stack_a = NULL;
	while (i < argc)
	{
		if (is_number(argv[i]) == 1)
		{
			if (append_node(&stack_a, ft_atoi(argv[i]), i - 1) == NULL)
			{
				free_list(stack_a);
				return (NULL);
			}
			i++;
		}
		else
		{
			ft_printf("Error\n");
			free_list(stack_a);
			return (NULL);
		}
	}
	return (stack_a);
}
