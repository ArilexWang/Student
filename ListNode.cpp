//
//  ListNode.cpp
//  student
//
//  Created by Ricardo on 2016/9/26.
//  Copyright © 2016年 Ricardo. All rights reserved.
//

#include "ListNode.hpp"

ListNode::ListNode(){
    number = -1;
    name = "0";
    sex = "0";
    age = -1;
    job = "0";
    next = nullptr;
}

ListNode::ListNode(int number,string name,string sex,int age,string job)
{
    this->number = number;
    this->name = name;
    this->sex = sex;
    this->age = age;
    this->job = job;
    //next = nullptr;
}

ListNode::ListNode(ListNode& ref){
    number = ref.number;
    name = ref.name;
    sex = ref.sex;
    age = ref.age;
    job = ref.job;
    next = nullptr;
}

ostream& operator<<(ostream& o,ListNode& ref){
    o << ref.number<< "    " << ref.name << "     "
    << ref.sex << "    " << ref.age << "    " << ref.job
    << endl;
    return o;

}

istream& operator>>(istream& i, ListNode& ref){
    string name,sex,job;
    int age,number;
    i >> number >> name >> sex >> age >> job;
    ref.number = number;
    ref.name = name;
    ref.sex = sex;
    ref.age = age;
    ref.job = job;
    return i;
}


