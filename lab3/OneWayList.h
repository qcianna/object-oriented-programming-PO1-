#pragma once
#include <iostream>
#include <string.h>
#include "Node.h"

//struktura listy jednokierunkowej
typedef struct OneWayList
{
    Node* head = 0;
}OneWayList;

//funkcja ustawiajaca wskaznik head na null
void prepare(OneWayList* list);
//funkcja dodajaca element do listy
void add(OneWayList* list, const char* text);
//funkcja sprawdzajaca czy lista jest pusta
bool empty(const OneWayList* list);
//funkcja drukujaca liste
void dump(const OneWayList* list);
//funkcja usuwajaca elementy listy
void clear(OneWayList* list);