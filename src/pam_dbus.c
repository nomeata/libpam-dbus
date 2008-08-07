/***
  This file is part of pam_dbus.

  pam_dbus is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  
  pam_dbus is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with pam_dbus; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
  USA
***/
        
#define PAM_SM_AUTH

#include <security/pam_modules.h>

#include <glib.h>
#include <dbus/dbus.h>
#include <dbus/dbus-glib.h>

PAM_EXTERN int pam_sm_authenticate(pam_handle_t *ph, int flags, int argc, const char **argv) {
  DBusGConnection *connection;
  GError *error;
  DBusGProxy *proxy;

  gboolean login_ok;
  
  g_type_init ();

  error = NULL;
  connection = dbus_g_bus_get (DBUS_BUS_SYSTEM, &error);
  if (connection == NULL) {
      g_error_free (error);
      return PAM_AUTHINFO_UNAVAIL;
    }

  /* Create a proxy object for the "bus driver" (name "org.freedesktop.DBus") */
  
  proxy = dbus_g_proxy_new_for_name (connection,
                                     "de.nomeata.pam_dbus",
				     "/de/nomeata/pam_dbus",
				     "de.nomeata.pam_dbus"); 

  char *service, *user, *rhost, *ruser;
  pam_get_item(ph, PAM_SERVICE, (const void **)&service);
  pam_get_item(ph, PAM_USER,    (const void **)&user);
  pam_get_item(ph, PAM_RHOST,   (const void **)&rhost);
  pam_get_item(ph, PAM_RUSER,   (const void **)&ruser);

  /* Call ListNames method, wait for reply */
  error = NULL;
  if (!dbus_g_proxy_call_with_timeout (proxy, "MayLogin", 5*60*1000, &error,
			G_TYPE_STRING, service,
			G_TYPE_STRING, user,
			G_TYPE_STRING, rhost,
			G_TYPE_STRING, ruser,
  			G_TYPE_INVALID,
                        G_TYPE_BOOLEAN, &login_ok,
			G_TYPE_INVALID))
    {
      /* Just do demonstrate remote exceptions versus regular GError */
      g_error_free (error);
      g_object_unref (proxy);
      return PAM_AUTHINFO_UNAVAIL;
    }

  /* Print the results */


  g_object_unref (proxy);

  return login_ok ? PAM_SUCCESS : PAM_AUTH_ERR;
}
