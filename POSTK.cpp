//
//  POSTK.cpp
//  Stack
//
//  Created by fanaticheng on 2016/10/14.
//  Copyright © 2016年 fanaticheng. All rights reserved.
//

#include "POSTK.hpp"
void initPOSTK(POSTK *const p,int m){
    p->elems=(int *)malloc(m*sizeof(int));  //首地址
    p->max=m;
    p->pos=0;
}
void initPOSTK(POSTK *const p,const POSTK&s){ //首先释放
    if(p->max<s.max) free(p->elems);
    p->elems=(int *)malloc(s.max*sizeof(int));
    p->max=s.max;
    p->pos=0;
}
int size(const POSTK *const p){
    return p->max;
}
int howMany(const POSTK *const p){
    return p->pos;
}
int getelem(const POSTK *const p, int x){
    if(x>p->pos-1)   //越界访问
        return 0;
    else return p->elems[x];
}
POSTK *const push(POSTK *const p,int e){
    if(p->pos==p->max)
        return NULL;
    p->pos++;
    p->elems[p->pos-1]=e;
    return p;
}
POSTK *const pop(POSTK *const p ,int &e){
    if(p->pos==0)
        return NULL;
    e=p->elems[p->pos-1];
    p->pos--;
    return p;
}
POSTK *const assign(POSTK *const p,const POSTK&s){
    p->pos=s.pos;
    for(int i=0;i<=s.pos-1;i++)
        p->elems[i]=s.elems[i];
    return p;
}
void print(const POSTK *const p){
    if(p->pos==0)
        printf("该栈为空栈！\n");
    else{
        for(int i=0;i<=p->pos-1;i++)
            printf("该栈下标为%d个元素为:%d\n",i,p->elems[i]);
    }
}
void destroyPOSTK(POSTK *const p){
    if(p->elems!=NULL){
        free(p->elems);
        p->pos=p->max=0;
    }
}
int initPOSTKS(POSTK *const p){
    p->elems=(int *)malloc(4*sizeof(int));
    p->max=4;
    p->pos=4;
    for(int i=0;i<=p->pos-1;i++){
        p->elems[i]=i;
    }
    if(p->elems)
        return 1;
    else
        return 0;
}
