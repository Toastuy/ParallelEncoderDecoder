#include "utils.h"

#define MAX_SIZE 200000

// Work Array
workItem workItemArray[MAX_SIZE];

// Time Stuff
int input_time = 0;
int encode_time = 0;
int decode_time = 0;
int total_time = 0;


// Encode the values
uint16_t execute_encode_transform(char cmd, uint16_t original_key, double *d_retval){
    uint16_t encode_key;
    switch (cmd) {
            case 'A':
                encode_key = transformAE(original_key, d_retval);
                break;
            case 'B':
                encode_key = transformBE(original_key, d_retval);
                break;
            case 'C':
                encode_key = transformCE(original_key, d_retval);
                break;
            case 'D':
                encode_key = transformDE(original_key, d_retval);
                break;
            case 'E':
                encode_key = transformEE(original_key, d_retval);
                break;
            default:
                fprintf(stderr, "Oh shit\n");
                exit(1);
    }
    return encode_key;
}

// Decode step 1
uint16_t execute_decode_transform1(char cmd, uint16_t encode_key, double *d_retval){
    uint16_t decoded_key_1;
    switch (cmd) {
            case 'A':
                decoded_key_1 = transformAD1(encode_key, d_retval);
                break;
            case 'B':
                decoded_key_1 = transformBD1(encode_key, d_retval);
                break;
            case 'C':
                decoded_key_1 = transformCD1(encode_key, d_retval);
                break;
            case 'D':
                decoded_key_1 = transformDD1(encode_key, d_retval);
                break;
            case 'E':
                decoded_key_1 = transformED1(encode_key, d_retval);
                
                break;
            default:
                fprintf(stderr, "Oh shit\n");
                exit(1);
    }
    return decoded_key_1;

}

// Decode step 2
uint16_t execute_decode_transform2(char cmd, uint16_t dencoded_key_1, double *d_retval){
    uint16_t decoded_key_2;
    switch (cmd) {
            case 'A':
                decoded_key_2 = transformAD2(dencoded_key_1, d_retval);
                break;
            case 'B':
                decoded_key_2 = transformBD2(dencoded_key_1, d_retval);
                break;
            case 'C':
                decoded_key_2 = transformCD2(dencoded_key_1, d_retval);
                break;
            case 'D':
                decoded_key_2 = transformDD2(dencoded_key_1, d_retval);
                break;
            case 'E':
                decoded_key_2 = transformED2(dencoded_key_1, d_retval);
                
                break;
            default:
                fprintf(stderr, "Oh shit\n");
                exit(1);
    }
    return decoded_key_2;

}

int main(int argc, char const *argv[])
{
    
    // Time stuff init
    time_t start, end, encode_start, encode_end, decode_start, decode_end;
    encode_time = decode_time = 0;
    time(&start);
    
    // Reader For Loop
    int readerNumber = 0;
    workItem new;
    while (scanf("%c %hd\n", &new.cmd, &new.original_key) == 2) {
        if(new.cmd == 'X') {
            // readerDone = true;
            // pthread_exit(0);
            break;
        }
        new.id = readerNumber + 1;
        workItemArray[readerNumber] = new;
        readerNumber++;
    }

    // Encode time stuff
    time(&encode_start);
    
    // Encode For Loop
    #pragma omp parallel
    #pragma omp for
    for (int i=0; i<readerNumber; i++) {
        workItem item = workItemArray[i];
        item.encode_key = execute_encode_transform(item.cmd, item.original_key, &item.d_retval);
        workItemArray[i] = item;
    }
    
    // Encode time stuff
    time(&encode_end);
    encode_time = encode_end - encode_start;
    fprintf(stderr, "Total Encode Time: %d seconds\n", encode_time);
    
    // Decode time stuff
    time(&decode_start);
    
    // Decode 1 For Loop
    #pragma omp parallel
    #pragma omp for
    for (int i=0; i<readerNumber; i++) {
        workItem item = workItemArray[i];
        item.decoded_key_1 = execute_decode_transform1(item.cmd, item.encode_key, &item.d_retval);
        workItemArray[i] = item;
    }

    #pragma omp parallel
    #pragma omp for
    for (int i=0; i<readerNumber; i++) {
        workItem item = workItemArray[i];
        item.decoded_key_2 = execute_decode_transform2(item.cmd, item.decoded_key_1, &item.d_retval);
        workItemArray[i] = item;
    }
    
    // Decode Time Stuff
    time(&decode_end);
    decode_time = decode_end - decode_start;
    fprintf(stderr, "Total Decode Time: %d seconds\n", decode_time);
    
    // Writer For Loop
    for(int i = 0; i<readerNumber; i++) {
        workItem item = workItemArray[i];
        // remove this before submitting
        if(item.original_key != item.decoded_key_2) {
            printf("Bad!");
            return -1;
        }

        printf("%d\t%c\t%d\t%d\t%d\t%lf\n", item.id, item.cmd, item.encode_key, item.decoded_key_1, item.decoded_key_2, item.d_retval);
    }
    
    // Time stuff finish
    time(&end);
    total_time = end - start;
    fprintf(stderr, "Total run time of program: %d seconds\n",(int) total_time);
}