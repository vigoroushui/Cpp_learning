#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Dictionary
{
public:
    Dictionary() {}
    ~Dictionary() {}
    void read(string& filename);
    void store(/*const string& filename*/);
private:
    string _filename;
};


