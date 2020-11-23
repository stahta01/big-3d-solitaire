#ifndef _COLORES_H_
#define _COLORES_H_

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
