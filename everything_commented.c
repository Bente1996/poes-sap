#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*list;
	t_node	*stack_b;

	stack_b = NULL;
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
		ft_printf("Error\n");
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
			ft_printf("Error\n", argv[i]); // invalid integer found
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
			printf("Error\n");
			exit(1);
		}
		i++;
	}
	result *= sign;
	if (result < INT_MIN)
	{
		printf("Error\n");
		exit(1);
	}
	return ((int)result);
}

t_node	*append_node(t_node **head, int value, int index)
{
	t_node	*new;
	t_node	*temp;

	new = new_node(value, index); //malloc and assign value, index and next
	if (new == NULL) // malloc check
		exit(1);
	if (has_duplicate(*head, value)) // check value in new node with rest of the nodes
	{
		ft_printf("Error\n", value);
		exit (1); // ??
	}
	if (*head == NULL)  // If the list is empty, set head to new node
		*head = new; // head will point to new node now
	else
	{
		temp = *head; // if there already was a node, temp points to the same node as head, we use temp to go to the last node
		while (temp->next) // Find the last node 
			temp = temp->next;
		temp->next = new; // Attach the new node at the end (temp->next == NULL)
	}
	return (new);
}

t_node *new_node(int value, int index)
{
	t_node *new;
	
	new = malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->value = value;
	new->index = index;
	new->sorted_index = -1; //default easy to recognise
	new->next = NULL;
	return (new);
}

void pa(t_node **stack_a, t_node **stack_b) // put first element B on top of A
{
	if (*stack_b == NULL) // Nothing to push
		return;

	t_node *temp = *stack_b;	 // Store the first node of B
	*stack_b = (*stack_b)->next; // Move B's head forward
	temp->next = *stack_a;		 // Attach B's old head to A
	*stack_a = temp;			 // A's head now points to the new node
	ft_printf("pa\n");
	count_operations();
}

void pb(t_node **stack_a, t_node **stack_b) // put first element A on top of B
{
	if (stack_a == NULL || *stack_a == NULL) // Nothing to push
		return;
	t_node *temp = *stack_a;	 // Store the first node of A in temp
	*stack_a = (*stack_a)->next; // Move stack A head to the next node
	temp->next = NULL;			 // Disconnect temp from stack_a before attaching to stack_b
	if (stack_b == NULL)		 // Ensure stack_b is initialized
		*stack_b = temp;
	else
	{
		temp->next = *stack_b; // Attach old head of A to stack B
		*stack_b = temp;	   // Move stack B head to new node
	}
	ft_printf("pb\n");
	count_operations();
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
	ft_printf("sa\n");
	count_operations();
}

void ra(t_node **stack_a)
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
	ft_printf("ra\n");
	count_operations();
}

void rra(t_node **stack_a)
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
	ft_printf("rra\n");
	count_operations();
}

