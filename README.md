
# RGBESP Library for Arduino

The RGBESP library provides an easy-to-use interface for controlling RGB LEDs with ESP32 boards using the LEDC hardware. It supports setting colors using RGB values, hexadecimal color codes, and predefined HTML color names. Additionally, it allows dynamic brightness adjustment for the LEDs without changing the color.

## Features

- Set LED color using RGB values.
- Set LED color using hexadecimal color codes.
- Use predefined HTML color names for easy color selection.
- Dynamically adjust the brightness of the LEDs.

## Installation

1. Download the latest release of the `RGBESP` library from the GitHub repository.
2. In the Arduino IDE, navigate to `Sketch` > `Include Library` > `Add .ZIP Library...`
3. Select the downloaded `.zip` file of the `RGBESP` library and click `Open` to install.
4. After installation, the library is ready to use in your projects.

## Usage

### Initializing the Library

```cpp
#include <RGBESP.h>

// Initialize RGBESP with the GPIO pins for R, G, B LEDs
RGBESP rgbLed(40, 41, 42);
```

### Setting Colors

- **Using RGB Values**

```cpp
rgbLed.setColor(255, 0, 255); // Sets the LED color to purple
```

- **Using Hexadecimal Color Codes**

```cpp
rgbLed.setColorHex(0xFF0000); // Sets the LED color to red
```

- **Using Predefined HTML Color Names**

```cpp
rgbLed.setColorHex(Aqua); // Sets the LED color to aqua
```

### Adjusting Brightness

```cpp
rgbLed.setBrightness(128); // Adjusts the brightness to 50%
```

## Example Sketch

Refer to the `example.ino` file in the examples directory for a comprehensive demonstration of using the `RGBESP` library to set colors and adjust brightness.

## Contributing

Contributions to the `RGBESP` library are welcome. Please feel free to submit pull requests or open issues to improve the library or add new features.

## License

This project is licensed under the MIT License - see the LICENSE file for details.
```