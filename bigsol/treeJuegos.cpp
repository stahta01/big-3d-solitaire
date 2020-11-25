/////////////////////////////////////////////////////////////////////////////
// Name:        treetest.cpp
// Purpose:     wxTreeCtrl sample
// Author:      Julian Smart
// Modified by:
// Created:     04/01/98
// RCS-ID:      $Id: treetest.cpp,v 1.110 2006/11/04 11:26:51 VZ Exp $
// Copyright:   (c) Julian Smart
// Licence:     wxWindows license
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "wx/image.h"
#include "wx/imaglist.h"
#include "wx/treectrl.h"
#include "wx/math.h"

#define USE_LOG		0
#include "40.h"
#include "treejuegos.h"

BEGIN_EVENT_TABLE(DialogoArbol, wxDialog)
    EVT_IDLE(DialogoArbol::OnIdle)
    EVT_SIZE(DialogoArbol::OnSize)
    EVT_CLOSE(DialogoArbol::OnCloseWindow)
    EVT_BUTTON(wxID_OK, DialogoArbol::CloseWindow)
    EVT_BUTTON(wxID_CANCEL, DialogoArbol::Abandonar)
END_EVENT_TABLE()

#if USE_GENERIC_TREECTRL
BEGIN_EVENT_TABLE(MyTreeCtrl, wxGenericTreeCtrl)
#else
BEGIN_EVENT_TABLE(MyTreeCtrl, wxTreeCtrl)
#endif
    EVT_LEFT_DOWN  (MyTreeCtrl::OnLMouseClick)
    EVT_LEFT_DCLICK(MyTreeCtrl::OnLMouseDClick)
END_EVENT_TABLE()

// My frame constructor
DialogoArbol::DialogoArbol(wxWindow* parent)
             : wxDialog(parent, wxID_ANY, _("Select game"), wxDefaultPosition, wxSize(225, 400)),m_treeCtrl(NULL)
{
    finalizado=false;
    //SetBackgroundColour(wxColour(255, 255, 255));
    //m_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, sz, 0);
    CreateTreeWithDefStyle();
    
    wxBoxSizer *button_sizer = new wxBoxSizer( wxVERTICAL );
    wxButton *button = new wxButton(this, wxID_OK);
	wxButton *buttonC = new wxButton(this, wxID_CANCEL);
	button_sizer->Add( button , 0, wxALL | wxEXPAND | wxALIGN_CENTER_VERTICAL, 10 );
    button_sizer->Add( buttonC, 0, wxALL | wxEXPAND | wxALIGN_CENTER_VERTICAL, 10 );
    
    wxBoxSizer *topsizer = new wxBoxSizer( wxHORIZONTAL );
    topsizer->Add( m_treeCtrl, 1, wxALL|wxGROW, 10 );
	topsizer->Add( button_sizer, 0, wxALIGN_LEFT );

    SetSizer( topsizer );

    m_treeCtrl->SetFocus();
    SetSizer( topsizer );
    GetSizer()->Fit(this);
    GetSizer()->SetSizeHints(this);
    CentreOnParent();
}

DialogoArbol::~DialogoArbol(){
}

void DialogoArbol::OnCloseWindow(wxCloseEvent& WXUNUSED(event)){
    EndModal(wxID_OK);
}

void DialogoArbol::CloseWindow(wxCommandEvent& WXUNUSED(event)){
	//event.Skip();
	if(m_treeCtrl && m_treeCtrl->seleccionado != NULL && !finalizado){
		long l;
		wxString *s=new wxString(m_treeCtrl->seleccionado->GetDesc(),4);
		bool res=s->ToLong(&l,10);
		if(res){
			finalizado=true;
			EndModal((int)l);
		}else{
			m_treeCtrl->seleccionado=NULL;
		}
	}
    //EndModal(wxID_OK);
}

void DialogoArbol::Abandonar(wxCommandEvent& WXUNUSED(event)){
	EndModal(wxID_CANCEL);
}

