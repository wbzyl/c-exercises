#include <stdio.h>
#include <stdlib.h>  /* atoi */

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/*  day_of_year: podaj dzień roku na podstawie miesiąca i dnia  */
int day_of_year(int year, int month, int day);
/*  mont_day: podaj miesiąc i dzień na podstawie dnia roku  */
int month_day(int year, int yearday, int *monthp, int *dayp);
/*  month_name: podaj nazwę n-tego miesiąca  */
char *month_name(int n);
void usage(void);

int main(int argc, char *argv[]) {
  int y, yd, m, d;

  //int i;
  //printf("\targc = %d\n", argc);
  //printf("\targumenty wywołania programu:");
  //for (i=0; i<argc; i++)
  //  printf("  %s", argv[i]);
  //printf("\n");

  if (argc != 3 && argc != 4)
    usage();
  else if (argc==3) { /* oblicz day i year */
    y = atoi(argv[1]);
    yd = atoi(argv[2]);
    printf("\trok / dzień roku = %d / %d\n", y, yd);
    month_day(y,yd,&m,&d);
    printf("\trok miesiąc dzień = %d  %s  %d\n", y, month_name(m), d);
  } else if (argc==4) { /* oblicz: month i day */
    y = atoi(argv[1]);
    m = atoi(argv[2]);
    d = atoi(argv[3]);
    printf("\trok miesiąc dzień = %d %s %d\n", y, month_name(m), d);
    yd = day_of_year(y,m,d);
    printf("\trok / dzień roku = %d / %d\n", y, yd);
  }
}

void usage() {
  printf("Użycie: cdate YEAR YEARDAY\n");
  printf("        cdate YEAR MONTH DAY\n");
}

int month_day(int year, int yearday, int *monthp, int *dayp) {
  int i, leap;

  leap = (year%4==0 && year%100!=0) || year%400==0;
  for (i=1; yearday>daytab[leap][i]; i++)
    yearday -=daytab[leap][i];
  *monthp = i;
  *dayp = yearday;
  return 0;
}

int day_of_year(int year, int month, int day) {
  int i, leap;

  leap = (year%4==0 && year%100!=0) || year%400==0;  
  for (i=1; i<month; i++)
    day += daytab[leap][i];
  return day;
}

/* inicjowanie tablic wskaźników */
char *month_name(int n) {
  char *name[] = {
    "błędny miesiąc",
    "styczeń", "luty", "marzec", 
    "kwiecień", "maj", "czerwiec",
    "lipiec", "sierpień", "wrzesień",
    "październik", "listopad", "grudzień"
  };
  return (n<1 || n>12) ? name[0] : name[n];
}
