#include <uthash.h>
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// http://troydhanson.github.io/uthash/userguide.html
////////////////////////////////////////////////////////////////////////////////

// This is basically the pair that gets introduced in the map
// It looks like the intrusive data structures we find in boost
// or Doom3
typedef struct Human {
  // This will be our key
  int id;

  char* first_name;
  char* last_name;

  // This enable the structure to be used in a hash
  UT_hash_handle hh;
} Human;

int main(int argc, char *argv[argc])
{
  // This is our map
  Human* humansmap = NULL;

  // This is an element we insert
  Human h = {0, "Name", "Smith"};
  HASH_ADD_INT(humansmap, id, &h);

  // We can also insert dynamic memory members
  Human* h2 = (Human*)malloc(sizeof(Human));
  h2->id = 1;
  h2->first_name = "Crazy";
  h2->last_name = "Surname";
  HASH_ADD_INT(humansmap, id, h2);

  Human* out = NULL;
  int key = 0;
  HASH_FIND_INT(humansmap, &key, out);
  printf("Name: %s, Last Name: %s\n", out->first_name, out->last_name);

  key = 1;
  HASH_FIND_INT(humansmap, &key, out);
  printf("Name: %s, Last Name: %s\n", out->first_name, out->last_name);
   
  HASH_DEL(humansmap, &h);
  HASH_DEL(humansmap, h2);
  free(h2);
  return 0;
}
