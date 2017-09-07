//#define DEBUG 
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

/* Struct Node
 * It stores data of N, NB, P, Q, SPEED
 */
class Node
{
public:
	int n,nb,p,q;
	vector<float> speeds;
	
public:
	//CONSTRUCTOR
	Node()
	{
		n=0;nb=0;p=0;q=0;
	}
	Node(int _n,int _nb,int _p,int _q):n(_n),nb(_nb),p(_p),q(_q)
	{	
	}

	//METHOD addSpeed
	void addSpeed(float spd)
	{
		speeds.push_back(spd);
	}

	//-EQ
	friend bool operator==(const Node & l,const Node & r);

	//OUTPUT METHOD
	friend ostream & operator<<(ostream & o,const Node & n);

	//OUTPUT ANALYSIS
	void analysis(ostream & o)
	{
		o<<(*this);
		//GET MIN AND MAX
		auto p=std::minmax_element(speeds.begin(),speeds.end());		
		auto min=*p.first,max=*p.second;
		//GET AVERAGE
		float avg=0.0,sum=0.0;
		for(float spd : speeds)
		{
			sum+=spd;
		}
		avg=sum/speeds.size();
		o<<min<<"\t\t\t\tmin speed [GFLOPS]\n"
			<<max<<"\t\t\t\tmax speed [GFLOPS]\n"
			<<avg<<"\t\t\t\taverage speed [GFLOPS]\n";
	}	
	//TODO: hash function [May use <unordered_map> in the future?]
};

/*
 * OPERATOR == for class Node
 * @returns: true if (n,nb,p,q) are the same
 */
bool operator==(const Node & l, const Node & r)
{
	return (l.n==r.n && l.nb==r.nb && l.p==r.p && l.q==r.q);
}

/*
 * OPERATOR << for class Node (output stream operator)
 */
ostream & operator<<(ostream & o,const Node & n)
{
	o<<"========================================================="<<std::endl;
	o<<n.n<<" "<<n.nb<<" "<<n.p<<" "<<n.q<<"\t\t\tDATA: <N> <NB> <P> <Q>"<<std::endl
		<<n.speeds.size()<<"\t\t\t\t\t# of speed data"<<std::endl;
	std::for_each(n.speeds.begin(),n.speeds.end(),
			[&o](float t){o<<t<<" ";});
	o<<std::endl;
}

/*
 * FUNCTION senderr
 * Display specified message and exit program;
 *
 * @param s : error message to display on the screen
 */
void senderr(const string & s)
{
	cerr<<s<<endl;
	exit(-1);
}

/*
 * FUNCTION readTo
 * Read text specified by an istream object line by line
 * until find one line matches specified regular expression 
 * for a specified times
 * 
 * @param	in		: the specified input stream
 *			regExp	: the specified regular expression for matching
 *			rtimes	: default value is 1
 */
void readTo(istream & in,const std::regex & regExp,int rtimes=1)
{
	string s;
	while(!in.eof())
	{
		getline(in,s);
#ifdef DEBUG
		cout<<s;
		cin.get();
#endif
		if(std::regex_search(s,regExp) && (--rtimes)==0) return;
	}
	cerr<<"Cannot find text matches the regular expression "
		<<" [remain times = "<<rtimes<<" ]"
		<<std::endl
		<<"End of File reached"<<std::endl;
}

/*
 * FUNCTION init
 * Skip the head of HPL*.out
 */
void init(istream & in)
{
#ifdef DEBUG
	cout<<"reading head"<<endl;
#endif
	readTo(in,std::regex("={3,}"),2);
}

//MAIN
int main(int argc, char * argv[])
{
	if(argc!=2) senderr("USAGE:	./analysiser <filename>");
	ifstream fin(argv[1]);
	ofstream fout(string(argv[1])+".anly",ios::out);

	if(!fin) senderr("cannot open input file!");
	if(!fout) senderr("cannot open output file!");

	//INIT
	init(fin);
#ifdef DEBUG
	cout<<"about to read data"<<endl;
#endif
	int cnt=0;		//count of cases
	vector<Node> nodes;
	Node curr;
	int n,nb,p,q;	//data to fill node
	string temp;
	float spd,time;
	while(!fin.eof())
	{
		//GET DATA
		readTo(fin,std::regex("={3,}"));
		readTo(fin,std::regex("-{3,}"));
		fin>>temp>>n>>nb>>p>>q>>time>>spd;
		fin.get();
		curr=Node(n,nb,p,q);
#ifdef DEBUG
		cout<<curr<<time<<spd<<endl;
#endif
		//Fill Node
		
		if(!nodes.empty())
		{
			Node & cache=nodes[nodes.size()-1];
			if(curr==cache) 
				cache.addSpeed(spd);	//ENQUEUE	
			else 
			{
				curr.addSpeed(spd);		//UPDATE SPEED	
				nodes.push_back(curr);	//ENQUEUE
			}
		}
		else 	
		{
			curr.addSpeed(spd);		//UPDATE SPEED
			nodes.push_back(curr);	//ENQUEUE
		}
		cnt++;
	}
	
	for(auto n : nodes)
	{
		n.analysis(fout);
	}

	fin.close();
	fout.close();
	return 0;
}
