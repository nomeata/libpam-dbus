#!/usr/bin/python

import dbus.service
import gobject

from dbus.mainloop.glib import DBusGMainLoop



class PamDbusAnswer(dbus.service.Object):
    def __init__(self, bus_name, object_path="/de/nomeata/pam_dbus"):
        dbus.service.Object.__init__(self, bus_name, object_path)

    @dbus.service.method(dbus_interface='de.nomeata.pam_dbus',
                         in_signature='ssss', out_signature='b')
    def MayLogin(self, service, user, rhost, ruser):
	print service, user, rhost, ruser
	return True


DBusGMainLoop(set_as_default=True)

system_bus = dbus.SystemBus()
name = dbus.service.BusName("de.nomeata.pam_dbus", bus=system_bus)
object = PamDbusAnswer(name)

mainloop = gobject.MainLoop()
mainloop.run()

