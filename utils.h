typedef struct workItem
{
	uint16_t id; // sequence number
	char cmd; // cmd
	uint16_t original_key; // input key
	uint16_t encode_key; // encoded key by encoder
	uint16_t decoded_key_1; //decoded key by decoder1
	uint16_t decoded_key_2; //decoded key by decoder2
	double d_retval //retval by decoder2
} workItem;