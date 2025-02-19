/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   everything.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:07:12 by bde-koni          #+#    #+#             */
/*   Updated: 2025/02/18 18:12:19 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

typedef struct s_node {
    long long value;
    int sorted_index; // Field for normalized index
    struct s_node *next;
} t_node;


void pa(t_node **stack_a, t_node **stack_b) // put first element B on top of A
{
    if (*stack_b == NULL) // Nothing to push
        return;

    t_node *temp = *stack_b;  // Store the first node of B
    *stack_b = (*stack_b)->next; // Move B's head forward
    temp->next = *stack_a; // Attach B's old head to A
    *stack_a = temp; // A's head now points to the new node
}

void pb(t_node **stack_a, t_node **stack_b) //put first element A on top of B
{
    if (*stack_a == NULL) // Nothing to push
        return;

    t_node *temp = *stack_a;  // Store the first node of A in temp
    *stack_a = (*stack_a)->next; // Make head move to next node
    temp->next = *stack_b; // Attach A's old head (temp) to B
    *stack_b = temp; // B's head now points to the new node
}


void sa(t_node **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return;
	t_node *first = *stack_a;
	t_node *second = (*stack_a)->next;
	
	first->next = second->next;
	second->next = (*stack_a);
	*stack_a = second;
}

void sb(t_node **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return;
		
	t_node *first = *stack_b;
	t_node *second = (*stack_b);

	first->next = second->next;
	second->next = first;
	*stack_b = second;
}


void	ra(t_node **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return;
	
	t_node *first = *stack_a;
	t_node *last = *stack_a;

	while (last->next) // look for last node
		last = last->next;

	*stack_a = first->next; // make new head
	last->next = first;
	first->next = NULL;
}

void	rb(t_node **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return;
	
	t_node *first = *stack_b;
	t_node *last = *stack_b;

	while (last->next) // look for last node
		last = last->next;

	*stack_b = first->next; // make new head
	last->next = first;
	first->next = NULL;
}


void	rr(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rra(t_node **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return;
	
	t_node *second_last = *stack_a;
	t_node *last = *stack_a;

	while (last->next) // look for last node
	{	
		second_last = last;
		last = last->next;
	}
	
	second_last->next = NULL; 
	last->next = *stack_a;
	*stack_a = last;
}

void	rrb(t_node **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return;
	
	t_node *second_last = *stack_b;
	t_node *last = *stack_b;

	while (last->next) // look for last node
	{	
		second_last = last;
		last = last->next;
	}
	
	second_last->next = NULL; 
	last->next = *stack_b;
	*stack_b = last;
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

// t_node	*new_node(int number, size_t index)
// {
// 	t_node *node = (t_node *)malloc(sizeof(t_node)); //allocate new node
// 	if (!node)
// 		return (NULL);
// 	node->value = number; // in node: make value number
// 	//node->index = index;
// 	node->sorted_index;
// 	node->next = NULL; // in node: make next point to NULL
// 	return (node);
// }

// size_t	*bubble_sort(t_node **stack_a, size_t sorted_index)
// {
// 	t_node	*temp;
	
// 	temp = (*stack_a)->next; 
// 	while (*stack_a || (*stack_a)->value > temp->value)
// 	{
// 		if ((*stack_a)->next == NULL)
// 			return (&sorted_index);
// 		if ((*stack_a)->value > (*stack_a)->next)
// 			sa(stack_a);
// 	}
// 	(*stack_a)->sorted_index = 0;
// 	while (*stack_a)
// 	{
// 		(*stack_a)->next = temp;
// 		temp->sorted_index += 1;
// 	}
// 	return (&sorted_index); //bubble sorted stack
// }

// Swap the values of two nodes (for bubble sort)
void swap_values(t_node *a, t_node *b) {
    long long temp = a->value;
    a->value = b->value;
    b->value = temp;
}


// Bubble sort the linked list by swapping node values
void bubble_sort(t_node **head) {
    if (*head == NULL)
        return;
    
    int swapped;
    t_node *ptr1;
    t_node *lptr = NULL; // Marks the portion already sorted

    do {
        swapped = 0;
        ptr1 = *head;
        
        while (ptr1->next != lptr) {
            if (ptr1->value > ptr1->next->value) {
                swap_values(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Assign normalized indices based on the sorted order of the list
void assign_indices(t_node *head) {
    int index = 0;
    while (head) {
        head->sorted_index = index;
        index++;
        head = head->next;
    }
}

int has_duplicate(t_node *head, int value)
{
	while (head)
	{
		if (head->value == value)
			return (1); // Duplicate found
		head = head->next;
	}
	return (0); // No duplicates
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

// void append_node(t_node **head, int number, size_t index)
// {
// 	if (has_duplicate(*head, number))  // Check for duplicates before adding
// 	{
// 		printf("Error: Duplicate number found: %d\n", number);
// 		exit(1); // Exit the program with an error
// 	}
	
// 	t_node *new = new_node(number, index); // we make a node
// 	if (!new)
// 		return; //free
// 	if (*head == NULL)  // If the list is empty, set head to new node
// 		*head = new; // head will point to new node now
// 	else 
// 	{
// 		t_node *temp = *head; // if there already was a node, temp point to the same node as head
// 		while (temp->next) // Find the last node 
// 			temp = temp->next;
// 		temp->next = new; // Attach the new node at the end (temp->next == NULL)
// 	}
// }

// Create a new node
t_node *new_node(long long value) {
    t_node *node = malloc(sizeof(t_node));
    if (!node) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    node->value = value;
    node->sorted_index = -1; // Default index before normalization
    node->next = NULL;
    return node;
}

// Append a node to the end of the list
void append_node(t_node **head, long long value) {
    t_node *node = new_node(value);
    if (*head == NULL) {
        *head = node;
        return;
    }
    t_node *temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = node;
}

long int	ft_atoi(const char *str)
{
	int i = 0;
	int sign = 1;
	long int result = 0;

	while ((str[i] == ' ') || (str[i] == '\f') || (str[i] == '\n')
		|| (str[i] == '\r') || (str[i] == '\t') || (str[i] == '\v'))
		i++;

	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		// Check for overflow before multiplying by 10
		if ((result > (LONG_MAX / 10)) ||
			(result == (LONG_MAX / 10) && (str[i] - '0') > (LONG_MAX % 10))) //huhhhhh
			return (ERANGE); // Return error on overflow

		result = (str[i] - '0') + (10 * result);
		i++;
	}

	return (result * sign);
}

t_node *parse_input(int argc, char **argv)
{
	t_node *stack_a;
	size_t i = 1; // Start from 1 because argv[0] is the program name
	int value = ft_atoi(argv[i]);

	if (value == ERANGE)
	{
		printf("Error: Integer overflow with input: %s\n", argv[i]);
		exit(1);
	}
	
	stack_a = NULL; // stack_a starts empty
	while ((int)i < argc) // loop through all the arguments
	{
		if (is_number(argv[i]) == 1)
		{
			append_node(&stack_a, ft_atoi(argv[i])); // Convert and store numbers in nodes
			// if (malloc check)
			printf("%zu", i);
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

// void print_list(t_node *head)
// {
// 	while (head) // move through list
// 	{
// 		printf("%d -> ", head->value); // print value
// 		head = head->next;
// 	}
// 	printf("NULL\n\n");
// }

int	find_max_bits(t_node *stack_a)
{
	int	max;
	int	max_bits;

	max = 0;
	max_bits = 0;
	while (stack_a)
	{
		if (stack_a->value > max) //wanneer we in een node een hogere value vinden
			max = stack_a->value; // benoem een nieuwe max value
		stack_a = stack_a->next; // move to next node and check again untill stack_a (stack_a) is checked
	}
	while ((max >> max_bits) > 0) // shifts max , max_bits positions to the right (starts at max in binary and ends when there are only 0's left)
		max_bits++;
	return (max_bits); // max in binary digits
}

size_t	stack_a_size(t_node *stack_a)
{
	size_t	size;

	size = 0;
	while (stack_a)
	{
		size++;
		stack_a = stack_a->next;
	}
	return (size);
}

void	radix(t_node **stack_a, t_node **stack_b)
{
	size_t	max_bits;
	size_t	bit_position;
	size_t	size;
	size_t	elements;
	
	max_bits = find_max_bits(*stack_a);
	bit_position = 0;
	size = stack_a_size(*stack_a); // hoeveel elementel zijn er in totaal
	while (bit_position < max_bits) // zoland we nog niet alle digits af zijn gegaan
	{
		elements = 0;
		while (elements < size) // ga elementen af
		{
			if ((((*stack_a)->value >> bit_position) & 1) == 0) // check steeds laatste digit door steeds meer te verschuiven, kijk de hele tijd naar head
				pb(stack_a, stack_b); // als het 0 is, push naar stapel B
			else
				ra(stack_a); // anders zet onderaan A
			elements++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		bit_position++;
	}
}

// Print the list (both value and sorted index)
void print_list(t_node *head) {
    while (head) {
        printf("Value: %lld, Sorted Index: %d\n", head->value, head->sorted_index);
        head = head->next;
    }
}

// Free the linked list
void free_list(t_node *head) {
    t_node *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <numbers>\n", argv[0]);
        return 1;
    }
    
    t_node *list = NULL;

    // Parse command-line arguments and create the linked list
    for (int i = 1; i < argc; i++) {
        char *endptr;
        errno = 0;
        long long value = strtoll(argv[i], &endptr, 10);

        // Check for conversion errors
        if (errno == ERANGE || *endptr != '\0') {
            fprintf(stderr, "Invalid number: %s \n", argv[i]);
            free_list(list);
            return 1;
        }
        append_node(&list, value);
    }
    
    // Sort the list using bubble sort
    bubble_sort(&list);
    
    // Assign normalized indices based on the sorted order
    assign_indices(list);
    
    // Print the sorted list with normalized indices
    print_list(list);
    
    // Free allocated memory
    free_list(list);
    
    return 0;
}

// int	main(int argc, char **argv)
// {
// 	t_node	*stack_a;
// 	t_node	*stack_b;
// 	size_t	index;
	
// 	index = 0;
// 	if (argc < 2) // no arguments given
// 	{
// 		printf("no arguments\n");
// 		return (1);
// 	}
// 	stack_a = parse_input(argc, argv); // parse input and put in new node'
// 	stack_b = NULL;
	
	
	// printf("Stack A before:\n");
	// print_list(stack_a);

	// pa(&stack_a, &stack_b);
	// printf("Stack A after pa:\n");
	// print_list(stack_a);
	// printf("Stack B after pa:\n");
	// print_list(stack_b);
	// if (stack_b != NULL)
	// 	pb(&stack_a, &stack_b);
	
	// pb(&stack_a, &stack_b);
	// printf("Stack A after pb:\n");
	// print_list(stack_a);
	// printf("Stack B after pb:\n");
	// print_list(stack_b);
	// if (stack_a != NULL)
	// 	pa(&stack_a, &stack_b);
	// print_list(stack_b);
	
	// sa(&stack_a);
	// printf("Stack A after sa:\n");
	// print_list(stack_a);
	// sa(&stack_a);

	// sb(&stack_b);
	// printf("Stack B after sb:\n");
	// print_list(stack_b);
	// sb(&stack_b);

	// ra(&stack_a);
	// printf("Stack A after ra:\n");
	// print_list(stack_a);
	// rra(&stack_a);

	// rb(&stack_b);
	// printf("Stack B after rb:\n");
	// print_list(stack_b);
	// rrb(&stack_b);

	// rr(&stack_a, &stack_b);
	// printf("Stack A after rr:\n");
	// print_list(stack_a);
	// printf("Stack B after rr:\n");
	// print_list(stack_b);
	// rra(&stack_a);
	// rrb(&stack_b);

	// rra(&stack_a);
	// printf("Stack A after rra:\n");
	// print_list(stack_a);
	// ra(&stack_a);

	// rrb(&stack_b);
	// printf("Stack B after rrb:\n");
	// print_list(stack_b);
	// rb(&stack_b);

	// rrr(&stack_a, &stack_b);
	// printf("Stack A after rrr:\n");
	// print_list(stack_a);
	// printf("Stack B after rrr:\n");
	// print_list(stack_b);
	// ra(&stack_a);
	// rb(&stack_b);




	// t_node *stack_a = NULL;
    // t_node *stack_b = NULL;
    // Example input: 5 3 8 6 2 7 4 1
    // append_node(&stack_a, 5);
    // append_node(&stack_a, 3);
    // append_node(&stack_a, 8);
    // append_node(&stack_a, 6);
    // append_node(&stack_a, 2);
    // append_node(&stack_a, 7);
    // append_node(&stack_a, 4);
    // append_node(&stack_a, 1);

//     printf("Stack A before sorting:\n");
//     print_list(stack_a);

//     radix(&stack_a, &stack_b);

//     printf("Stack A after sorting:\n");
//     print_list(stack_a);

// 	return (0);
// }