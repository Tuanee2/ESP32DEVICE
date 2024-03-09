#ifndef VALUE_H
#define VALUE_H

#include "interface.h"
#include "UIPainter.h"
#include "config.h"

// mouse
uint8_t mouseApp = default_mouse_position;
uint8_t mouseSetup[6] ={0,0,0,0,0,0};
uint8_t mouseWifi[3] = {0,0,0};
uint8_t mouseClock = default_mouse_position;
uint8_t mouseIOT = default_mouse_position;
uint8_t mouseWeather = default_mouse_position;

// button

button button1,button2,button3;
button* ptrbut1 = &button1;
button* ptrbut2 = &button2;
button* ptrbut3 = &button3;

// screen
Ui screen = Ui();


#endif