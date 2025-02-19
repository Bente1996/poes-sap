/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:01:51 by bde-koni          #+#    #+#             */
/*   Updated: 2025/02/19 13:57:28 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *parse_input(int argc, char **argv)
{
	t_node	*stack_a;
	size_t i;
	int	value;
	
	i = 1; // Start from 1 because argv[0] is the program name
	value = ft_atoi(argv[i]);
	stack_a = NULL; // stack_a starts empty
	while (i < argc) // loop through all the arguments
	{
		if (is_number(argv[i]) == 1) // as long as we only find valid numbers (input as string)
		{
			append_node(&stack_a, ft_atoi(argv[i])); // Convert ton int and store numbers in nodes
			if (!stack_a)
			{
				free_list(); // ?
				return (NULL);
			}
			ft_printf("%zu", i); // print unsorted index
			i++;
		}
		else
		{
			printf("Error: Invalid integer found: %s\n", argv[i]);
			exit(1); // Exit the program with an error
		}
	}
	return (stack_a);
}

int	ft_atoi(const char *str)
{
	int i = 0;
	int sign = 1;
	long long result = 0;

	while ((str[i] == ' ') || (str[i] == '\f') || (str[i] == '\n')
		|| (str[i] == '\r') || (str[i] == '\t') || (str[i] == '\v'))
		i++;
	if (str[i] == '-')
		sign *= -1;
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (str[i] - '0') + (10 * result);
		if (result > INT_MAX)
		{
			ft_printf("Error: Found overflow \n");
			exit(1);
		}
		i++;
	}
	return (result * sign);
}