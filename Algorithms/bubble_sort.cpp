#include<iostream>
#include<vector>
#include<iterator>
using namespace std;

/*
This is a simple realization of bubble sort.
Other similar sorting algorithms are:
1. selection sort, done with an linked list, sorting by removing the min each time
2. insertion sort, done with an linked list, sorting by inserting each time
Their time complexities are O(n^2)
*/
template<typename T>
ostream& operator<<(ostream& os, vector<T> v)
{
    os<<'[';
    for(int i=0; i<v.size(); ++i)
    {
        if(i != v.size()-1)
            os<<v[i]<<", ";
        else
            os<<v[i];
    }
    os<<']';
    return os;
}

vector<int> bubble_sort(vector<int> v, int p=0)
{
    typedef vector<int>::iterator iterator;
    iterator i = v.begin();
    if(i == v.end())
        return v;
    bool sorted = true;

    while(next(i) != v.end())
    {
        if(*i > *next(i))
        {
            int tmp = *i;
            *i = *next(i);
            *next(i) = tmp;
            sorted = false;
        }
        i = next(i);
    }
    if(sorted)
        return v;
    else
    {
        cout<<"pass: "<<p<<endl;
        cout<<v<<endl;
        return bubble_sort(v, p+1);
    }
}


int main()
{
    vector<int> v;
        
    v = vector<int>({});
    cout<<bubble_sort(v)<<endl;
    
    v = vector<int>({2});
    cout<<bubble_sort(v)<<endl;

    v = vector<int>({3, 2, 1, 3, 2});
    cout<<bubble_sort(v)<<endl;

    return 0;
}