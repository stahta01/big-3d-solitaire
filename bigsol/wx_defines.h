/***************************************************************
 * Name:      wx_defines.h
 * Purpose:   Defines used by wxWidgets 
 **************************************************************/

#ifndef WX_DEFINES_H_INCLUDED
#define WX_DEFINES_H_INCLUDED

#if !defined(wxDEBUG_LEVEL)
# ifdef NDEBUG
#   define wxDEBUG_LEVEL 0
# else
#   define wxDEBUG_LEVEL 2
# endif
#endif // !defined(wxDEBUG_LEVEL)

#endif // WX_DEFINES_H_INCLUDED
