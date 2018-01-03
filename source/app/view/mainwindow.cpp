#include "mainwindow.h"
#include <QtGui>

#include "../global_val/global_val.h"
#include "../signals/signals.h"

MainWindow::MainWindow()
{
    ui_init();
    mainwindow = this;
    signals_init();
}

static void *plots_thread_job(void *arg)
{
    MainWindow *pHandler = (MainWindow *)arg;

    memset(&plots, 0, sizeof(plots));
    plots_test();
    while(1)  {

    }
}

void MainWindow::start_plots_thread_job()
{
    pthread_t pthread_plots;
    pthread_create(&pthread_plots, NULL, ::plots_thread_job, (void*)this);
    pthread_detach(pthread_plots);
}

MainWindow::~MainWindow()
{
    
}

int screen_h;
int screen_w;
void MainWindow::ui_init()
{
    QRect screen_size = QApplication::desktop()->screenGeometry();
    screen_h = screen_size.height();
    screen_w = screen_size.width();
    printf("------------------------------h=%d, w=%d\n", screen_h, screen_w);

    navbar_init();

    plots_init();
}

void MainWindow::signals_init()
{
    updateGasDataSignal = new SIGNALS();
    connect(updateGasDataSignal, SIGNAL(update_plots_data_Signal(float, float, float, float, float, float)), this, SLOT(change_plots_data_cb(float, float, float, float, float, float)));

    gasDataRangeSignal = new SIGNALS();
    connect(gasDataRangeSignal, SIGNAL(plots_data_range_signal()) ,this, SLOT(plots_data_range_cb()));

    clearGasDataSignal = new SIGNALS();
    connect(clearGasDataSignal, SIGNAL(clear_plots_data_signal()), this, SLOT(clear_plots_data_cb()));
}

void MainWindow::navbar_init(void)
{
    navbar = new QLabel(tr(""),this);
    navbar->setGeometry(0, 0, screen_w, screen_h/12);
    navbar->setStyleSheet("background-color:#0066cc;");

    navbarTitle = new QLabel(tr("QCustomPlot Test"),this);
    navbarTitle->setGeometry(screen_w*3/160, 0, screen_w, screen_h/12);
    navbarTitle->setStyleSheet("background-color:#0066cc;color:white;font-size:35px;font-weight:bold;");

    quitBtn = new QPushButton(tr(""), this);
    quitBtn->setGeometry(screen_w*1200/1280, 0, screen_w*60/1280, screen_h*60/720);
    quitBtn->setIcon(QIcon("/share/MES-Point/MES/images/quit.png")); //使用绝对路径
    quitBtn->setIconSize(QSize(screen_w*100/1280, screen_h*100/720));
    quitBtn->setStyleSheet("border-radius:100px;background-color:#0066cc;outline:none;");
    connect(quitBtn,SIGNAL(clicked()),this,SLOT(exitApp()));
}

