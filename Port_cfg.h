 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Dio Driver
 *
 * Author: ahmed zakria
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
#define PORT_CONFIGURED_CHANNLES    (43U)
#define MIN_PIN_NUM                 (0)
#define MAX_PIN_NUM                 (42)
#define zero                         (0)
#define PORTA_ID					(0U)
#define PORTB_ID					(1U)
#define PORTC_ID					(2U)
#define PORTD_ID					(3U)
#define PORTE_ID					(4U)
#define PORTF_ID					(5U)
#define PORT_PIN0 					(Port_PinType)0
#define PORT_PIN1 					(Port_PinType)1
#define PORT_PIN2 					(Port_PinType)2
#define PORT_PIN3 					(Port_PinType)3
#define PORT_PIN4 					(Port_PinType)4
#define PORT_PIN5 					(Port_PinType)5
#define PORT_PIN6 					(Port_PinType)6
#define PORT_PIN7 					(Port_PinType)7

// definations for pin and ports
#define compare                     (8) // reference to 8 bits
#define one                         (1)
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
#define PORT_PINE0 	(Port_PinType)32
#define PORT_PINE1 	(Port_PinType)33
#define PORT_PINE2 	(Port_PinType)34
#define PORT_PINE3 	(Port_PinType)35
#define PORT_PINE4	(Port_PinType)36
#define PORT_PINE5 	(Port_PinType)37
#define PORT_PINF0	(Port_PinType)38
#define PORT_PINF1	(Port_PinType)39
#define PORT_PINF2 	(Port_PinType)40
#define PORT_PINF3 	(Port_PinType)41
#define PORT_PINF4	(Port_PinType)42
/*********************************************************************************
 * 						CONFIG Definitions 														 *
 * *******************************************************************************/



