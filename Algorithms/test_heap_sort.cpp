#include<iostream>
#include<vector>
#include"heap_sort.cpp"
using namespace std;

void test_complete_tree()
{
    VectorCompleteTree<int> v = VectorCompleteTree<int>();
    v.addLast(0);
    v.addLast(1);
    v.addLast(2);
    v.print();

    v.removeLast();
    v.print();

    typedef VectorCompleteTree<int>::Node Node;
    Node n = v.root();
    v.print();
    Node rn = v.right(n);
    Node ln = v.left(n);
    cout<<v.idx(n)<<" "<<v.idx(ln)<<" "<<v.idx(rn)<<" "<<endl; 
    cout<<v.hasRight(n)<<" "<<v.hasLeft(n)<<endl;
    v.swap(n, ln);
    cout<<*v.parent(n)<<endl;
    v.print();
}

void test_heap()
{
    VectorHeap<int> h = VectorHeap<int>();
    h.insert(3);
    h.print();

    h.insert(2);
    h.print();

    h.insert(1);
    h.print();

    cout<<h.top()<<endl;
    
    h = VectorHeap<int>();
    vector<int> v = vector<int>({3,7,2,1,4});
    for(int i=0;i<v.size();++i)
    {
        h.insert(v[i]);
    }

    h.print();    
    cout<<h.top()<<" ";
    while(!h.empty())
    {
        h.removeMin();
        cout<<h.top()<<" ";
    }
}

int main()
{
    test_heap();
    return 0;
}