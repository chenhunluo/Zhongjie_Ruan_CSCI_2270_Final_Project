#include "Hashtable.hpp"

template <class T>
Hashtable<T>::Hashtable(int size_)
{
    size=size_;
    table = new node*[size];//*table = new node[size ] wrong
    for(int i=0; i<size; i++)
    {
        table[i]=nullptr;
    }
}
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
template <class T>
T Hashtable<T>::get(string key)
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


