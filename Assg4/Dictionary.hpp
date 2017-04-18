/*
 * Dictionary.hpp
 */

#ifndef DICTIONARY_HPP_
#define DICTIONARY_HPP_
#define SIZE 33 ;
namespace cs202
{
template<class Key, class Value>
class pair
{
private:
    Key _key ;
    Value _value ;
public:
    void m_pair(Key keyy , Value val)
    {
        _key = keyy ;
        _value = val ;
    }
    Key pair_key()
    {
        return _key ;
    }
    Value& pair_val()
    {
        return _value ; 
    }
    bool operator == (const pair<Key,Value>& rhs )
    {
        if(this->_key == rhs._key && this->_value == rhs._value)
        {
            return true ; 
        }
        else 
            return false ;
    }
};

template<class Key, class Value>
class Dictionary
{
public:
    /*
     * Destructor. Should release all the memory acquired by the dictionary.
     */
	virtual ~Dictionary(){};
    /*
     * Function : has
     * Returns true if the dictionay contains the key
     * false otherwise. It is search operation
     */
	virtual bool has(const Key& key) = 0;
    /*
     * Function : remove
     * Removes the given key and the corresponding value from the Dictionary if the key is in the dictionary.
     * Does nothing otherwise.
     */
	virtual void remove(const Key& key) = 0;
    /*
     * Function : get
     * Returns the value associated with the given key.
     * Raises an exception if the key does'nt exist in the dictionary.
     */
	virtual Value get(const Key& key) = 0;
    /*
     * Function : put
     * If the key does'nt exist in the dictionary, then insert the given key and value in the dictionary.
     * Otherwise change the value associated with the key to the given value.
     */
	virtual void put(const Key& key, const Value& value) = 0;
    int hash(Key keyy , int size)
    {
        return (keyy%size);
    }
    int double_hash(Key keyy,int size)
    {
        return (size/2- keyy%(size/2));
    }
};
}


#endif /* DICTIONARY_HPP_ */