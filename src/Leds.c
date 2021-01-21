#include "Leds.h"

void initLeds(Leds_t *pStructLeds, uint8_t *leds, uint8_t sizeVectorLeds)
{
    pStructLeds->state = 0;
    pStructLeds->ContRising = 0;
    pStructLeds->ContFalling = sizeVectorLeds - 1;
    pStructLeds->aux = 0;
}

void PowerOffAllLeds(uint8_t *leds, uint8_t sizeVectorLeds)
{
    for (int i = 0; i < sizeVectorLeds; i++)
    {
        gpioWrite(leds[i], 0);
    }
}

void PowerOnAllLeds(uint8_t *leds, uint8_t sizeVectorLeds)
{
    for (int i = 0; i < sizeVectorLeds; i++)
    {
        gpioWrite(leds[i], 1);
    }
}

void ToogleAllLeds(uint8_t *leds, uint8_t sizeVectorLeds)
{
    delayWrite(&delay_leds, 500);
    if (delayRead(&delay_leds))
    {
        for (int i = 0; i < sizeVectorLeds; i++)
        {
            gpioToggle(leds[i]);
        }
    }
}
void OnLedsModSwetpRight(Leds_t *pStructLeds, uint8_t *leds, uint8_t sizeVectorLeds)
{
    delayWrite(&delay_leds, 60);

    gpioWrite(leds[pStructLeds->ContRising], pStructLeds->state);
    if (delayRead(&delay_leds))
    {
        pStructLeds->ContRising++;
        if (pStructLeds->ContRising > sizeVectorLeds - 1)
        {
            pStructLeds->ContRising = 0;
            pStructLeds->state = !pStructLeds->state;
        }
    }
}
void OnLedsModSwetpLefth(Leds_t *pStructLeds, uint8_t *leds, uint8_t sizeVectorLeds)
{
    delayWrite(&delay_leds, 60);

    gpioWrite(leds[pStructLeds->ContFalling], pStructLeds->state);

    if (delayRead(&delay_leds))
    {
        pStructLeds->ContFalling--;

        if (pStructLeds->ContFalling == 255)
        {
            pStructLeds->ContFalling = sizeVectorLeds - 1;
            pStructLeds->state = !pStructLeds->state;
        }
    }
}

void OnLedsModSwetpWaterfall(Leds_t *pStructLeds, uint8_t *leds, uint8_t sizeVectorLeds)
{
    delayWrite(&delay_leds, 60);
    if (0 == sizeVectorLeds % 2)
    {

        if (delayRead(&delay_leds))
        {
            gpioWrite(leds[(pStructLeds->ContRising = sizeVectorLeds / 2) + pStructLeds->aux], pStructLeds->state);
            gpioWrite(leds[(pStructLeds->ContFalling = sizeVectorLeds / 2) - (1 + pStructLeds->aux)], pStructLeds->state);
            pStructLeds->aux++;
            if (pStructLeds->aux ==(sizeVectorLeds / 2))
            {
                pStructLeds->aux = 0;
                pStructLeds->state = !pStructLeds->state;
            }
        }
    }
    if (1 == sizeVectorLeds % 2)
    {
        gpioWrite(leds[(sizeVectorLeds / 2)], pStructLeds->state);
        if (delayRead(&delay_leds))
        {

            gpioWrite(leds[pStructLeds->ContRising = (sizeVectorLeds / 2) + (1 + pStructLeds->aux)], pStructLeds->state);
            gpioWrite(leds[pStructLeds->ContFalling = (sizeVectorLeds / 2) - (1 + pStructLeds->aux)], pStructLeds->state);
            pStructLeds->aux++;
            if (pStructLeds->aux == (sizeVectorLeds / 2))
            {
                pStructLeds->aux = 0;
                pStructLeds->state = !pStructLeds->state;
            }
        }
    }
}
