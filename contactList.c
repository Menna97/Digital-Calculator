#include "prototype.h"


void Listinit(void){
  
uint32_t ui32EEPROMInit;
//
// Enable the EEPROM module.
//
SysCtlPeripheralEnable(SYSCTL_PERIPH_EEPROM0);
//
// Wait for the EEPROM module to be ready.
//
while(!SysCtlPeripheralReady(SYSCTL_PERIPH_EEPROM0))
{
}
//
// Wait for the EEPROM Initialization to complete
//
ui32EEPROMInit = EEPROMInit();
//
// Check if the EEPROM Initialization returned an error
// and inform the application
//
if(ui32EEPROMInit != EEPROM_INIT_OK)
{
while(1)
{ }
}
}
void writeContact(uint32_t list[]){
EEPROMProgram(list, 0x400, sizeof(list));
}

uint32_t ReadContact(){
uint32_t res;
EEPROMRead(res, 0x400, sizeof(res));
return res;
}