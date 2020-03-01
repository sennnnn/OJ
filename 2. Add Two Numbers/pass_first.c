#include <stdio.h>

struct ListNode {
      int val;
      struct ListNode *next;
};

typedef struct ListNode a;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carry = 0;
    int a,b;
    int temp;
    struct ListNode* p;
    struct ListNode* temp_po;
    struct ListNode* q;
    _Bool ifstart = 1;
    while(l1 && l2){
        a = l1->val;
        b = l2->val;
        temp = a+b+carry;
        carry = temp/10;
        l1 = l1->next;
        l2 = l2->next;
        if(ifstart){
            q = (struct ListNode *)malloc(sizeof(struct ListNode));
            ifstart = 0;
            p = q;
            temp_po = p;
            q->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            q = q->next;
        }else{
            temp_po = q;
            q->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            q = q->next;
        }
        temp_po->val = temp%10;
    }
    while(l1){
        a = l1->val;
        b = carry;
        temp = a+b;
        q->val = temp%10;
        temp_po = q;
        q->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        q = q->next;
        carry = temp/10;
        l1 = l1->next;
    }
    while(l2){
        a = l2->val;
        b = carry;
        temp = a+b;
        q->val = temp%10;
        temp_po = q;
        q->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        q = q->next;
        carry = temp/10;
        l2 = l2->next;
    }
    if(carry != 0){
        temp_po = q;
        q->val = carry;
    }else{
        free(q);
    }
    temp_po->next = NULL;
    return p;
}

a* create(a* temp, int val){
    while(temp->next){
        temp = temp->next;
    }
    a* temp_ = (a *)malloc(sizeof(a));
    temp_->val = val;
    temp_->next = NULL;
    temp->next = temp_;
    return temp;
}

void show(a* temp){
    while(temp){
        printf("%d\n", temp->val);
        temp = temp->next;
    }
}

int main(){
    a* l1 = (a *)malloc(sizeof(a));
    a* l2 = (a *)malloc(sizeof(a));
    l1->val = 2;
    l2->val = 5;
    l1->next = NULL;
    l2->next = NULL;
    create(l1, 4);create(l1, 5);
    create(l2, 6);create(l2, 5);

    a* result = addTwoNumbers(l1, l2);
    show(result);
}