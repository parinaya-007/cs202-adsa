
/*
 * DoubleHashMap.hpp
 *
 * This is an interface for a hash table using Double Hashing.
 */
 #include <iostream>
#include "seqLinearList.hpp"
#include "Dictionary.hpp"
#ifndef DOUBLEHASHMAP_HPP_
#define DOUBLEHASHMAP_HPP_
//#include <sstream>
//#include <string>
using namespace cs202;
using namespace std;
namespace cs202
{
template<class Key, class Value>
class DoubleHashMap  : public Dictionary<Key,Value>
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
        //new Size is j;
        //cout<<"New Size is "<<j<<"\n";
        DoubleHashMap<Key, Value> ht(i);
        for(p=0;p<num;p++)
        {
            ht.put(k[p],v[p]);
        }
        k=ht.k;
        v=ht.v;
    }
public:
    /*
     * Constructor: DoubleHashMap
     * Creates a Open Hash Table with some default size.
     * NOTE: Please try to ensure that the size is a prime number for better performance.
     */
	DoubleHashMap()
	{

	    LinearList<Key> K(11,-1);
	    LinearList<Value> V(11,-1);
	    k=K;
	    v=V;
	}
    /*
     * Constructor:DoubleHashMap
     * Creates an empty Double Hash Map with the ability to hold atleast num Key value pairs.
     */
	DoubleHashMap(const int& num)         //make num prime
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
	    LinearList <Key>K(i,-1);
	    LinearList <Value>V(i,-1);
	    k=K;
	    v=V;
	}
    /*
     * Constructor: Open Map
     * Creates a new Hash Table which is the exact copy of the given hash table.
     **/
	DoubleHashMap(DoubleHashMap<Key, Value>& ht)
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
	~DoubleHashMap(){}
	int Hash1(const Key & key)           // hash function
	{
           /* stringstream a;
        a << key;
        string s = a.str();
        int l = s.length(),i,ll = 0,j;
        for(i = l - 1;i >= 0;i--)
        {
            j = s[i];
            ll = (ll*39 + j) % k.size();
        }
        return ll;*/
        int s=k.size();
        return key%s;
    }
        int Hash2(const Key & key)
        {
            int s=5-(key%5);
            return s;
        }

	bool has(const Key& key)        //returns true if dictionary contains key
	{
	    int m=k.size();
        int j=Hash1(key);
        int r=0;
        int offset=Hash2(key);
	    for(int i=j%m;r<m;r++)
        {
            if(k[i]==key)
            {
                //cout<<"K[i] is "<<k[i]<<"\n";
                return 1;
            }

            else if(k[i]==-1)
            {
                return 0;
            }
            i=i+offset;

        }
        return 0;
	}

    void remove(const Key& key)
    {
        int m=Hash1(key);
        int z=0;
        int s=k.size();
        int offset=Hash2(key);
        for(int i=m%s;z<s;z++)
        {
            if(k[i]==key)
                {
                    k[i]=-2;                //-2 is like mark that element is deleted
                    v[i]=-2;
                 //   cout<<"FOUND AND DELETED\n";
                   // cout<<"K[i] is "<<k[i]<<"\n";

                }
            i=i+offset;
        }
    }

    Value get(const Key& key)
    {
        int m=Hash1(key);
        int z=0;
        int s=k.size();
        int offset=Hash2(key);
        for(int i=m%s;z<s;z++)
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
            i=i+offset;
        }
        //cout<<"Key doesn't Exist\n";
        return -1;

    }
    void put(const Key& key, const Value& value)        //Provision not made if hash table is full
    {
        int m=Hash1(key);
        int z=0;
        int s=k.size();
        int offset=Hash2(key);
        for(int i=m%s;z<s;z++)
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
            i=i+offset;
        }
        if(z==s)
            rehash();
            m=Hash1(key);
            z=0;
            s=k.size();
            for(int i=m%s;z<s;z++)
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
                i=i+offset;
            }

    }
    /*
     * A convenience wrapper operator.
     * Returns a reference to the value corresponding to the given key.
     * If the key does'nt exist, then inserts the key in the table,
     * with the default value of the Value type.
     * This should enable you to write code like this:
     * DoubleHashMap<int,int> ht;
     * ht[1] = 2;
     * ht[1] = 4;
     * ht[2] = 3;
     */
    int index(const Key & key)
    {
        int m=Hash1(key);
        int z=0;
        int s=k.size();
        int offset=Hash2(key);
        for(int i=m%s;z<s;z++)
        {
            if(k[i]==key)
            {
                return i;
            }
            else if(k[i]==-1)
            {
               // cout<<"Key doesn't Exist\n";
                return -1;
            }
            i=i+offset;
        }
        //cout<<"Key doesn't Exist\n";
        return -1;
    }
	Value& operator[](const Key& key)
	{
	    int m=Hash1(key);
        int z=0;
        int offset=Hash2(key);
        int s=k.size();
        for(int i=m%s;z<s;z++)
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
            i=i+offset;
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


};
}

#endif
