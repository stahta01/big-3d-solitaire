/////////////////////////////////////////////////////////////////////////////
// Name:        treectrl.h
// Purpose:     wxTreeCtrl sample
// Author:      Julian Smart
// Modified by:
// Created:     04/01/98
// RCS-ID:      $Id: treetest.h,v 1.50 2006/11/04 11:26:51 VZ Exp $
// Copyright:   (c) Julian Smart
// Licence:     wxWindows license
/////////////////////////////////////////////////////////////////////////////

#define USE_GENERIC_TREECTRL 0

#if USE_GENERIC_TREECTRL
#include "wx/generic/treectlg.h"
#ifndef wxTreeCtrl
#define wxTreeCtrl wxGenericTreeCtrl
#define sm_classwxTreeCtrl sm_classwxGenericTreeCtrl
#endif
#endif
#include "wx/image.h"
#include "wx/imaglist.h"
#include "wx/treectrl.h"
#include "wx/math.h"

class MyTreeItemData : public wxTreeItemData
{
public:
    MyTreeItemData(const wxString& desc) : m_desc(desc) { }
    const wxChar *GetDesc() const { return m_desc.c_str(); }

private:
    wxString m_desc;
};

class MyTreeCtrl : public wxTreeCtrl
{
public:
	wxWindow *padre;
	MyTreeItemData *seleccionado;
	bool dobleclick;
    enum{
        TreeCtrlIcon_File,
        TreeCtrlIcon_FileSelected,
        TreeCtrlIcon_Folder,
        TreeCtrlIcon_FolderSelected,
        TreeCtrlIcon_FolderOpened
    };

    MyTreeCtrl() { }
    MyTreeCtrl(wxWindow *parent, const wxWindowID id,
               const wxPoint& pos, const wxSize& size,
               long style);
    virtual ~MyTreeCtrl(){};

    void OnSelChanged(wxTreeEvent& event);
    void OnSelChanging(wxTreeEvent& event);
    void OnLMouseDClick(wxMouseEvent& event);
    void OnLMouseClick(wxMouseEvent& event);
    void AddJuegos();

protected:

    // is this the test item which we use in several event handlers?
    bool IsTestItem(const wxTreeItemId& item){
        // the test item is the first child folder
        return GetItemParent(item) == GetRootItem() && !GetPrevSibling(item);
    }

private:
    void LogEvent(const wxChar *name, const wxTreeEvent& event);
    DECLARE_DYNAMIC_CLASS(MyTreeCtrl)
    DECLARE_EVENT_TABLE()
};

// Define a new dialog
class DialogoArbol: public wxDialog{
public:
    // ctor and dtor
    DialogoArbol(wxWindow* parent);
    virtual ~DialogoArbol();
    void OnIdle(wxIdleEvent& event);
    void OnSize(wxSizeEvent& event);
    bool finalizado;
    MyTreeCtrl *m_treeCtrl;
    
protected:
	void OnCloseWindow(wxCloseEvent& event);
	void CloseWindow(wxCommandEvent& event);
    void Abandonar(wxCommandEvent& event);
    
private:
    void Resize();
    void CreateTreeWithDefStyle();
    void CreateTree(long style);

	wxSize sz;
	wxButton* m_OK;
	wxButton* m_CANCEL;
    wxBoxSizer *box;
    DECLARE_EVENT_TABLE()
};

enum{
    TreeTest_Recreate,
    TreeTest_Ctrl = 1000
};

