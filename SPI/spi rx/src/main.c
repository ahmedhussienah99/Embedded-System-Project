

#include "TYPES.h"

#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "SPI_INTERFACE.h"



int main ( void ){
	u8 LOC_u8NewData  ;

	MRCC_VidInit();
	MRCC_VidEnablePeripheralClock( APB2_BUS , GPIOA_RCC );
	MRCC_VidEnablePeripheralClock( APB2_BUS , GPIOB_RCC );
	MRCC_VidEnablePeripheralClock( APB2_BUS , SPI1_RCC  );

	MGPIO_VidSetPinDirection( GPIOA , PIN7 , INPUT_FLOATING);//MOSI
	MGPIO_VidSetPinDirection( GPIOA , PIN6 , OUTPUT_SPEED_10MHZ_AFPP );//MISO

	MGPIO_VidSetPinDirection( GPIOA , PIN5 , INPUT_FLOATING  );//CLOCK
	MGPIO_VidSetPinDirection( GPIOA , PIN4 , INPUT_FLOATING );

	MGPIO_VidSetPinDirection      ( GPIOB , PIN0 ,  OUTPUT_SPEED_2MHZ_PP         ) ;

	MSPI_VidInit();






	while(1){


		LOC_u8NewData = MSPI1_VidSendDataU8 ('1');

				if( LOC_u8NewData == '1' ){

							MGPIO_VidSetPinValue( GPIOB , PIN0 , HIGH );

						}

				if( LOC_u8NewData =='0' ){
					MGPIO_VidSetPinValue( GPIOB , PIN0 , LOW );
			}

	}

	return 0 ;
}
