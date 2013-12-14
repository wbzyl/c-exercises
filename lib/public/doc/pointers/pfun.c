#include <stdio.h>

/*  str_copy[123]: skopiuj t do s  */

/*  wersja z indeksowaniem tablic  */
void str_copy1(char *s, char *t);

/*  wersja wskaźnikowa I  */
void str_copy2(char *s, char *t);

/*  wersja wskaźnikowa II  */
void str_copy3(char *s, char *t);

/*  str_cmp: zwróć <0 jeśli s<t, 0 jeśli s==t, >0 jeśli s>t  */
int str_cmp(char *s, char *t);

int main() {
  char *src = "ala ma kota";
  char dest1[100], dest2[100], dest3[100];

  str_copy1(dest1, src);
  str_copy2(dest2, src);
  str_copy3(dest3, src);

  printf("\tdest1 = `%s'\n", dest1);
  printf("\tdest2 = `%s'\n", dest3);
  printf("\tdest3 = `%s'\n", dest3);

  printf("\t%s %s %s\n", "ola",
	 str_cmp("ola","ala")==-1 ? "<" : ">=", "ala");
}

void str_copy1(char *s, char *t) {
  int i = 0;
  while ((s[i]=t[i]) != '\0')
    i++;
}

void str_copy2(char *s, char *t) {
  while ((*s=*t) != '\0') {
    s++;
    t++;
  }    
}

void str_copy3(char *s, char *t) {
  while ((*s++ = *t++) != '\0')
    ;
}

int str_cmp(char *s, char *t) {
  for ( ; *s==*t; s++, t++)
    if (*s=='\0')
      return 0;
  return *s-*t;
}
