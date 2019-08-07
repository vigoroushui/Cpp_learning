#include <stack>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2!=0)
            return false;
        map<char,char> tmp;
        tmp[')']='(';
        tmp[']']='[';
        tmp['}']='{';
        stack<char> stk;
        for(int i=0;i<s.length();++i)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
                stk.push(s[i]);
            if(s[i]==')'||s[i]==']'||s[i]=='}')
            {
                if(stk.empty())
                    return false;
                if(tmp[s[i]]==stk.top())
                {
                    stk.pop();
                }
            }
        }
        if(!stk.empty())
            return false;
        return true;
    }
};