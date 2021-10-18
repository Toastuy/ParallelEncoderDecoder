#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>
#include <omp.h>

typedef struct workItem
{
	uint16_t id; // sequence number
	char cmd; // cmd
	uint16_t original_key; // input key
	uint16_t encode_key; // encoded key by encoder
	uint16_t decoded_key_1; //decoded key by decoder1
	uint16_t decoded_key_2; //decoded key by decoder2
	double d_retval; //retval by decoder2
} workItem;


/*
d_retval = transformAE(original_key, encode_key);



*/


uint16_t transformAE(uint16_t input_val, double *retval);
uint16_t transformAD1(uint16_t input_val, double *retval);
uint16_t transformAD2(uint16_t input_val, double *retval);
uint16_t transformBE(uint16_t input_val, double *retval);
uint16_t transformBD1(uint16_t input_val, double *retval);
uint16_t transformBD2(uint16_t input_val, double *retval);
uint16_t transformCE(uint16_t input_val, double *retval);
uint16_t transformCD1(uint16_t input_val, double *retval);
uint16_t transformCD2(uint16_t input_val, double *retval);
uint16_t transformDE(uint16_t input_val, double *retval);
uint16_t transformDD1(uint16_t input_val, double *retval);
uint16_t transformDD2(uint16_t input_val, double *retval);
uint16_t transformEE(uint16_t input_val, double *retval);
uint16_t transformED1(uint16_t input_val, double *retval);
uint16_t transformED2(uint16_t input_val, double *retval);