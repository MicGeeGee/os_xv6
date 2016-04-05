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
sys_fork_winner(void)
{
	int n;
	if(argint(0, &n) < 0)
		return -1;
	return fork_winner(n);
}
