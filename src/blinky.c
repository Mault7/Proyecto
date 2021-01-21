/*=============================================================================
 * Copyright (c) 2021, Jose Mauricio Lara Tapia <Mau.lt7@hotmail.com.com>
 * All rights reserved.
 * License: 0bsd (see LICENSE.txt)
 * Date: 2021/01/01
 * Version: 1.0.0
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "blinky.h"
#include "sapi.h"
#include "Mef.h"
/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/
Mef_t Control;

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

int main(void)
{
  // ----- Setup -----------------------------------
  boardInit();
  init_MEf(&Control);
  //debounce_init(buttons, Vector_Tec,Vector_Led);

  // ----- Repeat for ever -------------------------
  while (true)
  {
    // debounce_update(buttons,Vector_Tec);
    update_Mef(&Control);
  }
  // YOU NEVER REACH HERE, because this program runs directly or on a
  // microcontroller and is not called by any Operating System, as in the
  // case of a PC program.
  return 0;
}