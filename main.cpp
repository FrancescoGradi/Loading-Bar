#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Frame.h"
#include "MainFrame.h"

class MyApp : public wxApp {

public:
    virtual bool OnInit() override;
    virtual int OnExit(void) override;

    int runTests(int argc, char* argv[]) {
        testing::InitGoogleTest(&argc, argv);
        RUN_ALL_TESTS();

        return 0;
    }

};

enum {
    ID_HELLO = 1
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
                EVT_MENU(ID_HELLO,   MainFrame::OnHello)
                EVT_MENU(wxID_EXIT,  MainFrame::OnExit)
                EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {

    MainFrame* mainFrame = new MainFrame("Main menu", wxPoint(50, 50), wxSize(400,200));

    mainFrame->Show(true);

    //runTests(argc, argv);

    return true;
}

int MyApp::OnExit(void) {
    close(true);
    return 0;
}
