//
// Created by Francesco Gradi on 24/02/18.
//

#include "AbstractSubject.h"

void AbstractSubject::notify() {

    for (auto itr = std::begin(observers); itr != std::end(observers); itr++) {
        (*itr)->update();
    }
}
