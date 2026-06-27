project('mate-indicator-applet', 'c',
  version: '1.28.0',
  meson_version: '>= 0.57.0',
  default_options: [
    'warning_level=1',
    'c_std=gnu99',
  ]
)

gnome = import('gnome')
i18n = import('i18n')

cc = meson.get_compiler('c')

add_project_arguments('-DHAVE_CONFIG_H', language: 'c')

# Prefix and Directories
prefix = get_option('prefix')
datadir = join_paths(prefix, get_option('datadir'))
libdir = join_paths(prefix, get_option('libdir'))
sysconfdir = join_paths(prefix, get_option('sysconfdir'))
libexecdir = join_paths(prefix, get_option('libexecdir'))

# Standard Dependencies
glib_dep = dependency('glib-2.0', version: '>= 2.50.0')
gio_dep = dependency('gio-2.0')
gtk_dep = dependency('gtk+-3.0', version: '>= 3.22.0')
mate_panel_dep = dependency('libmatepanelapplet-4.0', version: '>= 1.17.0')

# X11, Wayland and XWayland are part of the same build.
wayland_client_dep = dependency('gdk-wayland-3.0')
x11_client_dep = dependency('gdk-x11-3.0')
x11_lib_dep = dependency('x11')
have_wayland = true
have_x11 = true
wayland_deps = [wayland_client_dep]
x11_deps = [x11_client_dep, x11_lib_dep]

# Indicators detection
indicators_opt = get_option('indicators')
use_ayatana = false
use_ubuntu = false

if indicators_opt == 'ayatana'
  use_ayatana = true
elif indicators_opt == 'ubuntu'
  use_ubuntu = true
else
  # auto mode
  ayatana_dep_check = dependency('ayatana-indicator3-0.4', version: '>= 0.6.0', required: false)
  ubuntu_dep_check = dependency('indicator3-0.4', version: '>= 0.3.90', required: false)
  if ayatana_dep_check.found()
    use_ayatana = true
  elif ubuntu_dep_check.found()
    use_ubuntu = true
  else
    error('Either Ayatana Indicators or Ubuntu Indicators are required to build mate-indicator-applet.')
  endif
endif

# Configure Indicators dependencies
indicator_deps = []
conf = configuration_data()

if use_ayatana
  ayatana_dep = dependency('ayatana-indicator3-0.4', version: '>= 0.6.0')
  indicator_deps += [ayatana_dep]
  conf.set('HAVE_AYATANA_INDICATOR', 1)

  # Check for NG style
  ayatana_ido_dep = dependency('ayatana-ido3-0.4', version: '>= 0.4.0', required: false)
  if ayatana_ido_dep.found()
    indicator_deps += [ayatana_ido_dep]
    conf.set('HAVE_AYATANA_INDICATOR_NG', 1)
  endif

  # Directory paths from pkgconfig
  indicatordir = ayatana_dep.get_variable(pkgconfig: 'indicatordir', default_value: join_paths(libdir, 'ayatana-indicators3', '7'))
  iconsdir = ayatana_dep.get_variable(pkgconfig: 'iconsdir', default_value: join_paths(datadir, 'ayatana-indicator-applet', 'icons'))
else
  ubuntu_dep = dependency('indicator3-0.4', version: '>= 0.3.90')
  indicator_deps += [ubuntu_dep]
  conf.set('HAVE_UBUNTU_INDICATOR', 1)

  # Check for NG style
  ubuntu_ido_dep = dependency('libido3-0.1', version: '>= 13.10', required: false)
  if ubuntu_ido_dep.found()
    indicator_deps += [ubuntu_ido_dep]
    conf.set('HAVE_UBUNTU_INDICATOR_NG', 1)
  endif

  # Directory paths from pkgconfig
  indicatordir = ubuntu_dep.get_variable(pkgconfig: 'indicatordir', default_value: join_paths(libdir, 'indicators3', '7'))
  iconsdir = ubuntu_dep.get_variable(pkgconfig: 'iconsdir', default_value: join_paths(datadir, 'indicator-applet', 'icons'))
endif

# Configuration definitions
conf.set_quoted('PACKAGE', meson.project_name())
conf.set_quoted('VERSION', meson.project_version())
conf.set_quoted('GETTEXT_PACKAGE', meson.project_name())
conf.set_quoted('MATELOCALEDIR', join_paths(datadir, 'locale'))
conf.set_quoted('PREFIX', prefix)
conf.set_quoted('SYSCONFDIR', sysconfdir)
conf.set_quoted('LIBDIR', libdir)
conf.set_quoted('INDICATOR_DIR', indicatordir)
conf.set_quoted('INDICATOR_ICONS_DIR', iconsdir)
conf.set('ENABLE_NLS', 1)

if have_wayland
  conf.set('HAVE_WAYLAND', 1)
endif
if have_x11
  conf.set('HAVE_X11', 1)
endif

# Applet configurations
in_process = true
applet_in_process = in_process ? 'true' : 'false'
applet_platforms = 'X11;Wayland;'
indicator_libdir = join_paths(libdir, 'mate-indicator-applet')
if in_process
  applet_location_indicator = join_paths(indicator_libdir, 'libmate-indicator-applet.so')
  applet_location_appmenu = join_paths(indicator_libdir, 'libmate-indicator-applet-appmenu.so')
  applet_location_complete = join_paths(indicator_libdir, 'libmate-indicator-applet-complete.so')
else
  applet_location_indicator = join_paths(libexecdir, 'mate-indicator-applet')
  applet_location_appmenu = join_paths(libexecdir, 'mate-indicator-applet-appmenu')
  applet_location_complete = join_paths(libexecdir, 'mate-indicator-applet-complete')
endif

configure_file(
  output: 'config.h',
  configuration: conf
)

applet_deps = [
  glib_dep, gio_dep, gtk_dep, mate_panel_dep,
  wayland_deps, x11_deps, indicator_deps
]

po_dir = join_paths(meson.project_source_root(), 'po')

subdir('po')
subdir('src')
subdir('data')

gnome.post_install(
  gtk_update_icon_cache: true
)
