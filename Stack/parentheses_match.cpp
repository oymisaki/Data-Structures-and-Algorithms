#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Parentheses
{
public:
    char c;
    Parentheses(char c): c(c){};
    Parentheses(const Parentheses& p)
    {
        this->c = p.c;
    }
    bool match(const Parentheses& p) const
    {
        switch (p.c)
        {
            case '{':
                return this->c == '}';
                break;
            case '}':
                return this->c == '{';
                break;
            case '[':
                return this->c == ']';
                break;
            case ']':
                return this->c == '[';
                break;
            case '(':
                return this->c == ')';
                break;
            case ')':
                return this->c == '(';
                break;
            default:
                throw "not defined parentheses";
        }
    }
};

const string BEGIN = "{[(";
const string CLOSE = "}])";

bool parentheses_match(string s)
{
    stack<Parentheses> matcher = stack<Parentheses>();
    for(unsigned int i=0; i<s.length();++i)
    {
        // cout<<BEGIN.find(s[i])<<endl;
        if(BEGIN.find(s[i]) != string::npos)
        {
            Parentheses p = Parentheses(s[i]);
            matcher.push(p);
        }
        else if(CLOSE.find(s[i]) != string::npos)
        {
            Parentheses p = Parentheses(s[i]);
            if(matcher.size() == 0)
                return false;

            Parentheses last_p = matcher.top();
            matcher.pop();
            if(!p.match(last_p))
                return false;
        }
        else
            continue;
    }
    if(!matcher.empty())
        return false;
    return true;
}


int main()
{
    string s1 = "";
    cout<<parentheses_match(s1)<<endl;

    string s2 = "(){}[]";
    cout<<parentheses_match(s2)<<endl;

    string s3 = "){}[]";
    cout<<parentheses_match(s3)<<endl;

    string s4 = "abacs(+)+{123}[]";
    cout<<parentheses_match(s4)<<endl;

    return 0;
}