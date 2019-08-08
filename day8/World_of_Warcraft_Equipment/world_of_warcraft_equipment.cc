#include <iostream>
using std::cout;
using std::endl;

enum weapon {sword,bomb,arrow};
enum redHeadquarters {iceman,lion,wolf,ninja,dragon};


class Warrior
{
public:
    Warrior(int num,int healthPoint)
    : _num(num)
    , _healthPoint(healthPoint)
    {}
private:
    int _num;
    int _healthPoint;
};

class Dragon
:public Warrior
{
public:
    
private:
    float _morale;
};

class Ninja
:public Warrior
{
public:
private:
};

class Iceman
:public Warrior
{
public:
private:
};

class Lion
:public Warrior
{
public:
private:
    int _loyalty;
};

class Wolf
:public Warrior
{
public:
private:
};

