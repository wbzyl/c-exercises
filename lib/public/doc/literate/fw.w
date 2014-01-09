% --------------------------------------------------------------------
% This file is part of CWEB-NLS.
% It is distributed WITHOUT ANY WARRANTY, express or implied.
%
% Copyright (C) 2002 W{\l}odek Bzyl
% --------------------------------------------------------------------
\getCVSrevision$Revision: 1.1 $
\getCVSdate$Date: 2004/09/30 11:26:56 $
\getCVSsource$Source: /var/cvs/wyklady/JP1-L/80-ProgramowanieOpisowe/fw.w,v $
% --------------------------------------------------------------------

% Strona tytu³owa --

\def\title{FW}
\def\topofcontents{\null\vfill
  \centerline{\titlefont ZLICZANIE S£ÓW}
  \vskip 15pt
  \centerline{(wersja \CVSrevision)}
  \vskip1in
  \vfill}
\def\botofcontents{\parskip=0pt \parindent=0pt
  \vskip 0pt plus 1filll
  Copyright \copyright\ 2002 W³odek Bzyl
  \bigskip
  Jest to wersja programu autorstwa R.~Haighta
  z~ksi±¿ki B.~W. Kernighana, D.~M. Ritchiego, {\it Jêzyk ANSI C}.
  Program ten korzysta z~{\it locales}.
  Oznacza to, ¿e s³owa zostan± wypisane w~porz±dku alfabetycznym
  w³a¶ciwym dla jêzyka ustalonego przez zmienn± ¶rodowiskow±
  {\tt LANG}.
  \bigskip
  \line{\tt\CVSsource\hfil\CVSdate}\par}

