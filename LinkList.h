//
// Created by Erzbir on 2022/5/29.
//
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LinkList {
    ElemType elem;
    struct LinkList *next;
    struct LinkList *pre;
} LinkList;
LinkList *head = NULL;

LinkList *CreatHead_LinkList(int n) {
    LinkList *L = NULL;
    LinkList *s;
    int i;
    for (i = 0; i < n; i++) {
        s = (LinkList *) malloc(sizeof(LinkList));
        if (!s) {
            return NULL;
        }
        printf("input No.%d elem:", i);
        scanf("%d", &s->elem);
        s->next = L;
        L = s;
    }
    return L;
}

LinkList *CreatRear_LinkList(int n) {
    int i;
    LinkList *L = NULL;
    LinkList *s, *r = NULL;
    for (i = 0; i < n; i++) {
        s = (LinkList *) malloc(sizeof(LinkList));
        if (!s) {
            return NULL;
        }
        printf("input No.%d elem:", i);
        scanf("%d", &s->elem);
        if (L == NULL) {
            L = s;
        } else {
            r->next = s;
        }
        r = s;
    }
    if (r) {
        r->next = NULL;
    }
    return L;
}

int headRearList(int n) {
    int i;
    LinkList *L = NULL, *s, *r;
    L = head;
    r = L;
    for (i = 0; i < n; i++) {
        printf("输入第%d个元素:", i);
        s = (LinkList *) malloc(sizeof(LinkList));
        scanf("%d", &s->elem);
        r->next = s;
        r = s;
    }
    r->next = NULL;
    L = head->next;
    return 1;
}

LinkList *mergeTwoLists(LinkList *list1, LinkList *list2) {
    if (list1 == NULL) {
        return list2;
    } else if (list2 == NULL) {
        return list1;
    }
    struct LinkList *L = NULL, *s, *r;
    while (list1 != NULL && list2 != NULL) {
        s = (LinkList *) malloc(sizeof(LinkList));
        if (list1->elem <= list2->elem) {
            s->elem = list1->elem;
            list1 = list1->next;
        } else {
            s->elem = list2->elem;
            list2 = list2->next;
        }
        if (L == NULL) {
            L = s;
        } else {
            r->next = s;
        }
        r = s;
    }
    while (list1 != NULL) {
        s = (LinkList *) malloc(sizeof(LinkList));
        s->elem = list1->next->elem;
        list1 = list1->next;
        r->next = s;
        r = s;
    }
    while (list2 != NULL) {
        s = (LinkList *) malloc(sizeof(LinkList));
        s->elem = list2->elem;
        list2 = list2->next;
        r->next = s;
        r = s;
    }
    r->next = NULL;
    return L;

}

//struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
//    struct ListNode* l3 = (struct ListNode *)malloc(sizeof(struct ListNode));
//    struct ListNode* p1 = l1, * p2 = l2;
//    struct ListNode* r3 = l3;
//    while(p1 && p2){
//        if((p1 -> val) <= ( p2 -> val)){
//            r3 -> next = p1;
//            r3 = p1;
//            p1 = p1 -> next;
//        }
//        else{
//
//            r3 -> next = p2;
//            r3 = p2;
//            p2 = p2->next;
//        }
//    }
//    if(!p1)
//    { r3 -> next = p2 ; }
//    else if(!p2)
//    { r3 -> next = p1; }
//    return l3->next;
//}

void DoubleLinkList(int n) {
    int i;
    LinkList *front, *L = NULL, *s = NULL, *rear;
    L = head;
    rear = L;
    for (i = 0; i < n; i++) {
        s = (LinkList *) malloc(sizeof(LinkList));
        printf("input No.%d elem:", i);
        scanf("%d", &s->elem);
        rear->next = s;
        s->pre = rear;
        rear = s;
    }
}


int LinkList_Result() {
    head = (LinkList *) malloc(sizeof(LinkList));
    LinkList *L_1, *L_2, *L_3, *L_4 = NULL, *L_5;
//    L_1 = CreatRear_LinkList(2);
//    L_2 = CreatRear_LinkList(2);
//    L_3 = mergeTwoLists(L_1, L_2);
//    headRearList(3);
    DoubleLinkList(3);
    L_5 = head->next;
    while (L_5) {
        //如果该节点无后继节点，说明此节点是链表的最后一个节点
        if (L_5->next == NULL) {
            printf("%d\n", L_5->elem);
        } else {
            printf("%d <-> ", L_5->elem);
        }
        L_5 = L_5->next;
        printf("%d", L_5->pre->elem);
    }
//    printf("头插入链表:\n");
//    for(i = 0; i < 3; i++)
//    {
//        printf("头插入第%d个元素:%d\n", i, L_1->elem);
//        L_1 = L_1->next;
//    }
//    printf("尾插入链表:\n");
//    for(i = 0; i < 3; i++)
//    {
//        printf("尾插入第%d个元素:%d\n", i, L_2->elem);
//        L_2 = L_2->next;
//    }
    return 1;
}
