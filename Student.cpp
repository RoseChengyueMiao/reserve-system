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

	//初始化机房
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
			 "\t\t     1.申请预约              \n"
			 "\t\t                          \n"
			 "\t\t     2.我的预约               \n"
			 "\t\t                          \n"
			 "\t\t     3.所有预约            \n"
			 "\t\t                          \n"
			 "\t\t     4.取消预约               \n";
		 "\t\t                               \n"
			 "\t\t      0.注销登录                    \n";
		 cout << "学生 " << this->name_ << "登录" << endl;
		 cout << lay_;
		 cout << "" << endl;
		 system("pause");
		 system("cls");
	 }

	 void student::applyOrder() {
		 cout << "机房开放时间是周一到周五！"<<endl;
		 cout << "1.周一" << endl;
		 cout << "2.周二" << endl;
		 cout << "3.周三" << endl;
		 cout << "4.周四" << endl;
		 cout << "5.周五" << endl;

		 int date = 0;
		 int interval = 0;
		 int room = 0;

		 while (true) {
			 cin >> date;
			 if (date >= 1 && date <= 5) {
				 break;
			 }
			 cout << "输入有误" << endl;
		 }
		 cout << "请输入申请预约时间段" << endl;
		 cout << "1.上午" << endl;
		 cout << "2.下午" << endl;

		 while (true)
		 {
			 cin >> interval;
			 if (interval >= 1 && interval <= 2) {
				 break;
			 }
			 cout<<"输入有误"<<endl;
		 }
		 cout << "预约成功！审核中" << endl;


		 cout << "请选择机房" << endl;
		 for (auto& comp : this->vCom) {
			 cout<<comp.com_Id << "号机房容量为："<<comp.Max_num<<endl;
		 }

		 while (true) {
			 cin >> room;
			 if (room >= vCom[0].com_Id && room <= vCom.back().com_Id) {
				 break;
			 }
			 cout <<"输入有误" <<endl;
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
			 cout << "无预约记录" << endl;
			 system("pause");
			 system("cls");
			 return;
		 }
		 for (int i = 0; i < of.Size; i++) {
			 if (this->id_ == atoi(of.orderData[i]["stuTd"].c_str())) {
				 cout << "预约日期：周" << of.orderData[i]["date"];
				 cout << "时间段： " << of.orderData[i]["interval"];
				 cout << "机房编号" << of.orderData[i]["roomId"];
				 string status = " 状态： ";

				 if (of.orderData[i]["status"] == "1") {
					 status += " 审核中";
				 }
				 else if (of.orderData[i]["status"] == "2") {
					 status += "预约成功";
				 }
				 else if (of.orderData[i]["status"] == "-1") {
					 status += "预约失败" ;
				 }
				 else {
					 status += "预约已经取消" ;
				 }
			 }
			
		 }
		 system("pause");
		 system("cls");


	 };

	

	 void student::cancelMyOrder() {
		 OrderFile of;
		 if (of.Size == 0) {
			 cout << "无预约" << endl;
			 system("pause");
			 system("cls");
			 return;
		 }

		 cout << "输入可取消的记录" << endl;
		 vector<int>v;
		 int  index = 1;
		 for (int i = 0; i < of.Size; i++) {
			 if (this->id_ == atoi(of.orderData[i]["stuId"].c_str())) {
				 //在筛选状态
				 if (of.orderData[i]["status"] == "1" || of.orderData[i]["status"] == "2") {
					 v.push_back(i);
					 cout << index++ << "、";
					 cout << "预约日期：周" << of.orderData[i]["date"];
					 cout << "时间段：" << (of.orderData[i]["interval"]=="1"?  "上午" :"下午");

					 cout << "机房编号" << of.orderData[i]["roomId"];
					 string status = "状态：";
					 if (of.orderData[i]["status"] == "1")
					 {
						 status += "审核中";
					 }
					 else if (of.orderData[i]["status"] == "2") {
						 status += "预约成功";
					 }
					 cout << status << endl;
				 }
			 }
		 }
		 cout << "请输入取消的记录，0代表返回" << endl;
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
					 cout << "已经取消预约" << endl;
					 break;
				 }
			 }
			 cout << "输入有误" << endl;
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