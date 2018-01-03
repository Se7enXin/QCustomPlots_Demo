#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QUrl> 
#include <QPushButton>
#include <QMainWindow>
#include <QTimer>
#include "../../lib/qcustomplot/qcustomplot.h" // the header file of QCustomPlot. Don't forget to add it to your project, if you use an IDE, so it gets compiled.
#include "../Includes/Includes.h"

class QLabel;
class QPushButton;
class MainWindow : public QMainWindow 
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

    void start_plots_thread_job();

    void ui_init();
    void signals_init();
    void navbar_init();
    void plots_init();
  
private slots:
    void exitApp(void);

public slots: 
    void change_plots_data_cb(float data1_x, float data1_y, float data2_x, float data2_y, float data3_x, float data3_y);
    void plots_data_range_cb();
    void clear_plots_data_cb();

private:
    QTimer dataTimer;

    QLabel *navbar;
    QLabel *navbarTitle;
    QPushButton *quitBtn;

    QCustomPlot *customPlot;

protected: 

};

#endif // MAINWINDOW_H
