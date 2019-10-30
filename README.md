# ESP8266 Arduino Lua

This Arduino library provides the [lua](https://www.lua.org/) 5.3.4 scripting engine for ESP8266 sketches. This allows dynamic execution of code on Arduino without having to compile and flash a new firmware. As an example, the following standard Arduino functions are available in lua scripts as bindings:
* *pinMode()*
* *digitalWrite()*
* *delay()*
* *millis()*
* *print()* which redirects to *Serial.println()*

## Installation into the Arduino IDE

Download the content of this Github repository as a ZIP archive by clicking on *Clone or download* then *Download ZIP*. Follow the instructions on [installing additional Arduino libraries](https://www.arduino.cc/en/Guide/Libraries#toc4) and navigate to the file downloaded previously.

## Resources used (minimal sketch, 4MB (no spiffs)

Sketch uses 327776 bytes (31%) of program storage space. Maximum is 1044464 bytes.
Global variables use 31276 bytes (38%) of dynamic memory, leaving 50644 bytes for local variables. Maximum is 81920 bytes.


## Arduino sketch examples

After installing the library, some sketch examples are available from the *File* menu, then *Examples* and finally under *ESP8266-Arduino-Lua*. The examples include **ExecuteScriptFromSerial** which takes a lua script from the serial line and executes it:

```
# Enter the lua script and press Control-D when finished:
print("My first test!")
# Executing script:
My first test!


# Enter the lua script and press Control-D when finished:
print("Current uptime: "..millis())
# Executing script:
Current uptime: 159926.0
```

## Lua script examples

The lua language syntax is described in the [reference manual](https://www.lua.org/manual/). It is extended by the Arduino functions listed above.

### Hello world

```
print("Hello world!")
```

### Blinking LED

```
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
```
