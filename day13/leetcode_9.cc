#include <limits.h>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int tmp=x;
        long a=0;
        while(x)
        {
            a=a*10+x%10;
            x/=10;
            if(a>INT_MAX)
                return false;
        }
        cout<<"a="<<a<<endl;
        return tmp==static_cast<int>(a)?true:false;
    }
};

int main()
{
    Solution a;
    bool c=a.isPalindrome(121);
    cout<<c<<endl;
}