#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value >=2 && c.value <= VALUE_ACE);
  assert((c.suit == SPADES)||(c.suit == HEARTS)||(c.suit == DIAMONDS)||(c.suit == CLUBS));
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r){
  case STRAIGHT_FLUSH: 
    return "STRAIGHT_FLUSH";
    break;
  case FOUR_OF_A_KIND:
    return "FOUR_OF_A_KIND";
    break;
  case FULL_HOUSE:
    return "FULL_HOUSE";
    break;
  case FLUSH:
    return "FLUSH";
    break;
  case STRAIGHT:
    return "STRAIGHT";
    break;
  case THREE_OF_A_KIND:
    return "THREE_OF_A_KIND";
    break;
  case TWO_PAIR:
    return "TWO_PAIR";
    break;
  case PAIR:
    return "PAIR";
    break;
  case NOTHING:
    return "NOTHING";
    break;
}
  return "NOTHING";
}
char value_letter(card_t c) {
  switch(c.value){
  case 0:
    return '0';
    break;
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
    return ('0' + c.value);
    break;
  case 10:
    return '0';
    break;
  case 11:
    return 'J';
    break;
  case 12:
    return 'Q';
    break;
  case 13:
    return 'K';
    break;
  case 14:
    return 'A';
    break;
  }
  return 'x';
}


char suit_letter(card_t c) {
  switch(c.suit)
    {
    case SPADES:
      return 's';
      break;
    case HEARTS:
      return 'h';
      break;
    case DIAMONDS:
      return 'd';
      break;
    case CLUBS:
      return 'c';
      break;
    case NUM_SUITS:
      return 'x';
    }
  return 'x';
}

void print_card(card_t c) {
  printf("%c%c",value_letter(c),suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  assert((value_let >= 50 && value_let <= 57) || (value_let == 48) || (value_let == 65) || (value_let == 74) || (value_let == 81) || (value_let == 75));
  assert((suit_let == 115) || (suit_let == 104) || (suit_let == 100) || (suit_let == 99));
  switch(value_let)
    {
    case '0':
      temp.value = 10;
      break;
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      temp.value = value_let - '0';
      break;
    case 'A':
      temp.value = 14;
      break;
    case 'J':
      temp.value = 11;
      break;
    case 'Q':
      temp.value = 12;
      break;
    case 'K':
      temp.value = 13;
      break;
    }
  switch(suit_let)
    {
    case 's':
      temp.suit = SPADES;
      break;
    case 'h':
      temp.suit = HEARTS;
      break;
    case 'd':
      temp.suit = DIAMONDS;
      break;
    case 'c':
      temp.suit = CLUBS;
      break;
    }
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  int div, rem;
  div = c/13;
  rem = c%13;
  if(div == 0)
    temp.suit = SPADES;
  else if(div == 1)
    temp.suit = HEARTS;
  else if(div == 2)
    temp.suit = DIAMONDS;
  else if(div == 3)
    temp.suit = CLUBS;
  else
    temp.suit = NUM_SUITS;
  switch(rem)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
      temp.value = rem+1;
      break;
    case 0:
      temp.value = 14;
      break;
    case 9:
      temp.value = 10;
      break;
    case 10:
      temp.value = 11;
      break;
    case 11:
      temp.value = 12;
      break;
    case 12:
      temp.value = 13;
      break;
    }
  return temp;
}
