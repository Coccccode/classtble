#ifndef CALCTIME_H
#define CALCTIME_H
#include <QDate>
int calcDay(QDate startTime){
    int flag=0;
    while(1){
        if(startTime.dayOfWeek()!=1){
        startTime.addDays(1);
        flag=1;
        }
        else {
            break;
        }
    }
    QDate end=QDate::currentDate();
    int week=startTime.daysTo(end)/7+1+flag;
    return week;
}
#endif // CALCTIME_H
