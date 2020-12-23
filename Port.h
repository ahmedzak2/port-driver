 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

#include "Common_Macros.h"
#include "Std_Types.h"
#include "port_Cfg.h"
/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)
/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)

/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif


/* Id for the company in the AUTOSAR
 * for example ziko's ID = 100 :) */
#define PORT_VENDOR_ID    (100U)

/* Dio Module Id */
#define PORT_MODULE_ID    (120U)

/* Dio Instance Id */
#define PORT_INSTANCE_ID  (0U)


/* Macros for port Status
 */

#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)
   /******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
 /* Service ID for Port_Init */
#define Port_INIT_SID  (uint8)0x00
/* Service ID for Port Set Pin Direction */
#define Port_SET_PIN_DIRECTION_SID  (uint8)0x01
/* Service ID for  Port Refresh Port Direction */
#define Port_REFRESH_PORT_DIRECTION_SID  (uint8)0x02
/* Service ID for Port Get Version Info */
#define Port_VERSION_INFO_SID  (uint8)0x03
/* Service ID for Port Set Pin Mode */
#define Port_SET_PIN_MODE  (uint8)0x04
/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* DET code to report Invalid port pin id requested */
#define PORT_E_PARAM_PIN (uint8)0x0A

/* DET code to report  port pin not configured as changeable */
#define port_E_DIRECTION_UNCHANGEABLE (uint8)0x0b
/* DET code to report API Port_Init service  called with wrong parameter. */
#define port_E_PARAM_CONFIG (uint8)0x0C
/* DET code to report  API Port_SetPinMode service
 called when mode is unchangeable*/
#define port_E_PARAM_INVALID_MODE (uint8)0x0D
 /* DET code to report API Port_SetPinMode service
 called when mode is unchangeable*/
#define port_E_MODE_UNCHANGEABLE (uint8)0x0E
/* DET code to report API service 
called without module initialization*/
#define port_E_UNINIT  (uint8)0x0F 
/* DET code to report APIs called with a Null Pointer */
#define port_E_PARAM_POINTER (uint8)0x0C
/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
typedef uint8  Port_Status; /* Type definition is Data type for the symbolic name of a port statue. */
typedef uint8 Port_PinType;;/* Type definition is Data type for the symbolic name of a pin type. */
typedef uint8 Port_PortType;/* Type definition is Data type for the symbolic name of a port type. */
typedef uint8 Port_PinModeType;
/* Description: Enum to hold PIN direction */
typedef enum
{
    INPUT,OUTPUT
}Port_PinDirection;

/* Description: Enum to hold internal resistor type for PIN */
typedef enum
{
    OFF,PULL_UP,PULL_DOWN
}Port_InternalResistor;
/* Description: Enum to hold mode change for PIN */
typedef enum
{
  unchange,change
}Pin_ModeChange;
/* Description: Enum to hold mode change for PIN */
typedef enum
{
    no,yes
}Pin_DirectionChange;
/* Description: Enum to select the pin id  */
typedef enum
{
    input,ouput
}Pin_DirectionType;

/* Description: Enum to select the PORT NUM  */
typedef enum
{
    PORT_A,PORT_B,PORT_C,PORT_D,PORT_E,PORT_F
}port_num;
typedef enum {
	PORT_unchange	 = 	STD_LOW,
	PORT_change =	STD_HIGH
}Port_PinDirectionType;
typedef enum
{
  PORT_PIN_MODE_aft0,
  PORT_PIN_MODE_aft1,
  PORT_PIN_MODE_aft2,
  PORT_PIN_MODE_aft3,
  PORT_PIN_MODE_aft4,
  PORT_PIN_MODE_aft5,
  PORT_PIN_MODE_aft6,
  PORT_PIN_MODE_aft7,
  PORT_PIN_MODE_aft8,
  PORT_PIN_MODE_aft9,
  PORT_PIN_MODE_aft10,
  PORT_PIN_MODE_aft11,
  PORT_PIN_MODE_aft12,
  PORT_PIN_MODE_aft13,
  PORT_PIN_MODE_aft14,
  PORT_PIN_MODE_ADC,
  PORT_PIN_MODE_DIO
}mode_changes;
/* Description: Structure to configure each individual PIN:
 *	1. the PORT Which the pin belongs to. 0, 1, 2, 3, 4 or 5
 *	2. the number of the pin in the PORT.
 *      3. the direction of pin --> INPUT or OUTPUT
 *      4. the internal resistor --> Disable, Pull up or Pull down
 */
typedef struct 
{
    
    Port_PinDirection direction;
    Port_InternalResistor resistor;
    uint8 initial_value;
    Pin_ModeChange mode;
   Pin_DirectionChange change;
}Port_ConfigType;


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
/* Function for Initializes the Port Driver module */
void Port_Init(const Port_ConfigType *ConfigPtr );
/*  Function to Sets the port pin direction. */
void Port_SetPinDirection (Port_PinType Pin, Port_PinDirectionType Direction);    
/*  Function to shall refresh the direction of all configured 
ports to the configured direction. */
void Port_RefreshPortDirection(void);
/*  Function to Returns the version information of this module.. */
#if (DIO_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif
/*  Function to Sets the port pin mode. */ 
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);

/* Extern PB structures to be used by Dio and other modules */
extern const Port_ConfigType Port_Config;


#endif /* PORT_H */


