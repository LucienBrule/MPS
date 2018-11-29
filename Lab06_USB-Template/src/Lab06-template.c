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
	while (wait == 0) {
		wait = getchar();
	}
	printf("HOST ID: %x\r\n", husbh.id);
//	printf("TIMER: %x\r\n", husbh.Timer);
//	printf("TIMER: %x\r\n", husbh.);
	HAL_Delay(100);
	while (1) {
		USBH_Process(&husbh);
//		printf("connected : %x", husbh.device.is_connected);
//		printf("\r\n");
//		HAL_Delay(1000);
		// Other stuff
		if (isMouseConnected) {
			printf("Mouse is connected\r\n");
			if (mouse_info != NULL)
				printf("[x] %x [y] %x\r\n", (int) mouse_info->x,
						(int) mouse_info->y);
			else
				printf("Return value was NULL\r\n");
		}

	}
}

void USBH_UserProcess(USBH_HandleTypeDef *phost, uint8_t id) {
	// ...
	//printf("This happened!\r\n");
	printf("[INFO] ID is: %x\r\n", id);
	if (id == HOST_USER_CONNECTION) {

		printf("[INFO] Mouse was connected\r\n");
	} else if (id == HOST_USER_CLASS_ACTIVE) {
		printf("Mouse is active\r\n");

//		printf("[x] %x [y] %x\r\n",mouse_info->x, mouse_info->y);
	} else if (id == HOST_USER_DISCONNECTION) {
		printf("[INFO] Mouse was disconnected\r\n");

	}
}


// Interrupts and Callbacks...
void USBH_HID_EventCallback(USBH_HandleTypeDef *phost){
	//printf("This happened\r\n");
	mouse_info = USBH_HID_GetMouseInfo(&husbh);

}
