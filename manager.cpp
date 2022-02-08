#include"manager.h"
#include"global_file.h"
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

void printStudent(student& s) {
    cout << "ѧ�ţ�" << s.getId() << "������" << s.name_ << " ";
}
void printTeacher(teacher& t) {
    cout << "ѧ�ţ�" << t.getEmpId() << "������" << t.name_ << " ";
}


manager::manager(const string& name, const string pwd) {
	this->name_ = name;
	this->password_ = pwd;
    this->initVector();


    //Ŀǰ����Ķ��汾
    ifstream ifs;

    ifs.open(COMPUTER_FILE, ios::in);

    computerRoom c;
    while (ifs >> c.com_Id && ifs >> c.Max_num) {
        vCom.push_back(c);
    }
    cout << "��ǰ����������" << vCom.size() << endl;
    ifs.close();


};
//�˵�
 void manager::openMenue() {
	 const string lay_="\t\t------ -------------\n"
        "\t\t                          \n"
        "\t\t     1.����˺�               \n"
        "\t\t                          \n"
        "\t\t     2.�鿴�˺�               \n"
        "\t\t                          \n"
        "\t\t     3.�鿴����            \n"
        "\t\t                          \n"
         "\t\t     4.���ԤԼ               \n";
     "\t\t                               \n"
         "\t\t      0.ע����¼                    \n";
     cout << "��ӭ����Ա " << this->name_ << "��¼" << endl;
     cout << lay_;
     cout << "" << endl;
     system("pause");
     system("cls");


 };

//create account����˺�addperson
void manager::createAccount() {
    cout << "����������˺�����" << endl;
    cout << "1.�����ʦ" << endl;
    cout << "2.���ѧ��" << endl;

    string filename;
    string tip;
    ofstream ofs;
    int select = 0;
    cin >> select;

    if (select == 1) {
        filename = STUDENT_FILE;
        tip = "������ѧ��";
    }
    else {
        filename = TEACHER_FILE;
        tip = "������ְ����";
    }
    //׷�ӵķ�ʽд�ļ�
    ofs.open(filename,ios::out|ios::app);

    int id;//id
    string name;//����
    string pwd;//����
    while (true)
    {
        cout << "����id" << endl;
        cin >> id;
        bool res=checkRepeat(id, select);
        if (res) {
            cout << "���ظ�";
        }
        else {
            break;
        }

    }

    //
    cout << tip << endl;
    cin >> id;

    cout << "����������" << endl;
    cin >> name;

    cout << "����������" << endl;
    cin >> pwd;

    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "��ӳɹ�" << endl;

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
        cout << "�ļ���ȡʧ�ܣ�Invalid filename" <<endl;
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
    cout << "��ǰѧ��������" << vStu.size() << endl;
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
    cout << "��ѡ��鿴���ݣ�" << endl;
    cout << "1.�鿴����ѧ��" << endl;
    cout << "2.�鿴������ʦ" << endl;
    int select = 0;
    cin >> select;

    if (select == 1) {
        cout << "����ѧ����Ϣ��"<<endl;
        for_each(vStu.begin(), vStu.end(), printStudent);
    }
    else
    {
        cout<<"������ʦ��Ϣ��"<<endl;
        for_each(vTea.begin(), vTea.end(), printTeacher);
    }
    system("pause");
    system("cls");
};

//show computer lab information
void manager::showLabInfor() {
    cout << "" << endl;
    for ( auto iter = vCom.begin(); iter != vCom.end(); iter++) {
        cout << "������ţ�" << iter->com_Id << " ���������" << iter->Max_num << endl;
    }
    system("pause");
    system("cls");
};

//clear information
void manager::clearAll() {
    ofstream ofs(ORDER_FILE, ios::trunc);
    ofs.close();

    cout << "��ճɹ�" << endl;
    system("pause");
    system("cls");
};


