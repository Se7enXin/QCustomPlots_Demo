#ifndef _SIGNALS_H_
#define _SIGNALS_H_

#include <QtGui/QWidget>

class SIGNALS : public QObject
{
    Q_OBJECT

public:
	SIGNALS();
	~SIGNALS();

    void send_update_plots_data_signal(float data1_x, float data1_y, float data2_x, float data2_y, float data3_x, float data3_y);
    void send_plots_data_range_signal();
    void send_clear_plots_data_signal();

	signals:
	void update_plots_data_Signal(float data1_x, float data1_y, float data2_x, float data2_y, float data3_x, float data3_y);
	void plots_data_range_signal();
	void clear_plots_data_signal();
	
private: 

};


#endif