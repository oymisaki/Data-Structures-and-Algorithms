#include<iostream>
#include<vector>
#include<list>
using namespace std;

// 定义哈希函数
class Hash
{
public:
    int operator()(int i){
        return i;
    }
};

// Entry
template<typename K, typename V>
class Entry
{
    K key;
    V value;
};

// 哈希表
template<typename K, typename V, typename H>
class HashMap
{
public:
    type def Entry<const K, V> Entry;
    class Iterator;
public:
    HashMap(int capacity = 100);
    int size() const;
    bool empty();
    Iterator find(const K& k);
    Iterator put(const K& k, const V& v);
    void erase(const K& k);
    void erase(const Iterator& iter);
    Iterator begin();
    Iterator end();
protected:
    typedef list<Entry> Bucket;
    typedef vector<Bucket> BktArr;
    // tbd
private:
    int n;
    H hash;
    BktArr B;
public:
    class Iterator
    {
        typedef Vector<Bucket>::Iterator bIter;
        typedef list<Entry>::Interator eIter;
        public:
            Iterator(bIter bp, eIter ep): bp(bp), ep(ep){}
            V& operator*()
            {
                return ep->value;
            }
            Iterator operator++()
            {                    
                try
                {
                    if(bp->end() == ep+1)
                        return Iterator(bp+1, (bp+1)->begin());
                    else
                        return Iterator(bp, ep+1);  
                }
                catch(const std::exception& e)
                {
                    return Iterator(bp+1, ep);
                }
                
            }
            bool operator==(const Iterator* iter)
            {
                return this->bp == iter->bp && this->ep == iter->ep;
            }
        private:
            bIter bp;
            eIter ep;
    }
};
