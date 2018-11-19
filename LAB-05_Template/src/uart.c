#include "uart.h"

// Initialize Hardware Resources
void initDMA(void);

// Peripheral's clock enable
// Peripheral's GPIO Configuration

DMA_HandleTypeDef tx, rx;
int complete = 1;
void HAL_UART_MspInit(UART_HandleTypeDef *huart){
	GPIO_InitTypeDef  GPIO_InitStruct;

	if (huart->Instance == USART1) {
		// Enable GPIO Clocks
		__GPIOA_CLK_ENABLE();

		// Initialize TX Pin
		GPIO_InitStruct.Pin       = GPIO_PIN_9;
		GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull      = GPIO_PULLUP;
		GPIO_InitStruct.Speed     = GPIO_SPEED_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct); //TX Config

		// Initialize RX Pin
		GPIO_InitStruct.Pin = GPIO_PIN_10;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct); //RX Config

		// Enable UART Clocking
		__USART1_CLK_ENABLE();

		initDMA();
		__HAL_LINKDMA(huart,hdmatx,tx);
		__HAL_LINKDMA(huart,hdmarx,rx);
		///////////////////////////////////////////////
		// Add DMA initializations here
		///////////////////////////////////////////////


	} else if (huart->Instance == USART6) {
		// Enable GPIO Clocks
		__GPIOC_CLK_ENABLE();

		// Initialize TX Pin
		GPIO_InitStruct.Pin       = GPIO_PIN_6;
		GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull      = GPIO_PULLUP;
		GPIO_InitStruct.Speed     = GPIO_SPEED_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF8_USART6;
		HAL_GPIO_Init(GPIOC, &GPIO_InitStruct); //TX Config

		// Initialize RX Pin
		GPIO_InitStruct.Pin = GPIO_PIN_7;
		HAL_GPIO_Init(GPIOC, &GPIO_InitStruct); //RX Config

		// Enable UART Clocking
		__USART6_CLK_ENABLE();

	}
}


