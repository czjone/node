#include "Express.hpp"
#include <stack>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "../macros.hpp"


using namespace std;
XSE_NS_USING;
typedef  std::stack<std::string>::value_type vtype;
std::string Express::itoa(LLong val){
    char buffer[40];
	LLong d = val;
    sprintf(buffer,"%lld",d);
    string str(buffer);
    return str;
}

LLong Express::additionSubtraction(deque<string> &deque)
{
    if (deque.size() == 1) return atoll(deque.front().c_str());
	LLong num = atoll(deque.front().c_str());
    deque.pop_front();
	bool IsAdd;
    while (!deque.empty())
    {
        //是否为加法
        IsAdd = deque.front() == "+" ? true : false;
        deque.pop_front();
        if(deque.size()==0)  break;
		LLong num2 = atoll(deque.front().c_str());
        deque.pop_front();
        if (IsAdd) num = num + num2;
        else num = num - num2;
    }
    return num;
}


void Express::addValueToDeque(deque<string> &deque, LLong pre)
{
    //队列为空或加减号时，直接压入数字
    if (deque.empty() || deque.back() == "+" || deque.back() == "-")
    {
        deque.push_back(itoa(pre));
    }
    
    //乘除号时，先计算结果，再压入数字
    else if (deque.back() == "*" || deque.back() == "/")
    {
        bool IsMultiplication = (deque.back() == "*") ? true :false ;
        deque.pop_back();
        string numstr =deque.back();
        if(numstr.size()==0) throw "表达式错误!";
		LLong num = atoll(numstr.c_str());
        deque.pop_back();
        if (IsMultiplication){
            deque.push_back(itoa(num * pre));
        }
        else{
            XSE_ASSERT(pre!=0,"除0异常!");
            deque.push_back(itoa(num / pre));
        }
    }
}

pair<LLong, LLong> Express::getValue(const string &str, int index)
{
	LLong pre = 0;
    int size=str.size();
    deque<string> deq;
	pair<LLong, LLong> p;
	LLong result;
	LLong pre_right = 1.0;
	LLong is_right = false;
    while (index < size && str[index] != ')')
    {
        char c = str[index];
        if(c == ' '){ index++; continue;}
        //若是数字，累加pre
        if (!is_right && (c >= '0' && c <= '9'))
        {
            pre = pre * 10 + c - '0';
            ++index;
        }
        else if(c == '.'){
            is_right =  true;
            ++index;
        }else if(is_right && (c >= '0' && c <= '9')){
            pre_right *= 0.1;
            pre += (c - '0') * pre_right;
            ++index;
        }
        //若是加减乘除符号
        else if (c != '(')
        {
            //压入一个数的同时，把最后的乘除法计算出来
            addValueToDeque(deq, pre);
            pre = 0;
            pre_right = 1.0;
            is_right = false;
            deq.push_back(string(1, c));
            ++index;
        }
        //若是左括号，进入递归
        else
        {
            p = getValue(str, index + 1);
            addValueToDeque(deq,p.first);
            index = p.second;
        }
    }
    
    //处理最后一个数字
    addValueToDeque(deq, pre);
    //计算加减号
    result = additionSubtraction(deq);
    return make_pair(result, index + 1);
}

LLong Express::getValue(const string &str)
{
    if (str.empty())return 0;
    try{
        auto p= getValue(str, 0);
        return p.first;
    }catch(const char* error){
        printf("error:%s ,express :%s",error,str.c_str());
        return 0;
    }
}

std::string Express::Evaluate(std::string cstr){
	LLong val = getValue(cstr);
    const int len=20;
    char str[len];
    sprintf(str, "%lld",val);
    return str;
}
