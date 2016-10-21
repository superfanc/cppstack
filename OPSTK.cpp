 //
//  OPSTK.cpp
//  Stack
//
//  Created by fanaticheng on 2016/10/19.
//  Copyright © 2016年 fanaticheng. All rights reserved.
//

#include "OPSTK.hpp"
STACK::STACK(int m):elems(0),max(0){
    * (int **)&elems=new int[* (int*)&max=m];
    pos=0;
}
STACK::STACK(const STACK&s): elems(0), max(0){
    delete elems;
    * (int **)&elems=new int[s.max];
    * (int *)&max=s.max;
    pos =s.pos;
    for(int i=0;i<=pos-1;i++){
        elems[i]=s.elems[i];
    }
    
}
int STACK::size() const{
    return max;
}
STACK::operator int( ) const{
    return pos;
}//const表示强制转换不改变当前对象的值,STACK对象可以直接变为int类型调用
int STACK::operator[](int x)const{
    return elems[x];
}
STACK& STACK::operator<<(int e){
    elems[pos++]=e;
    return *this;
}
STACK& STACK::operator>>(int &e){
    e=elems[pos-1];
    pos--;
    return *this;
}
STACK& STACK::operator=(const STACK &s){
    delete elems;
    * (int **)&elems=new int[s.max];
    * (int *)&max=s.max;
    for(int i=0;i<=s.pos;i++)
        elems[i]=s.elems[i];
    pos=s.pos;
    return *this;
}
void STACK::print() const{
    if(pos==0)
        std::cout<<"该栈为空栈！";
    else{
        for(int i=0;i<=pos-1;i++)
            std::cout<<"下标为"<<i<<"个字符为:"<<elems[i]<<std::endl;
    }
}
STACK::~STACK(){
    free(elems);
    * (int *)&max=0;
    pos=0;
}
