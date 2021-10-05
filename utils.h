typedef struct workItem
{
	uint16_t id; // sequence number
	int pos; // work queue position
	char cmd; // cmd
	uint16_t original_key; // input key
	uint16_t encode_key; // encoded key by producer
	double p_retval; // retval by producer
	uint16_t decoded_key; //decoded key by consumer
	double c_retval //retval by consumer
} workItem;