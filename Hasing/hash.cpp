#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Node{
    public:
    string key;
    T value;
    Node<T>*next;
    Node(string key,T val)
    {
        this->key=key;
        value=val;
        next=NULL;
    }
    ~Node()
    {
        if(next!=NULL)
        {
            delete next;
        }
    }
};
template<typename T>
class HashTable{
    Node<T>**table;
    int current_size;
    int table_size;
    public:
    HashTable(int ts=7)
    {
        table_size=ts;
        table=new Node<T>*[table_size];
        current_size=0;
    }
}
int main()
{
    return 0;
}