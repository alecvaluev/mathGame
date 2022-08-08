#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "digits.h"
#include "languages.h"

#define VOCAB 44
#define MINI_WIDTH 6     // 120 / 8 = 15
#define MINI_HEIGHT 30
#define FULL_WIDTH 12    // 210 / 8 = 26.25
#define FULL_HEIGHT 51
#define SHIFT 2

void line(int k, int option, char message[]);
void pause(void);
void warning(char location[]);
void announcement(char message[], int score, int mistake);
void rank();
void menu();
void modeMenu();
void scoringMode();
void survivingMode();
void level();
void settingMenu();
void resolution();
void miniResolution();
void fullResolution();
void language();
void search_Digit(struct Digit* digit, int num);
void search_Sign(struct Digit* digit, char sign);
float showDigits(int rand1, int rand2, char sign);
int additionF();
int subtractionF();
int divisionF();
int multiplicationF();
int moduloF();
int all();
void setRank(int score, int mistake, char mode[], int sign);
void swap(int i);
void getRank(int i);
void customize();

int width = MINI_WIDTH;
int height = MINI_HEIGHT;
int limit = 10;  //base of digits
char operationSet[5] = { 1, 1, 1, 1, 1 }; ///1 or 0

void line(int k, int option, char message[]) {  // make a newline/tab
    int i;
    if (option == 0) {                //new line
        for (i = 0; i < (int)k; i++) {
            printf("\n");
        }
    }
    else if (option == 1){
        for (i = 0; i < k; i++) {
            printf("\t");             //tab == 8 symbols  => k*8 spaces
        }
        printf("%s", message);
    }
    return;
}

void pause(void) {      //pausing the screen
    printf(program.words[35].str);   //pause mes
    getchar();
    while (getchar() != '\n') {
    };
    return;
}

void warning(char location[]) {  //warning mes
    line(height / SHIFT, 0, "");
    line(width, 1, "");
    printf("!!!Error in %s function!!!", location); //mes location
    line(height / SHIFT * (SHIFT - 1) - 1, 0, "");
    pause();
}

void announcement(char message[], int score, int mistake) {  //announcement
    line(height / SHIFT, 0, "");
    line(width, 1, "");
    printf(">>>>> %s <<<<<\n\n", message); //mes
    line(width, 1, "");
    if(score != -1)printf("\t%d / %d", score, (score + mistake));    // score/total
    line(height / SHIFT * (SHIFT - 1) - 3, 0, "");
    pause();
}

void set_language(char lang[]) {    
    int i;
    if (!strcmp(lang, "eng")) {    //english
            for (i = 0; i < VOCAB; i++) {
                strcpy(program.words[i].str, English.words[i].str);
                if (i < 5) {
                    if (ranking[i].sign == 0) strcpy(ranking[i].repos, English.words[33].str);
                    else if (ranking[i].sign == 1)strcpy(ranking[i].repos, English.words[34].str);
                }
            }
    }
    else if (!strcmp(lang, "sp")) {   //spanish
        for (i = 0; i < VOCAB; i++) {
            strcpy(program.words[i].str, Spanish.words[i].str);
            if (i < 5) {
                if (ranking[i].sign == 0) strcpy(ranking[i].repos, Spanish.words[33].str);
                else if (ranking[i].sign == 1)strcpy(ranking[i].repos, Spanish.words[34].str);
            }
        }
    }
    else if (!strcmp(lang, "fr")) {   //french
        for (i = 0; i < VOCAB; i++) {
            strcpy(program.words[i].str, French.words[i].str);
            if (i < 5) {
                if (ranking[i].sign == 0) strcpy(ranking[i].repos, French.words[33].str);
                else if (ranking[i].sign == 1)strcpy(ranking[i].repos, French.words[34].str);
            }
        }
    }
    return;
}

