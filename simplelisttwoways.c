// nodelergerili.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <cstdlib>
#define NULL 0
using namespace std;

struct nodes {
    nodes* back;
    int val;
    nodes* next;
};

nodes* root;
nodes* iter = root;
void node_Add() {

    if (root == NULL) {
        root = new nodes;
        cout << "enter a val for node which is first : " << endl;
        int b = 0;
        cin >> b;
        root->val = b;
        root->back = NULL;
        root->next = NULL;
    }
    else {
        iter = root;
        while (iter->next != NULL) {
            iter = iter->next;
        }
        iter->next = new nodes;
        cout << "enter a val for the node which is not first :  " << endl;
        int a = 0;
        cin >> a;
        iter->next->val = a;
        iter->next->next = NULL;
        iter->next->back = iter;
    }
}

void delete_Nodes() {
    iter = root;
    if (root == NULL) {
        cout << "no nodes to delete" << endl;
    }
    else if (root->next == NULL) {
        delete(root);
        root = NULL;
        cout << "there was onl 1 item and it's being  deleted" << endl;
    }
    else {
        while (iter->next->next != NULL) {
            iter = iter->next;
        }
        delete(iter->next);
        iter->next = NULL;
        cout << "item is being deleted" << endl;
    }
}
int i = 1;
void node_Print() {
    if (root == NULL) {
      cout<<  "no nodes yet" << endl;
    }
    else {
        iter = root;
        while (iter != NULL) {
            cout << i << ". elemanin degeri : " << iter->val << endl;
            i++;
            iter = iter->next;
        }
    }
}

int main()
{
    node_Add();
    node_Add();
    node_Add();
    node_Add();
    node_Print();
    delete_Nodes();
    node_Print();
}