void DialogoArbol::CreateTreeWithDefStyle()
{
    long style = wxTR_DEFAULT_STYLE | wxTR_HIDE_ROOT |
#ifndef NO_VARIABLE_HEIGHT
                 wxTR_HAS_VARIABLE_ROW_HEIGHT
#endif
                 ;// | wxTR_EDIT_LABELS;

    CreateTree(style | wxSUNKEN_BORDER);
}

void DialogoArbol::CreateTree(long style){
	sz = wxSize(225, 400);
    m_treeCtrl = new MyTreeCtrl(this, TreeTest_Ctrl, wxDefaultPosition, sz, style);
    //m_treeCtrl->ExpandAll();
    //Resize();
}


void DialogoArbol::OnIdle(wxIdleEvent& event){
	event.Skip();
	if(m_treeCtrl && m_treeCtrl->dobleclick && m_treeCtrl->seleccionado != NULL && !finalizado){
		long l;
		wxString *s=new wxString(m_treeCtrl->seleccionado->GetDesc(),4);
		bool res=s->ToLong(&l,10);
		if(res){
			finalizado=true;
			EndModal((int)l);
		}else{
			m_treeCtrl->seleccionado=NULL;
		}
	}
}

void DialogoArbol::OnSize(wxSizeEvent& event)
{
    if( m_treeCtrl){
        Resize();
    }
    event.Skip();
}

void DialogoArbol::Resize()
{
    wxSize size = GetClientSize();
    m_treeCtrl->SetSize(0, 0, size.x, size.y);
    //m_textCtrl->SetSize(0, 2*size.y/3, size.x, size.y/3);
}

// MyTreeCtrl implementation
#if USE_GENERIC_TREECTRL
IMPLEMENT_DYNAMIC_CLASS(MyTreeCtrl, wxGenericTreeCtrl)
#else
IMPLEMENT_DYNAMIC_CLASS(MyTreeCtrl, wxTreeCtrl)
#endif

MyTreeCtrl::MyTreeCtrl(wxWindow *parent, const wxWindowID id,
                       const wxPoint& pos, const wxSize& size,
                       long style)
          : wxTreeCtrl(parent, id, pos, size, style)
{
	seleccionado=NULL;
	dobleclick=false;
	padre=parent;
    AddJuegos();
}

