#include "./plots_test.h"
#include "../global_val/global_val.h"

#define VALUE_Y_   0.0 + qrand()%(7000-0+1)

#define TEST_NUM   3
#define POINT_NUM  10
void plots_test(void)
{
	for (int i = 0; i < TEST_NUM; ++i) {
		for (int j = 0; j < POINT_NUM; ++j) {
		    plots.data[0][0] = j * 0.5;           //曲线1-X
		    plots.data[0][1] = VALUE_Y_;          //曲线1-Y
		    plots.data[1][0] = j * 0.5;
		    plots.data[1][1] = VALUE_Y_*0.5;
		    plots.data[2][0] = j * 0.5;
		    plots.data[2][1] = VALUE_Y_*2;
		    updateGasDataSignal->send_update_plots_data_signal(plots.data[0][0], plots.data[0][1], 
		    											 plots.data[1][0], plots.data[1][1], 
		    											 plots.data[2][0], plots.data[2][1]);
		    usleep(500000);
		}

		gasDataRangeSignal->send_plots_data_range_signal();
		clearGasDataSignal->send_clear_plots_data_signal();

		sleep(1);
	}
}