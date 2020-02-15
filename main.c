#include "main.h"

static int dinero = 0;
static int devolver = 0;
static int moneda = 0;
static int next_time = 0;
static int boto = 0;


void delay_until (unsigned int next)|{
    unsigned int now = millis();
    if ( next > now) {
      delay(next-now);
    }
}

int main () {


	// Configuracion de los pines
	wiringPiSetupGpio ()
	//ENTRADAS
	pinMode (GPIO_BOTON, INPUT);
	pinMode (GPIO_DEVOLVER, INPUT);
	pinMode (GPIO_MONEDA, INPUT);
	pinMode (GPIO_MONEDA_10, INPUT);
	pinMode (GPIO_MONEDA_20, INPUT);
	pinMode (GPIO_MONEDA_50, INPUT);
	// RUTINAS DE ATENCION A INTERRUPCIONES
	wiringPiISR (GPIO_BOTON, INT_EDGE_FALLING, boton_isr);
	wiringPiISR (GPIO_DEVOLVER, INT_EDGE_FALLING, devolver_isr);
	wiringPiISR (GPIO_MONEDA, INT_EDGE_FALLING, moneda_isr);
	//SALIDAS
	pinMode (GPIO_VASO, OUTPUT);
	pinMode (GPIO_CAFE, OUTPUT);
	pinMode (GPIO_LECHE, OUTPUT);
	pinMode (GPIO_FIN, OUTPUT);

    // Definicion de Transiciones
    fms_trans_t monedero[] = {
      {0, comprobarMoneda, 0, sumarDinero},
      {0, comprobarDevolver, 0, devolverDinero},
      {-1, NULL, -1, NULL}
    };

    fms_trans_t cafetera[] = {
        {0, comprobarBotonYDinero, 1, empezarVaso},
        {1, comprobarAcabado, 2, empezarCafe},
        {2, comprobarAcabado, 3, empezarLeche},
        {3, comprobarAcabado, 0, acabarServicio}
        {-1, NULL, -1, NULL},
    };

    fsm_t* monedero_fsm = fsm_new(monedero);
    fsm_t* cafetera_fsm = fsm_new(cafetera);


    unsigned int next;
    next = millis();


    while (1) {

      fsm_fire(monedero_fsm);
      fsm_fire(cafetera_fsm);

      next += CLK_MS;
  		delay_until (next);
    }
    return 0;
}
