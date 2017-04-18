/*
 * ChainedMap.hpp
 *
 */

#ifndef CHAINEDMAP_HPP_
#define CHAINEDMAP_HPP_
#include "list.hpp"
#include "dictionary.hpp"
using std::cout ;
using std::cin ;
using std::endl;
using namespace cs202;

namespace cs202
{
template<class Key, class Value>
class ChainedMap  : public Dictionary<Key,Value>
{

private:
    list<pair<Key,Value> > *arr ;
    int size ; 
    int arraysize ; 
    /*
     * Function rehash:
     * Resizes the hash table to the next convenient size.
     * Called when all the slots are full and a new element needs to be inserted.
     */
	void rehash();
public:
    /*
     * Constructor: ChainedMap
     * Creates a Chained Hash Table with some default size.
     * NOTE: Please try to ensure that the size is a prime number for better performance.
     */
	ChainedMap();
    /*
     * Constructor:ChainedMap
     * Creates an empty Chained Map with the ability to hold atleast num Key value pairs.
     */
	ChainedMap(const int& num);
    /*
     * Constructor: Chained Map
     * Creates a new Hash Table which is the exact copy of the given hash table.
     **/
	//ChainedMap(ChainedMap<Key, Value>& ht);
    /*
     * Destructor
     * Deletes the memory acquired by the given Hash Map.
     */
	//~ChainedMap();
    /*
     * A convenience wrapper operator.
     * Returns a reference to the value corresponding to the given key.
     * If the key does'nt exist, then inserts the key in the table,
     * with the default value of the Value type.
     * This should enable you to write code like this:
     * ChainedHashMap<int,int> ht;
     * ht[1] = 2;
     * ht[1] = 4;
     * ht[2] = 3;
     */
	Value& operator[](const Key& key);

    bool has(const Key& key);
    /*
     * Function : remove
     * Removes the given key and the corresponding value from the Dictionary if the key is in the dictionary.
     * Does nothing otherwise.
     */
    void remove(const Key& key) ;
    /*
     * Function : get
     * Returns the value associated with the given key.
     * Raises an exception if the key does'nt exist in the dictionary.
     */
    Value get(const Key& key);
    /*
     * Function : put
     * If the key does'nt exist in the dictionary, then insert the given key and value in the dictionary.
     * Otherwise change the value associated with the key to the given value.
     */
    void put(const Key& key, const Value& value);
    void print();
};

template<class Key, class Value>
ChainedMap<Key, Value>::ChainedMap() {
    arraysize = SIZE ; 
    arr = new list< pair<Key, Value> >[arraysize];
    size=0 ;
}
template<class Key, class Value>
ChainedMap<Key, Value>::ChainedMap(const int& num) {
    arraysize = num ;
    arr = new list< pair<Key, Value> >[arraysize];
    size=0 ;
     
}
template<class Key, class Value>
void ChainedMap<Key, Value>::put(const Key& key, const Value& value) {
    int pos = this->hash(key,arraysize);
    int flag=0 ;
    pair<Key,Value> p;
    p.m_pair(key,value) ;
    ChainNode<pair<Key,Value> >* temp = arr[pos].getfirst();
    while(temp!=NULL)
    {
        if((temp->data).pair_key()==key)
        {
            (temp->data).pair_val()=value;
            flag=1;
        }
        temp=temp->link;
        
    }
    if(flag==0)
    {
        arr[pos].append(p);
        size++;
    }
}

template<class Key, class Value>
Value&  ChainedMap<Key, Value>::operator[](const Key& key) {
    int pos = this->hash(key,arraysize);
    int flag=0 ;
    pair<Key,Value> p;
    p.m_pair(key,0) ;
    ChainNode<pair<Key,Value> >* temp = arr[pos].getfirst();
    while(temp!=NULL)
    {
        if((temp->data).pair_key()==key)
        {
            return (temp->data).pair_val();
        }
        temp=temp->link;
        
    }
    if(flag==0)
    {
        arr[pos].cons(p);
        size++;
        return (arr[pos].getfirst()->data).pair_val();
    }
}

template<class Key, class Value>
Value ChainedMap<Key, Value>::get(const Key& key) {
    int pos = this->hash(key,arraysize);
    ChainNode<pair<Key,Value> >* temp = arr[pos].getfirst();
    while(temp!=NULL)
    {
        if((temp->data).pair_key()==key)
        {
            return (temp->data).pair_val();
        }
        temp=temp->link;
        
    }
    return -1 ;
}

template<class Key, class Value>
bool ChainedMap<Key, Value>::has(const Key& key) {
    int pos = this->hash(key,arraysize);
    ChainNode<pair<Key,Value> >* temp = arr[pos].getfirst();
    while(temp!=NULL)
    {
        if((temp->data).pair_key()==key)
        {
            return true;
        }
        temp=temp->link;
        
    }
    return false ;
}

template<class Key, class Value>
void ChainedMap<Key, Value>::remove(const Key& key) {
    int pos = this->hash(key,arraysize);
    ChainNode<pair<Key,Value> >* temp = arr[pos].getfirst();
    while(temp!=NULL)
    {
        if((temp->data).pair_key()==key)
        {
            arr[pos].remove(temp->data);
        }
        temp=temp->link;
        
    }
}
template<class Key, class Value>
void ChainedMap<Key,Value>::print()
{
    int pos;
    for(pos=0;pos<arraysize;pos++)
    {
        //cout<<"asdada";
        ChainNode<pair<Key,Value> >* temp = arr[pos].getfirst();
        while(temp!=NULL)
        {   
            cout<<(temp->data).pair_val()<<" ";
            temp=temp->link;
        }
        cout<<endl;
    }
}

}
#endif /* CHAINEDMAP_HPP_ */