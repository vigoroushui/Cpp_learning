/**********************************************************
 * Author        : Vigoroushui
 * Email         : vigoroushui@gmail.com
 * Last modified : 2019-07-30 19:47:14
 * Filename      : Line.cc
 * Description   : 
 * *******************************************************/
#include "Line.h"
#include <iostream>
using std::cout;
using std::endl;

class Line::LinePimpl
{
    class Point
    {
    public:
        Point(int ix=0,int iy=0)
        : _ix(ix)
        , _iy(iy)
        {
            cout<<"Point(int,int)"<<endl;
        }
        void print() const
        {
            cout<<"("<<_ix
                <<","<<_iy
                <<")";
        }
        ~Point(){   cout<<"~Point()"<<endl;}
    private:
        int _ix;
        int _iy;
    };
public: 
   LinePimpl(int x1,int y1,int x2,int y2)
   : _pt1(x1,y1)
   , _pt2(x2,y2)
   {    cout<<"LinePimpl(int,int,int,int)"<<endl;}
   ~LinePimpl(){    cout<<"~LintPimpl()"<<endl;}
   void printLine() const;
private:
    Point _pt1;
    Point _pt2;
};

Line::Line(int x1,int y1,int x2,int y2)
: _pimpl(new LinePimpl(x1,y1,x2,y2))
{
    cout<<"Line(int x1,int y1,int x2,int y2)"<<endl;
}
Line::~Line()
{
    if(_pimpl)
        delete _pimpl;
    cout<<"~Line()"<<endl;
}
void Line::printLine()const
{
    _pimpl->printLine();
}
void Line::LinePimpl::printLine() const
{
    _pt1.print();
    cout<<"-->";
    _pt2.print();
    cout<<endl;
}
