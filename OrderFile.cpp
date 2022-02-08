#include<iostream>
#include"order.h"
#include<fstream>

using namespace std;

void insertIntoMap(unordered_map<string,string>m_map,string s){
	int pos = s.find(":");
	if (pos != -1) {
		string key = s.substr(0, pos);
		string value = s.substr(pos + 1, s.size() - pos);
		m_map.insert({ key,value });
	}
}

OrderFile::OrderFile() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;
	string interval;
	string stuId;
	string stuName;
	string roomId;
	string status;

	this->Size = 0;//记录预约个数

	
	while (ifs >> date && ifs >> interval && ifs >> stuName && ifs >> roomId && ifs >> status) {
		string key;
		string value;
		unordered_map<string, string>m_map;
		insertIntoMap(m_map,date );
		insertIntoMap(m_map, interval);
		insertIntoMap(m_map, stuId);
		insertIntoMap(m_map, stuName);
		insertIntoMap(m_map, roomId);
		insertIntoMap(m_map, status);
		this->Size++;
		this->orderData.insert({ this->Size,m_map });
	}
	ifs.close();
}
void OrderFile::updateOrder() {
	if (this->Size == 0) {
		return;
	}
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < Size; i++) {
		ofs << "date:" << orderData[i]["date"] << " ";
		ofs << "interval:" << orderData[i]["interval"] << " ";
		ofs << "stuId:" << orderData[i]["stuId"] << " ";
		ofs << "stuName:" << orderData[i]["stuName"] << " ";
		ofs << "roomId:" << orderData[i]["roomId"] << " ";
		ofs << "status" << orderData[i]["status"] << " ";
		
	}
	ofs.close();
	system("pause");
	system("cls");
}
