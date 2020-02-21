#include <iostream>

#define LIST_INIT_SIZE 100 //线性表初始化大小
#define LIST_INCREMENT 10 //线性表分配增量大小

using namespace std;

typedef int ElemType;

typedef struct{
    ElemType *elem;  //存储起始位置
    int length;     //当前存储元素的个数
    int listSize;  //当前线性表大小
}SqList;

//初始化线性表
bool InitList(SqList &L){
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem)
        exit(0);
    else
        return true;
}
//获取元素
ElemType getElem(SqList L,int index,int &flush){

}


/**
 * 插入数据
 * 1.已知插入位置(在第index个位置之前插入数据）
 * 2.插入位置未知（有序插入,从小到大）
 */
bool ListInsert(SqList &L,int index,ElemType e);
bool ListInsert(SqList &L,ElemType e);


/**
 * 合并两个线性表（有序，从小到大）
 * 1.允许存在相同元素
 * 2.求两个线性表的并集。
 * @return
 */
 void MergeList(SqList La,SqList Lb,SqList &Lc);//允许存在相同元素
 void UnionList(SqList La,SqList Lb,SqList &Lc);//求并集


int main(){

}


void MergeList(SqList La,SqList Lb,SqList &Lc){
    int indexLa = 1,indexLb = 1,indexLc = 1;
    int lengthLa = La.length,lengthLb = Lb.length;
    int elemLa,elemLb;
    while(indexLa <= lengthLa && indexLb <= lengthLb){
        elemLa = La.elem[indexLa];
        elemLb = Lb.elem[indexLb];
        if(elemLa <= elemLb){
            ListInsert(Lc,indexLc++,elemLa);
            indexLa++;
        } else{
            ListInsert(Lc,indexLc++,elemLb);
            indexLb++;
        }
    }
    while(indexLa <= lengthLa){
        elemLa = La.elem[indexLa];
        ListInsert(Lc,indexLc++,elemLa);
        indexLa++;
    }
    while (indexLb <= lengthLb){
        elemLb = Lb.elem[indexLb];
        ListInsert(Lc,indexLc++,elemLb);
        indexLb++;
    }
}


//先找出插入位置。
bool ListInsert(SqList &L,ElemType e){
    if(L.length >= L.listSize){
        ElemType *newBase = (ElemType *)realloc(L.elem,(L.listSize+LIST_INCREMENT)*sizeof(ElemType));
        if(!newBase)
            exit(0);
        L.elem = newBase;
        L.listSize += LIST_INCREMENT;
    }
        int index;
        int i;
        for(i = 1;i<=L.length;i++){
            if(e<=L.elem[i])
                break;
        }
        if(i == L.length+1)
            index = L.length+1;
        else
            index = i-1;
        if(ListInsert(L,index,e))
            return true;
}


bool ListInsert(SqList &L,int index,ElemType e){
    //判断插入位置是否合法
    if(index < 1 || index > L.length+1)
        return false;
    if(L.length>=L.listSize){
        ElemType * newBase = (ElemType *)realloc(L.elem,(L.listSize+LIST_INCREMENT)*sizeof(ElemType));
        //判断新的内存是否分配成功
        if(!newBase)
            exit(0);
        L.elem = newBase;
        L.listSize+=LIST_INCREMENT;
    }

    //操作指针实现插入
    ElemType *temp = &(L.elem[index-1]);   //插入位置指针
    for(ElemType *p = &(L.elem[L.length-1]);p >= temp;p--){
        *(p+1)=*p;
    }
    *temp = e;
    L.length++;
    return true;
}
