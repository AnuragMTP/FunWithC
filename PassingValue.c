/*
Passing a varibale to a function can be three ways
1. Pass by const value
2. Pass by const pointer
3. Pass by const value and const pointer
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

static char gHomeWifi[64]   = "MyHomeWifi";
static char gOfficeWifi[64] = "MyOfficeWifi";

static char *gNowWifi = gHomeWifi;


// Pass by const value and const pointer
void printCurrentWifi(const char * const pWifiName)
{   
    // This function can read the WiFi name but cannot modify it due to the const qualifier
   // for the variable and the pointer itself
    printf("Current WiFi: %s\n", pWifiName);
}

// Pass by const value
void connectToWorkWifi(const char **ppWifiName)
{
    // This will change the global variable to the new WiFi name
    *ppWifiName = gOfficeWifi; 
    printCurrentWifi(gNowWifi); 
}

// Pass by const pointer
void updateWifiName(char * const pWifiName)
{
    // This function can modify the WiFi name but cannot change the pointer itself
    snprintf(pWifiName, 64, "UpdatedWiFiName");
}

int main()
{
    printCurrentWifi(gNowWifi); // Output: MyHomeWifi

    connectToWorkWifi((const char **)&gNowWifi); // Output: MyOfficeWifi

    updateWifiName(gNowWifi); // This will update the current WiFi name to "UpdatedWiFiName"
    printCurrentWifi(gNowWifi); // Output: UpdatedWiFiName

    return 0;
}