#include "sapi.h"

//definicion de delay no bloqueante y determinacion de tiempo de los rebotones por presion de botones
delay_t delay_debounceButton;

#define time_debounce_ms 40
//===================================================================================================
//deficion de estados por la presion de botones
typedef enum
{
    UP = 0,
    RISING,
    FALLING,
    DOWN
} state_button_t;
//===================================================================================================
//abstraccion de datos para funcion de antirebote
typedef struct
{
    state_button_t state;
    tick_t time_debounce;
    bool_t Press;
    bool_t Release;
    uint8_t led;
    uint8_t tec;

} debounce_button_t;
//====================================================================================================
//iniializacion del la funcion antirebote
void debounce_init(debounce_button_t *debounce_button, uint8_t *vector_tec);
//====================================================================================================
//actualzacion de estados de los botones al momento de presionar
void debounce_update(debounce_button_t *debounce_button, uint8_t *vector_tec);
//====================================================================================================