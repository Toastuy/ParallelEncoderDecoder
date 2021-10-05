#include "utils.h"
#include <omp.h>

// Time Stuff
int input_finish = 0;
int produce_finish = 0;
int consumer_finish = 0;
int total_time = 0;
time_t producer_time, consumer_time;

int main(int argc, char const *argv[])
{

    #pragma omp parallel num_threads(10)
    {
        int t_id = omp_get_thread_num();
        printf("Hello from %d\n", t_id);
    }

    // Time stuff init
    // time start
    
    // Reader For Loop
    // read
    
    // Encode For Loop
    // encode
    
    // Decode 1 For Loop
    // decode
    
    // Decode 2 For Loop
    // decode
    
    // Writer For Loop
    // write
    
    // Time stuff finish
    // timing
}