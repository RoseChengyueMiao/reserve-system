#pragma once
#include<string>
#include"identity.h"
#include"computerRoom.h"
#include<vector>
#include"order.h"
class student :public Identity{
public:
	student() {};
	student(const int id, const string& name,const string&password);

	virtual void openMenue();

	void applyOrder();
	
	void showMyOrder();

	

	void cancelMyOrder();

	int getId();

	void setId(int a);

	vector<computerRoom>vCom;


private:
	int id_;
};
