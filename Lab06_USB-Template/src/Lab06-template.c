//--------------------------------
// Microprocessor Systems Lab 6 - Template - Lab06_p1_sample.c
//--------------------------------
//
//

#include "init.h"
#include "usbh_conf.h"
#include "usbh_hid.h"
#include "usbh_core.h"
#include "ff_gen_drv.h"
#include "usbh_diskio.h"

USBH_HandleTypeDef husbh;
void USBH_UserProcess(USBH_HandleTypeDef *, uint8_t);
uint8_t isMouseConnected = 0;
uint8_t isMouseActive = 0;
char data_ready = 0;

HID_MOUSE_Info_TypeDef* mouse_info;
int main(void) {
	// System Initializations
	// Application Initializations

	Sys_Init();
	HAL_Init();
	// USBH Driver Initialization
	USBH_Init(&husbh, &USBH_UserProcess, 0);

	// USB Driver Class Registrations: Add device types to handle.
	USBH_RegisterClass(&husbh, USBH_HID_CLASS);
	USBH_RegisterClass(&husbh, USBH_MSC_CLASS);
	// Start USBH Driver
	USBH_Start(&husbh);

	printf("Press any key to start\r\n");
	char wait = 0;
//	wait = getchar();
	printf("HOST ID: %x\r\n", husbh.id);
	while (1) {
		USBH_Process(&husbh);
		//printf("Is Mouse Active: %x\r", isMouseActive);
		if(data_ready && isMouseActive){
			printf("here");fflush(stdout);
			//mouse_info = USBH_HID_GetMouseInfo(&husbh);
		}
	}
}

void USBH_UserProcess(USBH_HandleTypeDef *phost, uint8_t id) {
	if (id == HOST_USER_CLASS_ACTIVE)
			isMouseActive = 1;
}

// Interrupts and Callbacks...
void USBH_HID_EventCallback(USBH_HandleTypeDef *phost){
	data_ready = 1;
}