/* defines for pin0*/
#define portConf_PORT_NUMBER0                     PORTA_ID    
#define portConf_CHANNEL_NUMBER0                  PORT_PIN0 
#define portConf_CHANNEL_DIRECTION0               INPUT
#define portConf_CHANNEL_INPUT_PIN_MODE0	  PULL_UP
#define portConf_CHANNEL_OUTPUT_PIN_MODE0	  LOW
#define portConf_CHANNEL_MODE_CHANGAEBLE0         change
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE0     yes
/* defines for pin1*/
#define portConf_PORT_NUMBER1                      PORTA_ID    
#define portConf_CHANNEL_NUMBER1                   PORT_PIN1 
#define portConf_CHANNEL_DIRECTION1                INPUT
#define portConf_CHANNEL_INPUT_PIN_MODE1	   PULL_UP
#define portConf_CHANNEL_OUTPUT_PIN_MODE1	   LOW
#define portConf_CHANNEL_MODE_CHANGAEBLE1          change
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE1     yes
/* defines for pin2*/
#define portConf_PORT_NUMBER2                      PORTA_ID    
#define portConf_CHANNEL_NUMBER2                   PORT_PIN2 
#define portConf_CHANNEL_DIRECTION2                INPUT
#define portConf_CHANNEL_INPUT_PIN_MODE2	   PULL_UP
#define portConf_CHANNEL_OUTPUT_PIN_MODE2	   LOW
#define portConf_CHANNEL_MODE_CHANGAEBLE2         change
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE2     yes
/* defines for pin3*/
#define portConf_PORT_NUMBER3                      PORTA_ID    
#define portConf_CHANNEL_NUMBER3                   PORT_PIN3 
#define portConf_CHANNEL_DIRECTION3                INPUT
#define portConf_CHANNEL_INPUT_PIN_MODE3	   PULL_UP
#define portConf_CHANNEL_OUTPUT_PIN_MODE3	   LOW
#define portConf_CHANNEL_MODE_CHANGAEBLE3         change
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE3     yes
/* defines for pin4*/
#define portConf_PORT_NUMBER4                     PORTA_ID    
#define portConf_CHANNEL_NUMBER4                  PORT_PIN4 
#define portConf_CHANNEL_DIRECTION4               INPUT
#define portConf_CHANNEL_INPUT_PIN_MODE4	  PULL_UP
#define portConf_CHANNEL_OUTPUT_PIN_MODE4	  LOW
#define portConf_CHANNEL_MODE_CHANGAEBLE4         change
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE4     yes
/* defines for pin5*/
#define portConf_PORT_NUMBER5                     PORTA_ID    
#define portConf_CHANNEL_NUMBER5                  PORT_PIN5 
#define portConf_CHANNEL_DIRECTION5               INPUT
#define portConf_CHANNEL_INPUT_PIN_MODE5	  PULL_UP
#define portConf_CHANNEL_OUTPUT_PIN_MODE5	  LOW
#define portConf_CHANNEL_MODE_CHANGAEBLE5         change
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE5     yes
/* defines for pin6*/
#define portConf_PORT_NUMBER6                     PORTA_ID    
#define portConf_CHANNEL_NUMBER6                  PORT_PIN6 
#define portConf_CHANNEL_DIRECTION6               INPUT
#define portConf_CHANNEL_INPUT_PIN_MODE6	  PULL_UP
#define portConf_CHANNEL_OUTPUT_PIN_MODE6	  LOW
#define portConf_CHANNEL_MODE_CHANGAEBLE6         change
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE6     yes
/* defines for pin7*/
#define portConf_PORT_NUMBER7                     PORTA_ID    
#define portConf_CHANNEL_NUMBER7                  PORT_PIN7
#define portConf_CHANNEL_DIRECTION7               INPUT
#define portConf_CHANNEL_INPUT_PIN_MODE7	  PULL_UP
#define portConf_CHANNEL_OUTPUT_PIN_MODE7	  LOW
#define portConf_CHANNEL_MODE_CHANGAEBLE7         change
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE7     yes
/* defines for pin8*/
#define portConf_PORT_NUMBER8                     PORTB_ID    
#define portConf_CHANNEL_NUMBER8                  PORT_PIN0 
#define portConf_CHANNEL_DIRECTION8               INPUT
#define portConf_CHANNEL_INPUT_PIN_MODE8	  PULL_UP
#define portConf_CHANNEL_OUTPUT_PIN_MODE8	  LOW
#define portConf_CHANNEL_MODE_CHANGAEBLE8         change
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE8     yes
/* defines for pin9*/
#define portConf_PORT_NUMBER9                     PORTB_ID    
#define portConf_CHANNEL_NUMBER9                  PORT_PIN1 
#define portConf_CHANNEL_DIRECTION9               INPUT
#define portConf_CHANNEL_INPUT_PIN_MODE9	  PULL_UP
#define portConf_CHANNEL_OUTPUT_PIN_MODE9	  LOW
#define portConf_CHANNEL_MODE_CHANGAEBLE9         change
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE9     yes
/* defines for pin10*/
#define portConf_PORT_NUMBER10                     PORTB_ID    
#define portConf_CHANNEL_NUMBER10                  PORT_PIN2
#define portConf_CHANNEL_DIRECTION10               INPUT
#define portConf_CHANNEL_INPUT_PIN_MODE10	   PULL_UP
#define portConf_CHANNEL_OUTPUT_PIN_MODE10	   LOW
#define portConf_CHANNEL_MODE_CHANGAEBLE10         change
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE10     yes
/* defines for pin11*/
#define portConf_PORT_NUMBER11                     PORTB_ID    
#define portConf_CHANNEL_NUMBER11                  PORT_PIN3
#define portConf_CHANNEL_DIRECTION11               INPUT
#define portConf_CHANNEL_INPUT_PIN_MODE11	   PULL_UP
#define portConf_CHANNEL_OUTPUT_PIN_MODE11	   LOW
#define portConf_CHANNEL_MODE_CHANGAEBLE11         change
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE11     yes
/* defines for pin12*/
#define portConf_PORT_NUMBER12                     PORTB_ID    
#define portConf_CHANNEL_NUMBER12                  PORT_PIN4
#define portConf_CHANNEL_DIRECTION12               INPUT
#define portConf_CHANNEL_INPUT_PIN_MODE12	   PULL_UP
#define portConf_CHANNEL_OUTPUT_PIN_MODE12	   LOW
#define portConf_CHANNEL_MODE_CHANGAEBLE12         change
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE12     yes
/* defines for pin13*/
#define portConf_PORT_NUMBER13                     PORTB_ID    
#define portConf_CHANNEL_NUMBER13                  PORT_PIN5
#define portConf_CHANNEL_DIRECTION13               INPUT
#define portConf_CHANNEL_INPUT_PIN_MODE13	   PULL_UP
#define portConf_CHANNEL_OUTPUT_PIN_MODE13	   LOW
#define portConf_CHANNEL_MODE_CHANGAEBLE13         change
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE13     yes
/* defines for pin14*/
#define portConf_PORT_NUMBER14                     PORTB_ID    
#define portConf_CHANNEL_NUMBER14                  PORT_PIN6
#define portConf_CHANNEL_DIRECTION14               INPUT
#define portConf_CHANNEL_INPUT_PIN_MODE14	   PULL_UP
#define portConf_CHANNEL_OUTPUT_PIN_MODE14	   LOW
#define portConf_CHANNEL_MODE_CHANGAEBLE14         change
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE14     yes
/* defines for pin15*/
#define portConf_PORT_NUMBER15                     PORTB_ID    
#define portConf_CHANNEL_NUMBER15                  PORT_PIN7
#define portConf_CHANNEL_DIRECTION15               INPUT
#define portConf_CHANNEL_INPUT_PIN_MODE15	   PULL_UP
#define portConf_CHANNEL_OUTPUT_PIN_MODE15	   LOW
#define portConf_CHANNEL_MODE_CHANGAEBLE15         change
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE15     yes
/* defines for pin16*/
#define portConf_PORT_NUMBER16                     PORTC_ID    
#define portConf_CHANNEL_NUMBER16                  PORT_PIN0
#define portConf_CHANNEL_DIRECTION16               INPUT
#define portConf_CHANNEL_INPUT_PIN_MODE16	   PULL_UP
#define portConf_CHANNEL_OUTPUT_PIN_MODE16	   LOW
#define portConf_CHANNEL_MODE_CHANGAEBLE16         change
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE16     yes
/* defines for pin17*/
#define portConf_PORT_NUMBER17                     PORTC_ID    
#define portConf_CHANNEL_NUMBER17                  PORT_PIN1
#define portConf_CHANNEL_DIRECTION17               INPUT
#define portConf_CHANNEL_INPUT_PIN_MODE17	   PULL_UP
#define portConf_CHANNEL_OUTPUT_PIN_MODE17	   LOW
#define portConf_CHANNEL_MODE_CHANGAEBLE17         change
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE17     yes
/* defines for pin18*/
#define portConf_PORT_NUMBER18                     PORTC_ID    
#define portConf_CHANNEL_NUMBER18                  PORT_PIN2
#define portConf_CHANNEL_DIRECTION18               INPUT
#define portConf_CHANNEL_INPUT_PIN_MODE18	   PULL_UP
#define portConf_CHANNEL_OUTPUT_PIN_MODE18	   LOW
#define portConf_CHANNEL_MODE_CHANGAEBLE18         change
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE18     yes
/* defines for pin19*/
#define portConf_PORT_NUMBER19                     PORTC_ID    
#define portConf_CHANNEL_NUMBER19                  PORT_PIN3
#define portConf_CHANNEL_DIRECTION19               INPUT
#define portConf_CHANNEL_INPUT_PIN_MODE19	   PULL_UP
#define portConf_CHANNEL_OUTPUT_PIN_MODE19	   LOW
#define portConf_CHANNEL_MODE_CHANGAEBLE19         change
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE19     yes
/* defines for pin20*/
#define portConf_PORT_NUMBER20                     PORTC_ID    
#define portConf_CHANNEL_NUMBER20                  PORT_PIN4
#define portConf_CHANNEL_DIRECTION20               INPUT
#define portConf_CHANNEL_INPUT_PIN_MODE20	   PULL_UP
#define portConf_CHANNEL_OUTPUT_PIN_MODE20	   LOW
#define portConf_CHANNEL_MODE_CHANGAEBLE20         change
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE20     yes
/* defines for pin21*/
#define portConf_PORT_NUMBER21                     PORTC_ID    
#define portConf_CHANNEL_NUMBER21                  PORT_PIN5
#define portConf_CHANNEL_DIRECTION21               INPUT
#define portConf_CHANNEL_INPUT_PIN_MODE21	   PULL_UP
#define portConf_CHANNEL_OUTPUT_PIN_MODE21	   LOW
#define portConf_CHANNEL_MODE_CHANGAEBLE21         change
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE21     yes
/* defines for pin22*/
#define portConf_PORT_NUMBER22                     PORTC_ID    
#define portConf_CHANNEL_NUMBER22                  PORT_PIN6
#define portConf_CHANNEL_DIRECTION22               INPUT
#define portConf_CHANNEL_INPUT_PIN_MODE22	   PULL_UP
#define portConf_CHANNEL_OUTPUT_PIN_MODE22	   LOW
#define portConf_CHANNEL_MODE_CHANGAEBLE22         change
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE22     yes
/* defines for pin23*/
#define portConf_PORT_NUMBER23                     PORTC_ID    
#define portConf_CHANNEL_NUMBER23                  PORT_PIN7
#define portConf_CHANNEL_DIRECTION23               INPUT
#define portConf_CHANNEL_INPUT_PIN_MODE23	   PULL_UP
#define portConf_CHANNEL_OUTPUT_PIN_MODE23	   LOW
#define portConf_CHANNEL_MODE_CHANGAEBLE23         change
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE23     yes
/* defines for pin24*/
#define portConf_PORT_NUMBER24                     PORTD_ID    
#define portConf_CHANNEL_NUMBER24                  PORT_PIN0
#define portConf_CHANNEL_DIRECTION24               INPUT
#define portConf_CHANNEL_INPUT_PIN_MODE24	   PULL_UP
#define portConf_CHANNEL_OUTPUT_PIN_MODE24	   LOW
#define portConf_CHANNEL_MODE_CHANGAEBLE24         change
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE24     yes
/* defines for pin25*/
#define portConf_PORT_NUMBER25                     PORTD_ID    
#define portConf_CHANNEL_NUMBER25                  PORT_PIN1
#define portConf_CHANNEL_DIRECTION25               INPUT
#define portConf_CHANNEL_INPUT_PIN_MODE25	   PULL_UP
#define portConf_CHANNEL_OUTPUT_PIN_MODE25	   LOW
#define portConf_CHANNEL_MODE_CHANGAEBLE25         change
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE25     yes
/* defines for pin26*/
#define portConf_PORT_NUMBER26                     PORTD_ID    
#define portConf_CHANNEL_NUMBER26                  PORT_PIN2
#define portConf_CHANNEL_DIRECTION26               INPUT
#define portConf_CHANNEL_INPUT_PIN_MODE26	   PULL_UP
#define portConf_CHANNEL_OUTPUT_PIN_MODE26	   LOW
#define portConf_CHANNEL_MODE_CHANGAEBLE26         change
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE26     yes
/* defines for pin27*/
#define portConf_PORT_NUMBER27                     PORTD_ID    /* port number */
#define portConf_CHANNEL_NUMBER27                  PORT_PIN3  /* pin number*/
#define portConf_CHANNEL_DIRECTION27               INPUT       /* direction*/
#define portConf_CHANNEL_INPUT_PIN_MODE27	   PULL_UP     /* resistor*/
#define portConf_CHANNEL_OUTPUT_PIN_MODE27	   LOW         /*intial value*/ 
#define portConf_CHANNEL_MODE_CHANGAEBLE27         change      /*mode chage*/
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE27     yes        /* direction change*/ 
/* defines for pin28*/
#define portConf_PORT_NUMBER28                     PORTD_ID    /* port number */
#define portConf_CHANNEL_NUMBER28                  PORT_PIN4  /* pin number*/
#define portConf_CHANNEL_DIRECTION28               INPUT       /* direction*/
#define portConf_CHANNEL_INPUT_PIN_MODE28	   PULL_UP     /* resistor*/
#define portConf_CHANNEL_OUTPUT_PIN_MODE28	   LOW         /*intial value*/ 
#define portConf_CHANNEL_MODE_CHANGAEBLE28         change      /*mode chage*/
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE28     yes        /* direction change*/ 
/* defines for pin29*/
#define portConf_PORT_NUMBER29                     PORTD_ID    /* port number */
#define portConf_CHANNEL_NUMBER29                  PORT_PIN5  /* pin number*/
#define portConf_CHANNEL_DIRECTION29               INPUT       /* direction*/
#define portConf_CHANNEL_INPUT_PIN_MODE29	   PULL_UP     /* resistor*/
#define portConf_CHANNEL_OUTPUT_PIN_MODE29	   LOW         /*intial value*/ 
#define portConf_CHANNEL_MODE_CHANGAEBLE29         change      /*mode chage*/
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE29     yes        /* direction change*/ 
/* defines for pin30*/
#define portConf_PORT_NUMBER30                     PORTD_ID    /* port number */
#define portConf_CHANNEL_NUMBER30                  PORT_PIN6  /* pin number*/
#define portConf_CHANNEL_DIRECTION30               INPUT       /* direction*/
#define portConf_CHANNEL_INPUT_PIN_MODE30	   PULL_UP     /* resistor*/
#define portConf_CHANNEL_OUTPUT_PIN_MODE30	   LOW         /*intial value*/ 
#define portConf_CHANNEL_MODE_CHANGAEBLE30         change      /*mode chage*/
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE30     yes        /* direction change*/ 
/* defines for pin31*/
#define portConf_PORT_NUMBER31                     PORTD_ID    /* port number */
#define portConf_CHANNEL_NUMBER31                  PORT_PIN7  /* pin number*/
#define portConf_CHANNEL_DIRECTION31               INPUT       /* direction*/
#define portConf_CHANNEL_INPUT_PIN_MODE31	   PULL_UP     /* resistor*/
#define portConf_CHANNEL_OUTPUT_PIN_MODE31	   LOW         /*intial value*/ 
#define portConf_CHANNEL_MODE_CHANGAEBLE31         change      /*mode chage*/
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE31     yes        /* direction change*/ 
/* defines for pin32*/
#define portConf_PORT_NUMBER32                     PORTE_ID    /* port number */
#define portConf_CHANNEL_NUMBER32                  PORT_PIN0  /* pin number*/
#define portConf_CHANNEL_DIRECTION32               INPUT       /* direction*/
#define portConf_CHANNEL_INPUT_PIN_MODE32	   PULL_UP     /* resistor*/
#define portConf_CHANNEL_OUTPUT_PIN_MODE32	   LOW         /*intial value*/ 
#define portConf_CHANNEL_MODE_CHANGAEBLE32         change      /*mode chage*/
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE32     yes        /* direction change*/ 
/* defines for pin33*/
#define portConf_PORT_NUMBER33                     PORTE_ID    /* port number */
#define portConf_CHANNEL_NUMBER33                  PORT_PIN1  /* pin number*/
#define portConf_CHANNEL_DIRECTION33               INPUT       /* direction*/
#define portConf_CHANNEL_INPUT_PIN_MODE33	   PULL_UP     /* resistor*/
#define portConf_CHANNEL_OUTPUT_PIN_MODE33	   LOW         /*intial value*/ 
#define portConf_CHANNEL_MODE_CHANGAEBLE33         change      /*mode chage*/
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE33     yes        /* direction change*/ 
/* defines for pin34*/
#define portConf_PORT_NUMBER34                     PORTE_ID    /* port number */
#define portConf_CHANNEL_NUMBER34                  PORT_PIN2  /* pin number*/
#define portConf_CHANNEL_DIRECTION34               INPUT       /* direction*/
#define portConf_CHANNEL_INPUT_PIN_MODE34	   PULL_UP     /* resistor*/
#define portConf_CHANNEL_OUTPUT_PIN_MODE34	   LOW         /*intial value*/ 
#define portConf_CHANNEL_MODE_CHANGAEBLE34         change      /*mode chage*/
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE34     yes        /* direction change*/ 
/* defines for pin35*/
#define portConf_PORT_NUMBER35                     PORTE_ID    /* port number */
#define portConf_CHANNEL_NUMBER35                  PORT_PIN3  /* pin number*/
#define portConf_CHANNEL_DIRECTION35               INPUT       /* direction*/
#define portConf_CHANNEL_INPUT_PIN_MODE35	   PULL_UP     /* resistor*/
#define portConf_CHANNEL_OUTPUT_PIN_MODE35	   LOW         /*intial value*/ 
#define portConf_CHANNEL_MODE_CHANGAEBLE35         change      /*mode chage*/
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE35     yes        /* direction change*/ 
/* defines for pin36*/
#define portConf_PORT_NUMBER36                     PORTE_ID    /* port number */
#define portConf_CHANNEL_NUMBER36                  PORT_PIN4  /* pin number*/
#define portConf_CHANNEL_DIRECTION36               INPUT       /* direction*/
#define portConf_CHANNEL_INPUT_PIN_MODE36	   PULL_UP     /* resistor*/
#define portConf_CHANNEL_OUTPUT_PIN_MODE36	   LOW         /*intial value*/ 
#define portConf_CHANNEL_MODE_CHANGAEBLE36         change      /*mode chage*/
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE36     yes        /* direction change*/ 
/* defines for pin37*/
#define portConf_PORT_NUMBER37                     PORTE_ID    /* port number */
#define portConf_CHANNEL_NUMBER37                  PORT_PIN5  /* pin number*/
#define portConf_CHANNEL_DIRECTION37               INPUT       /* direction*/
#define portConf_CHANNEL_INPUT_PIN_MODE37	   PULL_UP     /* resistor*/
#define portConf_CHANNEL_OUTPUT_PIN_MODE37	   LOW         /*intial value*/ 
#define portConf_CHANNEL_MODE_CHANGAEBLE37         change      /*mode chage*/
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE37     yes        /* direction change*/ 
/* defines for pin38*/
#define portConf_PORT_NUMBER38                     PORTF_ID    /* port number */
#define portConf_CHANNEL_NUMBER38                  PORT_PIN0  /* pin number*/
#define portConf_CHANNEL_DIRECTION38               INPUT       /* direction*/
#define portConf_CHANNEL_INPUT_PIN_MODE38	   PULL_UP     /* resistor*/
#define portConf_CHANNEL_OUTPUT_PIN_MODE38	   LOW         /*intial value*/ 
#define portConf_CHANNEL_MODE_CHANGAEBLE38         change      /*mode chage*/
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE38     no        /* direction change*/ 

