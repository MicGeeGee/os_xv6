#include "types.h"
#include "x86.h"
#include "defs.h"
#include "manip.h"

int
sys_shutdown24(void)
{
	return shutdown24();
}