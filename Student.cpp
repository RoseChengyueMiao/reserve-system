#include"student.h"
#include"global_file.h"
#include"computerRoom.h"
#include<iostream>
#include<fstream>
#include<ostream>


using namespace std;


student::student(const int id, const string& name, const string& password) {
	this->id_ = id;
	this->name_ = name;
	this->password_ = password;

	//��ʼ������
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	computerRoom com;
	while (ifs >> com.com_Id && ifs >> com.Max_num) {
		vCom.push_back(com);
	}
	ifs.close();
};

	 void student::openMenue(){
		 const string lay_ = "\t\t------ -------------\n"
			 "\t\t                          \n"
			 "\t\t     1.����ԤԼ              \n"
			 "\t\t                          \n"
			 "\t\t     2.�ҵ�ԤԼ               \n"
			 "\t\t                          \n"
			 "\t\t     3.����ԤԼ            \n"
			 "\t\t                          \n"
			 "\t\t     4.ȡ��ԤԼ               \n";
		 "\t\t                               \n"
			 "\t\t      0.ע����¼                    \n";
		 cout << "ѧ�� " << this->name_ << "��¼" << endl;
		 cout << lay_;
		 cout << "" << endl;
		 system("pause");
		 system("cls");
	 }

	 void student::applyOrder() {
		 cout << "��������ʱ������һ�����壡"<<endl;
		 cout << "1.��һ" << endl;
		 cout << "2.�ܶ�" << endl;
		 cout << "3.����" << endl;
		 cout << "4.����" << endl;
		 cout << "5.����" << endl;

		 int date = 0;
		 int interval = 0;
		 int room = 0;

		 while (true) {
			 cin >> date;
			 if (date >= 1 && date <= 5) {
				 break;
			 }
			 cout << "��������" << endl;
		 }
		 cout << "����������ԤԼʱ���" << endl;
		 cout << "1.����" << endl;
		 cout << "2.����" << endl;

		 while (true)
		 {
			 cin >> interval;
			 if (interval >= 1 && interval <= 2) {
				 break;
			 }
			 cout<<"��������"<<endl;
		 }
		 cout << "ԤԼ�ɹ��������" << endl;


		 cout << "��ѡ�����" << endl;
		 for (auto& comp : this->vCom) {
			 cout<<comp.com_Id << "�Ż�������Ϊ��"<<comp.Max_num<<endl;
		 }

		 while (true) {
			 cin >> room;
			 if (room >= vCom[0].com_Id && room <= vCom.back().com_Id) {
				 break;
			 }
			 cout <<"��������" <<endl;
		 }

		 ofstream ofs(ORDER_FILE, ios::app);

		 ofs << "date:" << date << " ";
		 ofs << "interval:"<<interval << " ";
		 ofs << "studentID:" << this->id_ <<" ";
		 ofs << "studentName:" << this->name_ << " ";
		 ofs << "roomID:" << room << " ";
		 ofs << " status:" << 1 << endl;

		 ofs.close();
		 system("pause");
		 system("cls");


	 };

	 void student::showMyOrder() {
		 OrderFile of;
		 if (of.Size == 0) {
			 cout << "��ԤԼ��¼" << endl;
			 system("pause");
			 system("cls");
			 return;
		 }
		 for (int i = 0; i < of.Size; i++) {
			 if (this->id_ == atoi(of.orderData[i]["stuTd"].c_str())) {
				 cout << "ԤԼ���ڣ���" << of.orderData[i]["date"];
				 cout << "ʱ��Σ� " << of.orderData[i]["interval"];
				 cout << "�������" << of.orderData[i]["roomId"];
				 string status = " ״̬�� ";

				 if (of.orderData[i]["status"] == "1") {
					 status += " �����";
				 }
				 else if (of.orderData[i]["status"] == "2") {
					 status += "ԤԼ�ɹ�";
				 }
				 else if (of.orderData[i]["status"] == "-1") {
					 status += "ԤԼʧ��" ;
				 }
				 else {
					 status += "ԤԼ�Ѿ�ȡ��" ;
				 }
			 }
			
		 }
		 system("pause");
		 system("cls");


	 };

	

	 void student::cancelMyOrder() {
		 OrderFile of;
		 if (of.Size == 0) {
			 cout << "��ԤԼ" << endl;
			 system("pause");
			 system("cls");
			 return;
		 }

		 cout << "�����ȡ���ļ�¼" << endl;
		 vector<int>v;
		 int  index = 1;
		 for (int i = 0; i < of.Size; i++) {
			 if (this->id_ == atoi(of.orderData[i]["stuId"].c_str())) {
				 //��ɸѡ״̬
				 if (of.orderData[i]["status"] == "1" || of.orderData[i]["status"] == "2") {
					 v.push_back(i);
					 cout << index++ << "��";
					 cout << "ԤԼ���ڣ���" << of.orderData[i]["date"];
					 cout << "ʱ��Σ�" << (of.orderData[i]["interval"]=="1"?  "����" :"����");

					 cout << "�������" << of.orderData[i]["roomId"];
					 string status = "״̬��";
					 if (of.orderData[i]["status"] == "1")
					 {
						 status += "�����";
					 }
					 else if (of.orderData[i]["status"] == "2") {
						 status += "ԤԼ�ɹ�";
					 }
					 cout << status << endl;
				 }
			 }
		 }
		 cout << "������ȡ���ļ�¼��0������" << endl;
		 int select = 0;
		 while (true) {
			 cin >> select;
			 if (select >= 0 && select <= v.size()) {
				 if (select == 0) {
					 break;
				 }
				 else {
					 of.orderData[v[select - 1]]["status"] = "0";

					 of.updateOrder();
					 cout << "�Ѿ�ȡ��ԤԼ" << endl;
					 break;
				 }
			 }
			 cout << "��������" << endl;
		 }
		 system("pause");
		 system("cls");
	 };

	 int student::getId() {
		 return this->id_;
	 };

	 void student::setId(int a) {
		 this->id_ = a;
	 }


;