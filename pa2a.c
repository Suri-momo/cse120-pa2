/* Programming Assignment 2: Exercise A (last modified 10/18/09)
 *
 * In this first set of exercises, you will study a simple program that
 * starts three processes, each of which prints characters at certain rates.
 * This program will form the basis for experimenting with scheduling
 * policies, the main subject for this programming assignment.
 *
 * The procedure SlowPrintf (n, format, ...) is similar to Printf, but
 * takes a "delay" parameter that specifies how much delay there should
 * be between the printing of EACH character.  An increase in n by 1 unit
 * represents an increase in delay by roughly a factor of 10.
 *
 * Run the program below.  Notice the speed at which the printing occurs.
 * Also notice the order in which the processes execute.  The current
 * scheduler (which you will modify in other exercises) simply selects
 * processes in the order they appear in the process table.
 *
 * Exercises
 *
 * Original output with constant delay between each:
 *  111111111122222222223333333333
 *
 * 1. Modify the delay parameters so that process 1 prints with delay 8
 * (more than process 2), and process 3 prints with delay 6 (less than
 * process 2).  Notice the speed and order of execution.
 *  111111111122222222223333333333
 *  [ slow ]  [ regular]  [ fast ]
 *
 * 2. Try other delay values and take note of speeds and orders of execution.
 * What are the smallest and largest values, and what are their effects?
 *
 *
 * 3. Now repeat steps 1 and 2, but this time MEASURE your program using
 * the Gettime () system call, which returns the current system time
 * in milliseconds.  To compute the elapsed time, record the current time
 * immediately before the activity you want to measure (e.g., SlowPrintf)
 * and immediately after, and then take the difference of the former from
 * the latter:
 *
 *	int t1, t2;
 *
 *	t1 = Gettime ();
 *	SlowPrintf (7, "How long does this take?");
 *	t2 = Gettime ();
 *
 *	Printf ("Elapsed time = %d msecs\n", t2 - t1);
 *
 * Do the times you measure correspond to the observations you made in
 * steps 1 and 2?  What is the resolution of Gettime () (i.e., what
 * is the smallest unit of change)?  Note that this is different from
 * Gettime ()'s return value units, which are milliseconds.
 */

#include <stdio.h>
#include "aux.h"
#include "umix.h"

void Main ()
{
        int t1, t2;

	if (Fork () == 0) {
               
                t1 = Gettime();
		SlowPrintf (6, "2222222222");		/* process 2 */
                t2 = Gettime();
                Printf (" time2 = %d msecs\n", t2-t1);
		Exit ();
	}

	if (Fork () == 0) {

		t1 = Gettime();
                SlowPrintf (6, "3333333333");		/* process 3 */
                t2 = Gettime();
                Printf (" time3 = %d msecs\n", t2-t1);
		Exit ();
	}

	t1 = Gettime();
        SlowPrintf (7, "1111111111");			/* process 1 */
        t2 = Gettime();
        Printf (" time1 = %d msecs\n", t2-t1);
	Exit ();
}
