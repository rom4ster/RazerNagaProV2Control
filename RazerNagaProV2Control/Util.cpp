
#include <iostream>
#include "HIDKeys.h"
#include "Util.h"
#include <map>




void printarr(unsigned char* array, int len) {
    for (int i = 0; i < len; i++) {
        printf("0x%02X ", array[i]);
    }
    printf("\n");
}


void zeroarr(unsigned char* array, int len) { std::fill(array, array+len, 0); }


ascii_key get_usb_code(char ascii) {
    if (ascii - 32 > 0 && ascii-32 < ASCII_ARRAY_SIZE) {
        throw std::invalid_argument("Invalid ASCII value for conversion");
    }
    ascii_key ret;
    const char * ascii_conv = ascii_to_hid_key_map[ascii];
    ret.modifier = ascii_conv[0];
    ret.value = ascii_conv[1];
    return ret;
}

