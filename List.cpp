//
//  List.cpp
//  student
//
//  Created by Ricardo on 2016/9/26.
//  Copyright © 2016年 Ricardo. All rights reserved.
//

#include "List.hpp"
#include <iostream>

List::~List(){
    makeEmpty();
}

void List::origin(int total){
    ListNode* newNode,* last;
    ListNode ref;
    length = total;
    int count = 0;
    last = head;
    while(count < total){
        cin >> ref;
        newNode = new ListNode(ref);
        if (newNode == NULL) {
            cerr << "储存分配错误！" << endl;
            exit(1);
        }
        last->next = newNode;
        last = newNode;
        count++;
    }
    last->next = NULL;
}

void List::printAll(){
    ListNode* current = head->next;
    cout << "考号   姓名   性别   年龄   报考类别" << endl;
    while (current != NULL) {
        cout << *current;
        current = current->next;
    }
}

ListNode* List::Located(int index){
    if(index < 0 || index > this->Length()) return NULL;
    ListNode* current = head;
    int k = 0;
    while (current != NULL && k < index) {
        current = current->next;
        k++;
    }
    return current;
}

bool List::Insert(int index, ListNode& ref){
    ListNode* current = Located(index);
    if(current == NULL){
        return false;
    }
    ListNode* newNode = new ListNode(ref);
    if(newNode == NULL){
        cerr << "存储分配错误！" << endl;
        exit(1);
    }
    newNode->next = current->next;
    current->next = newNode;
    length++;
    return true;
}

bool List::Delete(int number,ListNode& ref){
    ListNode* current = head;
    ListNode* del;
    while (current->next != NULL) {
        if(current->next->number == number) break;
        else current = current->next;
    }
    if (current == NULL || current->next == NULL) {
        return false;
    }
    del = current->next;
    current->next = del->next;
    ref = *del;
    ref.next = NULL;
    delete del;
    length--;
    return true;
}

int List::Length(){
//    int length = 0;
//    ListNode* current = head->next;
//    while (current != NULL) {
//        current = current->next;
//        length++;
//    }
    return length;
}


ListNode* List::Find(int number){
    ListNode* current = head;
    while (current != NULL) {
        if(current->number == number) break;
        else current = current->next;
    }
    return current;
}

bool List::Change(int number,ListNode& ref){
    ListNode* target = this->Find(number);
    if (target == NULL) {
        return false;
    }
    target->age = ref.age;
    target->job = ref.job;
    target->name = ref.name;
    target->number = ref.number;
    target->sex = ref.sex;
    return true;
}


void List::makeEmpty(){
    ListNode* q;
    while (head->next != NULL) {
        q = head->next;
        head->next = q -> next;
        delete q;
    }
    length = 0;
}

ostream& operator<<(ostream& o,List& ref){
    ref.printAll();
    return o;
}
