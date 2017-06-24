#include <iostream>
#include "encrypt.hpp"

using namespace std;

main()
{
	Encrypt* enc=new Encrypt(3,2,"encrypted.txt");
	enc->write_data("enc.txt");
	delete(enc);
	
	return 0;
}
