#include <uthash.h>
#include <stdio.h>
#include <string.h>

// This is our pari<word, count>
typedef struct CountWords {
  char* word;
  int id;
  int counter;
  UT_hash_handle hh;
} CountWords;

// Pair builder
CountWords* newCountWords(char* word) {
  CountWords* cwptr = (CountWords*)malloc(sizeof(CountWords));
  cwptr->word = word;
  cwptr->id = 0;
  cwptr->counter = 1;
  return cwptr;
}

// Calculates the hash of a word
int wordHash(char* word) {
  int len = strlen(word);  
  int hash = 19;
  int i = 0;
  for (i = 0 ; i < len ; i += 1) {
    hash += (word[i] << (i % 13));
  }
  return hash;
}

// Add a word to the map
void addWord(CountWords** map, char* word) {
  // Look for the word. If found, increment counter
  CountWords* find = NULL;
  int hash = wordHash(word);
  HASH_FIND_INT(*map, &hash, find);
  if (find != NULL) {
    find->counter++;
    return;
  }

  // New word. Set hash, and add to map
  CountWords* wptr = newCountWords(word);
  wptr->id = hash;
  HASH_ADD_INT(*map, id, wptr);
}

// Empty the map. Free all memory
void clearMap(CountWords** map) {
  CountWords *s, *tmp;
  HASH_ITER(hh, *map, s, tmp) {
    HASH_DEL(*map, s);
    free(s);
  }
}

int main(int argc, char *argv[argc])
{
  // Create map and add a few words
  CountWords* countmap = NULL;
  addWord(&countmap, "bla");
  addWord(&countmap, "ble");
  addWord(&countmap, "bla");
  addWord(&countmap, "bla");

  // How many unique words are there?
  int words = HASH_COUNT(countmap);
  printf("Unique words: %d\n", words);

  // Print all words and counters
  CountWords *s, *tmp;
  HASH_ITER(hh, countmap, s, tmp) {
    printf("%s, %d\n", s->word, s->counter);
  }

  // Release memory
  clearMap(&countmap);
  return 0;
}





