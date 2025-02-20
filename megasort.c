#include "pushswap.h"

//updateindex(a)
//updateindex(b)
//set_target_a(a, b)
//cost(a, b)
//set_cheapes(a)



//understand the rotateboth and revrotateboth functions

//and implement movetoa and movetob functionss

void	megasort(Stack **a, Stack **b)
{
	int	len_a;

	len_a = stacklen(*a);
	if (len_a-- > 3 && !is_ascending(a))
		pb(a, b, false); //should it be false?
	if (len_a-- > 3 && !is_ascending(a))
		pb(a, b, false); //should it be false?
	while (len_a-- > 3 && !is_ascending(a))
	{
		tune_nodes_a(*a, *b);
		
	}
}

