//
// Created by Francesco Gradi on 08/09/18.
//

#include "Frame.h"
#include "LoadingHandler.h"
#include "MainFrame.h"


#include <wx/wx.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <iostream>

enum {
    ID_HELLO = 1
};

void MainFrame::buttonSlowClicked(wxCommandEvent &event) {

    Frame *frame = new Frame(this);

    frame->Show(true);

    LoadingHandler* loadingHandler = new LoadingHandler();

    loadingHandler->add(frame);
    frame->setLoadingHandler(loadingHandler);

    loadingHandler->download(0, 150);

}


void MainFrame::buttonNormalClicked(wxCommandEvent &event) {

    Frame *frame = new Frame(this);

    frame->Show(true);

    LoadingHandler* loadingHandler = new LoadingHandler();

    loadingHandler->add(frame);
    frame->setLoadingHandler(loadingHandler);

    loadingHandler->download(0, 100);

}

void MainFrame::buttonFastClicked(wxCommandEvent &event) {

    Frame *frame = new Frame(this);

    frame->Show(true);

    LoadingHandler* loadingHandler = new LoadingHandler();

    loadingHandler->add(frame);
    frame->setLoadingHandler(loadingHandler);

    loadingHandler->download(0, 50);

}

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size,
                     long style) : wxFrame(NULL, wxID_ANY, title, pos, size, style) {

    wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer);

    boxSizer->Add(0, 0, 1, wxALL, 5);

    wxFlexGridSizer* gridSizerSlow = new wxFlexGridSizer(0, 2, 0, 15);
    gridSizerSlow->SetFlexibleDirection( wxBOTH );
    gridSizerSlow->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

    boxSizer->Add(gridSizerSlow);

    wxButton* buttonSlow = new wxButton(this, wxID_ANY, _("Download"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    gridSizerSlow->Add(buttonSlow, 4, wxALIGN_LEFT);
    buttonSlow->Bind(wxEVT_BUTTON, &MainFrame::buttonSlowClicked, this);

    wxStaticText* textSlow = new wxStaticText(this, wxID_ANY, _("Click on the button for the slow download."), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    gridSizerSlow->Add(textSlow, 3, wxALIGN_RIGHT|wxEXPAND, 4);


    boxSizer->Add(0, 0, 1, wxALL, 5);

    wxStaticLine* staticLine1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), wxLI_HORIZONTAL);
    boxSizer->Add(staticLine1, 0, wxALL|wxEXPAND);

    boxSizer->Add(0, 0, 1, wxALL, 5);


    wxFlexGridSizer* gridSizerNormal = new wxFlexGridSizer(0, 2, 35, 15);
    gridSizerNormal->SetFlexibleDirection( wxBOTH );
    gridSizerNormal->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

    boxSizer->Add(gridSizerNormal);

    wxButton* buttonNormal = new wxButton(this, wxID_ANY, _("Download"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    gridSizerNormal->Add(buttonNormal, 1, wxALIGN_CENTER, 4);
    buttonNormal->Bind(wxEVT_BUTTON, &MainFrame::buttonNormalClicked, this);

    wxStaticText* textNormal = new wxStaticText(this, wxID_ANY, _("Click on the button for the normal download."), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    gridSizerNormal->Add(textNormal, 1, wxALIGN_RIGHT|wxEXPAND, 4);

    boxSizer->Add(0, 0, 1, wxALL, 5);

    wxStaticLine* staticLine2 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), wxLI_HORIZONTAL);
    boxSizer->Add(staticLine2, 0, wxALL|wxEXPAND);

    boxSizer->Add(0, 0, 1, wxALL, 5);


    wxFlexGridSizer* gridSizerFast = new wxFlexGridSizer(0, 2, 35, 15);
    gridSizerFast->SetFlexibleDirection( wxBOTH );
    gridSizerFast->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

    boxSizer->Add(gridSizerFast);

    wxButton* buttonFast = new wxButton(this, wxID_ANY, _("Download"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    gridSizerFast->Add(buttonFast, 1, wxALIGN_LEFT, 4);
    buttonFast->Bind(wxEVT_BUTTON, &MainFrame::buttonFastClicked, this);

    wxStaticText* textFast = new wxStaticText(this, wxID_ANY, _("Click on the button for the fast download."), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    gridSizerFast->Add(textFast, 1, wxALIGN_RIGHT|wxEXPAND, 4);

    boxSizer->Add(0, 0, 1, wxALL, 5);


    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_HELLO, "&Hello...\tCtrl-H",
                     "Loading");
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
    wxMessageBox( "Choose your download",
                  "About Loading Bar", wxOK | wxICON_INFORMATION );
}

void MainFrame::OnHello(wxCommandEvent& event) {
    wxLogMessage("Loading bar");
}
