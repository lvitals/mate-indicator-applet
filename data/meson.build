applet_names = [
  {
    'name': 'Indicator',
    'id': 'org.mate.applets.Indicator',
  },
  {
    'name': 'IndicatorComplete',
    'id': 'org.mate.applets.IndicatorComplete',
  },
  {
    'name': 'IndicatorAppmenu',
    'id': 'org.mate.applets.IndicatorAppmenu',
  }
]

applet_conf = configuration_data()
applet_conf.set('LIBEXECDIR', join_paths(prefix, get_option('libexecdir')))
applet_conf.set('LIBDIR', join_paths(prefix, get_option('libdir')))
applet_conf.set('APPLET_IN_PROCESS', applet_in_process)
applet_conf.set('APPLET_PLATFORMS', applet_platforms)
applet_conf.set('APPLET_LOCATION_INDICATOR', applet_location_indicator)
applet_conf.set('APPLET_LOCATION_APPMENU', applet_location_appmenu)
applet_conf.set('APPLET_LOCATION_COMPLETE', applet_location_complete)

foreach a : applet_names
  desktop_in = configure_file(
    input: a['id'] + '.mate-panel-applet.desktop.in.in',
    output: a['id'] + '.mate-panel-applet.desktop.in',
    configuration: applet_conf
  )

  i18n.merge_file(
    input: desktop_in,
    output: a['id'] + '.mate-panel-applet',
    type: 'desktop',
    po_dir: po_dir,
    install: true,
    install_dir: join_paths(datadir, 'mate-panel/applets')
  )
endforeach

# DBus Service Files - only needed for out-of-process activation
if not in_process
  service_names = [
    'org.mate.panel.applet.IndicatorAppletFactory.service',
    'org.mate.panel.applet.IndicatorAppletCompleteFactory.service',
    'org.mate.panel.applet.IndicatorAppletAppmenuFactory.service'
  ]

  _libexecdir = join_paths(prefix, get_option('libexecdir'))
  if have_wayland
    _libexecdir = 'env GDK_BACKEND=x11 ' + _libexecdir
  endif

  service_conf = configuration_data()
  service_conf.set('SERVICE_EXEC_INDICATOR', _libexecdir + '/mate-indicator-applet')
  service_conf.set('SERVICE_EXEC_COMPLETE', _libexecdir + '/mate-indicator-applet-complete')
  service_conf.set('SERVICE_EXEC_APPMENU', _libexecdir + '/mate-indicator-applet-appmenu')

  foreach s : service_names
    configure_file(
      input: s + '.in',
      output: s,
      configuration: service_conf,
      install: true,
      install_dir: join_paths(datadir, 'dbus-1/services')
    )
  endforeach
endif

# Icons
install_data('mate-indicator-applet.svg',
  install_dir: join_paths(datadir, 'icons/hicolor/scalable/apps')
)
