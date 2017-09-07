//#define DEBUG
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <regex>
#include <iomanip>
using namespace std;
ifstream fin;
#define MAX_NB 4096
#define MAX_P 10
#define MAX_Q 10
struct Node{
	int nb,p,q;
	Node(int a=0,int b=0,int c=0):nb(a),p(b),q(c){
	}
};
bool operator<(const Node & l, const Node & r)
{
	if(l.nb==r.nb)
	{
		if(l.p==r.p) return l.q<r.q;
		return l.p<r.p;
	}
	return l.nb<r.nb;
}
map<Node,int> mp;
double sum[MAX_NB][MAX_P][MAX_Q];
int count1[MAX_NB][MAX_P][MAX_Q];

void senderr(const string & s)
{
	cerr<<s<<endl;
	exit(-1);
}

void readToLine(ifstream & in);
void init()
{
	cout<<"reading header..."<<endl;
	readToLine(fin);
	readToLine(fin);
}


const std::regex MAT("={3,}");
void readToLine(ifstream & in)
{
	string s;
	while(!in.eof())
	{
		getline(in,s);
		bool result=std::regex_search(s,MAT);
		if(result) break;
		//else cout<<s<<endl;
	}
}
float  deal()
{
	int n,nb,p,q;float time,ans;
	string s;
	readToLine(fin);	//==========================================
#ifdef DEBUG
	cout<<s<<endl;
#endif
	getline(fin,s);	//T/V			N		NB		P		Q
	getline(fin,s);	//------------------------------------------
	if(s[0]=='F') return 0.0;
	fin>>s>>n>>nb>>p>>q>>time>>ans;
	count1[nb][p][q]++;
	sum[nb][p][q]+=ans;fin.get();
	mp[Node(nb,p,q)]++;
	//getline(fin,s);	//WR00L2L2   2000		 4		2		2
	getline(fin,s);	//HPL_pdgesv() start time ........
	getline(fin,s);	//empty line
	getline(fin,s);	//HPL_pdgesv() end time ......
	getline(fin,s);	//empty line
	getline(fin,s);	//------------------------------------------
	getline(fin,s);	//||Ax-b||_oo/(eps*....),,,,,
	return ans;
}
struct Ans{
	Node d;float ans;
	Ans(Node dd,float a):d(dd),ans(a){
	}
};
bool cmp (const Ans & l, const Ans & r)
{
	return l.ans>r.ans;
}
#include <vector>
#include <algorithm>
int main(int argc,char *argv[])
{
	if(argc!=2) senderr("command: ./analysiser <filename>");
    fin.open(argv[1]);
	ofstream fout(string(argv[1])+".anly",ios::out);
	init();
	int cnt=0;
	while(!fin.eof())
	{
		float tmp=deal();
#ifdef DEBUG
		cout<<tmp<<endl;
#endif
		if(tmp==0.0) break;
		++cnt;
	}
	//cout.width(8);cout.fill(' ');
	//fout.width(8);fout.fill(' ');
	//
	cout<<"raw data "<<cnt<<endl;
	fout<<"raw data "<<cnt<<endl;
	vector<Ans> v;
	for(auto m:mp)
	{
		Node n=m.first;
		int nb=n.nb,p=n.p,q=n.q;
		cout<<setw(3)<<nb<<" "<<p<<" "<<q<<" "<<sum[nb][p][q]/count1[nb][p][q]<<endl;
		v.push_back(Ans(n,sum[nb][p][q]/count1[nb][p][q]));
		fout<<setw(3)<<nb<<" "<<p<<" "<<q<<" "<<sum[nb][p][q]/count1[nb][p][q]<<endl;
	}
	std::sort(v.begin(),v.end(),cmp);
	fout<<endl;
	fout<<"sorted data"<<endl;
	for(auto vv:v)
	{
		fout<<setw(3)<<vv.d.nb<<" "<<vv.d.p<<" "<<vv.d.q<<" "<<vv.ans<<endl;
	}
	fout.close();
	cout<<"printed to "<<argv[1]<<".anly"<<endl;
	return 0;
}
