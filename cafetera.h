#ifndef CAFETERA_H
#define CAFETERA_H

#include <wiringPi.h>

//SALIDAS
#define GPIO_VASO 7
#define GPIO_CAFE 8
#define GPIO_LECHE 9
#define GPIO_FIN 10

#define PRECIO 50
#define TIME_VASO	10
#define TIME_CAFE 100
#define TIME_LECHE 50

extern int dinero;
extern int next_time;
extern int boton;
