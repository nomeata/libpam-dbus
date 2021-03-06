#!/bin/sh
# $Id: bootstrap.sh 13 2003-07-31 12:40:54Z lennart $

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

if [ "x$1" = "xam" ] ; then
    set -ex
    automake -a -c
    ./config.status
else 
    set -ex

    make maintainer-clean || true

    rm -rf autom4te.cache
    rm -f config.cache

    aclocal
    libtoolize -c --force
    autoheader
    automake -a -c
    autoconf -Wall

    ./configure "$@"
fi

