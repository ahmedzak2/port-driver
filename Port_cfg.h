 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Dio Driver
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H
/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                (STD_ON)
#define PORT_SET_PIN_DIRECTION_API	     (STD_ON)
#define	PORT_SET_PIN_MODE_API	       	     (STD_OFF)
#define	PORT_VERSION_INFO_API		     (STD_ON)
#define	PORT_PIN_DIRECTION_CHANGEABLE	     (STD_OFF)
#define	PORT_PIN_MODE_CHANGEABLE	     (STD_ON)

             
   // ports defination
#define PORT_CONFIGURED_PINS	             (42U)
#define PORT_INITIALIZED                     (1U)
#define PORT_NOT_INITIALIZED                 (0U)
#define MIN_PIN_NUM                 (0)
#define MAX_PIN_NUM                 (42)
#define zero                         (0)
// definations for pin and ports
#define compare                     (8) // reference to 8 bits
#define one                         (1)
#define PORT_PD                     (3)
#define PIN_PD                      (7)
#define PORT_PF                     (5)
#define PIN_PF                      (0)
#define PORT_PC                      (2)
#define PIN_PC                      (3)
#define Max_mode                    (10)


   /*********************************************************************************
 * 						PIN Definitions 														 *
 * *******************************************************************************/

#define PORT_PINA0 	(Port_PinType)0
#define PORT_PINA1 	(Port_PinType)1
#define PORT_PINA2 	(Port_PinType)2
#define PORT_PINA3 	(Port_PinType)3
#define PORT_PINA4	(Port_PinType)4
#define PORT_PINA5       (Port_PinType)5
#define PORT_PINA6 	(Port_PinType)6
#define PORT_PINA7 	(Port_PinType)7
#define PORT_PINB0 	(Port_PinType)8
#define PORT_PINB1 	(Port_PinType)9
#define PORT_PINB2 	(Port_PinType)10
#define PORT_PINB3 	(Port_PinType)11
#define PORT_PINB4	(Port_PinType)12
#define PORT_PINB5       (Port_PinType)13
#define PORT_PINB6 	(Port_PinType)14
#define PORT_PINB7 	(Port_PinType)15
#define PORT_PINC0 	(Port_PinType)16
#define PORT_PINC1 	(Port_PinType)17
#define PORT_PINC2 	(Port_PinType)18
#define PORT_PINC3 	(Port_PinType)19
#define PORT_PINC4	(Port_PinType)20
#define PORT_PINC5       (Port_PinType)21
#define PORT_PINC6 	(Port_PinType)22
#define PORT_PINC7 	(Port_PinType)23
#define PORT_PIND0 	(Port_PinType)24
#define PORT_PIND1 	(Port_PinType)25
#define PORT_PIND2 	(Port_PinType)26
#define PORT_PIND3 	(Port_PinType)27
#define PORT_PIND4	(Port_PinType)28
#define PORT_PIND5       (Port_PinType)29
#define PORT_PIND6 	(Port_PinType)30
#define PORT_PIND7 	(Port_PinType)31
#define PORT_PINF0 	(Port_PinType)32
#define PORT_PINF1 	(Port_PinType)33
#define PORT_PINF2 	(Port_PinType)34
#define PORT_PINF3 	(Port_PinType)35
#define PORT_PINF4	(Port_PinType)36
#define PORT_PINE0 	(Port_PinType)37
#define PORT_PINE1 	(Port_PinType)38
#define PORT_PINE2 	(Port_PinType)39
#define PORT_PINE3 	(Port_PinType)40
#define PORT_PINE4	(Port_PinType)41
#define PORT_PINE5	(Port_PinType)42

#endif /* port_CFG_H */