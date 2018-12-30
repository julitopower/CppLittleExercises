#include <stdio.h>

#include "cJSON.h"

int main(int argc, char *argv[argc])
{
  // Print cJSON version
  printf("cJSON version is %s\n", cJSON_Version());

  // Test json string
  const char* json = "{\"key\":\"value\", \"key2\" : \"value2\"}";

  // Parse json and obtain root node. We are reponsible from calling
  // cJSON_Delete(root) in order to release all resources associated
  // with it
  cJSON* root =  cJSON_Parse(json);

  // Print the two key/value pairs available
  printf("%s, %s\n", root->child->string, root->child->valuestring);
  printf("%s, %s\n", root->child->next->string, root->child->next->valuestring);

  // Specifically get the "key" and "key2" children
  cJSON* key = cJSON_GetObjectItem(root, "key");
  printf("%s, %s\n", key->string, key->valuestring);
  cJSON* key2 = cJSON_GetObjectItem(root, "key2");
  printf("%s, %s\n", key2->string, key2->valuestring);

  // Ensure resources get deleted
  cJSON_Delete(root);
  return 0;
}
