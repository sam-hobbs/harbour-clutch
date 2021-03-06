# Clutch - SailfishOS application
A Silica frontend for the Transmission Torrent Client.

At present Clutch is quite simple: it starts transmission-daemon when the app is opened and provides an easy way to view the web UI.

A few modifications have been made to the Silica WebView to improve the Transmission Web UI's ease of use:
* File picker (for uploading .torrent files)
* Page width modified to suit phone screen size
* WebView starts lower down the page to prevent accidentally pressing the "back" dot on the page when clicking open file.

Since Clutch launches transmission in the background, transmission is a dependency of Clutch.
A minimal build of Transmission (and libevent2, a dependency of transmission) are available in [my repository on OpenRepos](https://openrepos.net/user/5451/repository), and should be automatically installed if you install Clutch using [Warehouse](https://openrepos.net/content/basil/warehouse-sailfishos).

# Development Priorities
Some development priorities, in order, are:
* Implement a model for the Transmission daemon settings stored in settings.json, and expose the settings in the settings page.
* Start writing a proper Silica frontend that uses Transmission directly without calling it as a separate process (probably required before application can be uploaded to Jolla Harbour)

Contributions welcome.
