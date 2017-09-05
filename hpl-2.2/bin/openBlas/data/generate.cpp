#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <cstring>

#define FOLDER "Data/"
void showHelp()
{
	fprintf(stderr,"USAGE : ./generate <fileName>\n");
	fprintf(stderr,"<fileName> is the name of config file\n");
	fprintf(stderr,"By default, <fileName> will be config.dat\n");
	exit(-1);
}

void sendErr(const char * s)
{
	fprintf(stderr,"%s\n",s);
	exit(-1);
}

void skipLine(std::ifstream & _i)
{
	std::string tmps;
	std::getline(_i,tmps);
}

std::string itos(int i);

void addRemain(std::ofstream & fout)
{
	std::ifstream fin("remain.dat");
	if(!fin)
	{
		sendErr("cannot open file remain.dat");
	}
	std::string line;
	while(!fin.eof())
	{
		std::getline(fin,line);
		fout<<line<<std::endl;
	}
}
void generateDat(int n,int nb,int p,int q,const char * filename,int cnt)
{
	//fname is the name of file
	//while filename is the output file name of xhpl
	fprintf(stdout,"writing data into HPL%d.dat, %d-%d-%d*%d ...",cnt,n,nb,p,q);
	std::string fname;
	fname="Data/HPL"+itos(cnt)+".dat";
	std::ofstream fout(fname,std::ios::out);
	if(!fout)
	{
		fprintf(stderr,"cannot open file %s, continue to next\n",fname.c_str());
		return;
	}
	fout<<"HPLinpack benchmark input file"<<std::endl
		<<"Innovative Computing Laboratory, University of Tennessee"<<std::endl
		<<filename<<"      output file name (if any)"<<std::endl
		<<"8            device out (6=stdout,7=stderr,file)\n1            # of problems sizes (N)"<<std::endl
		<<n<<"		Ns\n"
		<<"1           # of NBs\n"
		<<nb<<"		NBs\n"
		<<"0            PMAP process mapping (0=Row-,1=Column-major)\n1            # of process grids (P x Q)\n"
		<<p<<"		Ps"<<std::endl
		<<q<<"		Qs"<<std::endl;
	addRemain(fout);
	fout.close();
	fprintf(stdout," successful!\n");
}

std::string itos(int i)
{
    std::string s="";
	if(i==0) return "0";
	while(i!=0)
	{
		s=((char)(i%10+'0'))+s;
		i/=10;
	}
	return s;
}


int nn,nmin,nmax,nnb,npq;
std::vector<int> nbs,ps,qs,ns;

int main(int argc,char *argv[])
{
	//START
	std::string filename;
	if(argc==1)
	{
		fprintf(stdout,"Try to load default config file 'config.dat'\n");
		filename=std::string("config.dat");
	}
	else if(argc==2)
	{
		fprintf(stdout,"Try to load '%s' as config file\n",argv[1]);
		filename=std::string(argv[1]);
	}
	else showHelp();
	
	//OPEN CONFIG FILE
	std::ifstream fin;
	fin.open(filename.c_str());
	if(!fin)
	{
		sendErr("cannot open config file!");
	}

	//PRASE CONFIG FILE
	fin>>nn;skipLine(fin);
	fin>>nmin>>nmax;skipLine(fin);
	fprintf(stdout,"# of N is %d, ranged from %d to %d\n",nn,nmin,nmax);
	fin>>nnb;skipLine(fin);
	for(int i=0;i<nnb;i++)
	{
		int nb;fin>>nb;nbs.push_back(nb);
	}
	skipLine(fin);
	fprintf(stdout,"# of NB is %d\n",nnb);
	fin>>npq;skipLine(fin);
	for(int i=0;i<npq;i++)
	{
		int p;fin>>p;ps.push_back(p);
	}
	skipLine(fin);
	for(int i=0;i<npq;i++)
	{
		int q;fin>>q;qs.push_back(q);
	}
	skipLine(fin);
	fprintf(stdout,"# of P*Q is %d\n",npq);

	//GENERATE FILES
	int cnt=0;
	int gap=nmax-nmin;
	for(int i=0;i<nn;i++)
	{
		ns.push_back(nmin+gap*i/(nn-1));
	}
	for(int n : ns)
		for(int nb : nbs)
			for(int i=0;i<npq;i++)
			{
				std::string fn;
				fn="HPL-"+itos(n)+"-"+itos(nb)+"-"+itos(ps[i])+"*"+itos(qs[i]);
				generateDat(n,nb,ps[i],qs[i],fn.c_str(),cnt++);	
			}


}
