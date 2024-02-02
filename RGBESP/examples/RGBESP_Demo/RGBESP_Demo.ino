#include <RGBESP.h>

// Initialize RGBESP with the GPIO pins for R, G, B
RGBESP rgbLed(40, 41, 42);

void setup() {
  rgbLed.begin();
  
  // Set color using RGB values to purple
  rgbLed.setColor(255, 0, 255);
  delay(2000); // Wait for 2 seconds
  
  // Set color using hexadecimal color code for red
  rgbLed.setColorHex(0xFF0000);
  delay(2000); // Wait for 2 seconds
  
  // Set color using HTMLColorCode enum for Aqua
  rgbLed.setColorHex(Aqua);
  delay(2000); // Wait for 2 seconds
}

void loop() {
  // Cycle through a few HTMLColorCode enum values
  rgbLed.setColorHex(AliceBlue);
  delay(1000);
  rgbLed.setColorHex(Amethyst);
  delay(1000);
  rgbLed.setColorHex(AntiqueWhite);
  delay(1000);
  rgbLed.setColorHex(Aquamarine);
  delay(1000);
  rgbLed.setColorHex(Azure);
  delay(1000);
  rgbLed.setColorHex(Beige);
  delay(1000);
  rgbLed.setColorHex(Bisque);
  delay(1000);
}
