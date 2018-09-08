//
// Created by Francesco Gradi on 24/02/18.
//

#include "AbstractSubject.h"

bool AbstractSubject::notify() {

    for (auto itr = std::begin(observers); itr != std::end(observers); itr++) {
        if ((*itr)->update()) {
            continue;
        }
        else {
            remove(*itr);
            return false;
        }
    }
    return true;
}
