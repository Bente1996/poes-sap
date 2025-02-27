/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:01:51 by bde-koni          #+#    #+#             */
/*   Updated: 2025/02/27 17:39:16 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *parse_input(int argc, char **argv)
{
	t_node	*stack_a;
	int i;
	int	value;
	
	i = 1; // Start from 1 because argv[0] is the program name
	value = 0;
	stack_a = NULL; // stack_a starts empty
	if (argc < 3) // if only ./push_swap is input return
	{
		ft_printf("Error: not enough arguments \n");
		exit(1);
	}
	while (i < argc) // loop through all the arguments
	{
		if (is_number(argv[i]) == 1) // if a valid number is found
		{
			if (!append_node(&stack_a, ft_atoi(argv[i]), i - 1)) // if no list has been returned
			{
				free_list(stack_a);
				return (NULL);
			}
			i++;
		}
		else
		{
			ft_printf("Error: Invalid integer found: %s\n", argv[i]);
			exit(1); // Exit the program with an error
		}
	}
	return (stack_a);
}

int	ft_atoi(const char *str) // pas aan in libft/ printf
{
	int i = 0;
	int sign = 1;
	long long result = 0;

	while ((str[i] == ' ') || (str[i] == '\f') || (str[i] == '\n')
		|| (str[i] == '\r') || (str[i] == '\t') || (str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result > INT_MAX && (sign == 1))
		{
			printf("Error: Found overflow\n");
			exit(1);
		}
		i++;
	}
	result *= sign;
	if (result < INT_MIN)
	{
		printf("Error: Found underflow\n");
		exit(1);
	}
	return ((int)result);
}