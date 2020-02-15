#ifndef MONEDERO_H
#define MONEDERO_H

#include <wiringPi.h>

#define GPIO_MONEDA_10 4
#define GPIO_MONEDA_20 5
#define GPIO_MONEDA_50 6


extern int dinero;
extern int devolver;
extern int moneda;

int comprobarMoneda(fsm_t* this);
int comprobarDevolver(fsm_t* this);

void sumarDinero(fsm_t* this);
void devolverDinero(fsm_t* this);

static void devolver_isr (union sigval arg);
static void moneda_isr (union sigval arg);
