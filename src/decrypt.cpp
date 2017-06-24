#include "decrypt.hpp"

double Decrypt::loop(double number,unsigned int until){
	
	for(unsigned int i=1;i<until;i++){
		number*=number;
		
	}
	return number;
}
int Decrypt::one_digit(double num){
	int tmp=(int)num;
	
	if(tmp>10){
		while(tmp>10){
			tmp/=10;
			
		}
		
	}
	return tmp;
}
void Decrypt::find_b(){
	cout<<fixed<<setprecision(9);
	double pi_tmp;
	unsigned int digit_tmp;
	
	
	for(unsigned int i=(digit*2)-1;i<=(digit*2);i++){
		
		pi_tmp=loop(pi,i);
		digit_tmp=one_digit(pi_tmp);
					
		if(d==digit_tmp){
			
			b=i;
			
			break;		
		}
	}
}
void Decrypt::calculate_g(){
	cout<<fixed<<setprecision(9);
	double tmp1,tmp2;
	tmp1=loop(e,a);
	tmp2=loop(pi,b);
	
	g=tmp1-tmp2;
	

}
unsigned long Decrypt::extend_g(){
	unsigned long g_xor;
	
	for(unsigned int i=0;i<d;i++){
		
		g*=10;
	}
	
	g_xor=g;
	
	return g_xor;
	
}
void Decrypt::ascii_to_str(string tmp){
	unsigned int i=0;
	string ascii="";
	char temp;
	for(;i<tmp.length();){
		if(tmp[i]=='1'){
			for(unsigned int j=0;j<3;j++){
				temp=tmp[i+j];
				
				ascii+=temp;
								
			}
			i=i+3;
			write+=atoi(ascii.c_str());
			
			ascii="";
		}else{
			for(unsigned int j=0;j<2;j++){
				temp=tmp[i+j];
				
				ascii+=temp;	
					
			}
			i=i+2;
			write+=atoi(ascii.c_str());
			
			ascii="";
		}
	}
	
	

}
void Decrypt::read_data(string tmp){
	ifstream data;
	data.open(tmp);
	
	read="";
	string read2;
	if(data.is_open()){
		while(getline(data,read2)){
			read+=read2;
						
			}
		
	}
	data.close();
}
void Decrypt::xorwithg(string tmp){
	write_bfr="";
	ostringstream convert;
	
	unsigned long g_int=extend_g();
	convert<<g_int;
	string len=convert.str();
	
	unsigned int j=0;
	
	for(unsigned int i=0;i<tmp.length();i++){
		j=i%len.length();
		write_bfr+=tmp[i]^len[j];
		
	}
		
}
void Decrypt::write_data(string tmp){
	ofstream data;
	data.open(tmp);
	data<<write<<endl;
	data.close();

}
Decrypt::Decrypt(unsigned int first,unsigned int second,unsigned int third,string path){
	if(first<2) exit(0);
	a=first;
	d=second;
	digit=third;
	find_b();
	
	calculate_g();
	
	
	read_data(path);	
	xorwithg(read);
	ascii_to_str(write_bfr);
	

}
Decrypt::~Decrypt(){}
