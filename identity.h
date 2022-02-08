#pragma once
#ifndef IDENTITY_H

#include<string>
using namespace std;
class Identity
{
public:
	//pure virtual function as interface
	virtual void openMenue() = 0;

	
	string name_;
	string password_;
};
#endif // !IDENTITY_H


