#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "Frame.h"

class MyApp : public wxApp {

public:
    virtual bool OnInit() override;
    virtual int OnExit(void) override;

};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {

    Frame *frame = new Frame(nullptr);

    frame->Show(true);

    LoadingHandler *loadingHandler = new LoadingHandler();

    // installo la dipendenza
    loadingHandler->add(frame);
    frame->setLoadingHandler(loadingHandler);

    loadingHandler->download();


    return true;
}

int MyApp::OnExit(void) {
    close(true);
    return 0;
}
