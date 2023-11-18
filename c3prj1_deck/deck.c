#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){
  for(int i = 0; i < hand->n_cards; i++)
    {
      print_card(*hand->cards[i]);
      printf(" ");
    }
}

int deck_contains(deck_t * d, card_t c) {
  for(int i=0; i < d->n_cards; i++)
    {
      if(d->cards[i]->value == c.value && d->cards[i]->suit == c.suit)
	return 1;
    }
  return 0;
}

void shuffle(deck_t * d){
  for(int i = 0; i < d->n_cards; i++)
    {
      int random_n = random() % (d->n_cards - 1);
      card_t *temp;
      temp = d->cards[i];
      d->cards[i] = d->cards[random_n];
      d->cards[random_n] = temp;
    }
}

void assert_full_deck(deck_t * d) {
  for(int i = 0; i < d->n_cards; i++)
    {
      assert(deck_contains(d, card_from_num(i)));
    }
}

void add_card_to(deck_t * deck, card_t c)
{
  card_t * addC = malloc(sizeof(*addC));
  addC->suit = c.suit;
  addC->value = c.value;

  deck->cards = realloc(deck->cards, (deck->n_cards + 1)*sizeof(*deck->cards));
  size_t last = deck->n_cards;
  deck->cards[last] = addC;
  deck->n_cards++;
}

card_t * add_empty_card(deck_t * deck){
  card_t *addEc = malloc(sizeof(*addEc));
  addEc->value = 0;
  addEc->suit = 0;
  add_card_to(deck, *addEc);
  free(addEc);
  size_t last = deck->n_cards-1;
  return deck->cards[last];
}

deck_t * make_deck_exclude(deck_t * excluded_cards)
{
  deck_t * deck = malloc(sizeof(*deck));
  deck->cards = NULL;
  deck->n_cards = 0;
  for(int i = 0; i < 52; i++)
    {
      card_t card = card_from_num(i);
      if(!deck_contains(excluded_cards,card)){
	add_card_to(deck,card);
      }
    }
  return deck;
}

deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands)
{
  deck_t *rem = malloc(sizeof(*rem));
  rem->cards = NULL;
  rem->n_cards = 0;
  for(int i = 0; i < n_hands; i++)
    {
      deck_t *hand = hands[i];
      for(int j =0 ;j< hand->n_cards;j++){
	card_t *card = hand->cards[j];
	add_card_to(rem,*card);
      }
    }
  deck_t *res = make_deck_exclude(rem);
  free(rem);
  return res;
}

void free_deck(deck_t *deck){
  free(deck->cards);
}

