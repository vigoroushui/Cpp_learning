#include <iostream>
using std::cout;
using std::endl;
#define PI 3.14
class Circle
{
public:
    Circle()
    : _radius(0)
    {}
    Circle(double r)
    : _radius(r)
    {}
    double getArea()
    {
        return PI*_radius*_radius;
    }
    double getPerimeter()
    {
        return 2*_radius*_radius;
    }
    void show()
    {
        cout<<"Circle's radius="<<_radius<<endl
            <<"Circle's area="<<getArea()<<endl
            <<"Circle's perimeter="<<getPerimeter()<<endl;
    }
private:
    double _radius;
};

class Cylinder
:public Circle
{
public:
    Cylinder(double r,double h)
    : Circle(r)
    , _cldHeight(h)
    {}
    double getVolume()
    {
        return getArea()*_cldHeight;
    }
    void showVolume()
    {
        cout<<"Cylinder's getVolume="<<getVolume()<<endl;
    }
private:
    double _cldHeight;
};

int main(void)
{
    Cylinder cylinder(2,4);
    cylinder.Circle::show();
    cylinder.showVolume();
    return 0;
}