void menu() {                                     //main menu
    int choice = 0;
    while (choice != 4) {
        line(height / SHIFT, 0, "");
        line(width, 1, program.words[0].str);   
        line(width, 1, program.words[1].str);   //welcome
        line(width, 1, program.words[2].str);   //game
        line(width, 1, program.words[3].str);   //settings
        line(width, 1, program.words[4].str);   //exit
        line(height / SHIFT * (SHIFT -1) - 5, 0, "");

        printf("\n>>>");
        scanf("%d", &choice);
        switch (choice) {
        case 1: modeMenu(); //modeMenu();
            break;
        case 2: settingMenu();//settingMenu();
            break;
        case 3:
            rank();
            break;
        case 4:
            printf(program.words[5].str);  //shutting down mes
            break;
        default:
            warning("MAIN MENU");
            break;
        }
    }
    return;
}

void swap(int k) {
    int i = 3;
    while (i >= k) {  //nt hte last
        if (ranking[i].total == 0 ) {   //empty -> skip
            i--;
            continue;
        }
        ranking[i + 1].score = ranking[i].score;   //swap from the last to the current
        ranking[i + 1].total = ranking[i].total;
        strcpy(ranking[i + 1].repos, ranking[i].repos);
        ranking[i + 1].sign = ranking[i].sign;
        i--;
    }
    return;
}
void getRank(int i) {
    if(ranking[i].total != 0) printf("#%d | %2d/%-2d | %-13s\n", i + 1, ranking[i].score, ranking[i].total, ranking[i].repos);
    return;
}
void setRank(int score, int mistake, char mode[], int sign) {      //    | 0 | 1 | 2 | 3 | 4 |
    int i;                                                //       14,16  13  5   2   0
    for (i = 0; i <= 4; i++) {  
        if (ranking[i].total == 0 || i == 4) { // is empty or the last
            ranking[i].score = score;
            ranking[i].total = score + mistake;
            strcpy(ranking[i].repos, mode);
            ranking[i].sign = sign;
            break;
        }
        else {
            if (ranking[i].score <= score) {   //less go next, more or eq replace
                swap(i);
                ranking[i].score = score;
                ranking[i].total = score + mistake;
                strcpy(ranking[i].repos, mode);
                ranking[i].sign = sign;
                break;
            }
        }
    }
    return;
}

void rank() {
    line(height / SHIFT, 0, "");
    line(width, 1, program.words[32].str);
    line(width, 1, ""); getRank(0);
    line(width, 1, ""); getRank(1);
    line(width, 1, ""); getRank(2);
    line(width, 1, ""); getRank(3);
    line(width, 1, ""); getRank(4);
    line(height / SHIFT * (SHIFT - 1) - 4, 0, "");
    pause();
    return;
}
void modeMenu() {                             // level menu to choose one/all/custimise level
    int choice = 0;
    while (choice != 5) {
        line(height / SHIFT, 0, "");
        line(width, 1, program.words[6].str);
        line(width, 1, program.words[7].str);
        line(width, 1, program.words[8].str);
        line(width, 1, program.words[9].str);
        line(width, 1, program.words[43].str);
        line(width, 1, program.words[10].str);
        line(height / SHIFT * (SHIFT - 1) - 6, 0, "");
        
        printf("\n>>>");
        scanf("%d", &choice);
        switch (choice) {
        case 1: scoringMode(); //scoring();
            break;
        case 2: survivingMode();//surviving();
            break;
        case 3: level();
        case 4: customize(); 
            break;
        case 5: break;
        default:
            warning("MODE MENU");
            break;
        }
        if (choice == 1 || choice == 2) break;
    }
}

void scoringMode() {
    int score = 0, result = 0, mistake = 0;
    while ((score + mistake) != 15) {
        printf(program.words[11].str, score);
        result = all();
        if (result == 1) score++;
        else if (result == 0) mistake++;
    }
    announcement(program.words[12].str, score, mistake);
    setRank(score, mistake, program.words[33].str, 0);
    return;
}

