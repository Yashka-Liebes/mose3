/* fig 2-24 Peterson's solution for achieving mutual exclusion */


#define FALSE	0
#define TRUE	1
#define N		2	/* number of processes */



/* function prototype */
void enter_region(int process);
void leave_region(int process);



int turn;			/* who turn is it? */
int interested[N];	/* all value initially 0 (FALSE) */



void enter_region(int process) {	/* process is 0 or 1 */
	int other;						/* number of the other process */
	
	other = 1 - process;			/* the opposite of process */
	interested[process] = TRUE;		/* show that you are interested */
	turn = process;					/* set flag */
	
	while (turn == process && interested[other] == TRUE)
		;
}


void leave_region(int process) {
	interested[process] = FALSE;
}
