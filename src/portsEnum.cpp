/***************************************************************
 * Name:      portsEnum.h
 * Purpose:   Code for COM ports enumerator
 * Author:    Andres Cassagnes
 * Created:   2014-08-29
 * Copyright: Andres Cassagnes
 * License:   CPOL
 **************************************************************/

#include <string>
#include "portsEnum.h"
#include "windows.h"

using namespace std;

int Find_Comm(string* ports)
{
    //string ports[5];
    HANDLE DriverHandle;
    DWORD	LastError[4];
    char Com_Name[10];

    int portsCant = 0;

    for(int x = 1 ; x < 10 ; x++)
    {
        switch(x)
        {
            case 1:
                strcpy(Com_Name,"COM1");
                break;
            case 2:
                strcpy(Com_Name,"COM2");
                break;
            case 3:
                strcpy(Com_Name,"COM3");
                break;
            case 4:
                strcpy(Com_Name,"COM4");
                break;
            case 5:
                strcpy(Com_Name,"COM5");
                break;
            case 6:
                strcpy(Com_Name,"COM6");
                break;
            case 7:
                strcpy(Com_Name,"COM7");
                break;
            case 8:
                strcpy(Com_Name,"COM8");
                break;
            case 9:
                strcpy(Com_Name,"COM9");
                break;
        }

        DriverHandle = CreateFileA (Com_Name, 0, 0, NULL, OPEN_EXISTING, 0, NULL);

        LastError[x-1] = GetLastError();

        if(LastError[x-1] == 0)
        {
            ports[portsCant]=Com_Name;
            portsCant++;
        }

        CloseHandle(DriverHandle);

    }
    return portsCant;
}