void	two(t_node **stack_a)
{
	if (*stack_a == NULL)
		return;
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	three(t_node **stack_a)  // sa ra rra
{
	if (*stack_a == NULL)
		return;
	if (((*stack_a)->value > (*stack_a)->next->value) && \
		((*stack_a)->next->value > (*stack_a)->next->next->value)) // 321,  als eertse groter is dan tweede, en tweede groter dan derde
	{
		ra(stack_a);
		sa(stack_a);
	}
	if (((*stack_a)->value > (*stack_a)->next->value) && \
		(*stack_a)->next->value < (*stack_a)->next->next->value) // 312, als eertse groter is dan tweede, en tweede kleiner dan derde
		ra(stack_a);
	if (((*stack_a)->value < (*stack_a)->next->value) && ((*stack_a)->next->next->value < (*stack_a)->value)) // 231, eerste kleiner dan tweede, en derde kleiner dan eerste
		rra(stack_a);
	if (((*stack_a)->value > (*stack_a)->next->value) && ((*stack_a)->next->next->value > (*stack_a)->value)) // 213, eerste groter dan tweede, en derde groter dan eerste 
		sa(stack_a);
	if (((*stack_a)->value < (*stack_a)->next->next->value) && ((*stack_a)->next->next->value < (*stack_a)->next->value)) // 132, als eerste kleiner dan derde en derde kleiner dan tweede
	{
		rra(stack_a);
		sa(stack_a);
	}
}

// void	three(t_node **stack_a)
// {
// 	int first;
// 	int second;
// 	int third;
// 	if (*stack_a == NULL)
// 		return;
// 	first = (*stack_a)->value;
// 	second = (*stack_a)->next->value;
// 	third = (*stack_a)->next->next->value;
// 	if (first > second && second > third) 
// 	{
// 		ra(stack_a);
// 		sa(stack_a);
// 	}
// 	else if (first > second && second < third) 
// 		ra(stack_a);
// 	else if (first < second && third < first) 
// 		rra(stack_a);
// 	else if (first > second && third > first) 
// 		sa(stack_a);
// 	else if (first < third && third < second) 
// 	{
// 		rra(stack_a);
// 		sa(stack_a);
// 	}
// }

int	find_smallest(t_node *stack_a) // Find the position of the smallest number
{
	int		pos;
	int		smallest_pos;
	t_node	*smallest;

	pos = 1; // We count positions starting from 1
	smallest_pos = 1;
	smallest = stack_a;
	if (stack_a == NULL)
		return (-1); // Stack is empty
	while (stack_a)
	{
		if (stack_a->value < smallest->value)
		{
			smallest = stack_a;
			smallest_pos = pos; // Store the position of the smallest element
		}
		stack_a = stack_a->next;
		pos++;
	}
	return (smallest_pos);
}

void	move_smallest_to_top(t_node **stack_a)
{
	int	mid_stack;
	int	smallest_pos;

	if (*stack_a == NULL)
		return;
	smallest_pos = find_smallest(*stack_a);
	mid_stack = stack_size(*stack_a) / 2;
	if (mid_stack < smallest_pos) // if its in the second half
	{
		while (smallest_pos <= stack_size(*stack_a))
		{
			rra(stack_a);
			smallest_pos++;
		}
	}
	else // if its in the first half
	{
		while (smallest_pos > 1)
		{
			ra(stack_a);
			smallest_pos--;
		}
	}
}

void	selection_sort(t_node **stack_a, t_node **stack_b)
{
	if (*stack_a == NULL)
		return;
	while (stack_size(*stack_a) > 3) // move smallest numbers to b
	{
		move_smallest_to_top(stack_a);
		pb(stack_a, stack_b);
	}
	three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

//boolians?
int	is_already_sorted(t_node *head)
{
	while (head->next)
	{
		if (head->value > head->next->value)
			return(0);
		head = head->next;
	}
	return (1);
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

int has_duplicate(t_node *head, int value) // head points to first node
{
	while (head)
	{
		if (head->value == value) // check value in node with given value, move through whole list
			return (1); // Duplicate found
		head = head->next;
	}
	return (0); // No duplicates
}

void	decide_sort(t_node **stack_a, t_node **stack_b)
{
	// printf("Stack size: %d\n\n", stack_size(*stack_a));

	if (stack_a == NULL || *stack_a == NULL) // overbodig?
		return;
	if (stack_size(*stack_a) == 2)
		two(stack_a);
	else if (stack_size(*stack_a) == 3)
	 	three(stack_a);
	else if (stack_size(*stack_a) > 3 && stack_size(*stack_a) < 51)
		selection_sort(stack_a, stack_b);
	else
	{
		bubble_sort(stack_a);
		// print_list(*stack_a, "After bubble sort (sorted values):");
		sorted_indices(*stack_a); // assign sorted indeces to list
		// print_list(*stack_a, "With sorted indeces:");
		bubble_unsort(stack_a); // values back to original, normalized and ready for radix
		//print_list(*stack_a, "After bubble unsort (back to original):");
		radix_sort(stack_a, stack_b); // use operations to sort
		// print_list(*stack_a, "After radix (sorted again):");
	}
}

void	radix_sort(t_node **stack_a, t_node **stack_b) // change (*stack_a)-> value to ->index
{
	size_t	max_bits;
	size_t	bit_position;
	int	size;
	int	elements;
	
	max_bits = find_max_bits(*stack_a);
	bit_position = 0;
	size = stack_size(*stack_a); // hoeveel elementel zijn er in totaal
	while (bit_position < max_bits) // zolang we nog niet alle digits af zijn gegaan
	{
		elements = 0;
		while (elements < size) // ga elementen af
		{
			if ((((*stack_a)->sorted_index >> bit_position) & 1) == 0) // check steeds laatste digit door steeds meer te verschuiven, kijk de hele tijd naar head
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

int	find_max_bits(t_node *stack_a)
{
	int	max;
	int	max_bits;

	max = 0;
	max_bits = 0;
	while (stack_a)
	{
		if (stack_a->sorted_index > max) //wanneer we in een node een hogere sorted_index vinden
			max = stack_a->sorted_index; // benoem een nieuwe max value
		stack_a = stack_a->next; // move to next node and check again untill stack_a (stack_a) is checked
	}
	while ((max >> max_bits) > 0) // shifts max , max_bits positions to the right (starts at max in binary and ends when there are only 0's left)
		max_bits++;
	return (max_bits); // max in binary digits
}

void bubble_sort(t_node **head) // swapping the largest number till the end (sorted part), change value with index
{
	t_node	*compare;
	t_node	*sorted;
	int	swapped;
	
	sorted = NULL; // doesnt point to anything yet
	if (*head == NULL)
		return;
	swapped = 1;
	while (swapped == 1) // every time we were able to swap something
	{
		swapped = 0;
		compare = *head; // start comparing at beginning of list again
		while (compare->next != sorted) // sorted part starts at NULL and grows with each swapped == 1 loop (check if what we are gonna compare isnt sorted yet)
		{
			if (compare->value > compare->next->value) // swap when value is bigger than next value
			{
				swap_values(compare, compare->next); // swap value and index
				swapped = 1;
			}
			compare = compare->next; // move to next node until sorted part
		}
		sorted = compare; // is swapped
	}
}

void	bubble_unsort(t_node **head) // bubble sort based on index instead of value
{
	t_node	*compare;
	t_node	*sorted;
	int	swapped;

	sorted = NULL;
	if (*head == NULL)
		return;
	swapped = 1;
	while (swapped == 1)
	{
		swapped = 0;
		compare = *head;
		while (compare->next != sorted)
		{
			if (compare->index > compare->next->index)
			{
				swap_values(compare, compare->next);
				swap_sorted_indeces(compare, compare->next);
				swapped = 1;
			}
			compare = compare->next;
		}
		sorted = compare;
	}
}

void	swap_sorted_indeces(t_node *a, t_node *b)
{
	t_node *temp;                             // hoeft dit niet bij de ANDERE temps??: nee , we bewaren hier alle data van node en niet alleen pointer. zoek beter uit

	if (a == NULL || b == NULL)
	{
		printf("Error: Attempted to swap NULL nodes.\n");
		return;
	}

	temp = malloc(sizeof(t_node));  // Allocate memory for temp
	if (temp == NULL)
	{
		printf("Memory allocation failed!\n");
		return;  // Exit the function if allocation fails
	}
	
	temp->sorted_index = a->sorted_index;
	a->sorted_index = b->sorted_index;
	b->sorted_index = temp->sorted_index; 

	free(temp);  // Free temp after use
}

void swap_values(t_node *a, t_node *b)
{
	t_node *temp;

	if (a == NULL || b == NULL)
	{
		printf("Error: Attempted to swap NULL nodes.\n");
		return;
	}

	temp = malloc(sizeof(t_node));  // Allocate memory for temp
	if (temp == NULL)
	{
		printf("Memory allocation failed!\n");
		return;  // Exit the function if allocation fails
	}

	temp->value = a->value;
	a->value = b->value;
	b->value = temp->value;

	temp->index = a->index;
	a->index = b->index;
	b->index = temp->index; 

	free(temp);  // Free temp after use
}

void sorted_indices(t_node *head)
{
	int i;
	
	i = 0;
	while (head)
	{
		head->sorted_index = i;
		i++;
		head = head->next;
	}
}

void	print_list(t_node *head, char *str)
{
	ft_printf("%s\n", str);
	while (head)
	{
		ft_printf("Value: %d, Index: %d Sorted Index: %d\n", head->value, head->index, head->sorted_index);
		head = head->next;
	}
	ft_printf("\n");
}

void free_list(t_node *head)
{
	t_node *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

int	stack_size(t_node *stack_a)
{
	int	size;

	size = 0;
	while (stack_a)
	{
		size++;
		stack_a = stack_a->next;
	}
	return (size);
}

int count_operations(void)
{
	static int operation_count;
	
	operation_count++;
	return (operation_count);
}