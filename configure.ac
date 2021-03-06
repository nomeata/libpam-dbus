# -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

# $Id: configure.ac 23 2003-08-27 20:16:37Z lennart $

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

AC_PREREQ(2.61)
AC_INIT([pam_dbus],[0.2.1],[Joachim Breitner <mail@joachim-breitner.de>])
AC_CONFIG_SRCDIR([src/pam_dbus.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([foreign -Wall])

AM_DISABLE_STATIC

# Checks for programs.
AC_PROG_CC
AC_PROG_LIBTOOL
AC_PROG_CXX

# If using GCC specifiy some additional parameters
if test "x$GCC" = "xyes" ; then
   CFLAGS="$CFLAGS -pipe -Wall"
fi

CFLAGS="$CFLAGS -L/lib"

# Checks for libraries.
AC_CHECK_HEADER([security/pam_modules.h],, [AC_MSG_ERROR([*** Sorry, you have to install the PAM development files ***])])

LIBS="$LIBS -ldl -lpam -lpam_misc"

PAM_MODDIR="/lib/security"
AC_SUBST(PAM_MODDIR)

# Checks for header files.

AC_CHECK_FUNCS([dup2 memset strchr strerror strrchr])
AC_FUNC_FORK
AC_FUNC_LSTAT
AC_FUNC_LSTAT_FOLLOWS_SLASHED_SYMLINK
AC_FUNC_VPRINTF

AC_CHECK_HEADERS([fcntl.h limits.h syslog.h termios.h])
AC_HEADER_STDC
AC_HEADER_SYS_WAIT

AC_C_CONST

AC_TYPE_MODE_T
AC_TYPE_PID_T
AC_TYPE_SIGNAL
AC_TYPE_UID_T


PKG_CHECK_MODULES(GLIB, glib-2.0 >= 2.10, dummy=yes,
                                AC_MSG_ERROR(libglib-2.0 is required))
AC_SUBST(GLIB_CFLAGS)
AC_SUBST(GLIB_LIBS)

PKG_CHECK_MODULES(DBUS, dbus-1 >= 1.0, dummy=yes,
				AC_MSG_ERROR(libdbus is required))
AC_SUBST(DBUS_CFLAGS)
AC_SUBST(DBUS_LIBS)

PKG_CHECK_MODULES(DBUS_GLIB, dbus-glib-1 >= 0.70, dummy=yes,
				AC_MSG_ERROR(libdbus-glib is required))
AC_SUBST(DBUS_GLIB_CFLAGS)
AC_SUBST(DBUS_GLIB_LIBS)



AC_CONFIG_FILES([src/Makefile data/Makefile handlers/Makefile Makefile])
AC_OUTPUT
