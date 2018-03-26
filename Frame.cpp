//
// Created by Francesco Gradi on 23/02/18.
//
#include <wx/wx.h>
#include <iostream>

#include "Frame.h"

Frame::Frame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
        : wxDialog(parent, id, title, pos, size, style) {

    wxBoxSizer* boxSizer11 = new wxBoxSizer(wxVERTICAL_HATCH);
    this->SetSizer(boxSizer11);

    m_activityCtrl29 = new wxActivityIndicator(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 4);

    boxSizer11->Add(m_activityCtrl29, 3, wxALL|wxEXPAND, 5);
    m_activityCtrl29->Start();

    m_staticLine17 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), wxLI_HORIZONTAL);

    boxSizer11->Add(m_staticLine17, 0, wxALL|wxEXPAND);

    m_gauge15 = new wxGauge(this, wxID_ANY, 100, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), wxGA_TEXT);
    m_gauge15->SetValue(0);

    boxSizer11->Add(m_gauge15, 3, wxALL|wxEXPAND, 15);

    m_staticText37 = new wxStaticText(this, wxID_ANY, _("0 %"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    boxSizer11->Add(m_staticText37, 1, wxALL|wxALIGN_CENTER_VERTICAL);

    wxFlexGridSizer* flexGridSizer23 = new wxFlexGridSizer(2, 2, 15, 15);
    flexGridSizer23->SetFlexibleDirection( wxBOTH );
    flexGridSizer23->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

    boxSizer11->Add(flexGridSizer23, 2, wxALL|wxEXPAND, 10);

    m_button25 = new wxButton(this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);

    flexGridSizer23->Add(m_button25, 4, wxALL|wxALIGN_LEFT);

    m_button27 = new wxButton(this, wxID_ANY, _("Info"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);

    flexGridSizer23->Add(m_button27, 4, wxALL|wxALIGN_RIGHT);

    SetName(wxT("wxFrame"));
    SetSize(300,250);

    if (GetSizer()) {
        GetSizer()->Fit(this);
    }

    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }

}

Frame::~Frame() {

}

void Frame::update() {
    if (loadingHandler != nullptr) {
        int state = loadingHandler->getState();
        m_gauge15->SetValue(state);

        std::string s = std::to_string(state);
        m_staticText37->SetLabel(s + " %");

        if (state == m_gauge15->GetRange()) {
            m_activityCtrl29->Destroy();
        }

        wxYield();
    }
}

LoadingHandler *Frame::getLoadingHandler() const {
    return loadingHandler;
}

void Frame::setLoadingHandler(LoadingHandler *loadingHandler) {
    Frame::loadingHandler = loadingHandler;
}
