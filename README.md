# Sensors for ESP32 Development Framework

* [中文版](./README_CN.md)

# Developing With BHD-SENSOR

## Setting Up ESP-IDF

See setup guides for detailed instructions to set up the ESP-IDF:
* [Getting ESP-IDF and config environment](https://github.com/espressif/esp-idf)
    * Please make sure that you can build the demo in esp-idf

## Setting Up BHD-SENSOR
* Set `BHD_SENSOR_PATH`
    * `export BHD_SENSOR_PATH=<the path of BHD-SENSOR>`
* Config environment
    * python2： `python config_env_p2.py`
    * python3： `python config_env_p3.py`
        * Please make sure that you have set the `IDF_PATH` and `BHD_SENSOR_PATH`

## Configuring the Project

* `idf.py menuconfig`
* or `make menuconfig`

Once done configuring, press Escape multiple times to exit and say "Yes" to save the new configuration when prompted.

## Compiling the Project

* `idf.py build`
* or `make`

## Flashing the Project

* `idf.py -p PORT flash`
* or `make flash`

## Viewing Serial Output

* `idf.py monitor`
    * Exit the monitor by typing Ctrl-].
    * To build, flash and monitor output in one pass, you can run: `idf.py flash monitor`
* or other tools, such as minicom

## Compiling & Flashing Only the App

* `idf.py app` - build just the app.
* `idf.py app-flash` - flash just the app.

## Erasing Flash

* `idf.py erase_flash`
* or `make erase_flash`