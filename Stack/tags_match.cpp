#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Tag
{
public:
    string tag_name;
    bool isClose;

    Tag(): tag_name(""), isClose(false){};
    Tag(string tag_name, bool isClose): tag_name(tag_name), isClose(isClose){}
    Tag(const Tag& t)
    {
        this->isClose = t.isClose;
        this->tag_name = t.tag_name;
    }

    bool match(const Tag& t) const
    {
        return (this->isClose != t.isClose) &&
                (this->tag_name == t.tag_name);
    }
};

pair<Tag, int> tag_matcher(const string& s, int begin)
{
    typedef pair<Tag, int> pTi;
    int i = begin;
    bool hasBegin = false;
    while(s.size() != string::npos && i < s.size())
    {
        switch (s[i])
        {
            case '<':
                if(hasBegin)
                    return pTi(Tag(), -1);
                else
                {
                    hasBegin = true;
                    begin = i;
                }
                break;
            case '>':
                if(hasBegin)
                {
                    Tag t = Tag();
                    t.isClose = (s[begin+1] == '/');
                    // cout<<i<<" "<<s[i]<<endl;
                    t.tag_name = t.isClose? s.substr(begin+2, i-begin-2): s.substr(begin+1, i-begin-1);
                    return pTi(t, i+1);
                }
                else
                    return pTi(Tag(), -1);
                break;
            default:
                break;
        }
            
        i++;    
    }
    if(hasBegin)
        return pTi(Tag(), -1);
    else
        return pTi(Tag(), i);
}

bool html_parser(string s)
{
    int l = s.size();
    stack<Tag> parser = stack<Tag>();
    int i = 0;

    while(i < l)
    {
        pair<Tag, int> p = tag_matcher(s, i);
        cout<<p.first.tag_name<<endl;
        cout<<p.first.isClose<<endl;
        if(p.second == -1)
            return false;
        else
        {
            if(p.first.isClose)
            {
                if(parser.empty())
                    return false;
                else{
                    Tag tag = Tag(parser.top());
                    if(!tag.match(p.first))
                        return false;
                    parser.pop();                        
                }
            }
            else
            {
                parser.push(p.first);
            }
            i = p.second;
        }
    }

    if(parser.empty())
        return true;
    else
        return false;
}

int main()
{
    // pair<Tag, int> r;
    // string s;

    // s = "<1>";
    // r = tag_matcher(s, 0);
    // cout<<"name: "<<r.first.tag_name<<endl;
    // cout<<"type: "<<(r.first.isClose? "close":"begin")<<endl;
    // cout<<"pos: "<<r.second<<endl;

    // s = "</1234>";
    // r = tag_matcher(s, 0);
    // cout<<"name: "<<r.first.tag_name<<endl;
    // cout<<"type: "<<(r.first.isClose? "close":"begin")<<endl;
    // cout<<"pos: "<<r.second<<endl;

    // s = "</name>";
    // r = tag_matcher(s, 0);
    // cout<<"name: "<<r.first.tag_name<<endl;
    // cout<<"type: "<<(r.first.isClose? "close":"begin")<<endl;
    // cout<<"pos: "<<r.second<<endl;

    // s = "<1";
    // r = tag_matcher(s, 0);
    // cout<<"name: "<<r.first.tag_name<<endl;
    // cout<<"type: "<<(r.first.isClose? "close":"begin")<<endl;
    // cout<<"pos: "<<r.second<<endl;
    string s;

    s = "123<body><h><p>123</h></body>";
    cout<<html_parser(s)<<endl;

    return 0;
}