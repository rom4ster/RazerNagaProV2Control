#pragma once


#define RAZER_BUTTON_COMMAND_SIZE 0x0A
#define RAZER_SCROLL_COMMAND_SIZE 0x09
#define RAZER_BUTTON_COMMAND_READ_SIZE 0x07




const int RAZER_BUTTON_COMMAND_DATA_SIZE = 80;

// TY OpenRazer/razerqdhid
enum RAZER_COMMAND_STATUS : unsigned char {
	NEW = 0x0,
	BUSY = 0x1,
	SUCCESS = 0x2,
	FAILURE = 0x3,
	TIMEOUT = 0x4,
	UNSOPPORTED = 0x5
};

enum RAZER_COMMAND_FIXED : unsigned char {
	CONSTANT = 0
};

enum RAZER_BUTTON_OPERATION_START : unsigned short {
	READ  = 0x028C,
	WRITE = 0x020C
};

enum HYPERSHIFT : unsigned char {
	OFF = 0x0,
	ON = 0x1
};

typedef struct class_id  {
	unsigned char command_class;
	unsigned char id; 
} class_id;

#pragma pack(push, 1)
typedef struct razer_command {

	RAZER_COMMAND_STATUS status;
	unsigned char tid;
	unsigned short packets_remaining;
	RAZER_COMMAND_FIXED prototype;
	unsigned char data_size;
	class_id command;
	unsigned char data[RAZER_BUTTON_COMMAND_DATA_SIZE];
	unsigned char crc;
	RAZER_COMMAND_FIXED reserved;

} razer_command;
#pragma pack(pop)


typedef struct interaction {

	char* name;
	char* question;

} interaction;



