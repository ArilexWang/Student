//
//  List.hpp
//  student
//
//  Created by Ricardo on 2016/9/26.
//  Copyright © 2016年 Ricardo. All rights reserved.
// : 

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include <cstdlib>
#include "ListNode.hpp"
class List{
    friend ostream& operator << (ostream&,List& );
public:
    List() {head = new ListNode();}
    ~List();
    ListNode* Find(int number);
    bool Insert(int index,ListNode& ref);
    bool Delete(int index,ListNode& ref);
    bool Change(int number,ListNode& ref);
    int Length();
    ListNode* Located(int index);
    void origin(int totoal);
    void printAll();
    void makeEmpty();
private:
    ListNode* head;
    int length;
};

#endif /* List_hpp */