void MainWindow::plots_init(void)
{
    customPlot = new QCustomPlot(this);
    customPlot->setGeometry(screen_w*0/1024, screen_h*60/600, screen_w*1024/1024, screen_h*540/600);
  
    // customPlot->xAxis->setLabel("x");  
    customPlot->yAxis->setLabel(tr("单位(XXX)")); 
    customPlot->xAxis->setLabel(tr("单位(XXX)")); 
    customPlot->legend->setVisible(true);

    customPlot->addGraph();
    QPen bluePen;  
    bluePen.setColor(QColor("#33CCCC"));  
    bluePen.setWidthF(2.5);  
    customPlot->graph(0)->setPen(bluePen); 
    customPlot->graph(0)->setName(tr("测试点1"));
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);//标签位置
    customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
    
    customPlot->addGraph();
    QPen greenPen;  
    greenPen.setColor(QColor("#0066CC"));  
    greenPen.setWidthF(2.5);
    customPlot->graph(1)->setPen(greenPen); 
    customPlot->graph(1)->setName(tr("测试点2"));
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);//标签位置
    customPlot->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));

    customPlot->addGraph();
    QPen redPen;  
    redPen.setColor(QColor("#FF3366"));  
    redPen.setWidthF(2.5);
    customPlot->graph(2)->setPen(redPen); 
    customPlot->graph(2)->setName(tr("测试点3"));
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);//标签位置
    // customPlot->xAxis2->setLabel(tr("压力(Pa)"));
    //设置每个节点数据绘制风格，默认是空，这里设置为空心圆
    customPlot->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
    // generate data:
  
    // customPlot->graph()->rescaleAxes(true);
  
    // zoom out a bit: 
    // 默认即为1.0，可省略
    printf("yAxis=%f\n", customPlot->yAxis->range().center());
    customPlot->yAxis->scaleRange(1.2, customPlot->yAxis->range().center());
    // customPlot->xAxis->scaleRange(1.2, customPlot->xAxis->range().center());
    // set blank axis lines:
    customPlot->xAxis->setTicks(true); //刻度
    customPlot->yAxis->setTicks(true);
    customPlot->xAxis->setTickLabels(true);  //文本
    customPlot->yAxis->setTickLabels(true);
    // make top right axes clones of bottom left axes:
    //一个默认的坐标轴矩形配置，包括：顶部坐标轴跟随底部坐标轴同步、右侧坐标轴跟随左侧坐标轴同步，
    //不仅仅是坐标轴范围跟随同步，包括文本精度、文本格式、坐标轴类型、是否自动生成刻度、刻度间距等等。
    customPlot->axisRect()->setupFullAxesBox();
}

QVector<QVector<double> > data_x(3), data_y(3);
int recv_count = 0;
void MainWindow::change_plots_data_cb(float data1_x, float data1_y, float data2_x, float data2_y, float data3_x, float data3_y)
{
    if (recv_count == 0) {
        for(int i=0;i<3;i++) {
           data_x[i].resize(DATA_SIZE);
           data_y[i].resize(DATA_SIZE);
        }
    }

    recv_count ++;
    data_x[0][recv_count-1] = data1_x;
    data_y[0][recv_count-1] = data1_y;
    data_x[1][recv_count-1] = data2_x;
    data_y[1][recv_count-1] = data2_y;
    data_x[2][recv_count-1] = data3_x;
    data_y[2][recv_count-1] = data3_y;
    for (int i = 0; i < 3; ++i) {
        customPlot->graph(i)->setData(data_x[i], data_y[i]);
        customPlot->graph(i)->rescaleAxes(true); //坐标轴自适应
    }
    customPlot->replot(); 
}

void MainWindow::plots_data_range_cb()
{
    //清除
    recv_count = 0;
    for (int j = 0; j < 3; ++j) {
        for (int i = 0; i < DATA_SIZE; ++i) {
            data_x[j][i] = 0;
            data_y[j][i] = 0;
        }
    }

    customPlot->yAxis->scaleRange(1.1, customPlot->yAxis->range().center());
    customPlot->xAxis->scaleRange(1.1, customPlot->xAxis->range().center());
    customPlot->replot(); 
}

void MainWindow::clear_plots_data_cb()
{
    for (int i = 0; i < 3; ++i) {
        customPlot->graph(i)->data().data()->clear();
    }

    // customPlot->yAxis->setRange(0, 0);
    // customPlot->xAxis->setRange(0, 0);
    customPlot->yAxis->scaleRange(0.9, customPlot->yAxis->range().center());
    customPlot->xAxis->scaleRange(0.9, customPlot->xAxis->range().center());
    customPlot->replot(); 
}



void MainWindow::exitApp(void)
{
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this, tr("退出"),
        QString(tr("确定要退出么？")),
        QMessageBox::Yes | QMessageBox::No);
    if (button == QMessageBox::No) {

    }
    else if (button == QMessageBox::Yes) {
        exit(0);
    }
}






























