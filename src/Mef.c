
#include "Mef.h"
#include "debounce.h"
#include "Leds.h"

uint8_t Vector_Tec[] = {TEC1, TEC2, TEC3, TEC4};
uint8_t Vector_Led[] = {LEDR, LEDG, LEDB, LED1, LED2, LED3};

debounce_button_t buttons[sizeof(Vector_Tec)];

void init_MEf(Mef_t *pMef)
{
    
    pMef->state = MOD_POWEROFF;
    pMef->time = time_Mef_ms;
    debounce_init(buttons, Vector_Tec);
    delayWrite(&delay_Mef, pMef->time);
    initLeds(&leds, Vector_Led, sizeof(Vector_Led));
}

void update_Mef(Mef_t *pMef)
{
    debounce_update(buttons, Vector_Tec);

    switch (pMef->state)
    {
    case MOD_POWEROFF:
        
        for (int i = 0; i < sizeof(Vector_Tec); i++)
        {
            if (buttons[i].Release == TRUE)
            {
                pMef->state = i + 1;
                PowerOffAllLeds(Vector_Led, sizeof(Vector_Led));
            }
        }

        break;
    case MOD_TOOGLE:
        
        ToogleAllLeds(Vector_Led, sizeof(Vector_Led));

        for (int i = 0; i < sizeof(Vector_Tec); i++)
        {
            if (buttons[i].Release == TRUE)
            {
                pMef->state = i + 1;
                PowerOffAllLeds(Vector_Led, sizeof(Vector_Led));
            }
        }
        break;
    case MOD_SWEPT_RIGTH:
        
        OnLedsModSwetpRight(&leds, Vector_Led, sizeof(Vector_Led));

        for (int i = 0; i < sizeof(Vector_Tec); i++)
        {
            if (buttons[i].Release == TRUE)
            {
                pMef->state = i + 1;
                PowerOffAllLeds(Vector_Led, sizeof(Vector_Led));
                leds.ContFalling = 0;
                leds.ContRising = 0;
                leds.state = 0;
            }
        }
        break;
    case MOD_SWEPT_LEFTH:
        
        OnLedsModSwetpLefth(&leds, Vector_Led, sizeof(Vector_Led));
        for (int i = 0; i < sizeof(Vector_Tec); i++)
        {
            if (buttons[i].Release == TRUE)
            {
                pMef->state = i + 1;
                PowerOffAllLeds(Vector_Led, sizeof(Vector_Led));
                leds.ContFalling = 0;
                leds.ContRising = 0;
                leds.state = 0;
            }
        }
        break;
    case MOD_WATERFALL:
        
        OnLedsModSwetpWaterfall(&leds, Vector_Led, sizeof(Vector_Led));
        for (int i = 0; i < sizeof(Vector_Tec); i++)
        {
            if (buttons[i].Release == TRUE)
            {
                pMef->state = i + 1;
                PowerOffAllLeds(Vector_Led, sizeof(Vector_Led));
            }
        }
        break;
    default:
        break;
    }
}
