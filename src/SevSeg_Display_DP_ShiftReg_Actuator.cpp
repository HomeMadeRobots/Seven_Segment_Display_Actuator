#include "SevSeg_Display_DP_ShiftReg_Actuator.h"


static const uint8_t SEGMENT_MASK[8] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };

/**************************************************************************************************/
/* Constructor */
SevSeg_Display_DP_ShiftReg_Actuator::SevSeg_Display_DP_ShiftReg_Actuator( 
	E_SevSeg_Display_Hardware_Conf hw_conf )
{
	this->Segments_State = 0; /* all segments off */
	this->Hardware_Configuration = hw_conf;
}
/*------------------------------------------------------------------------------------------------*/
void SevSeg_Display_DP_ShiftReg_Actuator::Connect_Ports(
	i_Discrete_Output* serial_data_pin,
	i_Discrete_Output* latch_pin,
	i_Discrete_Output* clock_pin )
{
	this->Serial_Data_Pin = serial_data_pin;
	this->Latch_Pin = latch_pin;
	this->Clock_Pin = clock_pin;
}
/**************************************************************************************************/


/**************************************************************************************************/
/* Component_Type_Operations */
/**************************************************************************************************/
void SevSeg_Display_DP_ShiftReg_Actuator::Update_Display( void )
{
	this->Latch_Pin->Set_Level(IO_LEVEL_LOW);
	for(int i = 7; i >=  0; i--)
	{
		this->Clock_Pin->Set_Level(IO_LEVEL_LOW);

		uint8_t seg_state = ( (this->Segments_State) & (SEGMENT_MASK[i]) );

		if( seg_state != 0 )
		{
			if( this->Hardware_Configuration == SEVSEG_DISPLAY_COMMON_CATHODE )
			{
				this->Serial_Data_Pin->Set_Level(IO_LEVEL_HIGH);
			}
			else
			{
				this->Serial_Data_Pin->Set_Level(IO_LEVEL_LOW);
			}	
		}
		else
		{
			if( this->Hardware_Configuration == SEVSEG_DISPLAY_COMMON_CATHODE )
			{
				this->Serial_Data_Pin->Set_Level(IO_LEVEL_LOW);
			}
			else
			{
				this->Serial_Data_Pin->Set_Level(IO_LEVEL_HIGH);
			}
		}
		this->Clock_Pin->Set_Level(IO_LEVEL_HIGH);
	}
	this->Latch_Pin->Set_Level(IO_LEVEL_HIGH);
}
/**************************************************************************************************/


/**************************************************************************************************/
/* Event reception points accessors */
/**************************************************************************************************/


/**************************************************************************************************/
/* Prodided port accessors */
/**************************************************************************************************/
i_SevSeg_Display_DP_Command* SevSeg_Display_DP_ShiftReg_Actuator::Get_Port__Segments_Command( void )
{
	return (i_SevSeg_Display_DP_Command*)(this);
}
/**************************************************************************************************/


/**************************************************************************************************/
/* Private methods */
/**************************************************************************************************/


/**************************************************************************************************/
/* Provided operations */
/**************************************************************************************************/
void SevSeg_Display_DP_ShiftReg_Actuator::Set_Segments_Status( 
	bool is_a_on,
	bool is_b_on,
	bool is_c_on,
	bool is_d_on,
	bool is_e_on,
	bool is_f_on,
	bool is_g_on,
	bool is_dp_on )
{
	if( true==is_a_on )
	{
		this->Segments_State |= SEGMENT_MASK[0];
	}
	else
	{
		this->Segments_State &= ~(SEGMENT_MASK[0]);
	}
	
	if( true==is_b_on )
	{
		this->Segments_State |= SEGMENT_MASK[1];
	}
	else
	{
		this->Segments_State &= ~(SEGMENT_MASK[1]);
	}
		
	if( true==is_c_on )
	{
		this->Segments_State |= SEGMENT_MASK[2];
	}
	else
	{
		this->Segments_State &= ~(SEGMENT_MASK[2]);
	}
		
	if( true==is_d_on )
	{
		this->Segments_State |= SEGMENT_MASK[3];
	}
	else
	{
		this->Segments_State &= ~(SEGMENT_MASK[3]);
	}
	
	if( true==is_e_on )
	{
		this->Segments_State |= SEGMENT_MASK[4];
	}
	else
	{
		this->Segments_State &= ~(SEGMENT_MASK[4]);
	}
	
	if( true==is_f_on )
	{
		this->Segments_State |= SEGMENT_MASK[5];
	}
	else
	{
		this->Segments_State &= ~(SEGMENT_MASK[5]);
	}
	
	if( true==is_g_on )
	{
		this->Segments_State |= SEGMENT_MASK[6];
	}
	else
	{
		this->Segments_State &= ~(SEGMENT_MASK[6]);
	}
	
	if( true==is_dp_on )
	{
		this->Segments_State |= SEGMENT_MASK[7];
	}
	else
	{
		this->Segments_State &= ~(SEGMENT_MASK[7]);
	}
}
/**************************************************************************************************/


/**************************************************************************************************/
/* Received events */
/**************************************************************************************************/