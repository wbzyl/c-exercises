// Dokumentacja:
//
//   https://developer.gnome.org/glib/unstable/glib-Hash-Tables.html

#include <stdio.h>
#include <glib.h>

void print(gpointer state, gpointer capital, gpointer user_data) {
  printf("state: %s,\tcapital: %s\n", (char *) state, (char *) capital);
}

int main(int argc, char** argv) {
  GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);

  g_hash_table_insert(hash, "Polska", "Warszawa");
  g_hash_table_insert(hash, "Niemcy", "Berlin");
  g_hash_table_insert(hash, "Rosja", "Moskwa");

  printf("There are %d keys in the hash.\n\n", g_hash_table_size(hash));

  printf("The capital of Deutchland is %s.\n\n", (char *) g_hash_table_lookup(hash, "Niemcy"));

  g_hash_table_remove(hash, "Niemcy");

  g_hash_table_foreach(hash, print, NULL);

  g_hash_table_destroy(hash);
}
