common_sources = [
  'applet-main.c',
  'eggaccelerators.c',
  'tomboykeybinder.c',
]

if in_process
  in_process_args = ['-DINDICATOR_APPLET_IN_PROCESS']

  shared_library('mate-indicator-applet',
    common_sources,
    c_args: ['-DINDICATOR_APPLET'] + in_process_args,
    include_directories: [include_directories('..')],
    dependencies: applet_deps,
    install: true,
    install_dir: indicator_libdir
  )

  shared_library('mate-indicator-applet-appmenu',
    common_sources,
    c_args: ['-DINDICATOR_APPLET_APPMENU'] + in_process_args,
    include_directories: [include_directories('..')],
    dependencies: applet_deps,
    install: true,
    install_dir: indicator_libdir
  )

  shared_library('mate-indicator-applet-complete',
    common_sources,
    c_args: ['-DINDICATOR_APPLET_COMPLETE'] + in_process_args,
    include_directories: [include_directories('..')],
    dependencies: applet_deps,
    install: true,
    install_dir: indicator_libdir
  )
else
  executable('mate-indicator-applet',
    common_sources,
    c_args: ['-DINDICATOR_APPLET'],
    include_directories: [include_directories('..')],
    dependencies: applet_deps,
    install: true,
    install_dir: libexecdir
  )

  executable('mate-indicator-applet-appmenu',
    common_sources,
    c_args: ['-DINDICATOR_APPLET_APPMENU'],
    include_directories: [include_directories('..')],
    dependencies: applet_deps,
    install: true,
    install_dir: libexecdir
  )

  executable('mate-indicator-applet-complete',
    common_sources,
    c_args: ['-DINDICATOR_APPLET_COMPLETE'],
    include_directories: [include_directories('..')],
    dependencies: applet_deps,
    install: true,
    install_dir: libexecdir
  )
endif
