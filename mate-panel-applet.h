#ifndef MATE_INDICATOR_APPLET_COMPAT_MATE_PANEL_APPLET_H
#define MATE_INDICATOR_APPLET_COMPAT_MATE_PANEL_APPLET_H

#if defined(__has_include) && __has_include(<libmate-panel-applet/mate-panel-applet.h>)
#include <libmate-panel-applet/mate-panel-applet.h>
#else
#include_next <mate-panel-applet.h>
#endif

#endif
