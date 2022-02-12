


#include "TYPES.h"

#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"

#include "DELAY_INTERFACE.h"

#define LEDs_SIZE  8

int main(void)
{

	u8 LOC_u8RightSide = 0x01 ;
	u8 LOC_u8LeftSide  = 0x80 ;
	int x=200,y=200;
	MRCC_VidInit();
	MRCC_VidEnablePeripheralClock( APB2_BUS , GPIOA_RCC );

	MGPIO_VidSetPortDirection( GPIOA , LOW , OUTPUT_SPEED_2MHZ_PP );
//	MGPIO_VidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VidSetPinDirection(GPIOA,PIN3,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VidSetPinDirection(GPIOA,PIN4,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VidSetPinDirection(GPIOA,PIN5,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VidSetPinDirection(GPIOA,PIN6,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VidSetPinDirection(GPIOA,PIN7,OUTPUT_SPEED_2MHZ_PP);

	while( 1 ){

		for( u8 i = 0 ; i < ( LEDs_SIZE / 2 ) - 1  ; i++ ){

			MGPIO_VidSetPortValue( GPIOA , LOW , LOC_u8RightSide | LOC_u8LeftSide );
			//_delay_ms( 300 );
			for(u8 j=0;j<x;j++){	}
			LOC_u8RightSide <<= 1;
			LOC_u8LeftSide  >>= 1;
		}
		for( u8 i = 0 ; i < ( LEDs_SIZE / 2 )-1  ; i++ ){

			MGPIO_VidSetPortValue( GPIOA , LOW , LOC_u8RightSide | LOC_u8LeftSide );

			//_delay_ms( 300 );
			for(u8 j=0;j<y;j++){	}

			LOC_u8RightSide >>= 1;
			LOC_u8LeftSide  <<= 1;
		}

	}

	return 0;
}