void MyTreeCtrl::AddJuegos() {
    SetIndent(5);
    SetSpacing(15);
    wxTreeItemId rootId = AddRoot(wxT("Games by category"),-1,-1,new MyTreeItemData(wxT("Games")));
    
    wxTreeItemId candCtg = AppendItem(rootId, _T("Canfield"), -1,-1,new MyTreeItemData(wxT("candCtg")));
	wxTreeItemId can = AppendItem(candCtg, _T("Canfield"), -1, -1,new MyTreeItemData(wxT("7000")));
	wxTreeItemId can2 = AppendItem(candCtg, _T("Canfield Two Decks"), -1, -1,new MyTreeItemData(wxT("7001")));
	wxTreeItemId cansup = AppendItem(candCtg, _T("Canfield Superior"), -1, -1,new MyTreeItemData(wxT("7002")));
    
	wxTreeItemId doubCtg = AppendItem(rootId, _T("Doubles"), -1,-1,new MyTreeItemData(wxT("doubCtg")));
	wxTreeItemId doubles = AppendItem(doubCtg, _T("Doubles"), -1, -1,new MyTreeItemData(wxT("7004")));
	wxTreeItemId doubles13 = AppendItem(doubCtg, _T("Doubles 13"), -1, -1,new MyTreeItemData(wxT("7005")));
	
	wxTreeItemId fortCtg = AppendItem(rootId, _T("Forty Thieves"), -1,-1,new MyTreeItemData(wxT("fortCat")));
	wxTreeItemId corona  = AppendItem(fortCtg, _T("Corona"), -1, -1,new MyTreeItemData(wxT("7003")));
	wxTreeItemId forty   = AppendItem(fortCtg, _T("Forty Thieves"), -1, -1,new MyTreeItemData(wxT("7008")));
	wxTreeItemId forty3  = AppendItem(fortCtg, _T("Forty Thieves Three Decks"), -1, -1,new MyTreeItemData(wxT("7010")));
	wxTreeItemId forty4  = AppendItem(fortCtg, _T("Forty Thieves Four Decks"), -1, -1,new MyTreeItemData(wxT("7011")));
	wxTreeItemId forty8  = AppendItem(fortCtg, _T("Forty and Eight"), -1, -1,new MyTreeItemData(wxT("7009")));
	wxTreeItemId indian  = AppendItem(fortCtg, _T("Indian"), -1, -1,new MyTreeItemData(wxT("7017")));
	wxTreeItemId zfour   = AppendItem(fortCtg, _T("Z-four"), -1, -1,new MyTreeItemData(wxT("7039")));

	wxTreeItemId freeCtg = AppendItem(rootId, _T("Freecell"), -1,-1,new MyTreeItemData(wxT("freeCtg")));
	wxTreeItemId east    = AppendItem(freeCtg, _T("Easthaven"), -1, -1,new MyTreeItemData(wxT("7006")));
	wxTreeItemId emperor = AppendItem(freeCtg, _T("Emperor"), -1, -1,new MyTreeItemData(wxT("7007")));
	wxTreeItemId free    = AppendItem(freeCtg, _T("Freecell"), -1, -1,new MyTreeItemData(wxT("7012")));
	wxTreeItemId free2   = AppendItem(freeCtg, _T("Freecell Two Decks"), -1, -1,new MyTreeItemData(wxT("7013")));
	wxTreeItemId ocean   = AppendItem(freeCtg, _T("Ocean's Eleven"), -1, -1,new MyTreeItemData(wxT("7022")));
	wxTreeItemId tow     = AppendItem(freeCtg, _T("Towers"), -1, -1,new MyTreeItemData(wxT("7036")));
	
	wxTreeItemId golfCtg = AppendItem(rootId, _T("Golf"), -1,-1,new MyTreeItemData(wxT("golfCtg")));
	wxTreeItemId golf    = AppendItem(golfCtg, _T("Golf"), -1, -1,new MyTreeItemData(wxT("7014")));
	wxTreeItemId golfAK  = AppendItem(golfCtg, _T("Golf A-K"), -1, -1,new MyTreeItemData(wxT("7015")));
	wxTreeItemId golfAK2 = AppendItem(golfCtg, _T("Golf A-K Two Decks"), -1, -1,new MyTreeItemData(wxT("7016")));
	
	wxTreeItemId klonCtg = AppendItem(rootId, _T("Klondike"), -1, -1,new MyTreeItemData(wxT("klonCtg")));
	wxTreeItemId klondike= AppendItem(klonCtg, _T("Klondike one card"), -1, -1,new MyTreeItemData(wxT("7018")));
	wxTreeItemId klondike3= AppendItem(klonCtg, _T("Klondike three cards"), -1, -1,new MyTreeItemData(wxT("7040")));
	wxTreeItemId klondike2= AppendItem(klonCtg, _T("Klondike Two Decks"), -1, -1,new MyTreeItemData(wxT("7019")));
	wxTreeItemId lucky    = AppendItem(klonCtg, _T("Lucky Fans"), -1, -1,new MyTreeItemData(wxT("7020")));
		
	wxTreeItemId montCtg = AppendItem(rootId, _T("Montana"), -1, -1,new MyTreeItemData(wxT("montCtg")));
	wxTreeItemId montana = AppendItem(montCtg, _T("Montana Three Redeals"), -1, -1,new MyTreeItemData(wxT("7021")));
	
	wxTreeItemId railCtg = AppendItem(rootId, _T("Rail"), -1, -1,new MyTreeItemData(wxT("railCtg")));
	wxTreeItemId rail    = AppendItem(railCtg, _T("Rail"), -1, -1,new MyTreeItemData(wxT("7023")));
	wxTreeItemId rail2   = AppendItem(railCtg, _T("Rail Two Decks"), -1, -1,new MyTreeItemData(wxT("7024")));
	
	wxTreeItemId spidCtg = AppendItem(rootId, _T("Spider"), -1, -1,new MyTreeItemData(wxT("spidCtg")));
	wxTreeItemId scarab   = AppendItem(spidCtg, _T("Scarab"), -1, -1,new MyTreeItemData(wxT("7027")));
	wxTreeItemId simple   = AppendItem(spidCtg, _T("Simple Simon"), -1, -1,new MyTreeItemData(wxT("7029")));
	wxTreeItemId spider = AppendItem(spidCtg, _T("Spider"), -1, -1,new MyTreeItemData(wxT("7030")));
	wxTreeItemId spider1 = AppendItem(spidCtg, _T("Spider One Suite"), -1, -1,new MyTreeItemData(wxT("7031")));
	wxTreeItemId spider2 = AppendItem(spidCtg, _T("Spider Two Suites"), -1, -1,new MyTreeItemData(wxT("7032")));
	wxTreeItemId spider3 = AppendItem(spidCtg, _T("Spider Three Decks"), -1, -1,new MyTreeItemData(wxT("7033")));
	wxTreeItemId spiderT = AppendItem(spidCtg, _T("Spiderette"), -1, -1,new MyTreeItemData(wxT("7034")));
	wxTreeItemId spiderTR = AppendItem(spidCtg, _T("Spiderette Relaxed"), -1, -1,new MyTreeItemData(wxT("7035")));
	
	wxTreeItemId yukoCtg = AppendItem(rootId, _T("Yukon"), -1, -1,new MyTreeItemData(wxT("yukoCtg")));
	wxTreeItemId scor = AppendItem(yukoCtg, _T("Scorpion"), -1, -1,new MyTreeItemData(wxT("7028")));
	wxTreeItemId russ = AppendItem(yukoCtg, _T("Russian"), -1, -1,new MyTreeItemData(wxT("7025")));
	wxTreeItemId russR = AppendItem(yukoCtg, _T("Russian Relaxed"), -1, -1,new MyTreeItemData(wxT("7026")));
	wxTreeItemId yuk   = AppendItem(yukoCtg, _T("Yukon"), -1, -1,new MyTreeItemData(wxT("7037")));
	wxTreeItemId yukR = AppendItem(yukoCtg, _T("Yukon Relaxed"), -1, -1,new MyTreeItemData(wxT("7038")));
	
    SetItemBold(rootId,true);
    SetItemBold(doubCtg, true);
    SetItemBold(fortCtg, true);
    SetItemBold(freeCtg, true);
    SetItemBold(golfCtg, true);
    SetItemBold(klonCtg, true);
    SetItemBold(montCtg, true);
    SetItemBold(spidCtg, true);
    SetItemBold(candCtg, true);
    SetItemBold(railCtg, true);
    SetItemBold(yukoCtg, true);
    
    wxFont *font1=new wxFont();
    font1 = wxTheFontList->FindOrCreateFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    wxFont *font2=new wxFont();
    font2 = wxTheFontList->FindOrCreateFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    SetItemFont(candCtg, *font2);
    SetItemFont(doubCtg, *font2);
    SetItemFont(fortCtg, *font2);
    SetItemFont(freeCtg, *font2);
    SetItemFont(golfCtg, *font2);
    SetItemFont(klonCtg, *font2);
    SetItemFont(montCtg, *font2);
    SetItemFont(spidCtg, *font2);
    SetItemFont(railCtg, *font2);
    SetItemFont(yukoCtg, *font2);
    
    SetItemFont(can, *font1);
    SetItemFont(can2, *font1);
    SetItemFont(cansup, *font1);
    SetItemFont(doubles, *font1);
    SetItemFont(doubles13, *font1);
    SetItemFont(forty, *font1);
    SetItemFont(forty3, *font1);
    SetItemFont(forty4, *font1);
    SetItemFont(forty8, *font1);
    SetItemFont(corona, *font1);
    SetItemFont(indian, *font1);
    SetItemFont(zfour, *font1);
    SetItemFont(east, *font1);
    SetItemFont(free, *font1);
    SetItemFont(free2, *font1);
    SetItemFont(emperor, *font1);
    SetItemFont(ocean, *font1);
    SetItemFont(tow, *font1);
    SetItemFont(golf, *font1);
    SetItemFont(golfAK, *font1);
    SetItemFont(golfAK2, *font1);
    SetItemFont(klondike, *font1);
    SetItemFont(klondike2, *font1);
    SetItemFont(lucky, *font1);
    SetItemFont(montana, *font1);
    SetItemFont(rail, *font1);
    SetItemFont(rail2, *font1);
    SetItemFont(spider, *font1);
    SetItemFont(spider1, *font1);
    SetItemFont(spider2, *font1);
    SetItemFont(spider3, *font1);
    SetItemFont(spiderT, *font1);
    SetItemFont(spiderTR, *font1);
    SetItemFont(scarab, *font1);
    SetItemFont(simple, *font1);
    SetItemFont(scor, *font1);
    SetItemFont(russ, *font1);
    SetItemFont(russR, *font1);
    SetItemFont(yuk, *font1);
    SetItemFont(yukR, *font1);
    //id = GetNextChild(rootId, cookie);
    //SetItemTextColour(id, *wxRED);
    //SetItemBackgroundColour(id, *wxLIGHT_GREY);
}

