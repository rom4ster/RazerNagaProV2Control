// RazerHidTester.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../hidapi/hidapi.h"
using std::hex;


bool findInfo(hid_device_info** outt, hid_device_info* list, int* path) {
    hid_device_info* out = nullptr;
    if (path == nullptr) {
        hid_device_info temp;
        temp.next = list;
        out = &temp;
        while ((out = out->next) != nullptr) std::cout << out->usage_page << " " << out->usage << " " << out->interface_number << "\n";
        return false;
    }
    out = nullptr;
    if (list == nullptr) return false;
    out = list;
    while (out != nullptr && out->usage_page != path[0] && out->usage != path[1]) out = out->next;
    *outt = out;
    return out != nullptr;

}

void printarr(unsigned char * array, int len) {
    for (int i = 0; i < len; i++) {
        printf("0x%02X ", array[i]);
    }
    printf("\n");
}


void zeroarr(unsigned char* array, int len) { for (int i = 0; i < len; i++) { array[i] = 0x0; } }


int main()
{
    std::cout << "Hello World!\n";

    hid_device_info* info = NULL;
    auto info_list = hid_enumerate(5426, 167);
    int nums[]{ 1,2 };
    auto x = findInfo(&info, info_list, nums);
    std::cout << x << "\n";
    auto hidptr = hid_open_path(info->path);
    if (hidptr == NULL) { std::cout << "badptr \n"; exit(-1); }
    const int len = 91;
    unsigned char ret[len];
    zeroarr(ret, len);
    ret[0] = 0x0;
    hid_get_feature_report(hidptr, ret, len);
    printarr(ret, len);
    


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
