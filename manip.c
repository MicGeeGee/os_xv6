#include "types.h"
#include "defs.h"
#include "x86.h"
#include "manip.h"


int fork_winner_flag=0;
int fork_winner_run=0;


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

