#include <iostream>
#include <time.h>

using namespace std;

struct stack {
    int num;
    stack* next;
};

void push(stack*& stk, int n) {
    stack* temp = new stack;
    temp->next = stk;
    temp->num = n;
    stk = temp;
}

void show(stack* stk) {
    stack* temp = stk;
    while (temp) {
        cout << temp->num << " ";
        temp = temp->next;
    }
    cout << endl;
}

int findAverage(stack* stk) {
    int amount = 0, i = 0;
    for (stack* temp = stk; temp; temp = temp->next, i++)
        amount += temp->num;
    return amount / i;
}

void cleanOut(stack*& stk) {
    for (stack* temp = stk->next; stk->next; temp = stk->next) {
        delete stk;
        stk = temp;
    }
}

void Sort_p(stack*& p) {
    stack* t = NULL, * t1, * r;
    if ((p)->next->next == NULL) return;
    do {
        for (t1 = p; t1->next->next != t; t1 = t1->next)
            if (t1->next->num > t1->next->next->num) {
                r = t1->next->next;
                t1->next->next = r->next;
                r->next = t1->next;
                t1->next = r;
            }
        t = t1->next;
    } while ((p)->next->next != t);
}

void Sort_info(stack* p) {
    stack* t = NULL, * t1;
    int r;
    do {
        for (t1 = p; t1->next != t; t1 = t1->next)
            if (t1->num > t1->next->num) {
                r = t1->num;
                t1->num = t1->next->num;
                t1->next->num = r;
            }
        t = t1;
    } while (p->next != t);
}


int main() {
    stack* stk = new stack;
    stk = NULL;
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        push(stk, rand() % 100);
    show(stk);
    stk->num = findAverage(stk);
    show(stk);

    Sort_p(stk);
    show(stk);

    Sort_info(stk);
    show(stk);

    system("pause > nul");
    cleanOut(stk);
}
