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

    virtual void download() {
        // downloading...
        setState(0);

        for (int i = 0; i < 100; i++) {
            std::cout << i << "%" << std::endl;
            setState(state + 1);
            wxMilliSleep(500);
        }
    }

    int getState() const {
        return state;
    }

private:
    void setState(int state) {
        this->state = state;
        notify();
    }

    int state;
};


#endif //LOADINGBAR_LOADINGHANDLER_H
