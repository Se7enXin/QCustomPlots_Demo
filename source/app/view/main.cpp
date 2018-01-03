#include <QApplication>
#include <QTextCodec>
#include "./mainwindow.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
	QApplication::setGraphicsSystem("raster");
#endif
	QApplication a(argc, argv);

 	QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));  /* 设置字体，以显示中文*/
	QApplication::setOverrideCursor(Qt::BlankCursor);

	MainWindow w;
	w.setStyleSheet("background-color:white;");
	w.showFullScreen();

	w.start_plots_thread_job();

	return a.exec();
}
