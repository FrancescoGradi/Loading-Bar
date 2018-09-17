//
// Created by Francesco Gradi on 23/02/18.
//
#include <wx/wx.h>
#include <wx/wxprec.h>

#include <iostream>

#include "Frame.h"

Frame::Frame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
        : wxDialog(parent, id, title, pos, size, style) {

    boxSizer = new wxBoxSizer(wxVERTICAL_HATCH);
    this->SetSizer(boxSizer);

    activityIndicator = new wxActivityIndicator(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 4);

    boxSizer->Add(activityIndicator, 3, wxALL|wxEXPAND, 5);
    activityIndicator->Start();

    line = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), wxLI_HORIZONTAL);

    boxSizer->Add(line, 0, wxALL|wxEXPAND);

    gauge = new wxGauge(this, wxID_ANY, 100, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), wxGA_TEXT);
    gauge->SetValue(0);

    boxSizer->Add(gauge, 3, wxALL|wxEXPAND, 15);

    staticText = new wxStaticText(this, wxID_ANY, _("0 %"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    boxSizer->Add(staticText, 1, wxALL|wxALIGN_CENTER_VERTICAL);

    flexGridSizer = new wxFlexGridSizer(2, 2, 15, 15);
    flexGridSizer->SetFlexibleDirection( wxBOTH );
    flexGridSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

    boxSizer->Add(flexGridSizer, 2, wxALL|wxEXPAND, 10);

    button1 = new wxButton(this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    button1->Bind(wxEVT_BUTTON, &Frame::buttonCancelClicked, this);

    flexGridSizer->Add(button1, 4, wxALL|wxALIGN_LEFT);

    button2 = new wxButton(this, wxID_ANY, _("Stop"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    button2->Bind(wxEVT_BUTTON, &Frame::buttonStopClicked, this);

    flexGridSizer->Add(button2, 4, wxALL|wxALIGN_RIGHT);

    Bind(wxEVT_MENU, &Frame::OnExit, this, wxID_EXIT);

    SetName(wxT("Download"));
    SetSize(350,200);

    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }

    isActive = true;

}

Frame::~Frame() {
    loadingHandler->remove(this);
}

bool Frame::update() {
    if (loadingHandler != nullptr) {
        int state = loadingHandler->getState();

        if (state < 0) {
            state = 0;
        }

        if (state > 100) {
            state = 100;
        }

        gauge->SetValue(state);

        std::string s = std::to_string(state);
        staticText->SetLabel(s + " %");

        if (state == gauge->GetRange()) {
            activityIndicator->Destroy();
            button2->Destroy();
            button1->SetLabel("Finish");
        }

        wxYield();
        return isActive;
    }
    else
        return false;
}

LoadingHandler *Frame::getLoadingHandler() const {
    return Frame::loadingHandler;
}

void Frame::setLoadingHandler(LoadingHandler *loadingHandler) {
    Frame::loadingHandler = loadingHandler;
}

void Frame::OnExit(wxCommandEvent &event) {
    Close(true);
}

void Frame::buttonCancelClicked(wxCommandEvent &event) {

    isActive = false;
    Close(true);
}

void Frame::buttonStopClicked(wxCommandEvent &event) {

    isActive = false;
    activityIndicator->Stop();
    button2->SetLabel("Resume");
    button2->Bind(wxEVT_BUTTON, &Frame::buttonResumeClicked, this);
}

void Frame::buttonResumeClicked(wxCommandEvent &event) {

    isActive = true;

    activityIndicator->Start();

    button2->SetLabel("Stop");
    button2->Bind(wxEVT_BUTTON, &Frame::buttonStopClicked, this);

    loadingHandler->add(this);
    loadingHandler->download(loadingHandler->getState(), loadingHandler->getMsSpeed());
}

wxBoxSizer *Frame::getBoxSizer() const {
    return boxSizer;
}

bool Frame::getIsActive() {
    return isActive;
}
