#include <stdio.h>

void printRoman(int num, char one, char five, char ten) {
    if (num <= 3) {
        for (int i = 0; i < num; i++) {
            putchar(one);
        }
    } else if (num == 4) {
        putchar(one);
        putchar(five);
    } else if (num <= 8) {
        putchar(five);
        for (int i = 0; i < num - 5; i++) {
            putchar(one);
        }
    } else if (num == 9) {
        putchar(one);
        putchar(ten);
    }
}

int main() {
    int number;
    printf("Enter a number (up to 9 digits): ");
    scanf("%d", &number);

    if (number < 1 || number > 999999999) {
        printf("Number out of range.\n");
        return 1;
    }

    printf("Roman numeral: ");

    int billions = number / 1000000000;
    number %= 1000000000;
    while (billions--) {
        putchar('M');
    }

    int millions = number / 1000000;
    number %= 1000000;
    if (millions > 0) {
        printRoman(millions, 'C', 'D', 'M');
    }

    int thousands = number / 1000;
    number %= 1000;
    if (thousands > 0) {
        printRoman(thousands, 'M', 'D', 'M');
    }

    if (number > 0) {
        printRoman(number / 100, 'C', 'D', 'M');
        number %= 100;
    }

    if (number > 0) {
        printRoman(number / 10, 'X', 'L', 'C');
        number %= 10;
    }

    if (number > 0) {
        printRoman(number, 'I', 'V', 'X');
    }

    printf("\n");

    return 0;
}
