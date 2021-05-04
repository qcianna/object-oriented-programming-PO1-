#pragma once
#include <iostream>
#define MAX 50

//struktura pojedynczego wezla
typedef struct Node{
    char data[MAX];
    Node* next = 0;
}Node;