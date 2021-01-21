#include "debounce.h"

void debounce_init(debounce_button_t *debounce_button, uint8_t *vector_tec)
{
    for (int i = 0; i < sizeof(vector_tec); i++)
    {
        debounce_button[i].state = UP;
        debounce_button[i].tec = vector_tec[i];
        debounce_button[i].time_debounce = time_debounce_ms;
        debounce_button[i].Press = FALSE;
        debounce_button[i].Release = FALSE;
    }
}
void debounce_update(debounce_button_t *debounce_button, uint8_t *vector_tec)
{
    for (int i = 0; i < sizeof(vector_tec); i++)
    {

        switch (debounce_button[i].state)
        {

        case UP:

            debounce_button[i].Press = FALSE;
            debounce_button[i].Release = FALSE;
            if (!gpioRead(debounce_button[i].tec))
            {
                debounce_button[i].state = FALLING;
                delayWrite(&delay_debounceButton, debounce_button[i].time_debounce);
            }

            break;

        case FALLING:
            if (delayRead(&delay_debounceButton))
            {
                if (!gpioRead(debounce_button[i].tec))
                {
                    debounce_button[i].state = DOWN;
                }
                else
                {
                    debounce_button[i].state = UP;
                }
            }

            break;
        case DOWN:
            debounce_button[i].Press = TRUE;
            debounce_button[i].Release = FALSE;

            if (gpioRead(debounce_button[i].tec))
            {
                debounce_button[i].state = RISING;
                delayWrite(&delay_debounceButton, debounce_button[i].time_debounce);
            }
            break;
        case RISING:
            debounce_button[i].Press = TRUE;
            debounce_button[i].Release = FALSE;

            if (delayRead(&delay_debounceButton))
            {
                if (!gpioRead(debounce_button[i].tec))
                {
                }
                else
                {
                    debounce_button[i].state = UP;
                    debounce_button[i].Press = FALSE;
                    debounce_button[i].Release = TRUE;
                }
            }

            break;
        default:
            //debounce_init(debounce_button, debounce_button[i].tec,debounce_button[i].led);
            break;
        }
    }
}
