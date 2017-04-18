/*
 * OpenMap.hpp
 *
 *This is a Hash Table interface using Linear Probing
 */
 #include <iostream>
#include "seqLinearList.hpp"
#include "Dictionary.hpp"
#ifndef OPENMAP_HPP_
#define OPENMAP_HPP_

using namespace cs202;
using namespace std;
namespace cs202
{
template<class Key, class Value>
class OpenMap  : public Dictionary<Key,Value>
{
    LinearList<Key> k;
    LinearList<Value> v;
    /*
     * Function rehash:
     * Resizes the has table to the next convenient size.
     * Called when all the slots are full and a new element needs to be inserted.
     */

	void rehash()
	{
	   int num=k.size();
	    int j=num*2;
	    /*int p=1;
	    int j;
	    for(i;;i++)
        {
            p=1;
            for( j=2;j<i;j++)
            {
                if(i%j==0)
                    p=0;
            }
            if(p==1)
            {
                break;
            }
        }
        */
        //new Size is j;
        //cout<<"New Size is "<<j<<"\n";
        OpenMap<Key, Value> ht(j);
        for(int p=0;p<num;p++)
        {
            ht.put(k[p],v[p]);
        }
        k=ht.k;
        v=ht.v;
    }
public:
    /*
     * Constructor: OpenMap
     * Creates a Open Hash Table with some default size.
     * NOTE: Please try to ensure that the size is a prime number for better performance.
     */
	OpenMap()
	{

	    LinearList<Key> K(11,-1);
	    LinearList<Value> V(11,-1);
	    k=K;
	    v=V;
	}
    /*
     * Constructor:OpenMap
     * Creates an empty Open Map with the ability to hold atleast num Key value pairs.
     */
	OpenMap(const int& num)         //make num prime
	{
	    int i=num+1;
	    int p=1;
	    int j;
	    for(i;;i++)
        {
            p=1;
            for( j=2;j<i;j++)
            {
                if(i%j==0)
                    p=0;
            }
            if(p==1)
            {
                break;
            }
        }
      //  cout<<"number is "<<j<<"\n";
	    LinearList <Key>K(j,-1);
	    LinearList <Value>V(j,-1);
	    k=K;
	    v=V;
	}
    /*
     * Constructor: Open Map
     * Creates a new Hash Table which is the exact copy of the given hash table.
     **/
	OpenMap(OpenMap<Key, Value>& ht)
	{
	    int m=(ht.k).size();
	    LinearList <Key>K(m,-1);
	    LinearList<Value> V(m,-1);
        for(int i =0;i<m;i++)
        {
            K.push_back(ht.k[i]);
            V.push_back(ht.v[i]);
        }
        k=K;
        v=V;
	}
    /*
     * Destructor
     * Deletes the memory acquired by the given Hash Map.
     */
	~OpenMap(){}
	int openHash(const Key & key)           // hash function
	{
	    int s=k.size();
	    return key%s;
	}

	bool has(const Key& key)        //returns true if dictionary contains key
	{
	    int m=k.size();
        int j=openHash(key);
        int r=0;
	    for(int i=j%m;r<m;r++,i++)
        {
            if(k[i]==key)
            {
               // cout<<"K[i] is "<<k[i]<<"\n";
                return 1;
            }

            else if(k[i]==-1)
            {
                return 0;
            }

        }
        return 0;
	}

    void remove(const Key& key)
    {
        int m=openHash(key);
        int z=0;
        int s=k.size();
        for(int i=m%s;z<s;z++,i++)
        {
            if(k[i]==key)
                {
                    k[i]=-2;                //-2 is like mark that element is deleted
                    v[i]=-2;
     //               cout<<"FOUND AND DELETED\n";
       //             cout<<"K[i] is "<<k[i]<<"\n";

                }

        }
    }

    Value get(const Key& key)
    {
        int m=openHash(key);
        int z=0;
        int s=k.size();
        for(int i=m%s;z<s;i++,z++)
        {
            if(k[i]==key)
            {
                return v[i];
            }
            else if(k[i]==-1)
            {
               // cout<<"Key doesn't Exist\n";
                return -1;
            }
        }
        //cout<<"Key doesn't Exist\n";
        return -1;

    }
    void put(const Key& key, const Value& value)        //Provision not made if hash table is full
    {
        int m=openHash(key);
        int z=0;
        int s=k.size();
        for(int i=m%s;z<s;i++,z++)
        {
            if(k[i]==-1||k[i]==-2)
            {
                k[i]=key;
                v[i]=value;
                return;
            }
            else if(k[i]==key)
            {
                v[i]=value;
                return;
            }
        }
        if(z==s)
            rehash();
            m=openHash(key);
            z=0;
            s=k.size();
            for(int i=m%s;z<s;i++,z++)
            {
                if(k[i]==-1||k[i]==-2)
                {
                    k[i]=key;
                    v[i]=value;
                    return;
                }
                else if(k[i]==key)
                {
                    v[i]=value;
                    return;
                }
            }

    }
    /*
     * A convenience wrapper operator.
     * Returns a reference to the value corresponding to the given key.
     * If the key does'nt exist, then inserts the key in the table,
     * with the default value of the Value type.
     * This should enable you to write code like this:
     * OpenMap<int,int> ht;
     * ht[1] = 2;
     * ht[1] = 4;
     * ht[2] = 3;
     */

	Value& operator[](const Key& key)
	{
	    int m=openHash(key);
        int z=0;
        int s=k.size();
        for(int i=m%s;z<s;z++,i++)
        {
            if(k[i]==-1||k[i]==-2)
            {
                v[i]=-1;
                k[i]=key;
                return v[i];
            }
            else if(k[i]==key)
            {
                    return v[i];
            }
        }
	}
    void display()
    {
        int i=0;
        int z=k.size();
        cout<<"KEY"<<" -> "<<"VALUE"<<"\n";
        for(i;i<z;i++)
        {
            cout<<k[i]<<" -> "<<v[i];
            cout<<"\n";
        }
    }
    int Search(const Key& key){
        int index = openHash(key);
        int j = index;
        int counter = k.size();
      //  int counter = size;
        while(counter){
            if(k[j] == -1)
            {
                // key is absent
                return -1;
            }
            else if(k[j] == key){
                return j;
            }
            j = (j+1)%k.size();
            counter--;
        }
        return -1;
    }
    void insertAt(const int& index, const Key& key, const Value& val){
        k[index] = key;
        v[index] = val;
    }


};
}

#endif
