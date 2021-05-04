#include "func.h"

void set(Bits* bit, int* arr, int n)
{
    bit->size = n;
    for(int i=0; i<MAX; i++)
    {
        bit->data[i] = 0;
    }
    for(int i=0; i<n; i++)
    {
        bit->data[i] = arr[i];
    }
}

void print(const Bits* bit)
{
    for(int i=0; i<bit->size; i++)
    {
        std::cout << bit->data[i];
    }
    std::cout << std::endl << std::endl;
}

Bits add_up(Bits* bit1, Bits* bit2)
{
    Bits combined;
    combined.size = max(bit1->size, bit2->size);
    min(bit1->size, bit2->size) = max(bit1->size, bit2->size);
    set(&combined, bit1->data, combined.size);
    for(int i=combined.size-1; i>=0; i--)
    {
        switch(combined.data[i])
        {
            case 1:
            if(bit2->data[i] == 1)
            {
                combined.data[i] = 0;
                int j = i;
                while(combined.data[j] == 1)
                {
                    j--;
                }
                combined.data[j] = 1;
            }
            break;

            default:
            if(bit2->data[i] == 1)
            {
                combined.data[i] = 1;
            }
            break;
        }
    }
    return combined;
}

void bit_and(Bits* bit1, Bits* bit2)
{
    for(int i=bit1->size-1; i>=0; i--)
    {
        if(bit1->data[i] == bit2->data[i])
        {
            bit1->data[i] = 1;
        }
        else
        {
            bit1->data[i] = 0;
        }
    }
}

void bit_xor(Bits* bit1, Bits* bit2)
{
    for(int i=bit1->size-1; i>=0; i--)
    {
        if(((bit1->data[i] == 1) || (bit2->data[i] == 1)) && (bit1->data[i] != bit2->data[i]))
        {
            bit1->data[i] = 1;
        }
        else
        {
            bit1->data[i] = 0;
        }
    }
}

int to_decimal(const Bits* bit)
{
    int sum = 0;
    for(int i=bit->size-1; i>=0; i--)
    {
        if(bit->data[i])
        {
            sum += pow(2, bit->size-i-1);
        }
    }
    return sum;
}