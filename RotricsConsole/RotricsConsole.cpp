#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    /**
    HANDLE hComm;
    hComm = CreateFileA("\\\\.\\COM3",                //port name
        GENERIC_READ | GENERIC_WRITE, //Read/Write
        0,                            // No Sharing
        NULL,                         // No Security
        OPEN_EXISTING,// Open existing port only
        0,            // Non Overlapped I/O
        NULL);        // Null for Comm Devices
    if (hComm == INVALID_HANDLE_VALUE)
        printf("Error in opening serial port!\n");
    else
        printf("Opening serial port successful!\n");
    */

    HANDLE hCOM = CreateFileA("\\\\.\\COM3", GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hCOM != INVALID_HANDLE_VALUE)
    {
        cout << "COM3 is open OK!" << endl;
        char buffer[30];
        memset(buffer, 0, sizeof(buffer));
        strcpy(buffer, "M1112");
        DWORD nb;
        OVERLAPPED ov;
        WriteFile(hCOM, buffer, sizeof(buffer), &nb, &ov);
        CloseHandle(hCOM);
    }
    else cout << "Error Open COM1" << endl;


    //CloseHandle(hCOM);//Closing the Serial Port
    //return 0;
}
