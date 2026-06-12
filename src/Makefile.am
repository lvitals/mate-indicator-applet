if WITH_AYATANA_INDICATOR
INDICATOR_CFLAGS = $(AYATANA_INDICATOR_CFLAGS)		\
                   $(AYATANA_INDICATOR_NG_CFLAGS)
INDICATOR_LIBS   = $(AYATANA_INDICATOR_LIBS)		\
                   $(AYATANA_INDICATOR_NG_LIBS)
endif

if WITH_UBUNTU_INDICATOR
INDICATOR_CFLAGS = $(UBUNTU_INDICATOR_CFLAGS)		\
                   $(UBUNTU_INDICATOR_NG_CFLAGS)
INDICATOR_LIBS   = $(UBUNTU_INDICATOR_LIBS)		\
                   $(UBUNTU_INDICATOR_NG_LIBS)
endif

applet_lib_LTLIBRARIES = \
	libindicator-applet.la \
	libindicator-applet-appmenu.la \
	libindicator-applet-complete.la

applet_libdir = $(LIBDIR)/mate-panel/applets

AM_CPPFLAGS = \
	-DG_LOG_DOMAIN=\""Indicator-Applet"\" \
	-DDATADIR=\""$(datadir)"\" \
	-DINDICATOR_DIR=\""$(INDICATORDIR)"\" \
	-DINDICATOR_ICONS_DIR=\""$(INDICATORICONSDIR)"\" \
	-I$(srcdir)/.. \
	$(APPLET_CFLAGS) \
	$(INDICATOR_CFLAGS) \
	$(WAYLAND_CFLAGS) \
	$(X11_CFLAGS) \
	$(WARN_CFLAGS)

common_sources = \
	applet-main.c \
	eggaccelerators.c \
	eggaccelerators.h \
	tomboykeybinder.c \
	tomboykeybinder.h

common_ldadd = \
	$(APPLET_LIBS) \
	$(INDICATOR_LIBS) \
	$(WAYLAND_LIBS) \
	$(X11_LIBS)

libindicator_applet_la_CFLAGS = $(AM_CPPFLAGS) -DINDICATOR_APPLET -DINDICATOR_APPLET_IN_PROCESS
libindicator_applet_la_SOURCES = $(common_sources)
libindicator_applet_la_LDFLAGS = -module -avoid-version
libindicator_applet_la_LIBADD = $(common_ldadd)

libindicator_applet_appmenu_la_CFLAGS = $(AM_CPPFLAGS) -DINDICATOR_APPLET_APPMENU -DINDICATOR_APPLET_IN_PROCESS
libindicator_applet_appmenu_la_SOURCES = $(common_sources)
libindicator_applet_appmenu_la_LDFLAGS = -module -avoid-version
libindicator_applet_appmenu_la_LIBADD = $(common_ldadd)

libindicator_applet_complete_la_CFLAGS = $(AM_CPPFLAGS) -DINDICATOR_APPLET_COMPLETE -DINDICATOR_APPLET_IN_PROCESS
libindicator_applet_complete_la_SOURCES = $(common_sources)
libindicator_applet_complete_la_LDFLAGS = -module -avoid-version
libindicator_applet_complete_la_LIBADD = $(common_ldadd)

if HAVE_X11
libexec_PROGRAMS = \
	mate-indicator-applet \
	mate-indicator-applet-appmenu \
	mate-indicator-applet-complete

mate_indicator_applet_CFLAGS = $(AM_CPPFLAGS) -DINDICATOR_APPLET
mate_indicator_applet_SOURCES = $(common_sources)
mate_indicator_applet_LDADD = $(common_ldadd)

mate_indicator_applet_appmenu_CFLAGS = $(AM_CPPFLAGS) -DINDICATOR_APPLET_APPMENU
mate_indicator_applet_appmenu_SOURCES = $(common_sources)
mate_indicator_applet_appmenu_LDADD = $(common_ldadd)

mate_indicator_applet_complete_CFLAGS = $(AM_CPPFLAGS) -DINDICATOR_APPLET_COMPLETE
mate_indicator_applet_complete_SOURCES = $(common_sources)
mate_indicator_applet_complete_LDADD = $(common_ldadd)
endif

-include $(top_srcdir)/git.mk
