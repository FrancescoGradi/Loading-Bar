//
// Created by Francesco Gradi on 08/09/18.
//

#include "Frame.h"
#include "LoadingHandler.h"
#include "MainFrame.h"


#include <wx/wx.h>
#include <wx/button.h>
#include <iostream>

enum {
    ID_HELLO = 1
};

void MainFrame::buttonOneClicked(wxCommandEvent &event) {

    std::cout << "Button" << std::endl;

    Frame *frame = new Frame(this);

    frame->Show(true);

    LoadingHandler* loadingHandler = new LoadingHandler();

    // installo la dipendenza
    loadingHandler->add(frame);
    frame->setLoadingHandler(loadingHandler);

    loadingHandler->download(0, 50);

}

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size,
                     long style) : wxFrame(NULL, wxID_ANY, title, pos, size, style){

    wxButton * buttonOne = new wxButton(this, wxID_ANY, _("Download"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);

    buttonOne->Bind(wxEVT_BUTTON, &MainFrame::buttonOneClicked, this);

    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_HELLO, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );

}

void MainFrame::OnExit(wxCommandEvent& event) {
    Close( true );
}

void MainFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox( "This is a wxWidgets' Hello world sample",
                  "About Hello World", wxOK | wxICON_INFORMATION );
}

void MainFrame::OnHello(wxCommandEvent& event) {
    wxLogMessage("Hello world from wxWidgets!");
}
