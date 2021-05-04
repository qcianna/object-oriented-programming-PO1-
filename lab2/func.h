#pragma once
#include <iostream>

typedef int counter;
//count - licznik zainicjowanych ciagow
int count;
//wskaznik na licznik (bedzie przechowywac adres nPrints, aby zliczyc wywolania funkcji drukujacej)
counter* wsk_counter;

//funkcja przypisujaca adres licznika wskaznikowi
void initCounter(counter* l);
//funkcja tworzaca ciag geometryczny
//a1 - pierwszy wyraz ciagu
//q - iloraz ciagu
//n - rozmiar ciagu
const double* initGeometricalSequence(double a1, double q, int n);
//funkcja tworzaca ciag arytmetyczny
//a1 - pierwszy wyraz ciagu
//r - iloraz ciagu
//n - rozmiar ciagu
const double* initArithmeticSequence(double a1, double r, int n);
//funkcja drukujaca ciag
void printSequence(const double* seq, int n);
//funkcja usuwajaca dany ciag
void deleteSequence(const double** seq);
//funkcja dodajaca ciag do listy ciagow
void addSequence(const double*** list_seq, double** list_size, const double* seq, int n);
//funkcja drukujaca liste ciagow
void printAllSequences(const double** list_seq, double* list_size);
//funkcja usuwajaca liste ciagow
void deleteAllSequences(const double** list_seq, double* list_size);