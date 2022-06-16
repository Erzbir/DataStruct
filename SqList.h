#include <stdio.h>
#include <stdlib.h>
#define INIT_SIZE 5
#define INCREMENT 2
typedef int ElemType;

typedef struct
{
    ElemType *elem;
    int length; // 当前顺序表长度
    int listsize;   // 最大长度
}SqList;

int InitList_Sq(SqList *L)
{
    L->elem = (ElemType*) malloc(INIT_SIZE * sizeof(ElemType));
    if(!L->elem)
    {
        return -1;  //分配失败返回-1
    }
    L->length = 0;
    L->listsize = INIT_SIZE;
    return 1;
}

int InsertList_Sq(SqList *L, int index, ElemType elem)
{
    ElemType *newbase;
    if(index > L->length || index < 0)
    {
        return -1;
    }
    if(L->length == L->listsize)
    {
        newbase = (ElemType*) realloc(L->elem, (L->listsize + INCREMENT) * sizeof(ElemType));
        if(!newbase)
        {
            return -1;
        }
        L->elem = newbase;
        L->listsize += INCREMENT;
    }
    for(int i = index + 1; i < L->length; i++)
    {
        L->elem[i+1]= L->elem[i];
    }
    L->elem[index] = elem;
    ++L->length;
    return 1;
}

int ListDelete(SqList *L, int index, ElemType *e)
{
    int i;
    if(L->length == 0 || index < 0 || index > L->length)
    {
        return -1;
    }
    *e = L->elem[index];
    for(i = index; i < L->length; i++)
    {
        L->elem[i] = L->elem[i+1];
    }
    --(L->length);
    return 1;
}

int LocateElem_Sq(SqList *L, ElemType e)
{
    int head = 0, rear = L->length - 1;
    if(L->length == 0)
    {
        return -1;
    }
    while(head < rear)
    {
        if(L->elem[head] == e)
        {
            return head;
        }
        if(L->elem[rear] == e)
        {
            return rear;
        }
        head++;
        rear--;
    }
    return -1;
}

int MergeList_Sq(SqList LA, SqList LB, SqList *LC)
{
    int i = 0, j = 0, k = 0;
    if(LA.length == 0 || LB.length == 0)
    {
        return -1;
    }
    LC->listsize = LA.listsize + LB.listsize;
    LC->elem = (ElemType*) malloc(LC->listsize * sizeof(ElemType));
    if(!LC->elem)
    {
        return -1;
    }
    while(i <= LA.length && j < LB.length)
    {
        if(LA.elem[i] <= LB.elem[j])
        {
            LC->elem[k++] = LA.elem[i++];
            j++;
        }
        else
        {
            LC->elem[k++] = LB.elem[j++];
        }
    }
    while(i < LA.length)
    {
        LC->elem[k++] = LA.elem[i++];
    }
    while(j < LB.length)
    {
        LC->elem[k++] = LA.elem[j++];
    }
    LC->length = k;
    return 1;
}

int SqList_Result()
{
    int i, e = 2;
    SqList L_1, L_2, L_3;
    InitList_Sq(&L_1);
    InitList_Sq(&L_2);
    for(i = 0; i < 5; i++)
    {
        InsertList_Sq(&L_1, i, i);
    }
    for(i = 0; i < 10; i++)
    {
        InsertList_Sq(&L_2, i, i);
    }
    for(i = 0; i < L_1.length; i++)
    {
        printf("第一个表的第%d个元素:%d\n", i, L_1.elem[i]);
    }
    printf("\n");
    for(i = 0; i < L_2.length; i++)
    {
        printf("第二个表的第%d个元素:%d\n", i, L_2.elem[i]);
    }
    ListDelete(&L_1, 2, &e);
    printf("\n删除后的表一:\n");
    for(i = 0; i < L_1.length; i++)
    {
        printf("表一删除后的第%d个元素:%d\n", i, L_1.elem[i]);
    }
    printf("查询到的元素下标:%d", LocateElem_Sq(&L_1, 4));
    printf("\n");
    MergeList_Sq(L_2, L_1, &L_3);
    printf("\n合并后的表:\n");
    for(i = 0; i < L_3.length; i++)
    {
        printf("合并后的表的第%d个元素:%d\n", i, L_3.elem[i]);
    }
    return 0;
}
