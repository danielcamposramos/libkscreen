<picture>
  <source media="(prefers-color-scheme: dark)" srcset=".github/sparky-stereo-os/sparkyos-swirl-light-128.png">
  <img src=".github/sparky-stereo-os/sparkyos-swirl-dark-128.png" alt="SparkyOS" width="128" height="128">
</picture>

## Sparky Stereo OS

This is the stereo version of libkscreen by Sparky Stereo OS, forked from [KDE/libkscreen](https://github.com/KDE/libkscreen).
It adds a display's HDMI 1.4a 3D modes and the state of stereo outputs, for KScreen and other clients.

Where it comes from:

- [libkscreen](https://invent.kde.org/plasma/libkscreen) is made by the KDE community. Its authors include Daniel Vrátil, Sebastian Kügler, Alejandro Fiestas Olivares, Aleix Pol Gonzalez and Méven Car.
- [Debian](https://www.debian.org/) is the base of the system.
- [SparkyLinux](https://sparkylinux.org/), by Paweł "pavroo" Pijanowski, builds on Debian.
- [Sparky Stereo OS](https://github.com/Sparky-OS/sparky-stereo-os) is the stereo 3D edition of SparkyLinux: SparkyOS, powered by Debian.

The `stereo3d` branch holds the version the distribution builds.
KDE develops libkscreen on invent.kde.org.
The canonical version of this work is there too, on the [`stereo3d-6.7`](https://invent.kde.org/danielcamposramos/libkscreen/-/tree/stereo3d-6.7) branch.
The licences are unchanged; see [LICENSES](LICENSES).

Sparky Stereo OS, Daniel Ramos's edition of SparkyLinux (by Paweł "pavroo" Pijanowski).

---

# libkscreen

libkscreen is the screen management library for KDE Plasma Workspaces. Its primary consumer is the KDE screen management application KScreen.

libkscreen is part of [Plasma releases][plasma-releases].

## End user
Since this is a development library end users should instead look for support directly for the apps using this library. Please contact the support channels of your Linux distribution first. In case you find a bug in KScreen or if the bug is traced back to libkscreen, you can report it at the KDE [bug tracker][bug-tracker] (first look for duplicates).

## Contributing
See the `CONTRIBUTING.md` file.

[plasma-releases]: https://community.kde.org/Schedules/Plasma_5
[bug-tracker]: https://bugs.kde.org/describecomponents.cgi?product=KScreen
