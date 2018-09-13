//
// Created by Francesco Gradi on 24/02/18.
//

#ifndef LOADINGBAR_OBSERVER_H
#define LOADINGBAR_OBSERVER_H


class Observer {
public:
    virtual bool update() = 0;
    virtual ~Observer() {}
};


#endif //LOADINGBAR_OBSERVER_H
