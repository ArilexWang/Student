//
//  main.cpp
//  student
//
//  Created by Ricardo on 16/9/19.
//  Copyright © 2016年 Ricardo. All rights reserved.
//

#include <iostream>
#include <string>
#include "List.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    int total = 0;
    cout << "首先建立考生信息系统!" << endl
         << "请输入考生人数: ";
    cin >> total;
    List studentList;
    cout << "请依次输入考号，姓名，性别，年龄以及报考类别" << endl;
    studentList.origin(total);
    cout << studentList
         << "请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作)" << endl;
    int handle = -1;
    while (handle != 0) {
        cout  << "请选择您要进行的操作： ";
        cin >> handle;
        switch (handle) {
            case 0: break;
            case 1:{
                cout << "请输入你要插入的考生位置： ";
                int pos;
                cin >> pos;
                if (pos < 0 || pos > studentList.Length()) {
                    cout << "你不能在这个位置插入考生信息!" << endl;
                }
                else{
                    cout << "请依次输入要插入的考生的考号，姓名，性别，年龄及报考类别！" << endl;
                    ListNode ref;
                    cin >> ref;
                    studentList.Insert(pos, ref);
                    cout << studentList;
                }
                break;
            }
            case 2:{
                cout << "请输入要删除考生的考号： ";
                int number;
                cin >> number;
                ListNode deletedStu;
                studentList.Delete(number, deletedStu);
                cout << "你删除的考生信息是： " << deletedStu << endl;
                break;
            }
            case 3:{
                cout << "请输入要查找考生的考号： ";
                int number;
                cin >> number;
                ListNode* findStu;
                findStu = studentList.Find(number);
                if (findStu == NULL) {
                    cout << "这名学生不存在!" << endl;
                }
                else cout << *findStu;
                break;
            }
            case 4:{
                cout << "请输入你要修改考生的考号： ";
                int number;
                cin >> number;
                if (studentList.Find(number) == NULL) {
                    cout << "该名学生不存在！" << endl;
                }
                else {
                    cout << "请依次输入要修改的考生的考号，姓名，性别，年龄及报考类别！" << endl;
                    ListNode ref;
                    cin >> ref;
                    studentList.Change(number, ref);
                }
                break;
            }
            case 5:{
                cout << studentList;
                break;
            }
            default:
                break;
        }
    }
    return 0;
}




