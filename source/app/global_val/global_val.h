#ifndef _GLOBAL_CLASS_H_
#define _GLOBAL_CLASS_H_

#include "../view/mainwindow.h"
#include "../signals/signals.h"

//global
extern PLOTS_ plots;
extern MainWindow *mainwindow;

extern SIGNALS *updateGasDataSignal;
extern SIGNALS *gasDataRangeSignal;
extern SIGNALS *clearGasDataSignal;

#endif 