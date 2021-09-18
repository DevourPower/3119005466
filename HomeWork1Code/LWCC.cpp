```cpp
#include <bits/stdc++.h>
#define pii pair<int ,int >
#define X first
#define Y second
using namespace std;
/*
string p[3] =
{
	"C:/Users/86189/Desktop/bush/allin/orig_0.8_dis_1.txt",
	"C:/Users/86189/Desktop/bush/allin/orig_0.8_dis_10.txt",
	"C:/Users/86189/Desktop/bush/allin/out.txt"
};
int clo = 0;
*/
inline void output(string s){cout<<s<<endl;}
string  in()//读入一个文件;
{
	string path ;cin>>path;//读入路径;
	ifstream infile(path);
	string res ; string in;
	while(getline(infile,in) ) res += in;
	infile.close();
	return res;
}
int func(string s,map<pii,int > &m)
{//字符计数;
	int last = 0;
	for(int i = 0;i<s.size();++i)
	{
		if(s[i]<0)
		{
			if(last )m[{(int )last,(int )s[i]}]++;
			else last = s[i];
		}
		else m[{(int )s[i],0} ]++;
	}
}
inline void out (int cnt ,int len)
{//对于答案参数进行输出
	string path ;cin>>path;
	ofstream os(  path.c_str(), ios::out );
	os<<"匹配字符数(同字符出现的次数最小值之和): "<<cnt<<"\n";
	os<<"两文本长度平均值: "<<0.5*(len)<<"\n";
	os<<"匹配率(匹配字符数/长度平均值): "<<200.0*cnt/len<<"%\n";
}
int main()
{
	//否则则为普通ascii;
	printf("请你输入待比对文本A的路径:\n");
	string S = in(); int lenS = S.size();
	printf("请你输入带比对文本B的路径:\n");
	string T = in(); int lenT = T.size();
	printf("请你输入结果的输出路径:\n:");
	map<pii ,int >tong[2];
	func(S,tong[0]);
	func(T,tong[1]);
	int cnt =0;//匹配字符数;
	for(auto i:tong[0]) cnt += min( tong[1][i.X] ,i.Y );
	out(cnt, lenS+lenT);
	return 0;
}
```
