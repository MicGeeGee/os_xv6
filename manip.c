#include "types.h"
#include "defs.h"
#include "x86.h"


int
shutdown24(void)
{
	outw(0xB004, 0x0|0x2000);
	return 0;
}