\secpagedepth=2 % sekcje `@@*1' nie bêd± zaczynaæ siê od nowej strony

\begingroup \catcode`\!=\active
  \global\def!{\char`\| }
\endgroup
\def\commandline{\begingroup
  \catcode`\!=\active \catcode`\_=12
  \xcommandline}
\def\xcommandline #1{\medbreak
  \leftline{\hskip5em#1}\endgroup
  \medskip}

\def\FW/{{\tt fw\spacefactor1000}}
\def\GCC/{{\mc GCC\spacefactor1000}}
\def\Info/{{\mc INFO\spacefactor1000}}
\def\AnsiC/{{\mc ANSI C\spacefactor1000}}
\def\ASCII/{{\mc ASCII\spacefactor1000}}

% Polskie litery w nazwach zmiennych
\noatl % nie sk³adaj poni¿szych linijek
@l b1 xa
@l e6 xc
@l ea xe
@l b3 xl
@l f1 xn
@l f3 xo
@l b6 xs
@l bc xx
@l bf xz
@l a1 xA
@l c6 xC
@l ca xE
@l a3 xL
@l d1 xN
@l d3 xO
@l a6 xS
@l ac xX
@l af xZ

\input epsf.tex

@* Wstêp.
   Przedstawiany tu program po wczytaniu tekstu ze standardowego
wej¶cia wypisuje uporz±dkowan± alfabetycznie listê s³ów wraz z~liczb±
ich wyst±pieñ w~podanym tek¶cie.  Przez {\it s³owo\/} rozumiemy ka¿dy
napis z³o¿ony z~liter oddzielony od innych napisów znakiem nie bêd±cym
liter±. Wielkie i~ma³e litery nie bêd± rozró¿niane.

Program \FW/ mo¿na wykorzystaæ do wyszukiwania najczê¶ciej
wystêpuj±cych s³ów. Wykonanie poni¿szego polecenia spowoduje
wypisanie na ekranie monitora dziesiêciu linii zawieraj±cych
najczê¶ciej wystêpuj±ce s³owa w~tek¶cie tego programu:
  \commandline{\tt fw < fw.w ! sort +0nr ! head -n10}
@.sort, {\rm program}@>
@.head, {\rm program}@>
@^s³owo, definicja@>
@^u¿ycie {\tt fw}, przyk³ad@>

@ Program czyta tekst, po jednym wierszu, ze |stdin| przy pomocy
  funkcji |getline|. Funkcja ta nie nale¿y do standardowej
biblioteki I/O (wej¶cia/wyj¶cia). Nale¿y ona do biblioteki I/O
kompilatora \GCC/. U¿ywam tej funkcji poniewa¿ umo¿liwia ona
wczytywanie dowolnie d³ugich wierszy tekstu.

Napisy porównywane s± przez funkcjê |strcoll|. Funkcja ta,
porównuj±c napisy stosuje kolejno¶æ znaków jêzyka
okre¶lonego zmienn± ¶rodowiskow± {\tt LANG}. Aby program
\FW/ zaliczy³ polskie znaki diakrytyczne do liter i~s³owa zosta³y
wypisane wed³ug porz±dku alfabetycznego obowi±zuj±cego w~Polsce,
wystarczy przed uruchomieniem tego programu ustawiæ zmienn±
|LANG| tak, aby wskazywa³a jêzyk polski:
\commandline{\tt export LANG=pl_PL}
\noindent albo uruchamiamy program w~taki oto sposób:
\commandline{\tt LANG=pl_PL \ cat \hbox{$\langle$\it nazwa pliku\/$\rangle$} ! fw}
W~programie korzystam z~kilkunastu funkcji, których
prototypy zawarte s± w~standardowych plikach nag³ówkowych.

@.LANG, {\rm zmienna ¶rodowiskowa}@>

@d _GNU_SOURCE /* zdefiniuj |getline| */

@c
#include <stdio.h>
	 /* zawiera deklaracjê funkcji |getline| */
#include <stdlib.h> /* |malloc|, |EXIT_SUCCESS| */
#include <limits.h> /* |UCHAR_MAX| */
#include <locale.h> /* |setlocale| -- wp³ywa na dzia³anie
	    poni¿szych funkcji */
#include <ctype.h>  /* |isupper|, |islower|, |tolower| */
#include <string.h> /* |strcoll|, |strtok| */

@* Drzewa binarne. \begingroup\hangindent=-2.5in \hangafter=3
   Wczytywane s³owa s± na bie¿±co wstawiane do drzewa
binarnego. Zanim powstanie wierzcho³ek z~nowo wczytanego s³owa
zostanie ono porównane ze s³owem uprzednio wstawionym
do~korzenia. Je¶li nowe s³owo jest alfabetycznie mniejsze od
porównywanego s³owa, to operacja wstawiania zostanie zastosowana
rekurencyjnie do lewego poddrzewa. Je¶li jest wiêksze, to do prawego
poddrzewa. Je¶li jest równe s³owu porównywanemu to licznik jego wyst±pieñ
w~wczytywanym tek¶cie zostanie zwiêkszony o~1.%
  \vadjust{\medskip}\hfil\break
  \indent Obok przedstawiono drzewo binarne zdania z~ksi±¿ki
  S.~J. Leca, {\it My¶li nieuczesane\/}: ,,Chocia¿ krowie dasz
  kakao, nie wydoisz czekolady.''%
  \vadjust{\medskip}\hfil\break
  {\it Uwaga\/}: W~jêzyku \CEE/ nie dopuszcza siê, aby struktura by³a
definiowana rekurencyjnie inaczej ni¿ za pomoc± wska¼ników do siebie
samej.
  \medskip
  \rightline{\smash{\epsffile{fw.1}}}
  \vskip-\bigskipamount
  \endgroup
\labsec{sec:drzewa_binarne}
@^Lec SJ@>

@c
struct wierzcho³ek
{
  char *s³owo;
  int liczba_wyst±pieñ;
  struct wierzcho³ek *lewe_poddrzewo;
  struct wierzcho³ek *prawe_poddrzewo;
};

@ @<Zmienne lokalne funkcji main@>=
struct wierzcho³ek *korzeñ = NULL;

@*1 Utworzenie i inicjalizacja nowego wierzcho³ka.
    Je¶li zabraknie pamiêci na nowy wierzcho³ek to program \FW/ koñczy
dzia³anie. Je¶li miejsce jest, to kopiujemy wczytane s³owo |s|
z~bufora w~nowe miejsce w~pamiêci. Gdyby¶my tego nie zrobili, to
nastêpne wywo³anie funkcji |getline| umie¶ci³oby w~buforze now± liniê,
zamazuj±c tym samym poprzedni± zawarto¶æ zawieraj±c± s³owo |s|.

@c
struct wierzcho³ek *nowy_wierzcho³ek(char *s)
{
  struct wierzcho³ek *w = malloc(sizeof(struct wierzcho³ek));

  if (w==NULL)
    @<Zakoñcz dzia³anie komunikatem o braku pamiêci@>@;
  w->s³owo=strdup(s);
  if (w->s³owo==NULL)
    @<Zakoñcz dzia³anie komunikatem o braku pamiêci@>@;
  w->liczba_wyst±pieñ=1;
  w->lewe_poddrzewo=w->prawe_poddrzewo=NULL;

  return w;
}

@*1 Wstawianie wierzcho³ków do drzewa.
    Funkcja |wstaw_wierzcho³ek| jest rekurencyjna. Je¶li wczytywany
ci±g s³ów jest ju¿ czê¶ciowo uporz±dkowany, to budowane drzewo ma
ma³o rozga³êzieñ i~ro¶nie w~dó³ bardzo nisko (tak rosn± drzewa
w~RAM). Równie¿ w~takiej sytuacji, drzewo ro¶nie coraz wolniej,
poniewa¿ funkcja |wstaw_wierzcho³ek| bêdzie przegl±daæ wiêkszo¶æ
wierzcho³ków drzewa zanim wstawi nowy wierzcho³ek.

@c
struct wierzcho³ek *wstaw_wierzcho³ek(struct wierzcho³ek *w, char *s)
{
  int wynik_porównania;

  if (w==NULL)
    w=nowy_wierzcho³ek(s);
  else if ((wynik_porównania=strcoll(s,w->s³owo))==0)
    w->liczba_wyst±pieñ++;
  else if (wynik_porównania<0)
    w->lewe_poddrzewo=wstaw_wierzcho³ek(w->lewe_poddrzewo,s);
  else
    w->prawe_poddrzewo=wstaw_wierzcho³ek(w->prawe_poddrzewo,s);

  return w;
}

@*1 Drukowanie s³ów wstawionych do drzewa w~porz±dku alfabetycznym.
   Funkcja rekurencyjna |inorder_print| wypisze s³owa wystêpuj±ce
w~wierzcho³kach w~porz±dku alfabetycznym okre¶lonym przez
kolejno¶æ liter alfabetu jêzyka ustalonego przez zmienn± ¶rodowiskow±
{\tt LANG}. Jest tak, poniewa¿ dla ka¿dego wierzcho³ka, s³owa
wystêpuj±ce w~jego lewym poddrzewie s± mniejsze alfabetycznie od s³owa
wystêpuj±cego w~wierzcho³ku, a~ono samo jest mniejsze od wszystkich
s³ów wystêpuj±cych w~jego prawym poddrzewie
(zob. rysunek w~sekcji~\refsec{sec:drzewa_binarne}).
@.LANG, {\rm zmienna ¶rodowiskowa}@>

@c
void inorder_print(struct wierzcho³ek *w)
{
  if (w!=NULL) {
    inorder_print(w->lewe_poddrzewo);
    printf("%9d %s\n",w->liczba_wyst±pieñ,w->s³owo);
    inorder_print(w->prawe_poddrzewo);
  }
}

@ Przed umieszczeniem s³owa w~drzewie zamieniamy wielkie litery na ma³e.

@c
char *lowercase(char *s)
{
  char *c = s;

  while (isupper(*c)) {
    *c=tolower(*c);
    c++;
  }
  return s;
}

@ Jest mo¿liwe, by ten program zachowywa³ siê sensowniej, ni¿ tylko
  koñcz±c dzia³anie w~tym miejscu -- patrz dokumentacja \Info/ do
biblioteki {\tt libc} wêze³: {\it Basic Allocation}.

@<Zakoñcz dzia³anie komunikatem o braku pamiêci@>=
{
  fprintf(stderr, "! Virtual memory exhausted.\n");
  exit(1);
}

@* Funkcja g³ówna.
   G³ówna czê¶æ programu to pêtla |while|, w~której tekst ze
|stdin| wczytywany jest przez funkcjê |getline| do |bufora_p|.
Z~wczytanego wiersza kolejne s³owa oddzielane s± przez |strtok|
i~wstawiane na bie¿±co do drzewa binarnego przez funkcjê
|wstaw_wierzcho³ek|. Po wczytaniu ostatniego wiersza ze |stdin|,
funkcja |inorder_print| wypisze wszystkie przeczytane s³owa wraz
z~liczb± ich wyst±pieñ.

@.LANG, {\rm zmienna ¶rodowiskowa}@>

@c
int main ()
{
  @<Zmienne lokalne funkcji main@>@;@#

  @<Ustal jêzyk na podstawie warto¶ci zmiennej ¶rodowiskowej |LANG|@>@;
  @<Utwórz |ogranicznik| dla funkcji |strtok|@>@;@#

  while (getline(&bufor_p,&d³ugo¶æ_bufora,stdin)!=-1) {
    while ((nastêpne_s³owo=strtok(bufor_p,ogranicznik))!=NULL) {
      korzeñ=wstaw_wierzcho³ek(korzeñ,lowercase(nastêpne_s³owo));
      bufor_p=NULL; /* dlaczego |NULL| -- patrz strona
		       podrêcznika po¶wiêcona |strtok| */
    }
  }

  inorder_print(korzeñ);

  return EXIT_SUCCESS;
}

@ Je¶li przed wywo³aniem |getline| nadamy zmiennym |bufor_p|
  i~|d³ugo¶æ_bufora| warto¶æ |0|, to funkcja sama przydzieli
sobie pamiêæ na bufor i~adres pocz±tku bufora umie¶ci w~|bufor_p|.
Napotykaj±c koniec pliku |getline| zwraca warto¶æ $-1$.

@<Zmienne lokalne funkcji main@>=
char *bufor_p = 0;
size_t d³ugo¶æ_bufora = 0;

@ Wywo³anie |setlocale| z drugim argumentem bêd±cym pustym
napisem spowoduje, ¿e funkcje: |isupper|, |islower|, |tolower|
i~|strcoll| bêd± korzystaæ z~danych lokalnych ({\it locale data})
ustalonych przez zmienn± ¶rodowiskow± {\tt LANG}.
@.LANG, {\rm zmienna ¶rodowiskowa}@>

@<Ustal jêzyk na podstawie warto¶ci zmiennej ¶rodowiskowej |LANG|@>=
setlocale(LC_CTYPE,""); /* wczytaj kody wielkich i ma³ych liter */
setlocale(LC_COLLATE,""); /* wczytaj dane dotycz±ce porz±dku alfabetycznego */

@ Kolejne wywo³ania |strtok| oddzielaj± od pocz±tku bufora |bufor_p|
  napisy rozdzielone znakami umieszczonymi w~tablicy |ogranicznik|.
Tablica ta zawiera tylko znaki nie bêd±ce znakami alfanumerycznymi.

@<Utwórz |ogranicznik| dla funkcji |strtok|@>=
for (i=1,k=0; i<=UCHAR_MAX; i++)@+if (!isalnum(i)) ogranicznik[k++]=i;
ogranicznik[k]='\0';

@ Pozostaje jeszcze tylko zadeklarowaæ kilka zmiennych i~program jest
  gotowy. ,,To by by³o na tyle'' jak mawia prof.~Stanis³awski.

@^Stanis³awski JT, profesor@>

@<Zmienne lokalne funkcji main@>=
unsigned int i,k; /* liczniki pêtli */
char ogranicznik[UCHAR_MAX]; /* argument |delim| w~|strtok| */
char *nastêpne_s³owo;

@* Skorowidz.
   Poni¿ej znajdziesz listê identyfikatorów u¿ytych w~programie
\.{hello.w}. Liczba wskazuje na numer sekcji, w~której u¿yto identyfikatora,
a~liczba podkre¶lona --- numer sekcji w~której zdefiniowano identyfikator.
