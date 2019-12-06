#include "crkbd.h"

#define L_BASE 0
#define L_LOWER 4
#define L_RAISE 8
#define L_EXTRA 16
#define L_ADJUST 65548

char layer_state_str[40];

char *read_layer_state(void)
{
  switch (layer_state)
  {
    case L_BASE:
       snprintf(layer_state_str, sizeof(layer_state_str), "<< QWERTY >>");
       break;
    case L_LOWER:
       snprintf(layer_state_str, sizeof(layer_state_str), "<< LOWER >>");
       break;
    case L_RAISE:
       snprintf(layer_state_str, sizeof(layer_state_str), "<< RAISE >>");
       break;
    case L_EXTRA:
       snprintf(layer_state_str, sizeof(layer_state_str), "<< EXTRA >>");
       break;
    case L_ADJUST:
       snprintf(layer_state_str, sizeof(layer_state_str), "<< ADJUST >>");
       break;
    default:
       snprintf(layer_state_str,sizeof(layer_state_str), "WTH? ==> %ld", layer_state);
  }

  return layer_state_str;
}
