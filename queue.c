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


struct queue {
	int rear, front;
	stackelement items[MAXSIZE];
};


bool empty(queue* s) {
	return (s->front == s->rear) ? true : false;
}


void enqueue(queue* s, int data) {
	if (s->rear == MAXSIZE - 1) {
		s->rear = 0;
	}
	else s->rear += 1;
	if (s->rear == s->front) {
		cout << "queue overflow" << endl;
		exit(1);
	}
	s->items[s->rear].etype = 1;
	s->items[s->rear].element.ival = data;
	s->front = 0;
}
void enqueue(queue* s, float data) {
	if (s->rear == MAXSIZE - 1) {
		s->rear = 0;
	}
	else s->rear += 1;
	if (s->rear == s->front) {
		cout << "queue overflow" << endl;
		exit(1);
	}
	s->items[s->rear].etype = 2;
	s->items[s->rear].element.fval = data;
	s->front = 0;
}
void enqueue(queue* s, char* data) {
	if (s->rear == MAXSIZE - 1) {
		s->rear = 0;
	}
	else s->rear += 1;
	if (s->rear == s->front) {
		cout << "queue overflow" << endl;
		exit(1);
	}
	s->items[s->rear].etype = 3;
	s->items[s->rear].element.pval = data;
	s->front = 0;
}


stackelement dequeue(queue* s) {
	if (s->front == MAXSIZE - 1) {
		s->front = 0;
	}
	else s->front += 1;
	return s->items[s->front];
}

void printqueue(queue* s) {
	if (s->front == s->rear) {
		cout << "queue is empty" << endl;
	}
	else for (int i = s->front; i <= s->rear; i++) {
		if (s->items[i].etype == 1) {
			cout << s->items[i].element.ival << endl;
		}
		if (s->items[i].etype == 2) {
			cout << s->items[i].element.fval << endl;
		}
		if (s->items[i].etype == 3) {
			cout << s->items[i].element.pval << endl;
		}

	}
}


int main() {
	queue niyo;
	char y[6] = "nihat";
	niyo.front = MAXSIZE-1; niyo.rear = MAXSIZE - 1;
	enqueue(&niyo, 12.5f);
	enqueue(&niyo, 1546);
	enqueue(&niyo, y);
	printqueue(&niyo);
	dequeue(&niyo);
	printqueue(&niyo);
}
