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
  ledcWrite(_channelR, 255 - red);
  ledcWrite(_channelG, 255 - green);
  ledcWrite(_channelB, 255 - blue);
}

void RGBESP::setColorHex(uint32_t hexValue) {
  uint8_t red = (hexValue >> 16) & 0xFF;
  uint8_t green = (hexValue >> 8) & 0xFF;
  uint8_t blue = hexValue & 0xFF;
  setColor(red, green, blue);
}