void survivingMode() {
    int lives = 1, choice, score = 0, mistake = 0, result = 0;

    line(height / SHIFT, 0, "");
    line(width, 1, program.words[13].str);
    line(width, 1, program.words[14].str);
    line(width, 1, program.words[15].str);
    line(width, 1, program.words[16].str);
    line(height / (SHIFT * (SHIFT - 1)) - 4, 0, "");
    printf(">>>");
    scanf("%d", &choice);
    switch (choice) {
    case 1: lives = 10;
        break;
    case 2: lives = 5;
        break;
    case 3: lives = 1;
        break;
    default: warning("SURVIVING MODE");
        break;
    }
    while (lives != 0) {
        printf(program.words[17].str, lives);
        result = all();
        if (result == 1) score++;
        else {
            mistake++;
            lives--;
        }
    }
    announcement(program.words[12].str, score, mistake);
    setRank(score, mistake, program.words[34].str, 1);
    return;
}

void level() {                                //start menu with 2 mide choices
    int choice = 0;
    
        line(height / SHIFT, 0, "");
        line(width, 1, program.words[18].str);
        line(width, 1, ">> 1. 1 - 10 <<\n");
        line(width, 1, ">> 2. 1 - 25 <<\n");
        line(width, 1, ">> 3. 1 - 50 <<\n");
        line(width, 1, ">> 4. 1 - 99 <<\n");
        line(height / SHIFT * (SHIFT - 1) - 6, 0, "");

        printf("\n>>>");
        scanf("%d", &choice);
        switch (choice) {
        case 1: limit = 10; //scoring();
            break;
        case 2: limit = 25; //surviving();
            break;
        case 3: limit = 50;
            break;
        case 4: limit = 99;
            break;
        default:
            warning("MODE MENU");
            break;
        }
    
    return;
}

void settingMenu() {                                   //setting menu(language)
    int choice = 0;
    while (choice != 3) {
        line(height / SHIFT, 0, "");
        line(width, 1, program.words[19].str);
        line(width, 1, program.words[20].str);
        line(width, 1, program.words[21].str);
        line(width, 1, program.words[22].str);
        line(height / SHIFT * (SHIFT - 1) - 5, 0, "");

        printf("\n>>>");
        scanf("%d", &choice);
        switch (choice) {
        case 1: resolution(); //resolution();
            break;
        case 2: language();//language();
            break;
        case 3:break;
        default:
            warning("SETTING MENU");
            break;
        }
    }
    return;
} 

void resolution() {
    int choice = 0;
    while (choice != 3) {
        line(height / SHIFT, 0, "");
        line(width, 1, program.words[23].str);
        line(width, 1, program.words[24].str);
        line(width, 1, program.words[25].str);
        line(width, 1, program.words[26].str);
        line(height / SHIFT * (SHIFT - 1) - 5, 0, "");

        printf("\n>>>");
        scanf("%d", &choice);
        switch (choice) {
        case 1: miniResolution(); //mini sc();
            break;
        case 2: fullResolution();//full sc();
            break;
        case 3:
            break;
        default:
            warning("RESOLUTION MENU");
            break;
        }
    }
    return;
}

void miniResolution() {
    height = MINI_HEIGHT;
    width = MINI_WIDTH;
    return;
}

void fullResolution() {
    height = FULL_HEIGHT;
    width = FULL_WIDTH;
    return;
}

void language() {                                   //change the language   Eng/Sp/Ch/Fr
    int choice = 0;
    while (choice != 4) {
        line(height / SHIFT, 0, "");
        line(width, 1, program.words[27].str);
        line(width, 1, program.words[28].str);
        line(width, 1, program.words[29].str);
        line(width, 1, program.words[30].str);
        line(width, 1, program.words[31].str);
        line(height / SHIFT *  (SHIFT - 1) - 4, 0, "");

        printf(">>>");
        scanf("%d", &choice);
        switch (choice) {
        case 1: 
            set_language("eng");
            break;
        case 2: 
            set_language("sp");
            break;
        case 3: 
            set_language("fr");
            break;
        case 4: 
            break;
        default: warning("LANGUAGE");
            break;
        }
    }
    return;
}

