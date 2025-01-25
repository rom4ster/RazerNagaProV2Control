#pragma once
#include "HIDKeys.h"
#include <iostream>
#include <map>


typedef struct ascii_key {
    char modifier;
    char value;
} ascii_key;


void printarr(unsigned char* array, int len);
void zeroarr(unsigned char* array, int len);
ascii_key get_usb_code(char ascii);

template <class K, class V>
bool mapexists(std::map<K, V>* m, K key) {
    return m->count(key) > 0;
}