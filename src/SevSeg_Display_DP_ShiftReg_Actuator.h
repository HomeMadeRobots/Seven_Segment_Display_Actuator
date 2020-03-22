#ifndef SEVSEG_DISPLAY_DP_SHIFTREG_ACTUATOR_H
#define SEVSEG_DISPLAY_DP_SHIFTREG_ACTUATOR_H


/* Attributes */
#include "stdint.h"
#include "E_SevSeg_Display_Hardware_Conf.h"

/* Realized interfaces */
#include "i_SevSeg_Display_DP_Command.h"

/* Needed interfaces */
#include "i_Discrete_Output.h"

/* Events */


/* Component_Type */
class SevSeg_Display_DP_ShiftReg_Actuator : i_SevSeg_Display_DP_Command {
public :
    /*--------------------------------------------------------------------------------------------*/
    /* Constructor */
    SevSeg_Display_DP_ShiftReg_Actuator( E_SevSeg_Display_Hardware_Conf hw_conf );
	void Connect_Ports(
		i_Discrete_Output* serial_data_pin,
		i_Discrete_Output* latch_pin,
		i_Discrete_Output* clock_pin );
		
    /*--------------------------------------------------------------------------------------------*/
    /* Component_Type_Operations */
	void Update_Display( void );
	
    /*--------------------------------------------------------------------------------------------*/
    /* Event reception points accessors */
	
    /*--------------------------------------------------------------------------------------------*/
    /* Provided port accessors */
	i_SevSeg_Display_DP_Command* Get_Port__Segments_Command( void );
	
	/*--------------------------------------------------------------------------------------------*/
    /* Provided operations */
	void Set_Segments_Status( 
		bool is_a_on,
		bool is_b_on,
		bool is_c_on,
		bool is_d_on,
		bool is_e_on,
		bool is_f_on,
		bool is_g_on,
		bool is_dp_on ) override;
		
private :
    /*--------------------------------------------------------------------------------------------*/
    /* Private attributes */
	/* Bit carrier representing the segments state.
	DP|G|F|E|D|C|B|A */
	uint8_t Segments_State; 
	E_SevSeg_Display_Hardware_Conf Hardware_Configuration;
	
    /*--------------------------------------------------------------------------------------------*/
    /* Private methods */

    /*--------------------------------------------------------------------------------------------*/
    /* Requirer_Ports */
	i_Discrete_Output* Serial_Data_Pin;
	i_Discrete_Output* Latch_Pin;
	i_Discrete_Output* Clock_Pin;

    /*--------------------------------------------------------------------------------------------*/
    /* Provider ports */

    /*--------------------------------------------------------------------------------------------*/
    /* Sent events */

    /*--------------------------------------------------------------------------------------------*/
    /* Received events */
};

#endif