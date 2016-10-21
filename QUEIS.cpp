//
//  QUEIS.cpp
//  Stack
//
//  Created by fanaticheng on 2016/10/21.
//  Copyright © 2016年 fanaticheng. All rights reserved.
//

#include "QUEIS.hpp"
QUEIS::QUEIS(int m):STACK(m),s(m){ }
QUEIS::QUEIS(const QUEIS &q):STACK(q),s(q.s){ }
QUEIS::operator int() const{
    return STACK::operator int();
}
QUEIS& QUEIS::operator<<(int e){
    STACK::operator<<(e);
    return *this;
}
QUEIS& QUEIS::operator>>(int &e){
    int m;
    if(s==0){
        while(STACK::operator int()!=0){
            STACK::operator>>(m);
            s<<(m);
        }
    }
    if(s==0)
        std::cout<<"该队列为空队列"<<std::endl;
    else
        s>>(e);
    while(s!=0){
        s>>(m);
        STACK::operator<<(m);
    }
    return *this;
}
QUEIS& QUEIS::operator=(const QUEIS &q){
    QUEIS::~QUEIS();
    new (this)QUEIS(q);
    return *this;
}
void QUEIS::print( ) const{
    STACK::print();
}
QUEIS::~QUEIS(){ }
