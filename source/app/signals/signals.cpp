#include "./signals.h"

SIGNALS::SIGNALS()
{

}

SIGNALS::~SIGNALS()
{

}

void SIGNALS::send_update_plots_data_signal(float data1_x, float data1_y, float data2_x, float data2_y, float data3_x, float data3_y)
{
	emit update_plots_data_Signal(data1_x, data1_y, data2_x, data2_y, data3_x, data3_y);
}

void SIGNALS::send_plots_data_range_signal()
{
	emit plots_data_range_signal();
}

void SIGNALS::send_clear_plots_data_signal()
{
	emit clear_plots_data_signal();
}






