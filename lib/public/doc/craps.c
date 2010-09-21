/*
 * File: craps.c
 * -------------
 * This program plays the dice game called craps.  For a discussion
 * of the rules of craps, please see the GiveInstructions function.
 */

#include <stdio.h>
#include "genlib.h"
#include "random.h"
#include "simpio.h"
#include "strlib.h"

/* Function prototypes */

void GiveInstructions(void);
void PlayCrapsGame(void);
int RollTwoDice(void);
bool GetYesOrNo(string prompt);

/* Main program */

int main()
{
    Randomize();
    if (GetYesOrNo("Czy podać podać instrukcję gry `CRAPS'? ")) {
        GiveInstructions();
    }
    while (TRUE) {
        PlayCrapsGame();
        if (!GetYesOrNo("Czy chcesz zagrać jeszcz raz? ")) break;
    }
    return 0;
}

/*
 * Function: GiveInstructions
 * Usage: GiveInstructions();
 * -----------------------
 * This function welcomes the player to the game and gives
 * instructions on the rules to craps.
 */

void GiveInstructions(void)
{
    printf("Witam w grze `CRAPS'!\n\n");
    printf("W grze `craps' rzucasz parą kostek i sumujesz\n");
    printf("wyrzuconą liczbę oczek. Jeśli suma wynosi 2, 3 lub\n");
    printf("12, to przegrywasz. Jeśli wyrzuciłeś 7 lub 11,\n");
    printf("to wygrywasz. Jeśli wyrzuciłeś inną liczbę oczek, to ta liczba\n");
    printf("będzie twoim `celem' i będziesz rzucał tyle razy aż wyrzucisz\n");
    printf("ponownie tę liczbę (i wtedy wygrywasz)\n");
    printf("lub wyrzucisz 7 (i wtedy przegrywasz).\n");
    printf("\n");
}

/*
 * Function: PlayCrapsGame
 * Usage: PlayCrapsGame();
 * -----------------------
 * This function plays one game of craps.
 */

void PlayCrapsGame(void)
{
    int total, point;

    printf("\nZaczynamy!\n");
    total = RollTwoDice();
    if (total == 7 || total == 11) {
        printf("Wygrałeś.\n");
    } else if (total == 2 || total == 3 || total == 12) {
        printf("Przegrałeś.\n");
    } else {
        point = total;
        printf("Twój cel wynosi: %d.\n", point);
        while (TRUE) {
            total = RollTwoDice();
            if (total == point) {
                printf("Ponownie wyrzuciłeś: %d. Wygrałeś.\n", point);
                break;
            } else if (total == 7) {
                printf("Wyrzuciłeś siedem.  Przegrałeś.\n");
                break;
            }
        }
    }
}

/*
 * Function: RollTwoDice
 * Usage: total = RollTwoDice();
 * -----------------------------
 * This function rolls two dice and returns their sum.  As part
 * of the implementation, the result is displayed on the screen.
 */

int RollTwoDice(void)
{
    int d1, d2, total;

    printf("Rzucam parą kostek . . .\n");
    d1 = RandomInteger(1, 6);
    d2 = RandomInteger(1, 6);
    total = d1 + d2;
    printf("Wyrzuciłem %d i %d -- czyli razem %d.\n", d1, d2, total);
    return (total);
}

/*
 * Function: GetYesOrNo
 * Usage: if (GetYesOrNo(prompt)) . . .
 * ------------------------------------
 * This function asks the user the question indicated by prompt
 * and waits for a yes/no response.  If the user answers "yes"
 * or "no", the program returns TRUE or FALSE accordingly.
 * If the user gives any other response, the program asks
 * the question again.
 */

bool GetYesOrNo(string prompt)
{
    string answer;

    while (TRUE) {
        printf("%s", prompt);
        answer = GetLine();
        if (StringEqual(answer, "tak")) return (TRUE);
        if (StringEqual(answer, "nie")) return (FALSE);
        printf("Proszę napisz `tak' lub `nie'.\n");
    }
}