/* defines for pin39 for led */
#define portConf_PORT_NUMBER39                     PORTF_ID    /* port number */
#define portConf_CHANNEL_NUMBER39                  PORT_PIN1  /* pin number*/
#define portConf_CHANNEL_DIRECTION39               OUTPUT       /* direction*/
#define portConf_CHANNEL_INPUT_PIN_MODE39	   PULL_UP     /* resistor*/
#define portConf_CHANNEL_OUTPUT_PIN_MODE39	   LOW         /*intial value*/ 
#define portConf_CHANNEL_MODE_CHANGAEBLE39         change      /*mode chage*/
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE39     yes        /* direction change*/ 
/* defines for pin40*/
#define portConf_PORT_NUMBER40                     PORTF_ID    /* port number */
#define portConf_CHANNEL_NUMBER40                  PORT_PIN2  /* pin number*/
#define portConf_CHANNEL_DIRECTION40               INPUT       /* direction*/
#define portConf_CHANNEL_INPUT_PIN_MODE40	   PULL_UP     /* resistor*/
#define portConf_CHANNEL_OUTPUT_PIN_MODE40	   LOW         /*intial value*/ 
#define portConf_CHANNEL_MODE_CHANGAEBLE40         change      /*mode chage*/
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE40     yes        /* direction change*/ 
/* defines for pin41*/
#define portConf_PORT_NUMBER41                     PORTF_ID    /* port number */
#define portConf_CHANNEL_NUMBER41                  PORT_PIN3  /* pin number*/
#define portConf_CHANNEL_DIRECTION41               INPUT       /* direction*/
#define portConf_CHANNEL_INPUT_PIN_MODE41	   PULL_UP     /* resistor*/
#define portConf_CHANNEL_OUTPUT_PIN_MODE41	   LOW         /*intial value*/ 
#define portConf_CHANNEL_MODE_CHANGAEBLE41         change      /*mode chage*/
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE41     yes        /* direction change*/ 
/* defines for pin42*/
#define portConf_PORT_NUMBER42                     PORTF_ID    /* port number */
#define portConf_CHANNEL_NUMBER42                  PORT_PIN4  /* pin number*/
#define portConf_CHANNEL_DIRECTION42               INPUT       /* direction*/
#define portConf_CHANNEL_INPUT_PIN_MODE42	   PULL_UP     /* resistor*/
#define portConf_CHANNEL_OUTPUT_PIN_MODE42	   LOW         /*intial value*/ 
#define portConf_CHANNEL_MODE_CHANGAEBLE42         change      /*mode chage*/
#define portConf_CHANNEL_DIRECTION_CHANGAEBLE42     yes        /* direction change*/ 
#endif /* port_CFG_H */