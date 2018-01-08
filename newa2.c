/*
 * Name: Andrew Burcroff
 * Class: Operating Systems
 * Assignment: A2
 *
 * Description:
 * This is a simple C program to simulate a running operation system’s
 * scheduling of processes.  Your code will be one process/thread only and
 * the ‘processes’ are just data structures used in your simulation.You will
 * have 3 * 16 processes, 3 for each priority from 0-15.  One that is CPU
 * bound, one that is even CPU and I/O and 1 that is I/O bound.  CPU bound
 * must want more time than normally allowed in CPU before fast I/O spending
 * most time in CPU.  I/O bound should stay in CPU much less time than normal
 * CPU time and spend most time waiting for I/O.  Even should spend about the
 * same amount of time in CPU as doing I/O. here should be several data
 * structures. A priority queue of processes ready for the CPU. Each time
 * click (one time around the main loop) you adjust priorities and move
 * processes in this queue. A list of processes waiting for I/O. A struct
 * of OS parameters common to all processes. Max time in CPU before being
 * bumped to ready queue if no I/O. Max wait time user processes in ready
 * queue. (try different times, how small can your scheduling algorithm handle?)
 */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


/*
 * This struct was created for the number of Process with data corresponding
 * with the process number. We can keep track pf: Time in CPU needed before/between I/O,
 * Time I/O takes, Total time in machine not counting time in wait queue, Time
 * left waiting for current I/O, Time process has been waiting in ready queue,
 * Total time in CPU, Total time in I/O, Total time in ready queue, Smallest
 * time in ready queue and Longest time in ready queue.
 */

typedef struct{
  int nameOfProcess;           // Name of a Process.
  int timeToRun;               // Time needs to run the Process.
  int startTime;               // Time to the Process starts
  int priorty;                 //Level of which it occurs.
  int timeCPU;                 //Total time in CPU for Process.
  int timeIO;                  //Total time in I/O for Process
  int machineTime;
  int currentTimeInCPU;
  int currentTimeInIO;
  int timeInReadyQueue;
  int currentTotalTimeInIO;
  int currentTotalTimeInCPU;
  int totalTimeIO;
  int totalTimeCPU;
  int totalTimeInReadyQueue;   //Track total time in Ready Queue.
  int minTimeInReadyQueue;
  int maxTimeInReadyQueue;
  int smallestTimeReadyQueue;  //Track smallest time in Ready Queue. Check the lowest priorty.
  int longestTimeReadyQueue;   //Track the Longest time in Ready Queue. Check the highest priorty.
}Process;

void bubbleSort(Process arr[], int n);
void swap(Process *xp, Process *yp);
void add(Process array[], Process Pro, int pos);
void delete(int array[], int size, int pos);
/*
 * This is the main method of the entire program. The method will call other
 * methods to add proccess to the queue. First, it add two proccess to the queue
 * then ask the user to add more proccess. Then it will figure out the next
 * proccess in the queue to complete.
 */

int main(){
  int i;
  Process PQ[3];                 //Hard coded the number of proccess in struct.
  Process P;                      //Creating a varibale of my struct.

  //Stored info into PQ, Created number of Process
  for(i= 0; i <= 2; i++){
    P.nameOfProcess = i;
    int numRun = rand() % 12;
    int numStart = rand() % 20;
    int numPriority = rand() % 15;
    P.timeToRun = numRun;
    P.startTime = numStart;
    P.priorty = numPriority;
    P.timeCPU = 0;
    P.timeIO = 0;
    P.machineTime =0;
    P.currentTimeInIO = 0;
    P.currentTimeInCPU = 0;
    P.timeInReadyQueue = 0;
    P.currentTimeInCPU = 0;
    P.currentTimeInIO = 0;
    P.totalTimeIO = 0;
    P.totalTimeCPU = 0;
    P.minTimeInReadyQueue = 0;
    P.maxTimeInReadyQueue = 0;
    P.totalTimeInReadyQueue = 0;
    P.smallestTimeReadyQueue= 0;
    P.longestTimeReadyQueue = 0;
    //Testing to make sure Process created.
    //printf("%d / %i / %i / %i\n", i, numRun,numStart, numPriority );
    PQ[i] = P;        //Put stuff in Priorty Queue.
  }
  bubbleSort(PQ, 3);
  //Checking to see if sort works
  //for(intq=0; q <= 3; q++){printf("%i / %i \n",PQ[q].nameOfProcess, PQ[q].priorty);}

  //while(1)

  //Test add method
  //PQ[0].nameOfProcess;
  //Process testArray[3];
  //add(testArray,PQ[0],2);
  //printf("%i\n", testArray[2].nameOfProcess);

  // int *Andrew = malloc(sizeof(int)*3);
  // Andrew[0] = 3;
  // Andrew[1] = 5;
  // Andrew[2] = 8;
  // delete(Andrew,3,1);
  // int f;
  // for(f = 0; f < 2; f++){
  //   printf("%i\n",Andrew[f]);
  // }


  return 0;
}

/*
* This method deals with sorting the queue. I decided to use a insertion sort for the type of
* sorting the queue.
*/

void bubbleSort(Process arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++){
       for (j = 0; j < n-i-1; j++){
           if (arr[j].priorty > arr[j+1].priorty){
              swap(&arr[j], &arr[j+1]);
          }
       }
   }
}

/*
 * This method deals with swapping the elements for the bubble sort that calls
 * this method to swap the two elements to sort the array.
 */
void swap(Process *xp, Process *yp)
{
    Process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void add(Process array[], Process Pro, int pos)
{
  array[pos] = Pro;
  //printf("Added Process");
}

void delete(Pr array[], int size, int pos){
  //size -1
  int i;

  //move everything to the left
  for (i = pos; i < size -1; i++ ){
      array[i] = array[i+1];
  }
  //array[size-1] = NULL;
  array = realloc(array, sizeof(int) * size-1);

}

void check_aging(){

}

void IncrementReadyQueue(){

}

void IncrementIO(){

}

void IncrementCPU(){

}

void check_CPU(){

}

void check_IO(){

}
