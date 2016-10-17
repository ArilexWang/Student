//
//  ListNode.hpp
//  student
//
//  Created by Ricardo on 2016/9/26.
//  Copyright © 2016年 Ricardo. All rights reserved.
//

#ifndef ListNode_hpp
#define ListNode_hpp

#include <stdio.h>
#include <string>
#include <iostream>
class List;
using namespace std;
class ListNode{
    friend List;
public:
    friend istream& operator>>(istream&, ListNode&);
    friend ostream& operator<<(ostream&, ListNode&);
    ListNode(int number,string name,string sex,int age,string job);
    ListNode(ListNode& ref);
    ListNode(); 
private:
    int number;
    string name;
    string sex;
    int age;
    string job;
    ListNode* next;
};
#endif /* ListNode_hpp */

