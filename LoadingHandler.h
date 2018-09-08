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

    virtual void download(int initial, int msSpeed) {
        // downloading...
        if (initial <= 100 and initial >= 0 and msSpeed > 0) {

            setState(initial);
            setMsSpeed(msSpeed);

            for (int i = 0; i < (100 - initial) ; i++) {
                if (!observers.empty()) {
                    if (!setState(state + 1))
                        break;
                    wxMilliSleep(msSpeed);
                }
                else {
                    break;
                }
            }
        }
    }

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
