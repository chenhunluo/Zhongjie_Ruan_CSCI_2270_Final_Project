#include <string>
#include <climits>
#include "Hashtable.hpp"

using namespace std;

template <class T>
Hashtable<T>::Hashtable(int sizee_)
{
    size=sizee_;
    table = new node*[size];//*table = new node[size ] wrong
    for(int i=0; i<size; i++)
    {
        table[i]=nullptr;
    }
}

//Delete the dynamic array
template <class T>

Hashtable<T>::~Hashtable()
{
    delete []table;
}

template <class T>
int Hashtable<T>::hash(string key)
{
    int sum=0;
    for(int i=0;i<key.size();i++)
        sum = sum+key[i];
    sum=sum % size;
    return sum;
}
//Return the value which is vertex after input the state name
template <class T>
T& Hashtable<T>::get(string key)
{
    int value;
    value = hash(key);
    node* temp = table[value];//Also dereference
    while(temp!=nullptr && temp->key != key)
    {
        temp=temp->next;
    }
    return temp->value;
}
//Check whether the state is existed, return true/false
template <class T>
bool Hashtable<T>::checkexist(string key)
{
    int value;
    value = hash(key);
    node* temp = table[value];//Also dereference
    while(temp!=nullptr && temp->key != key)
    {
        temp=temp->next;
    }
    return temp!=nullptr;
}
//Insert state name and state vertex into the hash table.
//Also checking whether there's a collision, which is solved by creating a link list
template <class T>
void Hashtable<T>::set(string key, T value_)
{
    int index=hash(key);
    node* temp = table[index];
    if(temp==nullptr)
    {
        table[index] = new node;
        table[index]->key=key;
        table[index]->value=value_;
        table[index]->next=nullptr;
    }
    else
    {
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next=new node;
        temp->next->key=key;
        temp->next->value=value_;
        temp->next->next=nullptr;
    }
}


