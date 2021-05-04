#include "OneWayList.h"

void prepare(OneWayList* list)
{
    list->head = 0;
}

void add(OneWayList* list, const char* text)
{
    if(list->head == 0)
    {
        list->head = new Node;
        strcpy(list->head->data, text);
        list->head->next = 0;
        return;
    }
    Node* temp = list->head;
    while(temp->next)
    {
        temp = temp->next;
    }
    temp->next = new Node;
    strcpy(temp->next->data, text);
    temp->next->next = 0;
}

bool empty(const OneWayList* list)
{
    if(list->head)
    {
        return false;
    }
    return true;
}

void dump(const OneWayList* list)
{
    if(!empty(list))
    {
        Node* temp = list->head;
        while(temp)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
    }
}

void clear(OneWayList* list)
{
    if(!empty(list))
    {
        Node* temp = list->head;
        while(temp)
        {
            list->head = temp->next;
            delete temp;
            temp = list->head;
        }
    }
}