#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

class Number
{
public:
    Number(int data)
    : _data(data)
    {
        //cout<<"Number(int data)"<<endl;
    }
    void display() const
    {
        cout<< _data<<" ";
    }
    bool isEven() const
    {
        return (0==_data%2);
    }
    bool isPrime() const
    {
        if(1==_data||0==_data)
            return false;
        for(int idx=2;idx<=_data/2;++idx)
        {
            if(0==_data%idx)
                //cout<<_data%idx<<endl;
                return false;
        }
        return true;
    }
private:
    int _data;
};

int main(void)
{
    vector<Number> numbers;
    for(int idx=0;idx!=30;++idx)
        numbers.emplace_back(idx);
    std::for_each(numbers.begin(),numbers.end(),std::mem_fn(&Number::display));
    cout<<endl;
    //std::remove_if(numbers.begin(),numbers.end(),std::mem_fn(&Number::isEven));
    //std::for_each(numbers.begin(),numbers.end(),std::mem_fn(&Number::display));
    //cout<<endl;
    numbers.erase(std::remove_if(numbers.begin(),numbers.end(),std::mem_fn(&Number::isEven)),numbers.end());
    std::for_each(numbers.begin(),numbers.end(),std::mem_fn(&Number::display));
    cout<<endl;
    numbers.erase(std::remove_if(numbers.begin(),numbers.end(),std::mem_fn(&Number::isPrime)),numbers.end());
    std::for_each(numbers.begin(),numbers.end(),std::mem_fn(&Number::display));
    cout<<endl;
    return 0;
}
