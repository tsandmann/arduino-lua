# ESP Arduino Lua

This Arduino library provides the [lua](https://www.lua.org/) 5.3.5 (release) scripting engine for ESP8266/ESP32 sketches. This allows dynamic execution of Lua code on the Arduino without having to compile and flash a new firmware. 

Along with the Lua 5.3.5 Core the following Lua standard libraries are included:

- base (print(), tostring(), tonumber(), etc.)
- math
- table (insert(), sort(), remove(), ...)
- string (len(), match(), ...)

## Used Resources (ESP8266 minimal sketch, 4MB (no spiffs))

Sketch uses 327776 bytes (31%) of program storage space. Maximum is 1044464 bytes.
Global variables use 31276 bytes (38%) of dynamic memory, leaving 50644 bytes for local variables. Maximum is 81920 bytes.


## Arduino sketch examples

After installing the library, some sketch examples are available from the *File* menu, then *Examples* and finally under *ESP-Arduino-Lua*. The examples include **ExecuteScriptFromSerial** which takes a lua script from the serial line and executes it. As an example, the following standard Arduino functions are available in lua scripts as bindings:

- pinMode()
- digitalWrite()
- delay()
- millis()
- print() *(only builtin binding)*

```
# Enter the lua script and press Control-D when finished:
print("My first test!")
# Executing script:
My first test!


# Enter the lua script and press Control-D when finished-
print("Current uptime: "..millis())
# Executing script:
Current uptime: 159926.0


# Enter the lua script and press Control-D when finished:
print("Hello world!")
# Executing script:
Hello world!


# Enter the lua script and press Control-D when finished:
pinLED = 2
period = 500
pinMode(pinLED, OUTPUT)
while(true)
do
  print("LED on")
  digitalWrite(pinLED, LOW)
  delay(period)
  print("LED off")
  digitalWrite(pinLED, HIGH)
  delay(period)
end
# Executing script:
LED on
LED off
```
