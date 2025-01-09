// scanf.c
// scanf.c -- demonstrates scanf() working with different format specifiers. 
#include <stdio.h>

int main(void)
{

    char topping[5];
    int slices;
    int day, month, year;
    double price;

    printf("How many dollars does the pizza cost in your region? ");
    printf("(Enter as $XX.XX)\n");
    scanf(" $%lf", &price);

    printf("What is your favourite topping? (One word)\n");
    scanf(" %s", topping);

    printf("How many slices can you eat at once?\n");
    scanf(" %d", &slices);

    printf("What is the date today? (Enter as DD/MM/YY)\n");
    scanf(" %d/%d/%d", &day, &month, &year);

    // Output results
    printf("\n\nWhy not treat yourself to dinner on %02d/%02d/%d", day, month, year);
    printf(" and eat %d slices of pizza with %s topping?\n", slices, topping);
    printf("It will cost only $%.2f\n", price);

    return 0;
}