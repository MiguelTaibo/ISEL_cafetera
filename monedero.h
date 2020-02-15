#ifndef MONEDERO_H
#define MONEDERO_H

#include <wiringPi.h>
#include "main_lib.h"

int comprobarMoneda(fsm_t* this);
int comprobarDevolver(fsm_t* this);

void sumarDinero(fsm_t* this);
void devolverDinero(fsm_t* this);

extern int dinero;
extern int devolver;
extern int moneda;
