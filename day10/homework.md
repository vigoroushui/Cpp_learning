
# 1.词频统计的作业
用map/unordered_map容器去实现一次，体验一下使用vector/map/unordered_map时程序执行的速度
- 基于vector的词频统计 
```cpp
#include <string.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using std::ifstream;
using std::ofstream;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::istringstream;
using std::string;
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
```
- 基于map的词频统计
```cpp
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
using std::string;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::cout;
using std::endl;
using std::cin;
using std::map;
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
    map<string,int> wordCount;
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
```
- 基于unordered_map的词频统计
```cpp
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
```

# 2.文本查询作业
该程序将读取用户指定的任意文本文件【当前目录下的china_daily.txt】，然后允许用户从该文件中查找单词。查询的结果是该单词出现的次数，并列出每次出现所在的行。如果某单词在同一行中多次出现，程序将只显示该行一次。行号按升序显示。

要求：

​    a. 它必须允许用户指明要处理的文件名字。   

​    b. 程序将存储该文件的内容，以便输出每个单词所在的原始行。

```cpp
   vector<string> lines;//O(1)  完美hash
或 map<int, string> lines;//O(logN)
或 unorderedmap<int,string> lines;//O(1)     
```

​    c. 它必须将每一行分解为各个单词，并记录每个单词所在的所有行在输出行号时，应保证以升序输出，并且不重复。 

```cpp
map<string, set<int> > word2Line;
map<string, int> dict;      
```
​  
    d. 对特定单词的查询将返回出现该单词的所有行的行号。

​    e. 输出某单词所在的行文本时，程序必须能根据给定的行号从输入文件中获取相应的行。

示例：

​        使用提供的文件内容，然后查找单词 "element"。输出的前几行为：

```cpp
			--------------------------------------------- 				
			element occurs 125 times.
    			(line 62) element with a given key.
    			(line 64) second element with the same key.
    			(line 153) element |==| operator.
    			(line 250) the element type.
    			(line 398) corresponding element.
    		---------------------------------------------
    		  程序接口[可选]:
    			class TextQuery
    			{
    			public:
    			    void readFile(const string filename);
    			    void query(const string & word);
    			private:
							//......
    			};
    			
    			//程序测试用例
    			int main(int argc, char *argv[])
    			{
    			   string  queryWord("hello");
    			   
    			   TextQuery tq;
    			   tq.readFile("test.dat");
    			   tq.query(queryWord);			   
    			   return 0;
    			}  
```

代码如下：

```cpp
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
    string queryWord("to");			   
    TextQuery tq;
    //需换成你想要统计的文档的绝对路径 		   	     
    tq.readFile("/home/vigoroushui/C++_wangdao/day10/text_query/china_daily.txt");
    tq.query(queryWord);			   
    return 0;
}
```  
# 3.Leetcode 146 LRU [题目在当前目录下]
```cpp
#include <iostream>
#include <unordered_map>
#include <list>
using std::unordered_map;
using std::list;
using std::cout;
using std::endl;
using std::pair;
using std::make_pair;
class LRUCache {
public:
    LRUCache(int capacity)
    :_capicity(capacity)
    {}
    int get(int key)
    {
        auto iterator=_m.find(key);
        if(iterator==_m.end())
            return -1;
        int val=iterator->second->second;
        _list.erase(iterator->second);
        _list.push_front(make_pair(key,val));
        _m[key]=_list.begin();
        cout<<key<<"'s value="<<val<<endl;
        return iterator->second->second;
    }
    void put(int key, int value)
    {
        cout<<"put key="<<key<<", value="<<value<<endl;
        auto iterator=_m.find(key);
        if(iterator!=_m.end())
            _list.erase(iterator->second);
        _list.push_front(make_pair(key,value));
        _m[key]=_list.begin();
        if(_list.size()>_capicity){
            int key=_list.back().first;
            _m.erase(key);
            _list.pop_back();
        }
    }
private:
    int _capicity;
    list<pair<int,int>> _list;
    unordered_map<int,list<pair<int,int>>::iterator> _m;
};

int main()
{
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);       // 返回  1
    cache.put(3, 3);    // 该操作会使得密钥 2 作废
    cache.get(2);       // 返回 -1 (未找到)
    cache.put(4, 4);    // 该操作会使得密钥 1 作废
    cache.get(1);       // 返回 -1 (未找到)
    cache.get(3);       // 返回  3
    cache.get(4);       // 返回  4
}
```

# 4.实现一个堆排序算法
可选择使用模板或非模板的实现：   
使用模板的框架如下：
```cpp
template <typename T, typename Compare = std::less<T> >
class HeapSort
{
public:
    void heapAdjust();
    void sort();
private:
    //...
};
```
