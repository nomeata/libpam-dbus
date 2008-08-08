#!/usr/bin/python

import pygtk
import gtk
import gobject

import dbus
import dbus.service
import dbus.glib

import pynotify

# list of Notifications around, kept to prevent the garbage collector to handle them.
ns = []

def notify_cb(n, action, pam_cb):
    if pam_cb is not None:
        if action == "permit":
            pam_cb(True)
        else:
            pam_cb(False)
        pam_cb = None
    ns.remove(n)

# Initializite pynotify
if not pynotify.init("pam-dbus"):
    sys.exit(1)

# dbus object to answer the request
class PamDbusAnswer(dbus.service.Object):
     def __init__(self, bus_name, object_path="/de/nomeata/pam_dbus"):
         dbus.service.Object.__init__(self, bus_name, object_path)
 
     @dbus.service.method(dbus_interface='de.nomeata.pam_dbus',
                          in_signature='ssss', out_signature='b',
                          async_callbacks=('ret_cb', 'error_cb'))
     def MayLogin(self, service, user, rhost, ruser, ret_cb, error_cb):

         n = pynotify.Notification("Login request","Someone " + 
                            ("named %s " % ruser if ruser else "") +
                            "tries to log in via %s " % service + 
                            ("from %s " % rhost if rhost else "") + 
                            "as user %s. " % user + 
                            "Do you want to allow that?")

         n.set_timeout(5*60*1000)
         n.add_action("permit", "Permit login", notify_cb, ret_cb)
         n.add_action("deny", "Deny login", notify_cb,ret_cb)
         n.connect("closed",lambda n: notify_cb(n,"closed", ret_cb))

         if not n.show():
             print "Failed to send notification"
             sys.exit(1)

         ns.append(n)
 
system_bus = dbus.SystemBus()
name = dbus.service.BusName("de.nomeata.pam_dbus", bus=system_bus)
object = PamDbusAnswer(name)

gtk.main()

