# TapTo Esp32 Serial Bridge
The goal of this code is to provide a simple serial wifi bridge for the [TapTo Service](https://github.com/TapToCommunity/tapto) project in order to launch games. It also provides backwards compatbility for the v1 launch api. There are a few reasons why you may want to an ESP32 instead of the official [web api](https://tapto.wiki/API):
1. Use are using a project that interfaced with the older v1 api to launch games and that project has not been updated.
2. You are working with a wifi device that has limitted/lacking support for the autentication used by the official web api.
3. You plan on using this as sample code to interface your own project with TapTo via serial (like launching a game based temperature and light sensors, a control pad that triggers different games based on keypresses, etc...).

## Required Parts
* An Esp32

## ESP Setup
1. If you haven't already, downalod and install Ardunio Studio.
2. Clone/Download the repository and open EspTapToSerial.ino in Arunido Studio.
3. Select your board and port, located in the Tools menu. If you do not have options for an Esp32, follow these [instrustions](https://docs.sunfounder.com/projects/umsk/en/latest/03_esp32/esp32_start/03_install_esp32.html) for installing the board configurations.
4. Edit the wifi configuration variables in the EspTapToSerial.hpp file.
5. (Optional) Change the port, mac address, and hostname in the EspTapToSerial.hpp file as well.

## TapTo Setup
1. Connect your Esp32 to your TapTo device.
2. Open your tapto.ini file in a text editor.
3. In the [TapTo] section, add the line "reader=simple_serial:\<path to device>", where \<path to device> is the path to where your Esp32 is mounted.
   * For my setup using a Mister, my device was mounted at /dev/ttyACM0
4. Reboot the TapTo service (or the entire device).
