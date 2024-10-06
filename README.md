# 42_School_-push_swap  
  
The Push_swap project is a sorting algorithm implementation that requires sorting a list of integers using two stacks, `a` and `b`. The goal is to achieve this sorting with the minimum number of operations. I implemented the **Blocksort algorithm** to efficiently manage larger datasets and achieve optimal performance. 
  
## Objectives  
- Sort integers using a two-stack system.  
- Minimize the number of operations required for sorting.  
- Develop a robust understanding of sorting algorithms and data structures.  
  
## Development Process  
  
### 1. Initial Setup  
I began the project by organizing the directory structure and creating header files to define data structures and function prototypes. The main program was organized in several source files to improve maintainability and readability.  
  
### 2. Parsing Input  
The first step was to handle user input. I created the `splitt` function to split a single string of numbers into an array of strings if only one argument is provided. This is crucial for processing inputs effectively:

    char **splitt(int argc, char **argv, int *should_free)
    {
        char **args;

        *should_free = 0;
        if (argc == 2)
        {
            args = ft_split(argv[1], ' ');
            if (!args)
                print_error();
            *should_free = 1;
        }
        else
        {
            args = argv + 1; // Directly use the command line arguments
        }
     return (args);
    }  
- Functionality: This function checks the number of arguments provided and either splits a single argument into individual numbers or uses the command line arguments directly. 

3. Initializing Stacks  
  
Once the input is processed, the init_stack_a function initializes stack a by converting strings to integers and creating linked list nodes:  
  
    t_lists *init_stack_a(char **args)
    {
      t_lists *head = NULL;
      t_lists *new_node;
      long num;
      int i;

      i = 0;
      while (args[i])
      {
        if (check_num(args[i]))
        {
            num = ft_atoi_n(args[i]); // Convert string to integer
            if (!check_max_min(num) || !check_duplicate(head, num))
                print_error(); // Validate number range and duplicates
            new_node = ft_lstnew(num); // Create new node
            if (!new_node)
                print_error();
            ft_lstadd_back(&head, new_node); // Add node to the end of the list
        }
        else
            print_error();
        i++;
      }
      return head;
    }
  
- Key Functions: 
  - check_num: Validates whether the input string is a valid number.
  - ft_atoi_n: A custom implementation of atoi that includes overflow checks.  
  - ft_lstnew and ft_lstadd_back: Functions to create and add new nodes to the linked list.  
  
4. Sorting Logic  
  
The sorting logic is encapsulated in the sort_stack function, which determines the best sorting strategy based on the number of elements:  
  
    void sort_stack(t_lists **stack_a, t_lists **stack_b, int argc)
    {
        if (argc >= 3 && argc <= 6)
        {
            simple_sort(stack_a, stack_b); // Handle small sizes directly
        }
        else
        {
            find_index(stack_a); // Assign indexes to the elements
            group_sort(stack_a, stack_b, argc); // Sort in blocks
            while (*stack_b)
            {
                move_to_top(stack_b); // Move sorted elements back to stack A
                pa(stack_a, stack_b);
            }
        }
    }  
  
Explanation: For small input sizes (2 to 5), I utilized a simpler sorting method (simple_sort). For larger datasets, I assigned indices to the elements using the find_index function and used the group_sort function to sort blocks of elements.
  
5. Implementing Simple Sort  
  
The simple_sort function sorts small lists with the following methods:  

    void simple_sort(t_lists **stack_a, t_lists **stack_b)
    {
        int size = check_lst_size(*stack_a);
        if (size == 2)
        {
            sort_two(stack_a);
        }
        else if (size == 3)
        {
            sort_three(stack_a);
        }
        else if (size == 4)
        {
            sort_four(stack_a, stack_b);
        }
        else if (size == 5)
        {
            sort_five(stack_a, stack_b);
        }
    }
  
- Sort Functions: Each sorting function (sort_two, sort_three, etc.) implements a series of conditional checks to perform the necessary operations to sort small stacks efficiently.  
  
6. Implementing Block Sort  
  
 In the group_sort function, I implemented the Blocksort algorithm:  
   
    void group_sort(t_lists **lst_a, t_lists **lst_b, int total_count)
    {
        int bl_size = block_size(total_count); // Determine block size
        int sorted_count = 0;

        while (*lst_a)
        {
            if ((*lst_a)->index <= sorted_count)
            {
                pb(lst_b, lst_a); // Push to stack B
                if (check_lst_size(*lst_b) > 1)
                    rb(lst_b); // Rotate stack B if more than 1 element
                sorted_count++;
            }
            else if ((*lst_a)->index <= sorted_count + bl_size)
            {
                pb(lst_b, lst_a); // Push to stack B
                sorted_count++;
            }
            else
            {
                ra(lst_a); // Rotate stack A
            }
        }
    }
  
Block Logic: The algorithm divides the stack into blocks based on a calculated block size. It pushes elements to stack b while ensuring that sorted elements are rotated back to stack a efficiently.  
  
7. Moving Elements Back  
  
The move_to_top function is responsible for repositioning sorted elements from stack b back to stack a in their correct order:  
  
    void move_to_top(t_lists **lst_b)  
    {
        int total_size = check_lst_size(*lst_b);
        int max_distance = position(*lst_b, find_max); // Find max value
        int dist_to_up = max_distance;
        int dist_to_down = total_size - max_distance;

        if (dist_to_up <= dist_to_down)
        {
            while (dist_to_up > 0)
            {
                rb(lst_b); // Rotate stack B upwards
                dist_to_up--;
            }
        }
        else
        {
            while (dist_to_down > 0)
            {
                rrb(lst_b); // Rotate stack B downwards
                dist_to_down--;
            }
        }
    }
  
- Efficiency Consideration: The function calculates whether it is more efficient to rotate the stack upwards or downwards based on the position of the maximum element.  
  
8. Challenges Faced  

- Algorithm Complexity: Balancing the efficiency of the sorting logic with the complexity of the algorithm was a recurring challenge. It required careful thought about how elements were manipulated in stacks.  
  
- Debugging Stack Operations: Ensuring that stack operations were correctly implemented often led to bugs that required careful debugging, especially with linked list manipulations.  
  
Conclusion  
  
The Push_swap project was a valuable learning experience that enhanced my understanding of data structures, sorting algorithms, and performance optimization. Implementing the Blocksort algorithm allowed me to manage larger datasets effectively while minimizing operations. I learned to approach problems methodically, analyze performance, and handle errors gracefully, all of which are essential skills for any programmer.  
