#include "deck.h"
#include "future.h"
#include "cards.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

deck_t * hand_from_string(const char * str, future_cards_t * fc)
{
  deck_t * deck = malloc(sizeof(*deck));
  deck->cards = NULL;
  deck->n_cards = 0;
  for(int i = 0; i<strlen(str);i++)
    {
      if((str[i] == '\n')||(str[i] == ' '))
	continue;
      else
	{
	  if(str[i]=='?')
	    {
	      i++;
	      char number[strlen(str)];
	      int c = 0;
	      while(!((str[i] == '\n')||(str[i] == ' '))){
		number[n] = str[i];
		i++;
		c++;
	      }
	      number[c] = '\0';
	      add_future_card(fc,atoi(number),add_empty_card(deck));
	    }
	  else{
	    card_t a = card_from_letters(str[i],str[i+1]);
	    add_card_to(deck,a);
	    i++;
	  }
	}
    }
  if(deck->n_cards <  5)
    return NULL;
  return deck;
}

deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc)
{
  deck_t **arr = NULL;
  size_t sz = 0,n_hand = 0;
  char *line=NULL;
  while(getline(&line,&sz,f)>=0)
    {
      arr = realloc(arr, (n_hand+1)*sizeof(*arr));
      deck_t *deck = hand_from_string(line,fc);
      if(deck==NULL)
	continue;
      arr[n_hand] = deck;
      n_hand++;
    }
    free(line);
    *n_hands = n_hand;
    return arr;
}
