
dbussystemdir=/etc/dbus-1/system.d
dist_dbussystem_DATA=pam_dbus.conf

autostartdir=/etc/xdg/autostart
dist_autostart_DATA=pam-dbus-notify.desktop
CLEANFILES = $(dist_autostart_DATA)
EXTRA_DIST = pam-dbus-notify.desktop.in

pam-dbus-notify.desktop: pam-dbus-notify.desktop.in Makefile
	sed -e 's,[@]pkgdatadir[@],$(pkgdatadir),g' \
	      < pam-dbus-notify.desktop.in > pam-dbus-notify.desktop

