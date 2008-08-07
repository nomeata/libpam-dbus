# $Id: Makefile.am 13 2003-07-31 12:40:54Z lennart $
#
# This file is part of pam_dbus.
#
# pam_dbus is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# pam_dbus is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with pam_dbus; if not, write to the Free Software Foundation,
# Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.

AM_CFLAGS = -DSBINDIR=\"@sbindir@\" @GLIB_CFLAGS@ @DBUS_CFLAGS@ @DBUS_GLIB_CFLAGS@

moduledir = @PAM_MODDIR@
module_LTLIBRARIES = pam_dbus.la

pam_dbus_la_SOURCES = pam_dbus.c
pam_dbus_la_LDFLAGS = -module -avoid-version  @DBUS_GLIB_LIBS@ @DBUS_LIBS@ @GLIB_LIBS@
pam_dbus_la_CFLAGS = $(AM_CFLAGS)

bin_PROGRAMS = pamtest

pamtest_SOURCES = pamtest.c
