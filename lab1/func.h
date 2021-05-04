#pragma once
#include <iostream>
#define MAX 50

//struktura myArray
//arr-tablica o rozmiarze MAX 50
//spouse, mum, dad, children - wskazniki na strukture
typedef struct myArray
{
    int arr[MAX];
    int N = 0;
    myArray* spouse = 0;
    myArray* mum = 0;
    myArray* dad = 0;
    myArray* children = 0;
}myArray;

//funkcja drukujaca zawartosc myArray
void printArray(myArray v);
//funkcja rekurencyjna zwracajaca liczby fibonacciego
int fibonacci(int n);
//funkcja uzupelniajaca wyrazy tablicy arr ciagiem fibonacciego
bool fillArrayWithFibonacci(myArray* v, int n);
//funkcja zamieniajaca dwa wyrazy w tablicy 
void swap(int* a, int* b);
//funkcja odwracajaca tablice arr
void revert(myArray* v);
//funkcja rozszerzajaca tablice arr
void extend(myArray* v, int n);
//funkcja zmniejszajaca tablice arr
void truncate(myArray* v, int n);
//funkcja sprawdzajaca na co wskazuje wskaznik spouse
void checkArraySpouse(myArray* v);
//funkcja przypisuja wskaznikowi spouse inna strukture
void marry(myArray* v1, myArray* v2);
//funkcja przypisuja wskaznikowi spouse watrosc null
void divorce(myArray* v1, myArray* v2);
//funkcja tworzaca strukture na podstawie dwoch innych struktur
myArray formChild(myArray* v1, myArray* v2);
//funkcja drukujaca zawartosc struktur, na ktore wskazuja wskazniki mum i dad
void printParents(myArray* v);