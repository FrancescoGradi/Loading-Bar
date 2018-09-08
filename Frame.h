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
    wxActivityIndicator* m_activityCtrl29;
    wxStaticLine* m_staticLine17;
    wxGauge* m_gauge15;
    wxButton* m_button25;
    wxButton* m_button27;
    LoadingHandler* loadingHandler;
    wxStaticText* m_staticText37;
    wxFlexGridSizer* flexGridSizer23;
    wxBoxSizer* boxSizer11;

    bool isActive;

    void buttonCancelClicked(wxCommandEvent &event);
    void buttonStopClicked(wxCommandEvent &event);
    void buttonResumeClicked(wxCommandEvent &event);
    void OnExit(wxCommandEvent& event);

public:
    LoadingHandler *getLoadingHandler() const;

    void setLoadingHandler(LoadingHandler *loadingHandler);

    wxActivityIndicator* GetActivityCtrl29() { return m_activityCtrl29; }
    wxStaticLine* GetStaticLine17() { return m_staticLine17; }
    wxGauge* GetGauge15() { return m_gauge15; }
    wxButton* GetButton25() { return m_button25; }
    wxButton* GetButton27() { return m_button27; }
    wxStaticText* GetStaticText37() { return m_staticText37; }
    wxFlexGridSizer* GetFlexGridSizer23() { return flexGridSizer23; }
    wxBoxSizer *getBoxSizer11() const;

    Frame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Loading..."),
            const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500,300),
            long style = wxDEFAULT_DIALOG_STYLE);
    virtual ~Frame();

    bool update() override;
};



#endif //LOADINGBAR_FRAME_H
