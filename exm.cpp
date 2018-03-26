/* clock example: frequency of primes */
#include <stdio.h>      /* printf */
#include <time.h>
#include <sys/time.h>     /* clock_t, clock, CLOCKS_PER_SEC */
#include <math.h>       /* sqrt */
#include <unistd.h>
#include <iostream>

int frequency_of_primes (int n) {
  int i,j;
  // usleep(10000000);
  int freq=n-1;
  for (i=2; i<=n; ++i) for (j=sqrt(i);j>1;--j) if (i%j==0) {--freq; break;}
  return freq;
}

int main ()
{
  // clock_t t;
  int f;
  struct timeval  tv;
  // t = clock();
  // struct timeval  tv;
  gettimeofday(&tv, NULL);
  std::cout << gettimeofday(&tv, NULL) << std::endl;
  double begin =
  (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 ;
  std::cout << tv.tv_sec << "  "<<tv.tv_usec << std::endl;

  // usleep(100000);
  // printf ("Calculating...%f\n",(float)t);
  f = frequency_of_primes (9999999);
  // printf ("The number of primes lower than 100,000 is: %d\n",f);
  // std::cout << clock() << std::endl;
  // t = clock() - t;
  // std::cout << t << std::endl;
  // printf ("It took me %ld clicks(%ld) sdf(%f seconds).\n",t,CLOCKS_PER_SEC,((float)t)/CLOCKS_PER_SEC);
  gettimeofday(&tv, NULL);
  std::cout << tv.tv_sec << "  "<<tv.tv_usec << std::endl;

  double end =
  (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 ;

  printf("Execution time %f\n", (end - begin)/1000);
  return 0;
}