void search_Digit(struct Digit* digit, int num) {
    int i;
    switch (num) {
    case 1: 
        for (i = 0; i < 8; i++) {
            strcpy(digit[i].str, one[i].str);
        }
        break;
    case 2:
        for (i = 0; i < 8; i++) {
            strcpy(digit[i].str, two[i].str);
        }
        break;
    case 3:
        for (i = 0; i < 8; i++) {
            strcpy(digit[i].str, three[i].str);
        }
        break;
    case 4:
        for (i = 0; i < 8; i++) {
            strcpy(digit[i].str, four[i].str);
        }
        break;
    case 5:
        for (i = 0; i < 8; i++) {
            strcpy(digit[i].str, five[i].str);
        }
        break;
    case 6:
        for (i = 0; i < 8; i++) {
            strcpy(digit[i].str, six[i].str);
        }
        break;
    case 7:
        for (i = 0; i < 8; i++) {
            strcpy(digit[i].str, seven[i].str);
        }
        break;
    case 8:
        for (i = 0; i < 8; i++) {
            strcpy(digit[i].str, eight[i].str);
        }
        break;
    case 9:
        for (i = 0; i < 8; i++) {
            strcpy(digit[i].str, nine[i].str);
        }
        break;
    case 0:
        for (i = 0; i < 8; i++) {
            strcpy(digit[i].str, zero[i].str);
        }
        break;
    default: warning("SEARCH NUMBER");
        break;
    }
}

void search_Sign(struct Digit* digit, char sign) {
    int i = 0;
    switch (sign) {
    case '+':
        for (i = 0; i < 8; i++) {
            strcpy(digit[i].str, plus[i].str);
        }
        break;
    case '-':
        for (i = 0; i < 8; i++) {
          strcpy(digit[i].str, minus[i].str);
        }
        break;
    case 'x':
        for (i = 0; i < 8; i++) {
            strcpy(digit[i].str, multipication[i].str);
        }
        break;
    case '/':
        for (i = 0; i < 8; i++) {
            strcpy(digit[i].str, division[i].str);
        }
        break;
    case '%':
        for (i = 0; i < 8; i++) {
            strcpy(digit[i].str, modulo[i].str);
        }
        break;
    default: warning("SEARCH SIGN");
        break;
    }
    return;
}

float showDigits(int rand1, int rand2, char sign) {
    float answer = 1.0f;
    int i,
        n1 = rand1 / 10,
        n2 = rand1 % 10,
        n3 = rand2 / 10,
        n4 = rand2 % 10;

    struct Screen display = { {{""}}, {{""}}, {{" "}}, {{""}},{{""}} };

    if (n1 != 0) search_Digit(&display.num1, n1);
    search_Digit(&display.num2, n2);
    search_Sign(&display.sign, sign);
    if (n3 == 0) n3 = n4;
    search_Digit(&display.num3, n3);
    if (n3 != n4) search_Digit(&display.num4, n4);

    line(height / 3, 0, "");
    for (i = 0; i < 8; i++) {
        line(width - 2, 1, "");
        printf("%-8s   %-8s     %-8s     %-8s   %-8s\n", display.num1[i].str, display.num2[i].str, display.sign[i].str, display.num3[i].str, display.num4[i].str);
    }
    line(height / 3 * (3 - 1) - 10, 0, "");
    printf(">>>");
    scanf("%f", &answer);
    return answer;
}

int additionF() {   
    int rand1, rand2, answer, result;
    srand(time(NULL));
    rand1 = rand() % limit + 1;    
    rand2 = rand() % limit + 1;
    
    answer = (int)showDigits(rand1, rand2, '+');               
   
    if (answer == rand1 + rand2) result = 1;
    else result = 0;

    return result;
}

int subtractionF() {
    int rand1, rand2, answer, result;
    srand(time(NULL));
    rand1 = rand() % limit + 1;
    rand2 = rand() % limit + 1;

    answer = (int)showDigits(rand1, rand2, '-');
    
    if (answer == rand1 - rand2) result = 1;
    else result = 0;
    return result;
}

