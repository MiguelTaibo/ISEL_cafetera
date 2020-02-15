#include "cafetera.h"

// Comprobaciones
int comprobarBotonYDinero(fsm_t* this) {
  return (boton & dinero>PRECIO)
}

int comprobarAcabado(fsm_t* this) {
  return millis()>=next_time
}

// Acciones

void empezarVaso (fsm_t* this)
{
  digitalWrite (GPIO_FIN, LOW);
  digitalWrite (GPIO_VASO, HIGH);
  dinero-=PRECIO
  next_time = millis() +  TIME_VASO;
}

void empezarCafe (fsm_t* this)
{
  digitalWrite (GPIO_VASO, LOW);
  digitalWrite (GPIO_CAFE, HIGH);
  next_time = millis() + TIME_CAFE;
}

void empezarLeche (fsm_t* this)
{
  digitalWrite (GPIO_CAFE, LOW);
  digitalWrite (GPIO_LECHE, HIGH);
  next_time = millis() + TIME_LECHE;
}

void acabarServicio (fsm_t* this)
{
  digitalWrite (GPIO_LECHE, LOW);
  digitalWrite (GPIO_FIN, HIGH);
  boton = 0;
}

static void boton_isr (union sigval arg) {
	boton = 1;
}
