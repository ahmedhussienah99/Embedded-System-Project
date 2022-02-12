


#include "TYPES.h"
#include "MACROS.h"

#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "USART_INTERFACE.h"



int main(void)
{

	u8 LOC_u8NewData  ;

	int i;
	MRCC_VidInit();
	MRCC_VidEnablePeripheralClock ( APB2_BUS , GPIOA_RCC                   ) ;
	MRCC_VidEnablePeripheralClock ( APB2_BUS , USART1_RCC                  ) ;
	MRCC_VidEnablePeripheralClock ( APB2_BUS , GPIOB_RCC                   ) ;
	MGPIO_VidSetPinDirection      ( GPIOA , PIN9  , OUTPUT_SPEED_2MHZ_AFPP ) ;
	MGPIO_VidSetPinDirection      ( GPIOA , PIN10 , INPUT_FLOATING         ) ;
	MGPIO_VidSetPinDirection      ( GPIOB , PIN0 ,  OUTPUT_SPEED_2MHZ_PP         ) ;

	//MGPIO_VidSetPortDirection     ( GPIOA , LOW  , OUTPUT_SPEED_2MHZ_PP    ) ;

	MUSART_VidInit();


	while(1){

		LOC_u8NewData = MUSART1_u8RecCharSynch();

		if( LOC_u8NewData == '1' ){

					MGPIO_VidSetPinValue( GPIOB , PIN0 , HIGH );

				}

		if( LOC_u8NewData =='0' ){
			MGPIO_VidSetPinValue( GPIOB , PIN0 , LOW );
	}

	}

	return 0;
}

