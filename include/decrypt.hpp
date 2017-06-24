#ifndef DECRYPT_HPP
#define DECRYPT_HPP
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
class Decrypt{
	private:
	const double   e=2.718281828;
	const double  pi=3.141592653;
	
	unsigned int b;
	string read;
	string write;
	void calculate_g();
	string write_bfr;
	void find_b();
	unsigned long extend_g();
	int one_digit(double);
	void ascii_to_str(string);
	void xorwithg(string);
	void read_data(string);
	double loop(double,unsigned int);
	double g;
	public:
	unsigned int a;
	unsigned int d;
	unsigned int digit; 
	Decrypt(unsigned int ,unsigned int ,unsigned int ,string);
	void write_data(string);
	~Decrypt();



};

#endif 
