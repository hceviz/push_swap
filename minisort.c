#include "pushswap.h"

void	minisort(Stack **stck)
{
	if (stacklen(stck) == 2)
		sa(stck, true); // check the condition is done?
	else
	{
		Stack	*max;
		Stack	*min;
	
		min = getmin(stck);
		max = getmax(stck);
		if (max->index == 2 && min->index == 1)
			sa(stck, true);
		else if (max->index == 1 && min->index == 2)
			//ra

	}

}