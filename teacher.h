#pragma once
#include"identity.h"


class teacher:public Identity {
public:
	teacher();
	teacher(const int emp_id, const string& name, const string& pwd);
	
	
	//menue page
	virtual void openMenue();



	//see 
	void showMyorder();


	//���ԤԼ
	void validOrder();

	void setEmpId(int a);
	int getEmpId();


private:
	int emp_id_;
	

};
