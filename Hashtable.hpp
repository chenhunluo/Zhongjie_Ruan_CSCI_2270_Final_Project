#include<string>
using namespace std;
template <class T>
class Hashtable
{
    struct node
    {
        string key;
        T value;
        node* next;
    };
    
public:
    Hashtable(int size_);
    ~Hashtable();
    //    int& operator[](string key);
    T get(string key);
    void set(string key, T value );
    bool checkexist(string key);
private:
    node** table;//node* table[];
    int size;
    int hash(string key);
};

