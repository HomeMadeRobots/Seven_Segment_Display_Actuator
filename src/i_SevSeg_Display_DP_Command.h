#ifndef I_SEVSEG_DISPLAY_DP_COMMAND_H
#define I_SEVSEG_DISPLAY_DP_COMMAND_H


/* Client_Server_Interface */
/*
description
*/
class i_SevSeg_Display_DP_Command {
public :
    /* Synchronous_Operation */
    /* description */
    virtual void Set_Segments_Status( 
		bool is_a_on,
		bool is_b_on,
		bool is_c_on,
		bool is_d_on,
		bool is_e_on,
		bool is_f_on,
		bool is_g_on,
		bool is_dp_on ) = 0;
};

#endif