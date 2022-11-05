#pragma once
#include "esphome.h"
#include "ttgo-t-display-drawmenu.h"

/*
PRIVATE CODE(used by PUBLIC CODE later on in this file)

*/


/*
PUBLIC CODE (to be called from lambda in YAML file)
*/
void drawMyMenu(esphome::template_::TemplateSelect *p) {
  id(currentMenuSize) = p->size();
  drawMenu(p);
}


