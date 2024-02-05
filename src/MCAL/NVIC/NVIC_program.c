
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  NVIC_program.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "..\..\lip\Macros.h"
#include "..\..\lip\STD_TYPES.h"  
#include "NVIC_interface.h"
#include "NVIC_config.h"


/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Copy_u8IntNumber   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  OK
*                                    NOK                                  
*******************************************************************************/
ErrorStatus NVIC_enumInterruptEnable  (u8 Copy_u8IntNumber){
	ErrorStatus LOC_Errorstate=OK;
	if( Copy_u8IntNumber <= NVIC_INT_31){
			SET_BIT(NVIC_EN0_REG,Copy_u8IntNumber);
	}else if(Copy_u8IntNumber >= NVIC_INT_32 && Copy_u8IntNumber <= NVIC_INT_63){
			SET_BIT(NVIC_EN1_REG,(Copy_u8IntNumber%32));
	}else if(Copy_u8IntNumber >= NVIC_INT_64 && Copy_u8IntNumber <= NVIC_INT_95){
			SET_BIT(NVIC_EN2_REG,(Copy_u8IntNumber%32));
	}else if(Copy_u8IntNumber >= NVIC_INT_96 && Copy_u8IntNumber <= NVIC_INT_127){
			SET_BIT(NVIC_EN3_REG,(Copy_u8IntNumber%32));
	}else if(Copy_u8IntNumber >= NVIC_INT_128 && Copy_u8IntNumber <= NVIC_INT_138){
			SET_BIT(NVIC_EN4_REG,(Copy_u8IntNumber%32));
	}
	else{
	LOC_Errorstate=NOK;
	}
	return LOC_Errorstate;
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Copy_u8IntNumber   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  OK
*                                    NOK                                  
*******************************************************************************/
ErrorStatus NVIC_enumInterruptDisable (u8 Copy_u8IntNumber){
	ErrorStatus LOC_Errorstate=OK;
	if( Copy_u8IntNumber <= NVIC_INT_31){
			SET_BIT(NVIC_DIS0_REG,Copy_u8IntNumber);
	}else if(Copy_u8IntNumber >= NVIC_INT_32 && Copy_u8IntNumber <= NVIC_INT_63){
			SET_BIT(NVIC_DIS1_REG,(Copy_u8IntNumber%32));
	}else if(Copy_u8IntNumber >= NVIC_INT_64 && Copy_u8IntNumber <= NVIC_INT_95){
			SET_BIT(NVIC_DIS2_REG,(Copy_u8IntNumber%32));
	}else if(Copy_u8IntNumber >= NVIC_INT_96 && Copy_u8IntNumber <= NVIC_INT_127){
			SET_BIT(NVIC_DIS3_REG,(Copy_u8IntNumber%32));
	}else if(Copy_u8IntNumber >= NVIC_INT_128 && Copy_u8IntNumber <= NVIC_INT_138){
			SET_BIT(NVIC_DIS4_REG,(Copy_u8IntNumber%32));
	}
	else{
	LOC_Errorstate=NOK;
	}
	return LOC_Errorstate;

}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Copy_u8IntNumber   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  OK
*                                    NOK                                  
*******************************************************************************/
ErrorStatus NVIC_enumSetPendingState  (u8 Copy_u8IntNumber){
ErrorStatus LOC_Errorstate=OK;
	if(Copy_u8IntNumber <= NVIC_INT_31){
			SET_BIT(NVIC_PEND0_REG,Copy_u8IntNumber);
	}else if(Copy_u8IntNumber >= NVIC_INT_32 && Copy_u8IntNumber <= NVIC_INT_63){
			SET_BIT(NVIC_PEND1_REG,(Copy_u8IntNumber%32));
	}else if(Copy_u8IntNumber >= NVIC_INT_64 && Copy_u8IntNumber <= NVIC_INT_95){
			SET_BIT(NVIC_PEND2_REG,(Copy_u8IntNumber%32));
	}else if(Copy_u8IntNumber >= NVIC_INT_96 && Copy_u8IntNumber <= NVIC_INT_127){
			SET_BIT(NVIC_PEND3_REG,(Copy_u8IntNumber%32));
	}else if(Copy_u8IntNumber >= NVIC_INT_128 && Copy_u8IntNumber <= NVIC_INT_138){
			SET_BIT(NVIC_PEND4_REG,(Copy_u8IntNumber%32));
	}
	else{
	LOC_Errorstate=NOK;
	}
	return LOC_Errorstate;

}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Copy_u8IntNumber   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  OK
*                                    NOK                                  
*******************************************************************************/
ErrorStatus NVIC_enumClearPendingState(u8 Copy_u8IntNumber){
ErrorStatus LOC_Errorstate=OK;
	if( Copy_u8IntNumber <= NVIC_INT_31){
			SET_BIT(NVIC_UNPEND0_REG,Copy_u8IntNumber);
	}else if(Copy_u8IntNumber >= NVIC_INT_32 && Copy_u8IntNumber <= NVIC_INT_63){
			SET_BIT(NVIC_UNPEND1_REG,(Copy_u8IntNumber%32));
	}else if(Copy_u8IntNumber >= NVIC_INT_64 && Copy_u8IntNumber <= NVIC_INT_95){
			SET_BIT(NVIC_UNPEND2_REG,(Copy_u8IntNumber%32));
	}else if(Copy_u8IntNumber >= NVIC_INT_96 && Copy_u8IntNumber <= NVIC_INT_127){
			SET_BIT(NVIC_UNPEND3_REG,(Copy_u8IntNumber%32));
	}else if(Copy_u8IntNumber >= NVIC_INT_128 && Copy_u8IntNumber <= NVIC_INT_138){
			SET_BIT(NVIC_UNPEND4_REG,(Copy_u8IntNumber%32));
	}
	else{
	LOC_Errorstate=NOK;
	}
	return LOC_Errorstate;
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Copy_u8IntNumber   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  OK
*                                    NOK                                  
*******************************************************************************/
ErrorStatus NVIC_enumGetActiveState   (u8 Copy_u8IntNumber,u8 *Copy_u8ActiveVal){
ErrorStatus LOC_Errorstate=OK;
	if( Copy_u8IntNumber <= NVIC_INT_31){
		*Copy_u8ActiveVal=	GET_BIT(NVIC_ACTIVE0_REG,Copy_u8IntNumber);
	}else if(Copy_u8IntNumber >= NVIC_INT_32 && Copy_u8IntNumber <= NVIC_INT_63){
		*Copy_u8ActiveVal=	GET_BIT(NVIC_ACTIVE1_REG,(Copy_u8IntNumber%32));
	}else if(Copy_u8IntNumber >= NVIC_INT_64 && Copy_u8IntNumber <= NVIC_INT_95){
		*Copy_u8ActiveVal=	GET_BIT(NVIC_ACTIVE2_REG,(Copy_u8IntNumber%32));
	}else if(Copy_u8IntNumber >= NVIC_INT_96 && Copy_u8IntNumber <= NVIC_INT_127){
		*Copy_u8ActiveVal=	GET_BIT(NVIC_ACTIVE3_REG,(Copy_u8IntNumber%32));
	}else if(Copy_u8IntNumber >= NVIC_INT_128 && Copy_u8IntNumber <= NVIC_INT_138){
		*Copy_u8ActiveVal=	GET_BIT(NVIC_ACTIVE4_REG,(Copy_u8IntNumber%32));
	}
	else{
	LOC_Errorstate=NOK;
	}
	return LOC_Errorstate;

}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Copy_u8IntNumber   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  OK
*                                    NOK                                  
*******************************************************************************/ 
ErrorStatus NVIC_enumSetPriorityLevels(u8 Copy_u8PriorityLevels){
ErrorStatus 	LOC_Errorstate=OK;
u32 APINT_u32RegVal = SCB_APINT_REG;
		if(	Copy_u8PriorityLevels <= 0x7)
		{
						APINT_u32RegVal &= (APINT_PRIGROUP_MASK | APINT_VECTKEY_MASK << APINT_VECTKEY_POSITION);
						APINT_u32RegVal |= ((APINT_VECTKEY				 << APINT_VECTKEY_POSITION ) 	|														 
																(Copy_u8PriorityLevels << APINT_PRIGROUP_POSITION)  );
						SCB_APINT_REG=APINT_u32RegVal;
		}
		else
		{
						LOC_Errorstate=NOK;
		}
						
		return LOC_Errorstate;
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Copy_u8IntNumber   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  OK
*                                    NOK                                  
*******************************************************************************/ 

ErrorStatus NVIC_enumSetPriorityValue (u8 Copy_u8IntNumber,u8 Copy_u8PriorityVal){
ErrorStatus 	LOC_Errorstate=OK;
u8 PRI_u8RegOffset ;
u32 PRI_u32RegVal  ;
u8 PRI_Offset      ;	
	if((Copy_u8IntNumber <= NVIC_INT_138) && (Copy_u8PriorityVal <= 0x7)){
		PRI_u32RegVal = Copy_u8PriorityVal;
		PRI_u8RegOffset = Copy_u8IntNumber/4;
		PRI_Offset =(u8)((u16)((Copy_u8IntNumber*8)+5) - (u16)(32*PRI_u8RegOffset)) ;
		PRI_u32RegVal <<= PRI_Offset;
		NVIC_PRI_REG[PRI_u8RegOffset]|=PRI_u32RegVal;
	}else{
	LOC_Errorstate=NOK;
	}
	
	return LOC_Errorstate;

}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Copy_u8IntNumber   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  OK
*                                    NOK                                  
*******************************************************************************/ 

void NVIC_voidPriorityInit(){

u32 APINT_u32RegVal = SCB_APINT_REG;
#if   PRIORITY_LEVELS == NVIC_GRROUP_0_SUB_3
						APINT_u32RegVal &= (APINT_PRIGROUP_MASK | APINT_VECTKEY_MASK << APINT_VECTKEY_POSITION);
						APINT_u32RegVal |= ((APINT_VECTKEY				 << APINT_VECTKEY_POSITION ) 	|														 
																(NVIC_GRROUP_0_SUB_3 << APINT_PRIGROUP_POSITION)  );
						SCB_APINT_REG=APINT_u32RegVal;		
#elif PRIORITY_LEVELS == NVIC_GRROUP_1_SUB_2
						APINT_u32RegVal &= (APINT_PRIGROUP_MASK | APINT_VECTKEY_MASK << APINT_VECTKEY_POSITION);
						APINT_u32RegVal |= ((APINT_VECTKEY				 << APINT_VECTKEY_POSITION ) 	|														 
																(NVIC_GRROUP_1_SUB_2 << APINT_PRIGROUP_POSITION)  );
						SCB_APINT_REG=APINT_u32RegVal;		
#elif PRIORITY_LEVELS == NVIC_GRROUP_2_SUB_1
						APINT_u32RegVal &= (APINT_PRIGROUP_MASK | APINT_VECTKEY_MASK << APINT_VECTKEY_POSITION);
						APINT_u32RegVal |= ((APINT_VECTKEY				 << APINT_VECTKEY_POSITION ) 	|														 
																(NVIC_GRROUP_2_SUB_1 << APINT_PRIGROUP_POSITION)  );
						SCB_APINT_REG=APINT_u32RegVal;		
#elif PRIORITY_LEVELS == NVIC_GRROUP_3_SUB_0
						APINT_u32RegVal &= (APINT_PRIGROUP_MASK | APINT_VECTKEY_MASK << APINT_VECTKEY_POSITION);
						APINT_u32RegVal |= ((APINT_VECTKEY				 << APINT_VECTKEY_POSITION ) 	|														 
																(NVIC_GRROUP_3_SUB_0 << APINT_PRIGROUP_POSITION)  );
						SCB_APINT_REG=APINT_u32RegVal;		
#else 
#error "Wrong Priority Level Config"
#endif

u8 PRI_u8RegOffset ;
u32 PRI_u32RegVal  ;
u8 PRI_Offset      ;
#if (PRIORITY_VALUE <=7) && (INTERRUPT_NUMBER <= NVIC_INT_138)
		PRI_u32RegVal = PRIORITY_VALUE;
		PRI_u8RegOffset = INTERRUPT_NUMBER/4;
		PRI_Offset =(u8)((u16)((INTERRUPT_NUMBER*8)+5) - (u16)(32*PRI_u8RegOffset)) ;
		PRI_u32RegVal <<= PRI_Offset;
		NVIC_PRI_REG[PRI_u8RegOffset]|=PRI_u32RegVal;
#else 
#error "Wrong Priority Level Config"
#endif	
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/








