# 问答题
## 1. 迭代器的种类有哪些？他们各自的功能是什么？为什么要定义这么多种类？
- 随机访问迭代器(RandomAccessIterator):组合双向迭代器的功能与直接访问容器中任何元素的功能，即可向前向后跳过任意个元素。
- 双向迭代器(BidirectionalIterator):组合正向迭代器和逆向迭代器的功能，支持多遍算法。
- 前向迭代器(ForwardIterator):组合输入迭代器和输出迭代器的功能，并保留在容器中的位置。
- 输出迭代器(OutputIterator):向容器中写入元素，输出迭代器只能一次一个元素向前移动，输出迭代器只支持一遍算法，同一输出迭代器不能两次遍历一个序列。
- 输入迭代器(InputIterator):从容器中读取元素，输入迭代器只能一次读入一个元素向前移动，输入迭代器只支持一遍算法，同一输入迭代器不能两次遍历一个序列。

不同的算法要求的迭代器类型不同，之所以定义了5种迭代器，是为了使用“最合适”的工具，编写算法时在满足要求的基础上尽可能地使用功能少的迭代器，减少迭代器引入的副作用，假设要编写一个查找函数find()，只要能读取容器中的元素即可，最理想的方案是使用输入迭代器，这样，有效防止了在find()函数内对元素的修改，真正“物尽其用”。
## 2. 通过阅读迭代器源码的方式来理解迭代器，如：
		 > ostream_iterator
		 > istream_iterator
		 > back_insert_iterator 
## 3. 什么是适配器模式？STL中有哪些适配器？
配器模式将一个类的接口转换成客户希望的另外一个接口，使得原本由于接口不兼容而不能一起工作的那些类可以一起工作。它包括类适配器和对象适配器。

STL中的适配器包括stack、queue、priority_queue。
# 代码题:
## 1. Leetcode 20 Valid Parentheses -->stack
题目描述：
```
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
1.	Open brackets must be closed by the same type of brackets.
2.	Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.
Example 1:
Input: "()"Output: true
Example 2:
Input: "()[]{}"Output: true
Example 3:
Input: "(]"Output: false
Example 4:
Input: "([)]"Output: false
Example 5:
Input: "{[]}"Output: true
```
解法：
```cpp
class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2!=0)
            return false;
        map<char,char> tmp;
        tmp[')']='(';
        tmp[']']='[';
        tmp['}']='{';
        stack<char> stk;
        for(int i=0;i<s.length();++i)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
                stk.push(s[i]);
            if(s[i]==')'||s[i]==']'||s[i]=='}')
            {
                if(stk.empty())
                    return false;
                if(tmp[s[i]]==stk.top())
                {
                    stk.pop();
                }
            }
        }
        if(!stk.empty())
            return false;
        return true;
    }
};
```

## 2. Leetcode 127 Word Ladder
题目描述：
```
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
1.	Only one letter can be changed at a time.
2.	Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:
•	Return 0 if there is no such transformation sequence.
•	All words have the same length.
•	All words contain only lowercase alphabetic characters.
•	You may assume no duplicates in the word list.
•	You may assume beginWord and endWord are non-empty and are not the same.
Example 1:
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:
Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"] 
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
```
解法：
```cpp
class Solution {
public:
int ladderLength(string beginWord, 
		string endWord, 
		const set<string>& wordList) {
    }
};
```

## 3. 完成C++ primer(第5版)中的15.9节的文本查询程序扩展,
   即使不自己实现, 最好也要照着书敲一遍代码,在机器
   上让程序跑起来, 也会让你对面向对象设计有新的理解.[慢慢做]
