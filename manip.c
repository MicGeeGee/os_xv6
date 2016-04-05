#include "types.h"
#include "defs.h"
#include "x86.h"
#include "manip.h"


int fork_winner_flag=0;
int fork_winner_run=0;
struct mem24 p_mem24;


int
shutdown24(void)
{
	outw(0xB004, 0x0|0x2000);
	return 0;
}


int
fork_winner(int winner)
{
	
	fork_winner_flag=winner;
	
	return 0;
}

void*			
malloc24(int size)
{
	if(p_mem24.size_left-size>=0)
	{
		void* ptr=p_mem24.ptr;
		p_mem24.ptr+=size;
		p_mem24.size_left-=size;
		return ptr;
	}
	else
	{
		cprintf("Error:run out of memory.\n");
		return 0;
	}
}
int 
free24(void* ptr, int size)
{
	if(p_mem24.size_left+size<=4096)
	{
		p_mem24.ptr-=size;
		p_mem24.size_left+=size;
		return 1;
	}
	else
	{
		cprintf("Error:restored too much memory.\n");
		return -1;
	}
}

void			
minit24(void)
{
	p_mem24.ptr=kalloc();
	p_mem24.size_left=4096;
}