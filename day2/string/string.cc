#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class String
{
public:
    String(const char* movieName,float ticketPrice,const char* movieType)
        : _movieName(new char[strlen(movieName)+1]())
          , _ticketPrice(ticketPrice)
          , _movieType(new char[strlen(movieType)+1]())
    {
        cout<<"这是构造函数"<<endl;
        strcpy(_movieName,movieName);
        strcpy(_movieType,movieType);
    }

    String(const String & rhs)//拷贝构造函数
        : _movieName(new char[strlen(rhs._movieName)+1]())
          , _ticketPrice(rhs._ticketPrice)
          , _movieType(new char[strlen(rhs._movieType)+1]())
    {
        cout<<"这是拷贝构造函数"<<endl;
        strcpy(_movieName,rhs._movieName);
        strcpy(_movieType,rhs._movieType);
    }

    String & operator=(const String & rhs)//赋值运算符
    {
        if(this!=&rhs)
        {
            cout<<"这是赋值运算符"<<endl;
            delete [] _movieName;
            delete [] _movieType;
            _movieName=new char[strlen(rhs._movieName)+1]();
            strcpy(_movieName,rhs._movieName);
            _movieType=new char[strlen(rhs._movieType)+1]();
            strcpy(_movieType,rhs._movieType);
            _ticketPrice=rhs._ticketPrice;
        } 
        return *this;
    }
    ~String()//析构函数
    {
        cout<<"这是析构函数"<<endl;
        if(_movieName)
            delete [] _movieName;
        if(_movieType)
            delete [] _movieType;
    }
    void print()
    {
        cout<<"movieName:"<<_movieName<<endl
            <<"ticketPrice:"<<_ticketPrice<<endl
            <<"movieType:"<<_movieType<<endl
            <<"-------------------------------------"<<endl;
     }
private:
    char* _movieName;
    float _ticketPrice;
    char* _movieType;
};

String movie0("Casino",25,"Crime");
void movieTest()
{
    movie0.print();

    String movie1("Toy Story",30.49,"Adventure");
    movie1.print();

    static String movie2("GoldenEye",28.5,"Action");
    movie2.print();

    String movie3=movie2;
    movie3.print();
    
    movie3=movie1;
    movie3.print();
    
    String movie4(movie1);
    movie4.print();

}
int main(void)
{
    movieTest();
    return 0;
}

