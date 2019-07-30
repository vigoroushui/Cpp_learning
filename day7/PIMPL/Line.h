/**********************************************************
 * Author        : Vigoroushui
 * Email         : vigoroushui@gmail.com
 * Last modified : 2019-07-30 19:45:49
 * Filename      : Line.h
 * Description   : 
 * *******************************************************/
#pragma once
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;
class Line
{
    class LinePimpl;
public:
    Line(int,int,int,int);
    ~Line();
    void printLine() const;
private:
    LinePimpl *_pimpl;
};

