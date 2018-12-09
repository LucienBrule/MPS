//--------------------------------
// Microprocessor Systems Lab 6 - Template - Lab06_p1_sample.c
//--------------------------------
//
//

#include "init.h"
#include "usb_device.h"
#include "usbd_conf.h"
#include "usbd_hid.h"
#include "usbd_desc.h"
#include "init.h"






//#include "usbd_desc.c"





USBD_HandleTypeDef USBDevice;
//PCD_HandleTypeDef hpcd_USB_OTG_HS;
uint8_t buff[4] = {1,0,0,0};



int main(void) {
	Sys_Init();

	HAL_NVIC_SetPriority(OTG_HS_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(OTG_HS_IRQn);
	printf("Started\r\n");
	//USBD_RegisterClass(&USBDevice,&USBD_HID);
	USBD_Init(&USBDevice,&HS_Desc, 1);
	printf("Check1\r\n");
	USBD_RegisterClass(&USBDevice,&USBD_HID);
	printf("Check2\r\n");
	USBD_Start(&USBDevice);
	printf("Working\n");
	USBD_HID_SendReport(&USBDevice,buff,4);

	while(1)

		asm("nop");
}


void OTG_HS_IRQHandler(void)
{
  /* USER CODE BEGIN OTG_HS_IRQn 0 */

  /* USER CODE END OTG_HS_IRQn 0 */
  HAL_PCD_IRQHandler(&hpcd_USB_OTG_HS);
  /* USER CODE BEGIN OTG_HS_IRQn 1 */

  /* USER CODE END OTG_HS_IRQn 1 */
}









// Interrupts and Callbacks...
