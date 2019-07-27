#include "dictionary.h"
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>
using std::ifstream;
using std::ofstream;
using std::cin;
using std::vector;
using std::istringstream;

struct WordFre
{
    WordFre(const string &w,int n)
        :word(w)
         ,wordNumber(n)
    {}
    string word;
    int wordNumber;
};

int main()
{
    string filePath;
    cout<<"pls input the absoute path of file"<<endl;
    cin>>filePath;
    ifstream ifs(filePath.c_str());
    if(!ifs)
    {
        cout<<"ifstream open file error!"<<endl;
        return -1;
    }//传入待统计英文文章的绝对路径
    vector<WordFre> dict;
    string word;
    int flag;
    while(ifs>>word)
    {   
        flag=0;
        if(isalpha(word[0]))
        {
            for(size_t idx=0;idx!=dict.size();++idx)
            {
                if(dict[idx].word==word)
                {
                    dict[idx].wordNumber++;
                    flag=1;
                    break;
                }
            }
            if(0==flag)    
            {
                WordFre wordFre("",0);
                wordFre.word=word;
                wordFre.wordNumber=1;
                dict.push_back(wordFre);
            }
        }
    } 
    ofstream ofs("dictionary.txt",std::ios::app);
    for(auto &wordFre:dict)
    {
        ofs<<wordFre.word<<" "
            <<wordFre.wordNumber<<endl;
    }
    ofs.close();
}


