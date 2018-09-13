//
// Created by Francesco Gradi on 23/02/18.
//

#ifndef LOADINGBAR_FRAME_H
#define LOADINGBAR_FRAME_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/activityindicator.h>
#include <wx/statline.h>
#include <wx/gauge.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/animate.h>
#include <wx/progdlg.h>

#include "Observer.h"
#include "LoadingHandler.h"

class Frame : public wxDialog, public Observer {

protected:
    wxActivityIndicator* activityIndicator;
    wxStaticLine* line;
    wxGauge* gauge;
    wxButton* button1;
    wxButton* button2;
    LoadingHandler* loadingHandler;
    wxStaticText* staticText;
    wxFlexGridSizer* flexGridSizer;
    wxBoxSizer* boxSizer;

    bool isActive;

public:
    LoadingHandler *getLoadingHandler() const;

    void setLoadingHandler(LoadingHandler *loadingHandler);

    wxActivityIndicator* GetActivityIndicator() { return activityIndicator; }
    wxStaticLine* GetStaticLine() { return line; }
    wxGauge* GetGauge() { return gauge; }
    wxButton* GetButton1() { return button1; }
    wxButton* GetButton2() { return button2; }
    wxStaticText* GetStaticText() { return staticText; }
    wxFlexGridSizer* GetFlexGridSizer() { return flexGridSizer; }
    wxBoxSizer* getBoxSizer() const;
    bool getIsActive();

    Frame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Loading..."),
            const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500,300),
            long style = wxDEFAULT_DIALOG_STYLE);
    virtual ~Frame();

    void buttonCancelClicked(wxCommandEvent &event);
    void buttonStopClicked(wxCommandEvent &event);
    void buttonResumeClicked(wxCommandEvent &event);
    void OnExit(wxCommandEvent& event);

    bool update() override;

};



#endif //LOADINGBAR_FRAME_H
