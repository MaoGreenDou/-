
/*
*    ԭ��ҵ�����д��ڵ����⣺
*    1.ƥ�亯����i�ĳ�ʼ���������⣬���㿪ʼ��Ӧ����i=pos-1��
*    2.��ƥ��ɹ�ʱ�����ص�λ��Ӧ�ý���+1��������ͬ�ϡ�
*    
*    ��д����ʱ���������⣺
*    1.�ַ�����¼��������Ļ��з����ַ����ĳ����򲻰���
*    2.��iֵ���µ����
*    3.�������±��ͷ���λ�õĴ���
*/

#include<iostream>
#include<string.h>
using namespace std;

typedef char SString[255];//�����ַ�������SString

int Index(SString S, SString T, int pos) {
    int i = pos;   int j = 0;//�±��0��ʼ
    while (i < strlen(S) && j < strlen(T)) {    /* �˴���С�ںţ���Ϊ�±��0��ʼ */
      if (S[i] == T[j]) { ++i;  ++j; }   // �����ȽϺ���ַ�
      else
      { i = i-j+1;   j = 0; }// ָ��������¿�ʼƥ��    /* �˴���i-j+1���ȼ��� i_0-0+1 */
    }
   if (j == strlen(T))  return  i-strlen(T);    /* j== strlen(T) �ڴ˴��ȼ��� j>=strlen(T) */
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
//	i = pos - 0 ;    //i�������е�Ԫ���±꣬��0��ʼ
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
//		return i - strlen(t) + 1;    //���ص���ʵ��λ�ã������������±�
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
