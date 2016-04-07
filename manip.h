#ifndef MANIP_H
#define MANIP_H
#endif

extern int fork_winner_flag;
extern int fork_winner_run;
extern int display_enabled;

struct mem24
{
	char* bp;
	int pos;
	char used[4096];
};

extern struct mem24 p_mem24;



