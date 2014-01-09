#include <stdio.h>
#include <glib.h>

int main(int argc, char** argv) {
  GSList *list = NULL;  // singly-linked lists
  GSList *iterator = NULL;

  list = g_slist_append(list, "Polska");
  list = g_slist_append(list, "Niemcy");
  list = g_slist_append(list, "Rosja");

  printf("liczba elementów na liście: %d\n\n", g_slist_length(list));

  for (iterator = list; iterator; iterator = iterator->next) {
    printf("bieżący element: '%s'\n", (char *) iterator->data);
  }

  g_slist_free(list);
}
