//
// Created by Francesco Gradi on 24/02/18.
//

#include "LoadingHandler.h"

void LoadingHandler::download(int initial, int msSpeed) {

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