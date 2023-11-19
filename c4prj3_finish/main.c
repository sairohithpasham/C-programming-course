#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"
#include "future.h"
#include "input.h"

void monte_carlo_trial(deck_t **hands,size_t n_hands, deck_t *deck, unsigned *wins, future_cards_t *fc)
{
  shuffle(deck);
  future_cards_from_deck(deck,fc);
  int winning_index = 0;
  deck_t *winningHand = hands[winning_index];
  int isTie = 0;
  for(int i = 1; i < n_hands; i++)
    {
      int result = compare_hands(winningHand, hands[i]);
      if(result < 0)
	{
	  winning_index = i;
	  winningHand = hands[i];
	  isTie = 0;
	}
      else if(result == 0)
	{
	  isTie = 1;
	}
      else
	{
	  continue;
	}
    }
  if(isTie == 1)
    {
      wins[n_hands]++;
    }
  else
    wins[winning_index]++;
}


int main(int argc, char ** argv) {
  //YOUR CODE GOES HERE
  if(argc!=2 && argc !=3)
    return EXIT_FAILURE;
  unsigned num_trials = 10000;
  if(argc == 3){
    num_trials = atoi(argv[2]);
  }
  FILE *f = fopen(argv[1],"r");
  if(f == NULL)
    {
      fprintf(stderr, "Cant open the file");
      return EXIT_FAILURE;
    }
  future_cards_t *fc = malloc(sizeof(*fc));
  fc->decks = NULL;
  fc->n_decks = 0;
  size_t n_hands = 0;
  deck_t **hands = read_input(f, &n_hands, fc);
  deck_t *deck = build_remaining_deck(hands,n_hands);
  unsigned *win = malloc((n_hands+1)*sizeof(*win));
  for(int i = 0; i<n_hands+1;i++)
    {
      win[i] = 0;
    }
  for(int i=0;i<num_trials;i++)
    {
      monte_carlo_trial(hands,n_hands,deck,win,fc);
    }
  for(int i =0; i<n_hands;i++)
    {
      double percentage_win = ((double)win[i]/num_trials)*100;
      printf("Hand %d won %u / %u times (%.2f%%)\n", i , win[i],num_trials,percentage_win);
    }
  printf("And there were %u ties\n", win[n_hands]);
  for(int i =0;i<n_hands;i++)
    {
      free_deck(hands[i]);
    }
  free_deck(deck);
  free(win);
  for(int i = 0;i < fc->n_decks;i++)
    {
      free_deck(&fc->decks[i]);
    }
  free(fc);
  if(fclose(f) != 0){
    fprintf(stderr, "Cant close the file");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
