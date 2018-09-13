//
// Created by Francesco Gradi on 24/02/18.
//

#ifndef LOADINGBAR_LOADINGHANDLER_H
#define LOADINGBAR_LOADINGHANDLER_H

#include "AbstractSubject.h"

#include <iostream>
#include <wx/utils.h>

class LoadingHandler : public AbstractSubject {

public:
    LoadingHandler() { this->state = 0; }
    virtual ~LoadingHandler() { }

    virtual void download(int initial, int msSpeed);

    int getState() const {
        return state;
    }

    int getMsSpeed() const {
        return msSpeed;
    }

    void setMsSpeed(int msSpeed) {
        LoadingHandler::msSpeed = msSpeed;
    }

private:
    bool setState(int state) {
        this->state = state;
        return notify();
    }

    int state, msSpeed;

};


#endif //LOADINGBAR_LOADINGHANDLER_H
