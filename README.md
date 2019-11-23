# Arduino Lua

This Arduino library provides the [lua](https://www.lua.org/) 5.3.5 ( [release](https://www.lua.org/ftp/lua-5.3.5.tar.gz) ) scripting engine for Arduino sketches. This allows dynamic execution of Lua code on the Arduino without having to compile and flash a new firmware.

Along with the Lua 5.3.5 Core the following Lua standard libraries are included:

- base (print(), tostring(), tonumber(), etc.)
- math
- table (insert(), sort(), remove(), ...)
- string (len(), match(), ...)

## Resources Used (HelloWorld.ino)

**ESP8266:**
Sketch uses 365276 bytes (34%) of program storage space. Maximum is 1044464 bytes. Global variables use 34712 bytes (42%) of dynamic memory, leaving 47208 bytes for local variables. Maximum is 81920 bytes.

**ESP32:**
Sketch uses 309913 bytes (23%) of program storage space. Maximum is 1310720 bytes. Global variables use 15388 bytes (4%) of dynamic memory, leaving 312292 bytes for local variables. Maximum is 327680 bytes.

## The Lua Language

[Lua 5.3 Reference Manual](https://www.lua.org/manual/5.3/)
