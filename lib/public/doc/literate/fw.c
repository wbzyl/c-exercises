#define _GNU_SOURCE  \

/*2:*/
#line 115 "./fw.w"

#include <stdio.h> 

#include <stdlib.h>  
#include <limits.h>  
#include <locale.h>  

#include <ctype.h>   
#include <string.h>  

/*:2*//*3:*/
#line 149 "./fw.w"

struct wierzchoxlek
{
char*sxlowo;
int liczba_wystxapiexn;
struct wierzchoxlek*lewe_poddrzewo;
struct wierzchoxlek*prawe_poddrzewo;
};

/*:3*//*5:*/
#line 168 "./fw.w"

struct wierzchoxlek*nowy_wierzchoxlek(char*s)
{
struct wierzchoxlek*w= malloc(sizeof(struct wierzchoxlek));

if(w==NULL)
/*9:*/
#line 248 "./fw.w"

{
fprintf(stderr,"! Virtual memory exhausted.\n");
exit(1);
}

/*:9*/
#line 174 "./fw.w"

w->sxlowo= strdup(s);
if(w->sxlowo==NULL)
/*9:*/
#line 248 "./fw.w"

{
fprintf(stderr,"! Virtual memory exhausted.\n");
exit(1);
}

/*:9*/
#line 177 "./fw.w"

w->liczba_wystxapiexn= 1;
w->lewe_poddrzewo= w->prawe_poddrzewo= NULL;

return w;
}

/*:5*//*6:*/
#line 192 "./fw.w"

struct wierzchoxlek*wstaw_wierzchoxlek(struct wierzchoxlek*w,char*s)
{
int wynik_porxownania;

if(w==NULL)
w= nowy_wierzchoxlek(s);
else if((wynik_porxownania= strcoll(s,w->sxlowo))==0)
w->liczba_wystxapiexn++;
else if(wynik_porxownania<0)
w->lewe_poddrzewo= wstaw_wierzchoxlek(w->lewe_poddrzewo,s);
else
w->prawe_poddrzewo= wstaw_wierzchoxlek(w->prawe_poddrzewo,s);

return w;
}

/*:6*//*7:*/
#line 220 "./fw.w"

void inorder_print(struct wierzchoxlek*w)
{
if(w!=NULL){
inorder_print(w->lewe_poddrzewo);
printf("%9d %s\n",w->liczba_wystxapiexn,w->sxlowo);
inorder_print(w->prawe_poddrzewo);
}
}

/*:7*//*8:*/
#line 232 "./fw.w"

char*lowercase(char*s)
{
char*c= s;

while(isupper(*c)){
*c= tolower(*c);
c++;
}
return s;
}

/*:8*//*10:*/
#line 265 "./fw.w"

int main()
{
/*4:*/
#line 158 "./fw.w"

struct wierzchoxlek*korzexn= NULL;

/*:4*//*11:*/
#line 291 "./fw.w"

char*bufor_p= 0;
size_t dxlugoxsxc_bufora= 0;

/*:11*//*14:*/
#line 318 "./fw.w"

unsigned int i,k;
char ogranicznik[UCHAR_MAX];
char*nastxepne_sxlowo;

/*:14*/
#line 268 "./fw.w"


/*12:*/
#line 301 "./fw.w"

setlocale(LC_CTYPE,"");
setlocale(LC_COLLATE,"");

/*:12*/
#line 270 "./fw.w"

/*13:*/
#line 309 "./fw.w"

for(i= 1,k= 0;i<=UCHAR_MAX;i++)if(!isalnum(i))ogranicznik[k++]= i;
ogranicznik[k]= '\0';

/*:13*/
#line 271 "./fw.w"


while(getline(&bufor_p,&dxlugoxsxc_bufora,stdin)!=-1){
while((nastxepne_sxlowo= strtok(bufor_p,ogranicznik))!=NULL){
korzexn= wstaw_wierzchoxlek(korzexn,lowercase(nastxepne_sxlowo));
bufor_p= NULL;

}
}

inorder_print(korzexn);

return EXIT_SUCCESS;
}

/*:10*/
