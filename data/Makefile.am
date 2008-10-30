
dbussystemdir=/etc/dbus-1/system.d
dist_dbussystem_DATA=pam_dbus.conf

autostartdir=/etc/xdg/autostart
nodist_autostart_DATA=pam-dbus-notify.desktop
CLEANFILES = $(nodist_autostart_DATA)
EXTRA_DIST = pam-dbus-notify.desktop.in

pam-dbus-notify.desktop: pam-dbus-notify.desktop.in Makefile
	sed -e 's,[@]pkgdatadir[@],$(pkgdatadir),g' \
	      < $(srcdir)/pam-dbus-notify.desktop.in > pam-dbus-notify.desktop

