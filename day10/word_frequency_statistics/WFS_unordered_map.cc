#include <ctype.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
using std::string;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::cout;
using std::endl;
using std::cin;
using std::unordered_map;
int main()
{
    string filePath;
    cout<<"pls input the absoute path of file"<<endl;
    cin>>filePath;
    ifstream ifs(filePath.c_str());
    if(!ifs)
    {
        cout<<"ifstream open file error"<<endl;
        return -1;
    }
    string line,word;
    unordered_map<string,int> wordCount;
    while(!(ifs.eof()))
    {
        getline(ifs,line);
        istringstream istr(line);
        while(!(istr.eof()))
        {
            istr>>word;
            if(isalpha(word[0]))
            {
                wordCount[word]++;
            }
        }
    }
    ifs.close();
    ofstream ofd("dictionary.txt",std::ios::app);
    for(auto iter=wordCount.begin();iter!=wordCount.end();iter++)
    {
        ofd<<iter->first<< "   "<<iter->second<<"\n";
    }
}
