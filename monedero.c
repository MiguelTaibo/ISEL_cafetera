#include "monedero.h"

/// Comprobaciones
int comprobarMoneda(fsm_t* this) {
    return moneda;
}

int comprobarDevolver(fsm_t* this) {
  return devolver;
}

/// Acciones
void sumarDinero(fsm_t* this) {
  dinero = moneda + dinero;
  moneda = 0;
}

void devolverDinero(fsm_t* this) {
  dinero = 0;
  devolver = 0;
}

static void devolver_isr (union sigval arg) {
	devolver = 1;
}

static void moneda_isr (union sigval arg) {
	if digitalRead(GPIO_MONEDA_10) {
		moneda += 10
	} else if digitalRead(GPIO_MONEDA_20) {
		moneda += 20
	} else if digitalRead(GPIO_MONEDA_50) {
		moneda += 50
	} else {
		moneda +=0
	}
}
