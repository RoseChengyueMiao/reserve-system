#pragma once
#include"identity.h"
#include"student.h"
#include"teacher.h"
#include<vector>
#include"computerRoom.h"
class manager :public Identity{
public:
	static manager*& get_manager_instance(const string& name, const string pwd) {
		static manager* instance=new manager(name,pwd);
		return instance;
	}
	
	//²Ëµ¥
	virtual void openMenue();

	//create account
	void createAccount();

	//show person information
	void showPersonInfor();

	//show computer lab information
	void showLabInfor();

	//clear information
	void clearAll();
	void initVector();


	bool checkRepeat(int id, int type);

private:
	manager()=delete;
	manager(const string& name, const string pwd);
	
	vector<student>vStu;
	vector<teacher>vTea;
	vector<computerRoom>vCom;
};