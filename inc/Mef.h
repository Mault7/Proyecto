#include "sapi.h"

//definicion de delay no bloqueante y determinacion de tiempo de los estados
delay_t delay_Mef;
delay_t delay_buttonPress;

#define time_Mef_ms 500;
//===========================================================================
//deficion de estados de la maquina de estados
typedef enum
{
    MOD_POWEROFF = 0,
    MOD_TOOGLE,
    MOD_SWEPT_RIGTH,
    MOD_SWEPT_LEFTH,
    MOD_WATERFALL
} Mef_state;
//===========================================================================
//Abstraccion  de los datos para la Maquina de estados prinipal
typedef struct
{
    Mef_state state;
    tick_t time;

} Mef_t;
//===========================================================================
//Inicializacion de la maquina de estados con parametros definidos
void init_MEf(Mef_t *pMef);
//===========================================================================
//Atualiacion de la maquina de estados segun eventos de accion
void update_Mef(Mef_t *pMef);
//===========================================================================