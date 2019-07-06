
Debian
====================
This directory contains files used to package wisprd/wispr-qt
for Debian-based Linux systems. If you compile wisprd/wispr-qt yourself, there are some useful files here.

## wispr: URI support ##


wispr-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install wispr-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your wispr-qt binary to `/usr/bin`
and the `../../share/pixmaps/wispr128.png` to `/usr/share/pixmaps`

wispr-qt.protocol (KDE)

