#ifndef ENCRYPT_HPP
#define ENCRYPT_HPP
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
class Encrypt{
	private:
	const double   e=2.718281828;
	const double  pi=3.141592653;
	double d;
	string read;
	string write;
	void calculate_g();
	void find_d();
	unsigned long extend_g();
	int one_digit(double);
	string str_to_ascii(string);
	void xorwithg(string);
	void read_data(string);
	double loop(double,unsigned int);
	double g;
	public:
	unsigned int a;
	unsigned int b;
	Encrypt(unsigned int ,unsigned int ,string);
	void write_data(string);
	~Encrypt();

};

#endif
