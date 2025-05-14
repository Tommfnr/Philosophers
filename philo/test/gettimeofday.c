#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>


/* struct    timeval  {
	time_t        tv_sec ;   //used for seconds
	suseconds_t       tv_usec ;   //used for microseconds
  } */


// int main() {
//   struct timeval current_time;
//   time_t timer;

//   gettimeofday(&current_time, NULL);
//   timer = current_time.tv_sec;
//   usleep(5000000);
//   gettimeofday(&current_time, NULL);
//   printf("seconds : %ld\nmicro seconds : %ld",current_time.tv_sec - timer, current_time.tv_usec);
//   return 0;
// }
