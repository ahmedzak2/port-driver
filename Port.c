 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: ahmed zakria
 ******************************************************************************/
#include "Port.h"
#include "Port_Regs.h"
#include "tm4c123gh6pm_registers.h"
#if (PORT_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
/* AUTOSAR Version checking between Det and port Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif
#endif

 volatile Port_Status PORTSTATUS;
  Port_ConfigType port[MAX_PIN_NUM];
/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
* Service Name: Port_Init
* Sync/Async: Synchronous
* Reentrancy: non reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initializes the Port Driver module.
************************************************************************************/
void Port_Init(const Port_ConfigType *ConfigPtr )
{
  
  
  
 Port_PinType loopCounter ;
 port_num port_num; 
  uint8 pin_num; 
   PORTSTATUS = PORT_INITIALIZED ;
    for(loopCounter= MIN_PIN_NUM;loopCounter<=MAX_PIN_NUM;loopCounter ++)
    {
    port[loopCounter].direction = ConfigPtr->direction;
      port[loopCounter].resistor= ConfigPtr->resistor;
     port[loopCounter].initial_value= ConfigPtr->initial_value;
     port[loopCounter].mode = ConfigPtr->mode;
     port[loopCounter].change = ConfigPtr->change;

    }

    volatile uint32 * PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */
    volatile uint32 delay = 0;
    #if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		/* Report to DET  */
	Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_INIT_SID, port_E_PARAM_CONFIG);
	}
	else
        {
        }
    #endif 
    for(loopCounter= MIN_PIN_NUM;loopCounter<=MAX_PIN_NUM;loopCounter ++)
    {
      pin_num = loopCounter;
      if(pin_num >= compare)
{
    pin_num = pin_num % compare;// compare reference to 8 bits
}
if ((pin_num  % compare == MIN_PIN_NUM) &&(pin_num!=MIN_PIN_NUM))
{
 port_num = ++port_num  ;
    }
      
    
    switch(port_num)
    {
        case  PORT_A: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
		 break;
	case  PORT_B: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
		 break;
	case  PORT_C: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
		 break;
	case  PORT_D: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
		 break;
        case  PORT_E: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
		 break;
        case  PORT_F: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
		 break;
    }
    
    /* Enable clock for PORT and allow time for clock to start*/
    SYSCTL_REGCGC2_REG |= (1<<port_num);
    delay = SYSCTL_REGCGC2_REG;
    
    if( ((port_num == PORT_PD) && (pin_num == PIN_PD)) || ((port_num == PORT_PF && (pin_num == PIN_PF)) )) /* PD7 or PF0 */
    {
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_LOCK_REG_OFFSET) = 0x4C4F434B;                     /* Unlock the GPIOCR register */   
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_COMMIT_REG_OFFSET) , pin_num);  /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
    }
    else if( (port_num == PORT_PC) && (pin_num <= PIN_PC) ) /* PC0 to PC3 */
    {
        /* Do Nothing ...  this is the JTAG pins */
        return;
    }
    else
    {
        /* Do Nothing ... No need to unlock the commit register for this pin */
    }
    
    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , pin_num);             /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
    *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (pin_num * 4));     /* Clear the PMCx bits for this pin */
    
    if(port[loopCounter].direction == OUTPUT)
    {
	SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , pin_num);                /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
        
        if(port[loopCounter].initial_value == STD_HIGH)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , pin_num);          /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
        }
        else
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , pin_num);        /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
        }
    }
    else if(port[loopCounter].direction == INPUT)
    {
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
        
        if(port[loopCounter].resistor == PULL_UP)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , pin_num);       /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
        }
        else if(port[loopCounter].resistor == PULL_DOWN)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , pin_num);     /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
        }
        else
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , pin_num);     /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , pin_num);   /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
        }
    }
    else
    {
        /* Do Nothing */
    }
    
    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , pin_num);        /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */

}
          }
/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
* Service Name: Port_SetPinDirection
* Sync/Async: Synchronous
* Reentrancy:  reentrant
* Parameters (in): Port Pin ID number - Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Sets the port pin direction.
************************************************************************************/
void Port_SetPinDirection (Port_PinType Pin, Port_PinDirectionType Direction)
{
   volatile uint32 * PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */
    
Port_PortType  local_port=zero ;
Port_PinType local_pin;
  Port_PinDirectionType direction =Direction ;
 if(Pin >=compare)
  {
    local_pin = Pin % compare; // compare reference to 8 bits
}
if ((Pin  % compare == MIN_PIN_NUM) &&(Pin!=zero))

{
  local_port= local_port+one;
    }
#if(PORT_DEV_ERROR_DETECT ==STD_ON)
  if(PORTSTATUS !=PORT_INITIALIZED)
{
   Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SET_PIN_DIRECTION_SID,
		port_E_UNINIT);
}
 if(local_port >PORT_F)
{
   Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SET_PIN_DIRECTION_SID,
		port_E_DIRECTION_UNCHANGEABLE);
}
else
  {
  }
 if(local_pin>PORT_CONFIGURED_PINS)
  {
    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SET_PIN_DIRECTION_SID,
		PORT_E_PARAM_PIN);
  }
  else
  {
  }
  
