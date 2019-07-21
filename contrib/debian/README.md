
Debian
====================
This directory contains files used to package rpicoind/rpicoin-qt
for Debian-based Linux systems. If you compile rpicoind/rpicoin-qt yourself, there are some useful files here.

## rpicoin: URI support ##


rpicoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install rpicoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your rpicoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/rpicoin128.png` to `/usr/share/pixmaps`

rpicoin-qt.protocol (KDE)

