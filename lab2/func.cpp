#include "func.h"

void initCounter(counter* l)
{
    wsk_counter = l;
}

const double* initGeometricalSequence(double a1, double q, int n)
{
    if(n<=0)
    {
        std::cout << "Size must be non-zero (and positive)" << std::endl;
        return 0;
    }
    double* geom = new double[n];
    geom[0] = a1;
    for(int i=1; i<n; i++)
    {
        geom[i] = geom[i-1]*q;
    }
    return geom;
}

const double* initArithmeticSequence(double a1, double r, int n)
{
    if(n<=0)
    {
        std::cout << "Size must be non-zero (and positive)" << std::endl;
        return 0;
    }
    double* arithm = new double[n];
    arithm[0] = a1;
    for(int i=1; i<n; i++)
    {
        arithm[i] = arithm[i-1]+r;
    }
    return arithm;
}

void printSequence(const double* seq, int n)
{
    (*wsk_counter)++;

    if(n<=0)
    {
        std::cout << "Nothing to print." << std::endl;
        return;
    }

    std::cout << "(";
    for(int i=0; i<n; i++)
    {
        std::cout << seq[i];
        if(i<n-1)
        {
            std::cout << ",";
        }
    }
    std::cout << ")" << std::endl;
}

void deleteSequence(const double** seq)
{
    if(*seq == 0)
    {
        std::cout << "Nothing to delete." << std::endl;
        return;
    }
    std::cout << "Sequence deleted." << std::endl;
    delete [] *seq;
    *seq = 0;
}

void addSequence(const double*** list_seq, double** list_size, const double* seq, int n)
{
    const double** temp_seq = *list_seq;
    *list_seq = new const double*[count+1];
    const double* temp_size = *list_size;
    *list_size = new double[count+1];
    for(int i=0; i<count; i++)
    {
        (*list_seq)[i] = temp_seq[i];
        (*list_size)[i] = temp_size[i];
    }
    (*list_seq)[count] = seq;
    (*list_size)[count] = n;

    delete [] temp_seq;
    temp_seq = 0;
    delete [] temp_size;
    temp_size = 0;
    
    count++;
}

void printAllSequences(const double** list_seq, double* list_size)
{
    for(int i=0; i<count; i++)
    {
        std::cout << "Sequence " << i+1 << ": ";
        printSequence(list_seq[i], list_size[i]);
    }
}

void deleteAllSequences(const double** list_seq, double* list_size)
{
    for(int i=0; i<count; i++)
    {
        deleteSequence(list_seq + i);
    }
    delete list_seq;
    list_seq = 0;
    delete list_size;
    list_size = 0;
}