#endif
   switch(local_port)
    {
        case  PORT_A: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
		 break;
	case  PORT_B: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
		 break;
	case  PORT_C: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
		 break;
	case  PORT_D: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
		 break;
        case  PORT_E: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
		 break;
        case  PORT_F: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
		 break;
    }
    if(direction == Output)
    {
       /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
    
	SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , local_pin);               
}
else if(direction == Input)
    {
      /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
   
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , local_pin);           
    }
}
/********************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
* Service Name: Port_RefreshPortDirection
* Sync/Async: Synchronous
* Reentrancy: non- reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: shall refresh the direction of all configured ports to the configured direction.
************************************************************************************/

void Port_RefreshPortDirection(void)
{
    volatile uint32 * PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */ 
 Port_PinType loopCounter ;
 port_num port_num; 
  uint8 pin_num; 
    
#if (PORT_DEV_ERROR_DETECT == STD_ON)
  
  /* check if the Port driver initialized or Not */
  if(PORTSTATUS!= PORT_INITIALIZED)
  {
    /* Report to DET  */
    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SET_PIN_DIRECTION_SID,
		port_E_UNINIT);
  }
  else
  {
  }
 
#endif 
  for(loopCounter= MIN_PIN_NUM;loopCounter<=MAX_PIN_NUM; loopCounter ++)
    {
      pin_num = loopCounter ;
      if(pin_num >= compare)
{
    pin_num = pin_num % compare ; // compare reference to 8 bits
}
if ((pin_num  % compare == MIN_PIN_NUM) &&(pin_num!=MIN_PIN_NUM))
{
 port_num = ++port_num  ;
    }
      
    
    switch(port_num)
    {
        case  PORT_A: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
		 break;
	case  PORT_B: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
		 break;
	case  PORT_C: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
		 break;
	case  PORT_D: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
		 break;
        case  PORT_E: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
		 break;
        case  PORT_F: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
		 break;
    }

    if(port[loopCounter].direction == OUTPUT)
    {
	SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , pin_num);                /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
        
        if(port[loopCounter].initial_value == STD_HIGH)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , pin_num);          /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
        }
        else
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , pin_num);        /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
        }
    }
    else if(port[loopCounter].direction == INPUT)
    {
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
        
        if(port[loopCounter].resistor == PULL_UP)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , pin_num);       /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
        }
        else 
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , pin_num);     /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
        }
  
}
/************************************************************************************
* Service Name: Port_GetVersionInfo
* Sync/Async: Synchronous
* Reentrancy: non- reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: Pointer to where to store the version information of this module.
* Description: Returns the version information of this module.
************************************************************************************/
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
  #if(PORT_DEV_ERROR_DETECT ==STD_ON)
  if (NULL_PTR == versioninfo)
	{
		/* Report to DET  */
	Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_VERSION_INFO_SID, port_E_PARAM_POINTER);
	}
	else
    #endif 
  
        {
                  /* Copy the vendor Id */
		versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
		/* Copy the module Id */
		versioninfo->moduleID = (uint16)PORT_MODULE_ID;
		/* Copy Software Major Version */
		versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
}
}
#endif


    

/************************************************************************************
* Service Name: Port_SetPinMode
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in):Port Pin ID number -New Port Pin mode to be set on port pin.
* Parameters (inout): None
* Parameters (out): None
* Return value: Pointer to where to store the version information of this module.
* Description: Sets the port pin mode.
************************************************************************************/
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{
volatile uint32 * PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */ 
Port_PortType  local_port=zero ;
Port_PinType local_pin;
   
 #if(PORT_DEV_ERROR_DETECT ==STD_ON)
if(Pin>PORT_CONFIGURED_PINS)
  {
    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SET_PIN_MODE,
		PORT_E_PARAM_PIN);
  }
if (PORT_PIN_MODE_CHANGEABLE == STD_OFF )
{
  Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SET_PIN_MODE,
		port_E_MODE_UNCHANGEABLE);
}
if(Mode>Max_mode)
{
  Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SET_PIN_MODE,
		port_E_PARAM_INVALID_MODE);
}
else
{
}
#endif
 if(Pin >=compare)
  {
    local_pin = Pin % compare; // compare reference to 8 bits
}
if ((Pin  % compare == MIN_PIN_NUM) &&(Pin!=zero))

{
  local_port= local_port+one ;
    }
switch(local_port)
    {
        case  PORT_A: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
		 break;
	case  PORT_B: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
		 break;
	case  PORT_C: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
		 break;
	case  PORT_D: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
		 break;
        case  PORT_E: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
		 break;
        case  PORT_F: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
		 break;
    }
if (Mode == PORT_PIN_MODE_ADC)
{
  SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , local_pin);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , local_pin); /* CLEAR Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
}
else if (Mode == PORT_PIN_MODE_DIO)
{
  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , local_pin);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , local_pin);             /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
    *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (local_pin * 4));     /* Clear the PMCx bits for this pin */
}
else
{
  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , local_pin);      /* SETT the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , local_pin); /* enbale Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
      *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (0x0000000F << (local_pin * 4)); /* Clear the PMCx bits for this pin */
      *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (Mode << (local_pin * 4));
     SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , local_pin);  /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
}
}