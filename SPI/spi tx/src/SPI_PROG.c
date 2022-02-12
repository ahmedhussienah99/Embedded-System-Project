


#include "TYPES.h"
#include "MACROS.h"
#include "GPIO_INTERFACE.h"

#include "SPI_INTERFACE.h"
#include "SPI_CONFIG.h"
#include "SPI_REG.h"

void (*MSPI1_CallBack) (void);

void MSPI_VidInit ( void ){

#if   MSP1_STATUS == MSPI_ENABLE

#if		MSPI1_CLOCK_MODE == MSPI_MODE0

	CLR_BIT( MSPI1 -> CR1 , 0 ); CLR_BIT( MSPI1 -> CR1 , 1 );

#elif	MSPI1_CLOCK_MODE == MSPI_MODE1

	SET_BIT( MSPI1 -> CR1 , 0 ); CLR_BIT( MSPI1 -> CR1 , 1 );

#elif	MSPI1_CLOCK_MODE == MSPI_MODE2

	CLR_BIT( MSPI1 -> CR1 , 0 ); SET_BIT( MSPI1 -> CR1 , 1 );

#elif	MSPI1_CLOCK_MODE == MSPI_MODE3

	SET_BIT( MSPI1 -> CR1 , 0 ); SET_BIT( MSPI1 -> CR1 , 1 );

#endif

#if    MSPI1_MASTER_SLAVE == MSPI_MASTER

	SET_BIT( MSPI1 -> CR1 , 2 );

#elif  MSPI1_MASTER_SLAVE == MSPI_SLAVE

	CLR_BIT( MSPI1 -> CR1 , 2 );

#endif

#if   MSPI1_DATA_ORDER == MSPI_MSB_FIRST

	CLR_BIT( MSPI1 -> CR1 , 7 );

#elif MSPI1_DATA_ORDER == MSPI_LSB_FIRST

	SET_BIT( MSPI1 -> CR1 , 7 );

#endif

#if   MSPI1_SS_MANAGE  == HW_SLAVE_MANAGEMENT

	CLR_BIT( MSPI1 -> CR1 , 9 );

#elif MSPI1_SS_MANAGEb == SW_SLAVE_MANAGEMENT

	SET_BIT( MSPI1 -> CR1 , 9 );

#endif

#if   MSPI1_DATA_SIZE == MSPI_8BIT_DATA

	CLR_BIT( MSPI1 -> CR1 , 11 );

#elif MSPI1_DATA_SIZE == MSPI_16BIT_DATA

	SET_BIT( MSPI1 -> CR1 , 11 );

#endif

#if   MSPI1_INT_STATUS == MSPI_INT_DISABLE

	MSPI1 -> CR2 = 0 ;

#elif MSPI1_INT_STATUS == MSPI_TXE_INT_ENABLE

	SET_BIT( MSPI1 -> CR2 , 7 );

#elif MSPI1_INT_STATUS == MSPI_RXNE_INT_ENABLE

	SET_BIT( MSPI1 -> CR2 , 6 );

#endif

	MSPI1 -> CR1 &= 0xFFC7 ;
	MSPI1 -> CR1 |= ( MSPI1_PRESCALLER << 3 ) ;

	SET_BIT( MSPI1 -> CR1 , 6 );

#elif MSP1_STATUS == MSPI_DISABLE
	CLR_BIT( MSPI1 -> CR1 , 6 );
#endif
	//MSPI1->CR1 = 0x0347;
	//SET_BIT( MSPI1 -> CR1 , 8 );

}

u8 MSPI1_VidSendDataU8 ( u8 Copy_u8Data ){

	//MGPIO_VidSetPinValue( GPIOA , 4 , 0 );
	MSPI1 -> DR = Copy_u8Data;

	while ( GET_BIT( MSPI1 -> SR , 7) == 1 );

	//Copy_u8Data1=MSPI1 -> DR ;

		//MGPIO_VidSetPinValue( GPIOA , 0 , 1 );
		//MGPIO_VidSetPinValue( GPIOB , 0 , 1);
		return (u8)MSPI1 -> DR ;


}
//
//u8 MSPI1_VidrxDataU8 ( void ){
//	 u8 Copy_u8Data;
//	Copy_u8Data=MSPI1 -> DR ;
//
//	//while ( GET_BIT( MSPI1 -> SR , 7) == 1 );
//	//MGPIO_VidSetPinValue( GPIOB , 0 , 1);
//
//	MGPIO_VidSetPinValue( GPIOA , 4 , 1);
//
//	return Copy_u8Data ;
//
//}


void MSPI1_VidSetCallBack( void (*ptr) (void) ){

	MSPI1_CallBack = ptr;

}

void SPI1_IRQHandler(void){

	MSPI1_CallBack();

}

