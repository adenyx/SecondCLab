#include <stdio.h>
#include <string.h>

//Ввести с клавиатуры строку символов.
//Программа должна определить длину введенной строки,
//и если длина четная, то удаляются 2 первых и 2 последних символа.
int first() {
    char userString[100];
    int length;

    printf("Input the line here: ");
    scanf("%s", userString);
    length = strlen(userString);
    printf("Length = %d \n", length);
    if (length % 2 == 0) {
        userString[0] = (char) "0";
        userString[1] = (char) "0";
        userString[length-1] = (char) "0";
        userString[length] = (char) "0";
        for (int i = 2; i < length - 2; i++) {
            printf("%c", userString[i]);
        }
        printf("\n");
    }
    return 0;
}

//В тексте поменять слова местами (первое с последним, второе с предпоследним и тд)
//Слова имеют разную длину
//hello world mother fuckers
int second() {
    //TODO
    // - FINISH THE LAB
    char string[100];
    printf("Input the line here (2): ");
    scanf(" %s", string);
    printf("%s \n", string);

    int length = strlen(string);
    printf("%d \n", length);
    int numberOfWords = 1;
    for (int i = 0; i < length; i++) {
        if ((char *) string[i] == "_") {
            numberOfWords++;
        }
    }
    printf("%d \n", numberOfWords);

    int isCycleContinue;
    char words[numberOfWords][100];
    int k = 0;
    for (int i = 0; i < numberOfWords; i++) {
        int j = 0;
        isCycleContinue = 1;
        do {
            words[i][j] = string[k];
            k++;
            j++;
            if (string[k + 1] == "_") {
                isCycleContinue = 0;
                k++;
            }
        } while (isCycleContinue == 1);
        k++;
    }

    char variable;
    for (int i = 0; i < numberOfWords / 2; ++i) {
        for (int j = 0; j < length; ++j) {
            variable = words[i][j];
            words[i][j] = words[numberOfWords - i][j];
            words[numberOfWords - i][j] = variable;
        }
    }

    for (int i = 0; i < numberOfWords; i++) {
        for (int j = 0; j < length; j++) {
            printf("%c", words[i][j]);
        }
        printf(" ");
    }

    /*int lengthOfWords[numberOfWords];
    int isSpaceDetected = 0;
    int i = 0, j = 0;
    do {
        if (isSpaceDetected == 0) {
            firstWord[i] = string[i];
            string[i] = "#";
            lengthOfWords[0] = i;
        } else if (isSpaceDetected == 1) {
            secondWord[j] = string[i];
            string[i] = "#";
            lengthOfWords[1] = j;
        } else if (isSpaceDetected == 2) {
            thirdWord[j] = string[i];
            string[i] = "#";
            lengthOfWords[2] = j;
        } else if (isSpaceDetected == 3) {
            fourthWord[j] = string[i];
            string[i] = "#";
            lengthOfWords[3] = j;
        } else if (isSpaceDetected == 4) {
            //something
        }
        if (string[i+1] == "_") {
            string[i+1] = "#";
            i++;
            isSpaceDetected++;
            j = 0;
        }
        i++;
    } while (string[i+1] != "\0");
    for (int i = 0; i < numberOfWords; i++) {
        for (int j = 0; j < lengthOfWords[i]; j++) {
            if (i = 0) {
                printf("%c", firstWord[j]);
            }
        }
        printf(" ");
    }*/
    return 0;
}

//Проверить, является ли слово палиндромом
int third() {
    char string[100], secondString[100];
    printf("Input line here: ");
    scanf(" %s", string);
    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        secondString[i] = string[length - 1 - i];
    }
    if (strcmp(string, secondString) == 0) {
        printf("Слово палиндром: ");
        printf("%s", string);
    } else {
        printf("Слово не палиндом :C");
    }
    return 0;
}

//Ввести строку и если длина кратна 4, то поменять местами первую часть строки и вторую
int fourth() {
    char string[100];
    char firstPart[50], secondPart[50];
    printf("Input line here: ");
    scanf(" %s", string);
    int length = strlen(string);

    if (length % 4 == 0) {
        int j = 0;
        for (int i = 0; i < length / 2; i++) {
            firstPart[i] = string[i];
        }
        for (int i = length / 2; i < length; i++) {
            secondPart[j] = string[i];
            j++;
        }
        printf("%s", secondPart);
        printf("%s", firstPart);
    }
    return 0;
}

//В строке символов поменять местами символы на четных и нечетных позициях
int fifth() {
    char string[100];
    printf("Input line here (5): ");
    scanf(" %s", string);

    int length = strlen(string);
    char variable;
    if (length % 2 == 0) {
        for (int i = 0; i < length - 1; i++) {
            variable = string[i];
            string[i] = string[i + 1];
            string[i + 1] = variable;
        }
    } else {
        printf("String should be multiple of two!");
    }
    printf("%s", string);
    return 0;
}

//Ввести с клавиатуры строку. Посчитать число вхождений символов в строку
//КАРАБАС_БАРАБАС: А6Б3К1Р2С2
int sixth() {
    char string[100];
    printf("Input line here (6): ");
    scanf(" %s", string);

    int counter;
    int length = strlen(string);
    printf("%d \n", length);
    for (char i = 'a'; i <= 'z'; i++) {
        counter = 0;
        for (int j = 0; j < length; j++) {
            if (string[j] == i) {
                counter++;
            }
        }
        if (counter > 0) {
            printf("%c", i);
            printf("%d", counter);
        }
    }
}

int second1() {
    char string[100];
    char newString[100];
    char newChars[100];
    char preString[100];
    printf("Input line here (7): ");
    scanf(" %s", string);
    printf("Input pre-line here: ");
    scanf(" %s", preString);
    printf("Input new-line here: ");
    scanf(" %s", newChars);

    int lengthStr = strlen(string);
    int lengthPreStr = strlen(preString);
    int k = 0;
    int counter = 0;

    for (int i = 0; i < lengthStr; i++) {
        if (string[i] == preString[0] && string[i+1] == preString[1]) {
            counter++;
            for (int j = 0; j < lengthPreStr; j++) {
                newString[k] = newChars[j];
                printf("%c", newString[k]);
                k++;
            }
            printf("%d", counter);
            i++;
        } else {
            newString[k] = string[i];
            printf("%c", newString[k]);
            k++;
        }
    }
}


int main() {
    int choose;
    printf("1 / 2 / 3 / 4 / 5 / 6 / 21: ");
    scanf("%d", &choose);
    if (choose == 1) {
        first();
    } else if (choose == 2) {
        second();
    } else if (choose == 3) {
        third();
    } else if (choose == 4) {
        fourth();
    } else if (choose == 5) {
        fifth();
    } else if (choose == 6) {
        sixth();
    } else if (choose == 21) {
        second1();
    } else {
        printf("Input Error!");
    }
    return 0;
}