#include<iostream>
#include<vector>
#include<iterator>
using namespace std;


template<typename T>
class VectorCompleteTree
{
public:
    class Node
    {
    private:
        typedef typename vector<T>::iterator iter;
        iter i;
    public:
        Node(iter i): i(i){}
        Node(const Node& n): i(n.i){}
        T& operator*() const{ return *i;} 
        Node operator+(const int& num) { return Node(this->i + num);}
        Node operator-(const int& num) { return Node(this->i - num);}
        int operator-(const Node& n) { return (int)(this->i - n.i);}
    };

    VectorCompleteTree(): v(vector<T>(1)){} // 0位置为空
    int size() const{ return v.size() - 1;}
    int idx(Node n){ return n - Node(v.begin());}
    Node root(){ return Node(v.begin() + 1);}
    Node last(){ return Node(v.end() - 1);}
    Node left(Node n) { return Node(n + this->idx(n));}
    Node right(Node n) { return Node(n + this->idx(n) + 1);}
    Node parent(Node n) { return Node(n - this->idx(n)/2);}
    bool hasLeft(Node n) { return 2*this->idx(n) <= (v.size() - 1);}
    bool hasRight(Node n) { return 2*this->idx(n) + 1 <= (v.size() - 1);}
    bool isRoot(Node n) { return this->idx(n) == 1;}
    void addLast(const T& e){ v.push_back(e);}
    void removeLast(){ v.pop_back();}
    void swap(const Node& n1, const Node& n2)
    {
        T e = *n1;
        *n1 = *n2;
        *n2 = e;      
    }
    void print()
    {
        cout<<'[';
        for(int i=0; i<v.size(); ++i)
        {
            if(i != v.size()-1)
                cout<<v[i]<<", ";
            else
                cout<<v[i];
        }
        cout<<']';
    }
private:
    vector<T> v;
};

template<typename T>
class VectorHeap
{
public:
    typedef typename VectorCompleteTree<T>::Node Node;
    
    T top()
    {
        return *(tree.root());
    }

    bool empty()
    {
        return tree.size() == 1;
    }

    void print()
    {
        this->tree.print();
    }

    void insert(T e)
    {
        tree.addLast(e);
        Node n = tree.last();
        while(!tree.isRoot(n))
        {
            Node p = tree.parent(n);
            if(*p > *n ) 
                tree.swap(p, n);
            n = tree.parent(n);
        }
    }

    void removeMin()
    {
        Node r = tree.root();
        *r = *tree.last();
        while(tree.hasRight(r) || tree.hasLeft(r))
        {
            if(tree.hasRight(r) && tree.hasLeft(r))
            {
                Node rn = tree.right(r);
                Node ln = tree.left(r);
                if(*rn < *ln)
                {
                    tree.swap(rn, r);
                    r = rn;
                }
                else
                {
                    tree.swap(ln, r);
                    r = ln;
                }
            }
            else
            {
                Node n = tree.hasRight(r)? tree.right(r): tree.left(r);
                tree.swap(n, r);
                r = n;
            }
        }
        tree.removeLast();
    }

private:
    VectorCompleteTree<T> tree = VectorCompleteTree<T>();
};

