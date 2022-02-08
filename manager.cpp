#include"manager.h"
#include"global_file.h"
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

void printStudent(student& s) {
    cout << "学号：" << s.getId() << "姓名：" << s.name_ << " ";
}
void printTeacher(teacher& t) {
    cout << "学号：" << t.getEmpId() << "姓名：" << t.name_ << " ";
}


manager::manager(const string& name, const string pwd) {
	this->name_ = name;
	this->password_ = pwd;
    this->initVector();


    //目前不会改动版本
    ifstream ifs;

    ifs.open(COMPUTER_FILE, ios::in);

    computerRoom c;
    while (ifs >> c.com_Id && ifs >> c.Max_num) {
        vCom.push_back(c);
    }
    cout << "当前机房数量：" << vCom.size() << endl;
    ifs.close();


};
//菜单
 void manager::openMenue() {
	 const string lay_="\t\t------ -------------\n"
        "\t\t                          \n"
        "\t\t     1.添加账号               \n"
        "\t\t                          \n"
        "\t\t     2.查看账号               \n"
        "\t\t                          \n"
        "\t\t     3.查看机房            \n"
        "\t\t                          \n"
         "\t\t     4.清空预约               \n";
     "\t\t                               \n"
         "\t\t      0.注销登录                    \n";
     cout << "欢迎管理员 " << this->name_ << "登录" << endl;
     cout << lay_;
     cout << "" << endl;
     system("pause");
     system("cls");


 };

//create account添加账号addperson
void manager::createAccount() {
    cout << "请添加输入账号类型" << endl;
    cout << "1.添加老师" << endl;
    cout << "2.添加学生" << endl;

    string filename;
    string tip;
    ofstream ofs;
    int select = 0;
    cin >> select;

    if (select == 1) {
        filename = STUDENT_FILE;
        tip = "请输入学号";
    }
    else {
        filename = TEACHER_FILE;
        tip = "请输入职工号";
    }
    //追加的方式写文件
    ofs.open(filename,ios::out|ios::app);

    int id;//id
    string name;//姓名
    string pwd;//密码
    while (true)
    {
        cout << "输入id" << endl;
        cin >> id;
        bool res=checkRepeat(id, select);
        if (res) {
            cout << "有重复";
        }
        else {
            break;
        }

    }

    //
    cout << tip << endl;
    cin >> id;

    cout << "请输入姓名" << endl;
    cin >> name;

    cout << "请输入密码" << endl;
    cin >> pwd;

    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "添加成功" << endl;

    system("pause");
    system("cls");

    ofs.close();

    this->initVector();

};

void manager::initVector()
{
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件读取失败，Invalid filename" <<endl;
        return;
    }

    vStu.clear();
    vTea.clear();

    student s;
    int a;
    while (ifs >> a && ifs >> s.name_ && ifs >> s.password_) {
        s.setId(a);
        vStu.push_back(s);
    }
    cout << "当前学生数量：" << vStu.size() << endl;
    ifs.close();

    ifs.open(TEACHER_FILE, ios::in);

    teacher t;
    while (ifs>>a&&ifs>>t.name_&&ifs>>t.password_) {
        t.setEmpId(a);
        vTea.push_back(t);
    }
    ifs.close();
}

bool manager::checkRepeat(int id, int type) {
    if (type == 1) {
        for (auto iter = vStu.begin(); iter != vStu.end(); iter++) {
            if (id == iter->getId())
                return true;
        }
    }
    else  {
        for (auto iter = vTea.begin(); iter != vTea.end(); iter++) {
            if (id == iter->getEmpId()) {
                return true;
            }
        }
    }
    return false;
}

//show person information
void manager::showPersonInfor() 
{
    cout << "请选择查看内容：" << endl;
    cout << "1.查看所有学生" << endl;
    cout << "2.查看所有老师" << endl;
    int select = 0;
    cin >> select;

    if (select == 1) {
        cout << "所有学生信息："<<endl;
        for_each(vStu.begin(), vStu.end(), printStudent);
    }
    else
    {
        cout<<"所有老师信息："<<endl;
        for_each(vTea.begin(), vTea.end(), printTeacher);
    }
    system("pause");
    system("cls");
};

//show computer lab information
void manager::showLabInfor() {
    cout << "" << endl;
    for ( auto iter = vCom.begin(); iter != vCom.end(); iter++) {
        cout << "机房编号：" << iter->com_Id << " 最大容量：" << iter->Max_num << endl;
    }
    system("pause");
    system("cls");
};

//clear information
void manager::clearAll() {
    ofstream ofs(ORDER_FILE, ios::trunc);
    ofs.close();

    cout << "清空成功" << endl;
    system("pause");
    system("cls");
};


