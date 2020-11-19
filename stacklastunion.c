#include <iostream>
#define INT 1
#define FLOAT 2
#define STRING 3
#define MAXSIZE 100

using namespace std;

struct stackelement {
	int etype;
	union
	{
		int ival;
		float fval;
		char* pval;
	}element;


};
struct stack {
	int top;
	stackelement* item = new stackelement[MAXSIZE];
};
bool empty(stack* s) {
	if (s->top == -1) return 1;
	return 0;
}
void push(stack* s, int data) {
	if (s->top == MAXSIZE - 1) {
		cout << "stack overflow" << endl;
	}
	else {
		s->item[++s->top].etype = 1;
		s->item[s->top].element.ival = data;

	}
}
void push(stack* s, float data) {
	if (s->top == MAXSIZE - 1) {
		cout << "stack overflow" << endl;
	}
	else {
		s->item[++s->top].etype = 2;
		s->item[s->top].element.fval = data;
	}
}
void push(stack* s, char* data) {
	if (s->top == MAXSIZE - 1) {
		cout << "stack overflow" << endl;
	}
	else {
		s->item[++s->top].etype = 3;
		s->item[s->top].element.pval = data;
	}
}
stackelement pop(stack* s) {
	if (empty(s)) {
		cout << "stack underflow" << endl;
		exit(1);
	}
	else (s->top -= 1);
	cout << "last index has been deleted" << endl;
	return s->item[s->top];
}
void print(stack* s) {
		for(int i =0;i<s->top+1;i++){
			if (s->item[i].etype == 1) {
			cout << s->item[i].element.ival<<endl;
		}
			if (s->item[i].etype == 2) {
				cout << s->item[i].element.fval << endl;
			}
			if (s->item[i].etype == 3) {
				cout << s->item[i].element.pval << endl;
			}
		}
	}
int main() {
	stack nihat;
	char x[6] = "nihat";
	nihat.top = -1;
	push(&nihat, 10);
	push(&nihat, x);
	push(&nihat, 20.4f);
	push(&nihat, 45);
	print(&nihat);
	pop(&nihat);
	pop(&nihat);
	print(&nihat);




}
