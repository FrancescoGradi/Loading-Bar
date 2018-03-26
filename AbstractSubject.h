//
// Created by Francesco Gradi on 24/02/18.
//

#ifndef LOADINGBAR_ABSTRACTSUBJECT_H
#define LOADINGBAR_ABSTRACTSUBJECT_H

#include <list>
#include "Observer.h"

class AbstractSubject {
private:
    std::list<Observer*> observers;

public:
    void add(Observer *o) { observers.push_back(o); }
    void remove(Observer *o) { observers.remove(o); }
    void notify();

};


#endif //LOADINGBAR_ABSTRACTSUBJECT_H
