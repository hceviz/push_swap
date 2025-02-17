#include "pushswap.h"

//updateindex(a)
//updateindex(b)
//set_target_a(a, b)
//cost(a, b)
//set_cheapes(a)

void	find_target_node(Stack *a, Stack *b)
{

}

static void	set_target_a(Stack *a, Stack *b)//Find `a` node's target in stack `b`
{
	Stack	*current_b; //To store the pointer to the current node in stack `b` and iterate through each node following
	Stack	*target_node; //To store the pointer to the target node in stack `b`
	long			best_match_index; //In this case, the best match indexe stores the value of the "closest smaller number" so far

	while (a) //As long as we have nodes in stack `a`
	{
		best_match_index = LONG_MIN; //Assign the smallest `long` as the closest smaller number so far
		current_b = b; //Assign to `current_b` the current `b` node
		while (current_b) //Iteratively search through all the nodes in stack `b` until the end of the stack is reached
		{
			if (current_b->value < a->value 
				&& current_b->value > best_match_index) //Check if `b` node is smaller than `a` node && bigger than the closest smaller number so far
			{
				best_match_index = current_b->value; //If so, update the value of the closest smaller number so far
				target_node = current_b; //Assign the current `b` node as the `target_node`
			}
			current_b = current_b->next; //Move to the next `b` node for comparison, until a "closer smaller number" is found
		}
		if (best_match_index == LONG_MIN) //Check if the LONG_MIN hasn't changed, it means we haven't found anything smaller
			a->target = find_max(b); //If so, find the biggest `value` and set this as the target node
		else
			a->target = target_node; //If no "closer smaller number" is found, and the best match has changed
		a = a->next; //Move to the next `a` node to find it's target `b` node
	}
}

