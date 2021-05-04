#pragma once
#include <iostream>
#include <cmath>
#define MAX 32
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b

typedef struct Bits{
    int data[MAX];
    int size;
}Bits;

void set(Bits* bit, int* arr, int n);

void print(const Bits* bit);

Bits add_up(Bits* bit1, Bits* bit2);

void bit_and(Bits* bit1, Bits* bit2);

void bit_xor(Bits* bit1, Bits* bit2);

int to_decimal(const Bits* bit);