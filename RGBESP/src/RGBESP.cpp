#include "RGBESP.h"

RGBESP::RGBESP(uint8_t pinR, uint8_t pinG, uint8_t pinB, uint8_t channelR, uint8_t channelG, uint8_t channelB, uint16_t freq, uint8_t resolution)
  : _pinR(pinR), _pinG(pinG), _pinB(pinB), _channelR(channelR), _channelG(channelG), _channelB(channelB), _freq(freq), _resolution(resolution) {}

void RGBESP::begin() {
  ledcSetup(_channelR, _freq, _resolution);
  ledcSetup(_channelG, _freq, _resolution);
  ledcSetup(_channelB, _freq, _resolution);

  ledcAttachPin(_pinR, _channelR);
  ledcAttachPin(_pinG, _channelG);
  ledcAttachPin(_pinB, _channelB);
}

void RGBESP::setColor(uint8_t red, uint8_t green, uint8_t blue) {
  _currentRed = red;
  _currentGreen = green;
  _currentBlue = blue;
  updateColor();
}

void RGBESP::setColorHex(uint32_t hexValue) {
  _currentRed = (hexValue >> 16) & 0xFF;
  _currentGreen = (hexValue >> 8) & 0xFF;
  _currentBlue = hexValue & 0xFF;
  updateColor();
}

void RGBESP::setBrightness(uint8_t brightness) {
  _brightness = brightness;
  updateColor();
}

void RGBESP::updateColor() {
  uint8_t red = (_currentRed * _brightness) / 255;
  uint8_t green = (_currentGreen * _brightness) / 255;
  uint8_t blue = (_currentBlue * _brightness) / 255;

  ledcWrite(_channelR, 255 - red);
  ledcWrite(_channelG, 255 - green);
  ledcWrite(_channelB, 255 - blue);
}
