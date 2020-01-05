# 用于Espressif开发框架的传感器

* [English Version](./README.md)

# 使用 BHD-SENSOR 进行开发

## 搭建 ESP-IDF 开发环境

请参阅如下指南搭建 ESP-IDF 的开发环境：
* [ESP-IDF](https://github.com/espressif/esp-idf)
    * 请确保您可以在 esp-idf 中编译 demo

## 搭建 BHD-SENSOR 开发环境
* 设置 `BHD_SENSOR_PATH`
    * `export BHD_SENSOR_PATH=<the path of BHD-SENSOR>`
* 配置环境
    * python2： `python config_env_p2.py`
    * python3： `python config_env_p3.py`
        * 请确保已设置 `IDF_PATH` 和 `BHD_SENSOR_PATH`

## 配置项目

* `idf.py menuconfig`
* 或 `make menuconfig`

Once done configuring, press Escape multiple times to exit and say "Yes" to save the new configuration when prompted.

## 编译项目

* `idf.py build`
* 或 `make`

## 烧写项目

* `idf.py -p PORT flash`
* 或 `make flash`

## 观察串口输入

* `idf.py monitor`
    * 输入 `Ctrl-]` 可退出监视器。
    * 想要一次性执行构建，烧写和监视，可以运行命令：`idf.py flash monitor`
* 或其他串口工具，比如： minicom

## 仅编译并烧写应用程序

* `idf.py app` - 仅构建应用程序。
* `idf.py app-flash` - 仅烧写应用程序。

## 擦除 Flash

* `idf.py erase_flash`
* 或 `make erase_flash`
