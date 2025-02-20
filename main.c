/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:00:11 by bde-koni          #+#    #+#             */
/*   Updated: 2025/02/20 16:26:39 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*list;

	list = NULL;
	if (argc < 2) // if only ./push_swap is input return
		return (1);

	parse_input();
	small_sort();
	bubble_sort();
	radix_sort();
		
	return (0);
}