int divisionF() {
    int rand1, rand2, answer, result;
    srand(time(NULL));
    rand1 = rand() % limit + 1;
    rand2 = rand() % limit + 1;

    answer = (int)(showDigits(rand1, rand2, '/') * 100);

    if (answer == (int)((float)rand1 / rand2)*100) result = 1;
    else result = 0;

    return result;
}

int multiplicationF() {
    int rand1, rand2, answer, result;
    srand(time(NULL));
    rand1 = rand() % limit + 1;
    rand2 = rand() % limit + 1;

    answer = (int)showDigits(rand1, rand2, 'x');
    
    if (answer == rand1 * rand2) result = 1;
    else result = 0;

    return result;
}

int moduloF() {
    int rand1, rand2, answer, result;
    srand(time(NULL));
    rand1 = rand() % limit + 1;
    rand2 = rand() % limit + 1;

    answer = (int)showDigits(rand1, rand2, '%');

    if (answer == rand1 % rand2) result = 1;
    else result = 0;

    return result;
}

int all() {
    int answer = 0, k = 0, i, base = 0, random;
    char buffer[5];
    srand(time(NULL));
    
    for (i = 0; i < 5; i++) {
        if (operationSet[i] == 1) base++;
    }
    for (i = 0; i < 5; i++) {
        if (operationSet[i] == 1) {
            buffer[k] = i;
            k++;
        }
    }

    random = rand() % base;   //error if there os base = 0

    switch (buffer[random]) {
    case 0: answer = additionF();
        break;
    case 1: answer = subtractionF();
        break;
    case 2: answer = multiplicationF();
        break;
    case 3: answer = divisionF();
        break;
    case 4: answer = moduloF();
        break;
    default:
        announcement("Please choose any type of operation", -1, 0);
    }
    return answer;
}

void getOperrationLine(int i, char string[]) {
    char sign, on = 'o', off = '-';
    if (operationSet[i - 1] == 1) sign = on;
    else sign = off;
    printf("%c >%d. %-15s<<\n",sign, i,string);
}

void customize() {
    int choice = 0, on = 0;
    int i, n1, n2, n3, n4, n5;

    for (i = 0; i < 5; i++) {
        if (operationSet[i] == 1) on++;
    }

    do {
        do {
            line(height / SHIFT, 0, "");
            line(width, 1, program.words[36].str);
            line(width, 1, ""); getOperrationLine(1, program.words[37].str);
            line(width, 1, ""); getOperrationLine(2, program.words[38].str);
            line(width, 1, ""); getOperrationLine(3, program.words[39].str);
            line(width, 1, ""); getOperrationLine(4, program.words[40].str);
            line(width, 1, ""); getOperrationLine(5, program.words[41].str);
            line(width, 1, program.words[42].str);
            line(height / SHIFT * (SHIFT - 1) - 6, 0, "");

            printf("\n>>>");
            scanf("%d", &choice); //12453

            n1 = choice / 10000,     //getting 5 digits
                n2 = (choice / 1000) % 10,
                n3 = (choice / 100) % 10,
                n4 = (choice / 10) % 10,
                n5 = choice % 10;

        } while ((n1 > 6 || n1 < 0) || (n2 > 6 || n2 < 0) || (n3 > 6 || n3 < 0) || (n4 > 6 || n4 < 0) || (n5 > 6 || n5 < 0) || choice / 100000 > 0);

        for (i = 1; i <= 5; i++) {
            if (n1 == i || n2 == i || n3 == i || n4 == i || n5 == i) {
                if (operationSet[i - 1] == 0) {
                    operationSet[i - 1] = 1;
                    on++;
                    printf("%d", on);
                }
                else {
                    operationSet[i - 1] = 0;
                    on--;
                    printf("%d", on);
                }
            }
        }
        if (choice == 6 && on == 0) announcement("PLEASE CHOOSE OPERATION", -1, 0);
    } while (choice != 6 || on == 0);
    return;
}
