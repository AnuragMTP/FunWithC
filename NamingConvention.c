/* Naming Convention Example 
    - Struct names are in PascalCase (e.g., Person).
    - Function names and variable names are in camelCase (e.g., printPersonDetails(), firstName). 
    - Constants are in UPPER_SNAKE_CASE (e.g., MAX_AGE).
    
    -
    
    */

#include <stdio.h>
#include<stdbool.h>
#include<stdint.h>

typedef struct
{
    uint8_t  slaveAddress;
    uint32_t msTimeout;
    bool     bIsMaster;

}I2cHandle_t; //PascalCase for struct name

static uint16_t gTotalApples; //global variable in camelCase with a prefix 'g' to indicate it's global
                              //static keyword indicates that that the scope is limited to the file0

int main()
{
    uint16_t totalGreenApples = 5; //use descriptive names
    uint16_t totalRedApples   = 3; //Put each variable declaration ib a new line
    float    verticalSpeed    = 9.81f; //Allign names and values
    
    char *pFarmerName = "Thevar Farm"; //pointer has a prefix 'p', douple pointer 'pp'
    bool bIsLightOn   = true; //boolean has prefix 'b'

    I2cHandle_t hTempSensor; // handle has a prefix 'h'
    
    hTempSensor.slaveAddress = 0x48; 
    hTempSensor.msTimeout    = 1000; 
    hTempSensor.bIsMaster    = true;

    printf("Slave Address: 0x%X\n", hTempSensor.slaveAddress);
    printf("Timeout: %lu ms\n", (unsigned long)hTempSensor.msTimeout);
    printf("Is Master: %s\n", hTempSensor.bIsMaster ? "true" : "false");

    return 0;
}

//Priority of naming if it multiple types
//1.g
//2.p
//3.normal - int, bool, handle

//Variable keywords: const, static, volatile

//Constant- if within the function/file scope or in the runtime the variable is not going to be modified use const
// const char  myName = "Anu";
// const float mathPi = 3.14f;
// void printThat(const int iWantToBeJustPrinted)
//{
//  print("The number to be printed is:%d",iWantToBeJustPrinted);
//}
// int printMe=5;
//printThat(printMe);

//Static- Limits scope of the variable(i.e to file it is defined), used also only to define a variable only once within
//a function
//int incrementCounter(void)
//{
//  static int counter=0; //Only run first time of invocation after that the previous value of counter is retained
//  counter++;
//  return counter;
//}


//Volatile- prevents compiler from making any assumption about the variable
//E.g use it for variables updated by ISR routine