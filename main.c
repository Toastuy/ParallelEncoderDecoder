#include "utils.h"

#define MAX_SIZE 200000

// Work Array
workItem workItemArray[MAX_SIZE];

// Time Stuff
int input_finish = 0;
int encode_finish = 0;
int decode_finish = 0;
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
    time_t start, end;
    encode_time = decode_time = 0;
    time(&start);
    
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
    time(&end);
    total_time = end - start;
    printf("total run time of program: %d s\n", end - start);
}