void MyTreeCtrl::LogEvent(const wxChar *name, const wxTreeEvent& event){
    //wxTreeItemId item = event.GetItem();
    //wxString text;
    //if ( item.IsOk() )
    //    text << _T('"') << GetItemText(item).c_str() << _T('"');
    //else
    //    text = _T("invalid item");
    //wxLogMessage(wxT("%s(%s)"), name, text.c_str());
}

#define TREE_EVENT_HANDLER(name)                                 \
void MyTreeCtrl::name(wxTreeEvent& event)                        \
{                                                                \
    LogEvent(_T(#name), event);                                  \
    SetLastItem(wxTreeItemId());                                 \
    event.Skip();                                                \
}
#undef TREE_EVENT_HANDLER

void LogKeyEvent(const wxChar *name, const wxKeyEvent& event)
{
    wxString key;
    long keycode = event.GetKeyCode();
    {
        switch ( keycode ){
            case WXK_BACK: key = wxT("BACK"); break;
            case WXK_TAB: key = wxT("TAB"); break;
            case WXK_RETURN: 
            	key = wxT("RETURN");
            	printf("Hemos pulsado RETUNR"); 
            break;
            case WXK_ESCAPE: key = wxT("ESCAPE"); break;
            case WXK_SPACE: key = wxT("SPACE"); break;
            case WXK_DELETE: key = wxT("DELETE"); break;
            case WXK_START: key = wxT("START"); break;
            case WXK_LBUTTON: key = wxT("LBUTTON"); break;
            case WXK_RBUTTON: key = wxT("RBUTTON"); break;
            case WXK_CANCEL: key = wxT("CANCEL"); break;
            case WXK_MBUTTON: key = wxT("MBUTTON"); break;
            case WXK_CLEAR: key = wxT("CLEAR"); break;
            case WXK_SHIFT: key = wxT("SHIFT"); break;
            case WXK_ALT: key = wxT("ALT"); break;
            case WXK_CONTROL: key = wxT("CONTROL"); break;
            case WXK_MENU: key = wxT("MENU"); break;
            case WXK_PAUSE: key = wxT("PAUSE"); break;
            case WXK_CAPITAL: key = wxT("CAPITAL"); break;
            case WXK_END: key = wxT("END"); break;
            case WXK_HOME: key = wxT("HOME"); break;
            case WXK_LEFT: key = wxT("LEFT"); break;
            case WXK_UP: key = wxT("UP"); break;
            case WXK_RIGHT: key = wxT("RIGHT"); break;
            case WXK_DOWN: key = wxT("DOWN"); break;
            case WXK_SELECT: key = wxT("SELECT"); break;
            case WXK_PRINT: key = wxT("PRINT"); break;
            case WXK_EXECUTE: key = wxT("EXECUTE"); break;
            case WXK_SNAPSHOT: key = wxT("SNAPSHOT"); break;
            case WXK_INSERT: key = wxT("INSERT"); break;
            case WXK_HELP: key = wxT("HELP"); break;
            case WXK_NUMPAD0: key = wxT("NUMPAD0"); break;
            case WXK_NUMPAD1: key = wxT("NUMPAD1"); break;
            case WXK_NUMPAD2: key = wxT("NUMPAD2"); break;
            case WXK_NUMPAD3: key = wxT("NUMPAD3"); break;
            case WXK_NUMPAD4: key = wxT("NUMPAD4"); break;
            case WXK_NUMPAD5: key = wxT("NUMPAD5"); break;
            case WXK_NUMPAD6: key = wxT("NUMPAD6"); break;
            case WXK_NUMPAD7: key = wxT("NUMPAD7"); break;
            case WXK_NUMPAD8: key = wxT("NUMPAD8"); break;
            case WXK_NUMPAD9: key = wxT("NUMPAD9"); break;
            case WXK_MULTIPLY: key = wxT("MULTIPLY"); break;
            case WXK_ADD: key = wxT("ADD"); break;
            case WXK_SEPARATOR: key = wxT("SEPARATOR"); break;
            case WXK_SUBTRACT: key = wxT("SUBTRACT"); break;
            case WXK_DECIMAL: key = wxT("DECIMAL"); break;
            case WXK_DIVIDE: key = wxT("DIVIDE"); break;
            case WXK_F1: key = wxT("F1"); break;
            case WXK_F2: key = wxT("F2"); break;
            case WXK_F3: key = wxT("F3"); break;
            case WXK_F4: key = wxT("F4"); break;
            case WXK_F5: key = wxT("F5"); break;
            case WXK_F6: key = wxT("F6"); break;
            case WXK_F7: key = wxT("F7"); break;
            case WXK_F8: key = wxT("F8"); break;
            case WXK_F9: key = wxT("F9"); break;
            case WXK_F10: key = wxT("F10"); break;
            case WXK_F11: key = wxT("F11"); break;
            case WXK_F12: key = wxT("F12"); break;
            case WXK_F13: key = wxT("F13"); break;
            case WXK_F14: key = wxT("F14"); break;
            case WXK_F15: key = wxT("F15"); break;
            case WXK_F16: key = wxT("F16"); break;
            case WXK_F17: key = wxT("F17"); break;
            case WXK_F18: key = wxT("F18"); break;
            case WXK_F19: key = wxT("F19"); break;
            case WXK_F20: key = wxT("F20"); break;
            case WXK_F21: key = wxT("F21"); break;
            case WXK_F22: key = wxT("F22"); break;
            case WXK_F23: key = wxT("F23"); break;
            case WXK_F24: key = wxT("F24"); break;
            case WXK_NUMLOCK: key = wxT("NUMLOCK"); break;
            case WXK_SCROLL: key = wxT("SCROLL"); break;
            case WXK_PAGEUP: key = wxT("PAGEUP"); break;
            case WXK_PAGEDOWN: key = wxT("PAGEDOWN"); break;
            case WXK_NUMPAD_SPACE: key = wxT("NUMPAD_SPACE"); break;
            case WXK_NUMPAD_TAB: key = wxT("NUMPAD_TAB"); break;
            case WXK_NUMPAD_ENTER: key = wxT("NUMPAD_ENTER"); break;
            case WXK_NUMPAD_F1: key = wxT("NUMPAD_F1"); break;
            case WXK_NUMPAD_F2: key = wxT("NUMPAD_F2"); break;
            case WXK_NUMPAD_F3: key = wxT("NUMPAD_F3"); break;
            case WXK_NUMPAD_F4: key = wxT("NUMPAD_F4"); break;
            case WXK_NUMPAD_HOME: key = wxT("NUMPAD_HOME"); break;
            case WXK_NUMPAD_LEFT: key = wxT("NUMPAD_LEFT"); break;
            case WXK_NUMPAD_UP: key = wxT("NUMPAD_UP"); break;
            case WXK_NUMPAD_RIGHT: key = wxT("NUMPAD_RIGHT"); break;
            case WXK_NUMPAD_DOWN: key = wxT("NUMPAD_DOWN"); break;
            case WXK_NUMPAD_PAGEUP: key = wxT("NUMPAD_PAGEUP"); break;
            case WXK_NUMPAD_PAGEDOWN: key = wxT("NUMPAD_PAGEDOWN"); break;
            case WXK_NUMPAD_END: key = wxT("NUMPAD_END"); break;
            case WXK_NUMPAD_BEGIN: key = wxT("NUMPAD_BEGIN"); break;
            case WXK_NUMPAD_INSERT: key = wxT("NUMPAD_INSERT"); break;
            case WXK_NUMPAD_DELETE: key = wxT("NUMPAD_DELETE"); break;
            case WXK_NUMPAD_EQUAL: key = wxT("NUMPAD_EQUAL"); break;
            case WXK_NUMPAD_MULTIPLY: key = wxT("NUMPAD_MULTIPLY"); break;
            case WXK_NUMPAD_ADD: key = wxT("NUMPAD_ADD"); break;
            case WXK_NUMPAD_SEPARATOR: key = wxT("NUMPAD_SEPARATOR"); break;
            case WXK_NUMPAD_SUBTRACT: key = wxT("NUMPAD_SUBTRACT"); break;
            case WXK_NUMPAD_DECIMAL: key = wxT("NUMPAD_DECIMAL"); break;

            default:
            {
               if ( keycode < 128 && wxIsprint((int)keycode) )
                   key.Printf(wxT("'%c'"), (char)keycode);
               else if ( keycode > 0 && keycode < 27 )
                   key.Printf(_("Ctrl-%c"), wxT('A') + keycode - 1);
               else
                   key.Printf(wxT("unknown (%ld)"), keycode);
            }
        }
    }
}

void MyTreeCtrl::OnLMouseDClick(wxMouseEvent& event){
	dobleclick=true;
	MyTreeItemData *item=NULL;
    wxTreeItemId id = HitTest(event.GetPosition());
    if ( !id ){
        //wxLogMessage(wxT("No item under mouse"));
    }else{
        item = (MyTreeItemData *)GetItemData(id);
        if ( item ){
           //wxLogMessage(wxT("Item LEFT '%s' under mouse"), item->GetDesc());
        }
    }
    seleccionado=item;
    event.Skip();
}

void MyTreeCtrl::OnLMouseClick(wxMouseEvent& event){
	dobleclick=false;
	MyTreeItemData *item=NULL;
    wxTreeItemId id = HitTest(event.GetPosition());
    if ( !id ){
        //wxLogMessage(wxT("No item under mouse"));
    }else{
        item = (MyTreeItemData *)GetItemData(id);
        if ( item ){
           //wxLogMessage(wxT("Item LEFT '%s' under mouse"), item->GetDesc());
        }
    }
    seleccionado=item;
    event.Skip();
}

static inline const wxChar *Bool2String(bool b){
    return b ? wxT("") : wxT("not ");
}
