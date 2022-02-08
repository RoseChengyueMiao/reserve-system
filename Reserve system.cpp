// Reserve system.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#include<memory>
#include<vector>
#include<fstream>
#include<list>
#include"global_file.h"
#include"student.h"
#include"manager.h"
#include"teacher.h"
using namespace std;
//管理员操作页面
void studentMenue(Identity*& stud) {
    while (true) {
        stud->openMenue();
        student* stu = (student*)stud;
        int select = 0;
        cin >> select;

        if (select == 1)//预约
        {
            stu->applyOrder();
            system("pause");
            system("cls");
        }
        else if (select == 2)
        {
            stu->showMyOrder();
            system("pause");
            system("cls");
        }
        else if (select == 3) {
            return;
        }
        else if (select == 4) {
            stu->cancelMyOrder();
            system("pause");
            system("cls");
        }
        else {
            delete stu;
            cout << "注销成功" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}

void managerMenue(manager*& Manage)
{
    while (true)
    {
        Manage->openMenue();
        int select = 0;
        cin >> select;

        if (select == 1) {
            if (select == 1) {
                cout << "添加账号" << endl;
                Manage->createAccount();
            }
            else if (select == 2) {
                cout << "查看账号" << endl;
                Manage->showPersonInfor();
            }
            else if (select == 3)
            {
                cout << "查看账号" << endl;
                Manage->showLabInfor();
            }
            else if (select == 4) {
                cout << "清空预约" << endl;
                Manage->clearAll();
            }
            else {
                delete Manage;
                cout << "推出成功" << endl;
                system("pause");
                system("cls");
                return;
            }
        }

    }
}
void Login(string fileName, int type) {
   Identity *people =nullptr;

    ifstream ifs;
    ifs.open(fileName, ios::in);

    if (!ifs.is_open()) {
        cout << "Invalid Filename" << endl;
        ifs.close();
        return;
    }
    int id = 0;
    string name;
    string pwd;
    cout << "输入学号：" << endl;
    cin >> id;
    cout << "输入用户名：" << endl;
    cin >> name;

    cout << "请输入密码：" << endl;
    cin >> pwd;
    if(type==1)
    {//学生登陆
        
        int fid;
        string fname;
        string fpwd;
        while(ifs>>fid&&ifs>>fname&&ifs>>fpwd)
        {
            cout << fid << "," << fname << "," << fpwd;
            if (fid == id && fname == name && fpwd == pwd) {
                cout << "学生登陆成功" << endl;
                system("pause");
                system("cls");
                people = new student(id, name, pwd);
                //进入学生子菜单
                studentMenue(people);
                return;

            }
        }
     
    }
    else if (type == 2)
    {
        cout << "输入职工号：" << endl;
        cin >> id;
        int fid;
        string fname;
        string fpwd;
        while (ifs >> fid && ifs >> fname && ifs >> fpwd)
        {
            cout << fid << "," << fname << "," << fpwd;
            if (fid == id && fname == name && fpwd == pwd) {
                cout << "老师登陆成功" << endl;
                system("pause");
                system("cls");
                people = new teacher(fid, fname, fpwd);
                return;

            }
        }
       
    }
    else if (type == 3)
    {
        string fname;
        string fpwd;
        while (ifs >> fname && ifs >> fpwd)
        {
            if (name == fname && pwd == fpwd) {
                cout << "管理员登录成功：" << endl;
                system("pause");
                system("cls");
                //
                manager*person =  manager::get_manager_instance(name, pwd);//singeleton

                managerMenue(person);
                return;
            }
        }
    }

    

    cout << "登陆验证失败" << endl;

    system("pause");
    system("cls");
    return;
}

int main()

{
    
    int select = -1;//
    

    const string layout= "\t\t------ -------------\n"
        "\t\t                          \n"
        "\t\t     1.学生               \n"
        "\t\t                          \n"
        "\t\t     2.老师               \n"
        "\t\t                          \n"
        "\t\t     3.管理员             \n"
        "\t\t                          \n"
        "\t\t     0.退出               \n";
    while (true) {
        cout << layout;
        cout << "enter: ";
       

        cin >> select;
        switch (select)
        {
        case 1:
            Login(STUDENT_FILE, 1);
            break;
        case 2:
            Login(TEACHER_FILE, 2);
            break;
        case 3:
            Login(ADMIN_FILE, 3);
            break;
        case 0:
            cout << "欢迎下次使用";
            system("pause");
            return 0;
            break;
        default:
            cout << "Invalid input,please retry!";
            system("pause");
            system("cls");
            break;
        }
   }



    cout << "Hello World!\n";
}



// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
