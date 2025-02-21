/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:01:51 by bde-koni          #+#    #+#             */
/*   Updated: 2025/02/21 12:12:44 by bde-koni         ###   ########.fr       */
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
	if (argc < 2) // if only ./push_swap is input return
		return (NULL);
	while (i < argc) // loop through all the arguments
	{
    	if (is_number(argv[i]) == 1) 
    	{
            if (!append_node(&stack_a, ft_atoi(argv[i]), i - 1)) // Pass i-1 as index
            {
                free_list(stack_a);
                return (NULL);
            }
            ft_printf("Index: %d, Value: %d\n", i - 1, ft_atoi(argv[i])); // Debug print
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

int	ft_atoi(const char *str) // pas aan in libft/ printf
{
	int i = 0;
	int sign = 1;
	long long result = 0;

	// Skip whitespace
	while ((str[i] == ' ') || (str[i] == '\f') || (str[i] == '\n')
		|| (str[i] == '\r') || (str[i] == '\t') || (str[i] == '\v'))
		i++;

	// Handle sign
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}

	// Convert digits to integer
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');

		// Check for overflow
		if (result > INT_MAX)
		{
			printf("Error: Found overflow\n");
			exit(1);
		}
		i++;
	}

	// Apply sign and check for INT_MIN
	result *= sign;
	if (result < INT_MIN)
	{
		printf("Error: Found underflow\n");
		exit(1);
	}

	return ((int)result);
}