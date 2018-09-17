//
// Created by Francesco Gradi on 17/09/18.
//

#ifndef LOADINGBAR_TESTOBSERVER_H
#define LOADINGBAR_TESTOBSERVER_H

#include "../Observer.h"
#include "../LoadingHandler.h"

class TestObserver: public Observer {
public:
    TestObserver(LoadingHandler *loadingHandler, int state);
    virtual ~TestObserver();

    bool update() override;

    int getState() const;
    void setState(int state);

    LoadingHandler *getLoadingHandler() const;
    void setLoadingHandler(LoadingHandler *loadingHandler);

private:
    LoadingHandler* loadingHandler;
    int state;
};

#endif //LOADINGBAR_TESTOBSERVER_H
