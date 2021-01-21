#include "sapi.h"

delay_t delay_leds;

typedef struct
{
    uint8_t state;
    uint8_t ContRising;
    uint8_t ContFalling;
    uint8_t aux;
} Leds_t;

Leds_t leds;
//Funcion inicializadora de los parametros de leds
void initLeds(Leds_t *pLeds, uint8_t *leds, uint8_t sizeVectorLeds);
//========================================================================================
//Apagado de todos los leds a nivel sistema
void PowerOffAllLeds(uint8_t *leds, uint8_t sizeVectorLeds);
//========================================================================================
//Encendido de todos los leds a nivel sistema
void PowerOnAllLeds(uint8_t *leds, uint8_t sizeVectorLeds);
//========================================================================================
//Parpadeo de todos los leds a nivel sistema
void ToogleAllLeds(uint8_t *leds, uint8_t sizeVectorLeds);
//========================================================================================
//Encendido de leds en modo barrido hacia la derecha
void OnLedsModSwetpRight(Leds_t *pStructLeds, uint8_t *leds, uint8_t sizeVectorLeds);
//========================================================================================
//Encendido de leds en modo barrido hacia la izquierda
void OnLedsModSwetpLefth(Leds_t *pStructLeds, uint8_t *leds, uint8_t sizeVectorLeds);
//========================================================================================
//Encnedido de leds en modo cascada
void OnLedsModSwetpWaterfall(Leds_t *pStructLeds, uint8_t *leds, uint8_t sizeVectorLeds);
//========================================================================================