#include "func.h"

void printArray(myArray v)
{
    if(v.N == 0)
    {
        std::cout << "Cannot print empty array." << std::endl;
        return;
    }
    else
    {
        std::cout << "[";
        for(int i=0; i<v.N; i++)
        {
            std::cout << v.arr[i];
            if(i < v.N-1)
            {
                std::cout << ",";
            }
        }
        std::cout << "]";
    }
}

int fibonacci(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    return fibonacci(n-2) + fibonacci(n-1);
}

bool fillArrayWithFibonacci(myArray* v, int n)
{
    if (!(v->arr))
    {
        std::cout << "Empty pointer provided." << std::endl;
        return false;
    }
    if(n == 0)
    {
        std::cout << "Wrong number of dimensions." << std::endl;
        return false;
    }
    else
    {
        v->N = n;
        for(int i=0; i<v->N; i++)
        {
            v->arr[i] = fibonacci(i);
        }
        return true;
    }
}

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void revert(myArray* v)
{
    for(int i=0; i<(v->N)/2; i++)
    {
        swap(&v->arr[i], &v->arr[v->N-i-1]);
    }
    printArray(*v);
    std::cout << " (reverting done)" << std::endl;
}

void extend(myArray* v, int n)
{
    if(n > MAX)
    {
        std::cout << "Wow, you've just gone crazy (" << n << ">" << MAX << ")." << std::endl;
        return;
    }
    v->N = v->N + n;
    for(int i=v->N-n; i<v->N; i++)
    {
        v->arr[i] = 0;
    }
    printArray(*v);
    std::cout << " (extending by " << n << " done)" << std::endl;
}

void truncate(myArray* v, int n)
{
    v->N = v->N - n;
    printArray(*v);
    std::cout << " (truncation by " << n << " done)" << std::endl;
}

void checkArraySpouse(myArray* v)
{
    printArray(*v);
    if(!(v->spouse))
    {
        std::cout << " has no spouse." << std::endl;
    }
    else
    {
        std::cout << " is paired with ";
        printArray(*v->spouse);
        std::cout << std::endl;
    }
}

void marry(myArray* v1, myArray* v2)
{
    if((v2 == v1))
    {
        std::cout << "Can't marry myself" << std::endl;
        return;
    }
    else if(*(v1->arr) == *(v2->arr))
    {
        std::cout << "Can't marry my twin" << std::endl;
        return;
    }
    else
    {
        v1->spouse = v2;
        v2->spouse = v1;
    } 
}

void divorce(myArray* v1, myArray* v2)
{
    v1->spouse = 0;
    v2->spouse = 0;
}

myArray formChild(myArray* v1, myArray* v2)
{
    myArray child;

    if(!v1 && !v2)
    {
        std::cout << "I ain't God." << std::endl;
    }
    else if(!v1 || !v2)
    {
        std::cout << "No partenogenesis possible." << std::endl;
    }
    else if(v1->spouse != v2 && v2->spouse != v1)
    {
        std::cout << "Only spouses may have children." << std::endl;
    }
    else
    {
        child.N = v1->N + v2->N;
        for(int i=0; i<v1->N; i++)
        {
            child.arr[i] = v1->arr[i];
        }
        for(int i=0; i<v2->N; i++)
        {
            child.arr[i+v1->N] = v2->arr[i];
        }
        child.mum = v1;
        child.dad = v2;
        v1->children = &child;
        v2->children = &child;
    }

    return child;
}

void printParents(myArray* v)
{
    if(!v->mum && !v->dad)
    {
        printArray(*v);
        std::cout << " has no parents." << std::endl;
        return;
    }
    else
    {
        std::cout << "Parents of ";
        printArray(*v);
        std::cout << " are ";
        printArray(*v->mum);
        std::cout << " and ";
        printArray(*v->dad);
        std::cout << std::endl;
    }
}