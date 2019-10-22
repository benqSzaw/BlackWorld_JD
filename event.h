#ifndef EVENT_H
#define EVENT_H

#include <QString>
#include <iostream>
using namespace std;


class Event
{
private:


public:
    Event();
    int id;

    int type;
    QString description;
    QString option1, option2, option3;
    QString cons1, cons2, cons3;

};

#endif // EVENT_H
