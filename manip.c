#include "types.h"
#include "defs.h"
#include "x86.h"
#include "manip.h"


int fork_winner_flag=0;
int fork_winner_run=0;
int display_enabled=0;
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
	if(p_mem24.pos+size<4096)
	{
		void* ptr=p_mem24.bp+p_mem24.pos;
		memset(&(p_mem24.used[(char* )ptr-p_mem24.bp]),1,sizeof(char)*size);
		p_mem24.pos+=size;
		
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
	int i;
	int pos_temp;
	
	
	memset(&(p_mem24.used[(char* )ptr-p_mem24.bp]),0,sizeof(char)*size);
	
	//If the memory at the position of allocator, then controll the allocator back.
	if(((char* )ptr+size)==(p_mem24.bp+p_mem24.pos))
	{
		pos_temp=p_mem24.pos;
		for(i=pos_temp-1;i>=0;i--)
		{
			if(p_mem24.used[i]==0)
				p_mem24.pos--;
			else
				break;
		}
	}
	//cprintf("mem_pos=%d\n",p_mem24.pos);
	//cprintf("pos=%d\n",p_mem24.pos);

	return 1;
	
}

void			
minit24(void)
{
	p_mem24.bp=kalloc();
	p_mem24.pos=0;
	memset(p_mem24.used,0,sizeof(char)*4096);
}