#include "types.h"
#include "x86.h"
#include "defs.h"
#include "manip.h"

int
sys_shutdown24(void)
{
	return shutdown24();
}

int
sys_fork_winner(int winner)
{
	return fork_winner(winner);
}

void*			
sys_malloc24(int size)
{
	return malloc24(size);
}

int
sys_free24(void* ptr, int size)
{
	return free24(ptr,size);
}