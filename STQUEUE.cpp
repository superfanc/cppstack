//
//  STQUEUE.cpp
//  Stack
//
//  Created by fanaticheng on 2016/10/19.
//  Copyright © 2016年 fanaticheng. All rights reserved.
//


//思路：
//两个栈s1,s2，s1为输入栈，s2为输出栈。队列加元素的时候全部加在s1里面，出栈现将s1逆序拷贝到s2中，然后s2逆序拷贝到s1中

#include "STQUEUE.hpp"
QUE2S::QUE2S(int m):s1(m),s2(m){ }
QUE2S::QUE2S(const QUE2S &q):s1(q.s1),s2(q.s2){ }
QUE2S::operator int() const{
    return s1;
}
QUE2S& QUE2S::operator<<(int e){
    s1<<(e);
    return *this;
}
QUE2S& QUE2S::operator>>(int &e){
    int m;
    if(s2==0){
        while(s1!=0){
            s1>>(m);
            s2<<(m);
        }
    }
    if(s2==0)
        std::cout<<"该队列为空队列"<<std::endl;
    else
        s2>>(e);
    while(s2!=0){
        s2>>(m);
        s1<<(m);
    }
    return *this;
}
QUE2S& QUE2S::operator=(const QUE2S &q){
    QUE2S::~QUE2S();
    new (this)QUE2S(q);
    return *this;
    
}
void QUE2S::print() const{
    s1.print();
}
QUE2S::~QUE2S(){ }
