
Debian
====================
This directory contains files used to package RPICoind/RPICoin-qt
for Debian-based Linux systems. If you compile RPICoind/RPICoin-qt yourself, there are some useful files here.

## RPICoin: URI support ##


RPICoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install RPICoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your RPICoinqt binary to `/usr/bin`
and the `../../share/pixmaps/RPICoin128.png` to `/usr/share/pixmaps`

RPICoin-qt.protocol (KDE)

