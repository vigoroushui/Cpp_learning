#include <ctype.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <vector>
using std::string;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::cout;
using std::endl;
using std::cin;
using std::map;
using std::set;
using std::vector;

class TextQuery
{
public:
    void readFile(const string filename);
    void query(const string & word);
private:
    map<string,set<int>> _word2line;
    map<string,int> _dict;
    vector<string> _line;
};

void TextQuery::readFile(const string filename)
{
    ifstream ifs(filename.c_str());
    cout<<filename.c_str()<<endl;
    if(!ifs)
    {
        cout<<"Don't find this file!"<<endl;
        return;
    }
    string line,word;
    int lineNumb=0;
    while(!(ifs.eof()))
    {
        getline(ifs,line);
        ++lineNumb;
        _line.push_back(line);
        istringstream istr(line);
        while(!(istr.eof()))
        {
            istr>>word;
            if(isalpha(word[0]))
            {
                _dict[word]++;
                _word2line[word].insert(lineNumb);
            }
        }
    }
    ifs.close();
}

void TextQuery::query(const string & word)
{
    cout<<"-----------------------------------------"<<endl;
    cout<<word<<" occurs "<<_dict[word]<<" times"<<endl;
    map<string,set<int>>::iterator it=_word2line.find(word);
    if(it !=_word2line.end())
    {
        set<int>::iterator it2=_word2line[word].begin();
        while(it2!=_word2line[word].end())
        {
            cout<<"(line "<<*it2<<") "<<_line[*it2-1]<<endl;
            ++it2;
        }
    }else{
        cout<<"The word is not exist!"<<endl;
    }
    cout<<"-----------------------------------------"<<endl;
}

int main()
{
    string queryWord("Cdsadaw");			   
    TextQuery tq;
    tq.readFile("/home/vigoroushui/C++_wangdao/day10/text_query/china_daily.txt");
    tq.query(queryWord);			   
    return 0;
}
