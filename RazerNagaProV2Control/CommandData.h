
#pragma once
#include "RazerNagaProV2Control.h"

//TY Razerqdhid



enum CATEGORY : unsigned char {

	DISABLE                     = 0x00,
	MOUSE_BUTTON                = 0x01,
	MOUSE_BUTTON_DOUBLE         = 0x0b,
	MOUSE_BUTTON_MULTIPLE       = 0x0e,
	KEYBOARD_KEY                = 0x02,
	KEYBOARD_KEY_MULTIPLE       = 0x0d,
	SYS_POWER                   = 0x09,
	CONSUMER_CONTROL            = 0x0a,
	MACRO_KEYPRESS              = 0x03,
	MACRO_KEYDOWN               = 0x04,
	MACRO_TOGGLED               = 0x05,
	MACRO_FROM_LIST             = 0x0F,
	DPI_SWITCH                  = 0x06,
	PROFILE_SWITCH              = 0x07,
	HYPERSHIFT_SWITCH           = 0x0c,
	SCROLL_SWITCH               = 0x12

};

typedef struct data_packet_info {
	unsigned char len;
	unsigned char data[5];
} data_packet_info;


// From Synapse button diagram (for 12 btn grid)

//  1     7
//  2     8
//  3     9
//  4     10
//  5     11
//  6     12

/* From https://github.com/geezmolycos/razerqdhid/blob/main/docs/cmd_button-en.md */
// Lclick = 0x1
// Rclick = 0x2
// Mclick = 0x3
// scrl up = 0x9
// scrl dwn = 0x0a
// scrl left = 0x34
// scrl right = 0x35
// button below scrl = 0x6a
// button below ^^^ = 0x60

//Assumed values

enum  BUTTON_VALUES : unsigned char
{

	BTN_1 = 0x40,
	BTN_2 = 0x41,
	BTN_3 = 0x42,
	BTN_4 = 0x43,
	BTN_5 = 0x44,
	BTN_6 = 0x45,
	BTN_7 = 0x46,
	BTN_8 = 0x47,
	BTN_9 = 0x48,
	BTN_10 = 0x49,
	BTN_11 = 0x50,
	BTN_12 = 0x51,

	LEFT_CLICK = 0x01,
	RIGHT_CLICK = 0x02,
	MIDDLE_CLICK = 0x03,
	SCROLL_UP = 0x09,
	SCROLL_DOWN = 0x0a,
	SCROLL_LEFT = 0x34,
	SCROLL_RIGHT = 0x35,


};

enum BINDABLE_MOUSE_BUTTONS : unsigned char {

	LEFT_CLICK_BIND = 0x01,
	RIGHT_CLICK_BIND = 0x02,
	MIDDLE_CLICK_BIND = 0x03,
	BACKWARD = 0x04,
	FORWARD = 0x05,
	SCROLL_UP_BIND = 0x09,
	SCROLL_DOWN_BIND = 0x0a,
	SCROLL_LEFT_BIND = 0x68,
	SCROLL_RIGHT_BIND = 0x69,
};


enum SYSTEM_CONTROL : unsigned char {

	SHUTDOWN = 0x01,
	SLEEP = 0x02,
	WAKE = 0x04

};


enum MACRO_TYPE : unsigned char {
	FIXED = 0x03,
	PRESS = 0x04,
	TOGGLE = 0x05,
	CYCLE = 0x0F
};

enum DPI_OPERATION : unsigned char {

	DPI_NEXT = 0x01,
	DPI_PREV = 0x02,
	DPI = 0x03,
	DPI_NEXT_LOOPSTART = 0x06,
	DPI_NEXT_LOOPEND = 0x07

};


enum SCROLL_STAGE : unsigned char {

	STANDARD = 0x081,
	DISTINCT = 0x082,
	ULTRAFINE = 0x083,
	ADAPTIVE = 0x084,
	SMOOTHSCROLL = 0x085,
	CUSTOM = 0x086,
	

};



typedef struct button_command {

	unsigned char profile; 
	unsigned char num;
	HYPERSHIFT hypershift;
	CATEGORY category;
	unsigned char data_len;
	unsigned char data[5];


} button_command;


typedef struct scroll_command {

	unsigned char profile;
	unsigned char selection;
	unsigned char size;
	SCROLL_STAGE data[6];


} scroll_command;




typedef struct button_read {

	unsigned char profile;
	unsigned char num;
	HYPERSHIFT hypershift;

};










