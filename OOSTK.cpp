//
//  OOSTK.cpp
//  Stack
//
//  Created by fanaticheng on 2016/10/14.
//  Copyright © 2016年 fanaticheng. All rights reserved.
//

#include "OOSTK.hpp"
OOSTK::OOSTK(int m): elems(0), max(0){
    *(int **)&elems=new int[* (int*)&max=m];
    pos=0;
}
OOSTK::OOSTK(const OOSTK&s): elems(0), max(0){
    delete elems;
    * (int **)&elems=new int[s.max];
    * (int *)&max=s.max;
    pos =0;
}
int OOSTK::size () const{
    return max;
}
int OOSTK::howMany() const{
    return pos;
}
int OOSTK::getelem(int x) const{
    return elems[x];
}
OOSTK& OOSTK::push(int e){    //对函数成员有改变最好都是return *this，返回函数类型的引用，防止内存分配错误
    elems[pos++]=e;
    return *this;
}
OOSTK& OOSTK::pop(int &e){
    e=elems[pos-1];
    pos--;
    return *this;
}

OOSTK& OOSTK::assign(const OOSTK&s){
    delete elems;
    * (int **)&elems=new int[s.max];
    * (int *)&max=s.max;
    for(int i=0;i<=s.pos-1;i++)
        elems[i]=s.elems[i];
    pos=s.pos;
    return *this;
}
void OOSTK::print() const{
    if(pos==0)
        std::cout<<"为空！";
    else{
        for(int i=0;i<=pos-1;i++)
            std::cout<<"下标为"<<i<<"个字符为:"<<elems[i]<<std::endl;
    }
}
OOSTK::~OOSTK(){
    free(elems);
    * (int *)&max=0;
    pos=0;
}
