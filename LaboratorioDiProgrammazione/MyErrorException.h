#pragma once
#include <stdexcept>
using namespace std;

class MyErrorException : public exception
{
public:
	MyErrorException(const char* messaggio) : messaggio_errore(messaggio){}

private:

	string messaggio_errore;
		
};