void initDMA(){
	//__DMA2_CLK_ENABLE();
	__HAL_RCC_DMA2_CLK_ENABLE();

	tx.Instance = DMA2_Stream7;
	tx.Init.Channel = DMA_CHANNEL_4;
	tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
	tx.Init.PeriphInc = DMA_PINC_DISABLE;
	tx.Init.MemInc = DMA_MINC_ENABLE;
	tx.Init.PeriphDataAlignment = DMA_MDATAALIGN_BYTE;
	tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
	tx.Init.Mode = DMA_NORMAL;
	tx.Init.Priority = DMA_PRIORITY_LOW;
	tx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;


	rx.Instance = DMA2_Stream5;
	rx.Init.Channel = DMA_CHANNEL_4;
	rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
	rx.Init.PeriphInc = DMA_PINC_DISABLE;
	rx.Init.MemInc = DMA_MINC_ENABLE;
	rx.Init.PeriphDataAlignment = DMA_MDATAALIGN_BYTE;
	rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
	rx.Init.Mode = DMA_NORMAL;
	rx.Init.Priority = DMA_PRIORITY_LOW;
	rx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;

	HAL_DMA_Init(&tx);
	HAL_DMA_Init(&rx);

	HAL_NVIC_SetPriority(DMA2_Stream5_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(DMA2_Stream5_IRQn);
	HAL_NVIC_SetPriority(DMA2_Stream7_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(DMA2_Stream7_IRQn);




}

void DMA2_Stream7_IRQHandler(void)
{
  HAL_DMA_IRQHandler(&tx);
 // exit(0);
}
void DMA2_Stream5_IRQHandler(void)
{
  HAL_DMA_IRQHandler(&rx);
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	//printf("Received\r\n");
	//printf("Done receive\r\n");
	complete = 1;

}


void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){

}
//UART Initialization
void initUart(UART_HandleTypeDef* Uhand, uint32_t Baud, USART_TypeDef* Tgt) {
	Uhand->Instance        = Tgt;

	Uhand->Init.BaudRate   = Baud;
	Uhand->Init.WordLength = UART_WORDLENGTH_8B;
	Uhand->Init.StopBits   = UART_STOPBITS_1;
	Uhand->Init.Parity     = UART_PARITY_NONE;
	Uhand->Init.Mode       = UART_MODE_TX_RX;
	Uhand->Init.HwFlowCtl  = UART_HWCONTROL_NONE;

	Uhand->Instance ->CR3 |= USART_CR3_DMAT;
	Uhand->Instance ->CR3 |= USART_CR3_DMAR;
	HAL_UART_Init(Uhand);
}

/* ============================================================================

Reassigning _write and _read to USB_UART by default.

Note the following for an explanation of syntax:

HAL_UART_Transmit(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout)

HAL_UART_Receive(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout)

============================================================================= */

///////////////////////////////////////////////
// Change _write() and _read() to use DMAs
///////////////////////////////////////////////

// Make printf(), putchar(), etc. default to work over USB UART
int _write(int file, char *ptr, int len) {

	//HAL_DMA_PollForTransfer(&tx, HAL_DMA_FULL_TRANSFER, HAL_MAX_DELAY);
	//while(complete != 1);
	USB_UART.Instance -> CR3 |= USART_CR3_DMAR;
	HAL_DMA_PollForTransfer(&tx, HAL_DMA_FULL_TRANSFER, HAL_MAX_DELAY);
	USB_UART.Instance -> CR3 &= ~USART_CR3_DMAR;
	HAL_DMA_Start(&tx,ptr,(uint32_t)&USB_UART.Instance->TDR, len);
	HAL_UART_Transmit_DMA(&USB_UART,(uint8_t*) ptr, len);
	HAL_Delay(10);


	//complete = 0;

	//HAL_Delay(100);
	//HAL_UART_Transmit(&USB_UART, (uint8_t*) ptr, len, 1000);
	return len;
}

// Make scanf(), getchar(), etc. default to work over USB UART
int _read(int file, char *ptr, int len) {
	complete = 0;
	*ptr = 0x00; // Clear the character buffer because scanf() is finicky
	len = 1; // Again because of scanf's finickiness, len must = 1
	//USB_UART.Instance -> CR3 |= USART_CR3_DMAT;
	//HAL_DMA_PollForTransfer(&rx, HAL_DMA_FULL_TRANSFER, HAL_MAX_DELAY);
	//USB_UART.Instance -> CR3 &= ~USART_CR3_DMAT;
	//HAL_DMA_Start(&rx,ptr,(uint32_t)&USB_UART.Instance->TDR, len);
	//HAL_Delay(100);
	HAL_UART_Receive_DMA(&USB_UART, (uint8_t*) ptr, len);
	while(complete != 1);
	HAL_Delay(10);
	return len;
}

/* ============================================================================

Custom UART functions that can be mapped to any UART of your choice when called

Note the following for an explanation of syntax:

HAL_UART_Transmit(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout)

HAL_UART_Receive(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout)

============================================================================= */

// Print a string on the specified UART. (Basically a redirectable puts)
void uart_print(UART_HandleTypeDef *huart, char* string) {
    HAL_UART_Transmit(huart, (uint8_t*) string, strlen((const char*)string), 1000);
}

// Get one character
// 'echo' means enable (1) or disable (0) echoing of characters
char uart_getchar(UART_HandleTypeDef *huart, uint8_t echo) {
	char input[1];
	HAL_UART_Receive(huart, (uint8_t *)input, 1, HAL_MAX_DELAY);
	if (echo) HAL_UART_Transmit(huart, (uint8_t*) input, 1, 1000);
	return (char)input[0];
}

// Send one character
void uart_putchar(UART_HandleTypeDef *huart, char * input) {
	HAL_UART_Transmit(huart, (uint8_t*) input, 1, 1000);
}

// Collects characters until size limit or an endline is recieved
// Returns number of characters collected
// 'max size' should match the size of the array or be smaller
int uart_getline(UART_HandleTypeDef *huart, char * input, int max_size)
{
  char single;
  int i = 0;

	while(1)
	{
		if (i > max_size)
      {
				break;
			}

		single = uart_getchar(huart, 1); // Get one character

  	if (single == '\n' || single == '\r') // Unix & co. use \n, Windows uses \r\n
			break;
  	else
			input[i] = single;
  	i++;
	}
  return i; // The way this is set up, it will always report the wrong size
}
