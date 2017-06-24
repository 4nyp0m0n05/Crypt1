#include <iostream>
#include "decrypt.hpp"
using namespace std;

main()
{
	
	Decrypt* decr=new Decrypt(3,9,1,"enc.txt");
	decr->write_data("decr.txt");
	delete(decr);
	return 0;
}
