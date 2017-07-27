#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>

template <class T>
class Hashtable
{
    struct node
    {
        //Store name of the state in the project
        std::string key;
        //vertex type
        T value;
        //Used for building link list when collision happend
        node* next;
    };
public:
    Hashtable(int size_);
    ~Hashtable();
    //Get the value at key position
    T &get(std::string key);
    //insert into hashtable
    void set(std::string key, T value );
    //check if the position is occupied
    bool checkexist(std::string key);
private:
    
    node** table;//node* table[]; array of pointer(dynamic)
    int size;
    //Calculate sum index
    int hash(std::string key);
};

#endif