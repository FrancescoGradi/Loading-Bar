//
// Created by Francesco Gradi on 08/09/18.
//

#ifndef LOADINGBAR_MAINFRAME_H
#define LOADINGBAR_MAINFRAME_H

#include <wx/wx.h>
#include <wx/frame.h>
#include "LoadingHandler.h"


class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size, long style = wxDEFAULT_FRAME_STYLE);

private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void buttonOneClicked(wxCommandEvent & event);

    wxDECLARE_EVENT_TABLE();

};


#endif //LOADINGBAR_MAINFRAME_H
