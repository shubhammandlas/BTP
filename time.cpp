#include <iostream>
#include <ctime>
#include <cstdlib> //_sleep()  --- just a function that waits a certain amount of milliseconds
#include <unutistd.h>
#include <time.h>
using namespace std;

int main()
{

    clock_t cl;     //initializing a clock type

    cl = clock();   //starting time of clock

    usleep(51670);   //insert code here

    cl = clock() - cl;  //end point of clock

    usleep(1000);   //testing to see if it actually stops at the end point

    cout << cl/(double)CLOCKS_PER_SEC << endl;  //prints the determined ticks per second (seconds passed)


    return 0;
}
