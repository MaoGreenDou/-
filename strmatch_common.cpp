
/*
*    原作业代码中存在的问题：
*    1.匹配函数中i的初始化存在问题，从零开始，应该是i=pos-1；
*    2.若匹配成功时，返回的位置应该进行+1处理，理由同上。
*    
*    编写代码时遇到的问题：
*    1.字符串的录入包括最后的换行符，字符串的长度则不包括
*    2.对i值更新的理解
*    3.对数组下表，和返回位置的处理
*/

#include<iostream>
#include<string.h>
using namespace std;

typedef char SString[255];//定义字符串类型SString

int Index(SString S, SString T, int pos) {
    int i = pos;   int j = 0;//下标从0开始
    while (i < strlen(S) && j < strlen(T)) {    /* 此处用小于号，因为下标从0开始 */
      if (S[i] == T[j]) { ++i;  ++j; }   // 继续比较后继字符
      else
      { i = i-j+1;   j = 0; }// 指针回溯重新开始匹配    /* 此处是i-j+1，等价于 i_0-0+1 */
    }
   if (j == strlen(T))  return  i-strlen(T);    /* j== strlen(T) 在此处等价于 j>=strlen(T) */
   else return -1;
} // Index
 
int main(){
    SString S,T;
    int pos;
    cout<<"input mainstring  S:";
    cin>>S;
    cout<<"intput substring T:";
    cin>>T;
    cout<<"intput begin postion of match:";
    cin>>pos;
    cout<<"the match pos ="<<Index(S,T,pos)<<endl;
    return 0;
}


//#define MaxSize 255
//#define ERROR -1
//typedef char Sstring[MaxSize];
//
//
//int strMatchCommon(Sstring s, Sstring t, int pos)
//{
//	int i, j;
//	i = pos - 0 ;    //i是数组中的元素下标，从0开始
//	j = 0;
//
//	while (i < strlen(s) && j < strlen(t))
//	{
//		if (s[i] == t[j])
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			i = i - j + 1;
//			j = 0;
//		}
//	}
//	if (j == strlen(t))
//	{
//		return i - strlen(t) + 1;    //返回的是实际位置，而不是数组下标
//	}
//	else
//	{
//		return ERROR;
//	}
//}
//
//int main()
//{
//	Sstring s, t;
//	int pos;
//
//	cout << "Please input string S:";    //initial string s
//	cin >> s;
//	cout << endl;
//
//	cout << "Please input string T:";    //initial string t
//	cin >> t;
//	cout << endl;
//
//	cout << "Please input index of start:";    //initial index pos
//	cin >> pos;
//	cout << endl;
//
//	if (strMatchCommon(s, t, pos)!=ERROR)    
//	{
//		cout << "the start index is:" << strMatchCommon(s, t, pos) << endl;
//	}
//	else
//	{
//		cout << "not foud string T in string S!" << endl;
//	}
//	return 0;
//}
