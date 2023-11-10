#include "cards.h"
#include "cards.c"
int main(void) {
  card_t c;
  c = card_from_letters('0', 'd');
  print_card(c);
}
