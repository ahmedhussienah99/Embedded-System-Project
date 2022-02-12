


#include "TYPES.h"

#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "NVIC_INTERFACE.h"
#include "AFIO_INTERFACE.h"
#include "EXTI_INTERFACE.h"




u8 volatile Flag = 0;

void EXT0_CALLBACK(){

	if( Flag == 0 ){

		MGPIO_VidSetPinValue( GPIOA , PIN1 , HIGH );
		Flag = 1 ;

	}

}



void EXT1_CALLBACK(){

	if( Flag == 1 ){

		MGPIO_VidSetPinValue( GPIOA , PIN1 , LOW );
		Flag = 0 ;

	}

}

int main(void)
{

	MRCC_VidInit();
	MRCC_VidEnablePeripheralClock( APB2_BUS , GPIOA_RCC );
	MRCC_VidEnablePeripheralClock( APB2_BUS , GPIOB_RCC );
	MRCC_VidEnablePeripheralClock( APB2_BUS , AFIO_RCC  );

	MGPIO_VidSetPinDirection( GPIOA , PIN0 , INPUT_PULLUP_PULLDOWN );
	MGPIO_VidSetPinDirection( GPIOB , PIN1 , INPUT_PULLUP_PULLDOWN );



	MGPIO_VidSetPinValue( GPIOA , PIN0 , HIGH );
	MGPIO_VidSetPinValue( GPIOB , PIN1 , HIGH );


	MGPIO_VidSetPinDirection( GPIOA , PIN1 , OUTPUT_SPEED_2MHZ_PP );

	MNVIC_VidSetPriority( EXT0 , 1 , NO_SUB_PRIORITY , GROUP3 );
	MNVIC_VidSetPriority( EXT1 , 2 , NO_SUB_PRIORITY , GROUP3 );

	MNVIC_VidEnablePeripheral( EXT0 );
	MNVIC_VidEnablePeripheral( EXT1 );

	AFIO_VidSetEXTIConfiguration( EXTI_LINE0 , GPIOA );
	AFIO_VidSetEXTIConfiguration( EXTI_LINE1 , GPIOB );

	EXTI0_VidSetCallBack( EXT0_CALLBACK );
	EXTI1_VidSetCallBack( EXT1_CALLBACK );

	EXTI_VidInit( EXTI_LINE0 , FALLING_EDGE );
	EXTI_VidInit( EXTI_LINE1 , FALLING_EDGE );

	while(1);

	return 0;
}







