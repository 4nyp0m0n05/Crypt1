#include "encrypt.hpp"

double Encrypt::loop(double number,unsigned int until){
	
	for(unsigned int i=1;i<until;i++){
		number*=number;
		
	}
	return number;
}
int Encrypt::one_digit(double num){
	int tmp=(int)num;
	
	if(tmp>10){
		while(tmp>10){
			tmp/=10;
			
		}
		
	}
	return tmp;
}
void Encrypt::calculate_g(){
	cout<<fixed<<setprecision(9);
	double tmp1,tmp2;
	tmp1=loop(e,a);
	tmp2=loop(pi,b);
	
	
	g=tmp1-tmp2;
	

}
unsigned long Encrypt::extend_g(){
	unsigned long g_xor;
	
	for(unsigned int i=0;i<d;i++){
		
		g*=10;
	}
	
	g_xor=g;
	
	return g_xor;
	
}
void Encrypt::find_d(){
	double tmp=loop(pi,b);
	d=one_digit(tmp);
	

}
string Encrypt::str_to_ascii(string tmp){
	unsigned int i=0;
	string ascii="";
	ostringstream convert;
	for(;i<tmp.length();i++){
		
		convert<<(int)tmp[i];
		
	}
	ascii=convert.str();
	
	
	return ascii;

}
void Encrypt::read_data(string tmp){
	ifstream data;
	data.open(tmp);
	
	read="";
	string read2;
	if(data.is_open()){
		while(getline(data,read2)){
			
			read+=str_to_ascii(read2);
				
			}
		
	}
	data.close();
}
void Encrypt::xorwithg(string tmp){
	write="";
	ostringstream convert;
	
	unsigned long g_int=extend_g();
	convert<<g_int;
	string len=convert.str();
	
	unsigned int j=0;
	
	for(unsigned int i=0;i<tmp.length();i++){
		j=i%len.length();
		write+=tmp[i]^len[j];
		
	}
	
	
}
void Encrypt::write_data(string tmp){
	ofstream data;
	data.open(tmp);
	data<<write<<endl;
	data.close();

}
Encrypt::Encrypt(unsigned int first,unsigned int second,string path){
	if(second>=first||first<2||second<1) exit(0);
	a=first;
	b=second;
	calculate_g();
	find_d();
	cout<<d<<":d"<<endl;
	read_data(path);	
	xorwithg(read);
	

}
Encrypt::~Encrypt(){}
