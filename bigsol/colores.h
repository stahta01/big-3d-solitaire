#ifndef COLORES_H_INCLUDED
#define COLORES_H_INCLUDED

#include <wx/dialog.h>

class ColoresDialog : public wxDialog{
public:
    wxString m_color;
    
    ColoresDialog(wxWindow* parent);
    virtual ~ColoresDialog(){};

    const wxString& GetPlayersName();
    void OnSize(wxSizeEvent& event);

    DECLARE_EVENT_TABLE()

protected:
    void OnCloseWindow(wxCloseEvent& event);
    void CloseWindow(wxCommandEvent& event);
    void abandonar(wxCommandEvent& event);
    void SetColor(wxCommandEvent& event);

private:
    wxButton* m_OK;
    wxButton* m_cancel;
};
#endif
