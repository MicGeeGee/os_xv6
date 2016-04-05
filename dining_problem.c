#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
	//create 3 semaphores with different initial values
	int chopsticks[5];
	int i;
	int cmd_out;

	for(i=0;i<5;i++)
	{
		if((chopsticks[i]=alloc_sem(1))<0)
		{
			printf(1,"Error:cannot creat semaphore, please debug\n");
			return -1;
		}
	} 
	
	if((cmd_out=alloc_sem(1))<0)
	{
		printf(1,"Error:cannot creat semaphore, please debug\n");
		return -1;
	}

	//Loop by i as index of philosophers.
	for(i=0;i<5;i++)
	{
		if(fork()==0)
		{
			//For child processes:
			wait_sem(chopsticks[i]);
			wait_sem(chopsticks[(i+1)%5]);
			
			wait_sem(cmd_out);
			printf(1,"philospher %d is enjoying his/her meal\n",i);
			//This philospher has got 3 ticks for eating.
			sleep(3);
			printf(1,"philospher %d is done.\n",i);
			signal_sem(cmd_out);

			signal_sem(chopsticks[i]);
			signal_sem(chopsticks[(i+1)%5]);
			return 0;
		}
	}

	for(i=0;i<5;i++)
		wait();
	for(i=0;i<5;i++)
		dealloc_sem(chopsticks[i]);
	dealloc_sem(cmd_out);

	return 0;
}


