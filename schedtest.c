#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{

	int i;
	int j;
	int adder=100;
	int c_pid;
	//int prior_arr[]={3,3,2,2,1,1};
	int prior_arr[]={1,1,2,2,3,3};
	int sem_arr[6];
	int done_arr[6];

	for(i=0;i<6;i++)
	{
		sem_arr[i]=alloc_sem(0);
		done_arr[i]=alloc_sem(0);
		

		if((c_pid=fork())==0)
		{
			
			set_priority(getpid(),prior_arr[i]);
			wait_sem(sem_arr[i]);
			
			for(j=0;j<10000000;j++);
				adder++;

			signal_sem(done_arr[i]);
			return 0;
		}
		else
		{
			printf(1,"Parent: child (pid=%d priority=%d) created!\n",c_pid,	prior_arr[i]);
		}
	}
	for(i=0;i<6;i++)
		signal_sem(sem_arr[i]);
	
	enable_schedule_display(1);
	
	for(i=0;i<6;i++)
		wait_sem(done_arr[i]);
	
	enable_schedule_display(0);

	for(i=0;i<6;i++)
		wait();
	//Restore the cursor.
	printf(1,"\n");

	
	for(i=0;i<6;i++)
	{
		dealloc_sem(sem_arr[i]);
		dealloc_sem(done_arr[i]);
	}
	return 0;
}