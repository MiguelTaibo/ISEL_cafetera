#ifndef MAIN_H
#define MAIN_H

#include <wiringPi.h>
#include "fsm.h"
#include "monedero.h"
#include "cafetera.h"
#include "main_lib.h"

// ENTRADAS
#define  GPIO_BOTON 1
#define  GPIO_DEVOLVER 2
#define  GPIO_MONEDA 3

#define GPIO_MONEDA_10 4
#define GPIO_MONEDA_20 5
#define GPIO_MONEDA_50 6

extern int dinero;
extern int next_time;
extern int devolver;
extern int moneda;
extern int boton;
