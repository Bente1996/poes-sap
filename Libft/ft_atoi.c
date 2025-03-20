/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:19:28 by bde-koni          #+#    #+#             */
/*   Updated: 2025/03/20 13:54:56 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	skip_spaces(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] == ' ') || (str[i] == '\f') || (str[i] == '\n')
		|| (str[i] == '\r') || (str[i] == '\t') || (str[i] == '\v'))
		i++;
	return (i);
}

int	has_sign(const char *str, int i)
{
	int	sign;

	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	return (sign);
}

long long	convert_to_int(const char *str, int i, long long result, int sign)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result > INT_MAX && (sign == 1))
		{
			ft_printf("Error\n");
			exit(1);
		}
		if (result > INT_MAX - 1 && sign == -1)
		{
			ft_printf("Error\n");
			exit(1);
		}
		i++;
	}
	return (result);
}

//FUNCTION: characters to integer
int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	result = 0;
	i = skip_spaces(str);
	sign = has_sign(str, i);
	ft_printf("%d\n", sign);
	if (sign == -1)
		i++;
	result = convert_to_int(str, i, result, sign);
	result *= sign;
	if (result < INT_MIN)
	{
		ft_printf("Error\n");
		exit(1);
	}
	return ((int)result);
}

// int main(void)
// {
//     char nptr[50] = "   +---+4567890";
//
//     printf("%d \n", ft_atoi(nptr));
//     return(0);
// }