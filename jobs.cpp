 #include<iostream>
using namespace std;
#include<unistd.h>
int Queue[5];  //................................Queue Declaration

//..........................Front & Rear Initialization
int front = -1;
int rear = -1;
//.........................Queue Size Initialization
int qsize = 5;
//................................Insert in Queue
void insert_que(int val)
{
rear++;
Queue[rear] = val;
cout<<"\n\n Inserted Job: "<<val;
}
//..............................Delete from Queue
void delete_val()
{
front++;
cout<<"\n\n Deleted job: "<<Queue[front];
}
//.............................Display Queue
void display_que()
{
int i;
for(i=front+1; i<=rear; i++)
{
 cout<<Queue[i]<<", ";
}
}
//............................Is Queue Full..???
int que_full()
{
 if (rear == qsize-1)
return 1;
 else
return 0;
}
//............................Is Queue Empty..???
int que_empty()
{
 if(front == rear == -1 || front == rear)
return 1;
 else
return 0;
}
//............................Main Function


int main()
{
int job = 1;
//............................Insert untill Queue is not Full.
while(!que_full())
{
insert_que(job);
job++;
unsigned int microsecond = 1000000;
usleep(3 * microsecond);//sleeps for 3 second
}
cout<<"\n\t Queue is Full...!!!";
//............................Display Queue
cout<<"\n Queue: Jobs- ";
display_que();
//............................Delete untill Queue is not Empty.
while(!que_empty())
{
 delete_val();

 unsigned int microsecond = 1000000;
 usleep(3 * microsecond);//sleeps for 3 second
}
cout<<"\n\t Queue is Empty...!!!";
cout<<"\n\n";
return 0;
}
/*-------------OUTPUT---------------
student@ioe-aids-169:~$ g++ DSLPr12.cpp -o a
student@ioe-aids-169:~$ ./a
Inserted Job: 1
Inserted Job: 2
Inserted Job: 3
Inserted Job: 4
Inserted Job: 5
Queue is Full...!!!
Queue: Jobs- 1, 2, 3, 4, 5,
Deleted job: 1
Deleted job: 2
Deleted job: 3
Deleted job: 4
Deleted job: 5
Queue is Empty...!!!
student@ioe-aids-169:~$
*/
