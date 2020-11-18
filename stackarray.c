#include <iostream>
#include <cstdlib>
using namespace std;
int* myArr = new int[2];
int sizex = 2;
int tepe=0;
int pop() {
	if (tepe == 0) {
		cout << "stack underflow ! " << endl;
		exit(1);
	}
	if (tepe == sizex / 4) {
		int* temp = new int[sizex / 2];
		for (int i = 0; i <tepe; i++) {
			temp[i] = myArr[i];
		}
		delete[] myArr;
		myArr = temp;
		}
	tepe = tepe - 1;
	cout << "Last added index has been deleted " << endl;
	return myArr[tepe];
}

void push(int a) {

	if(tepe==sizex)  {
		int* temp = new int[sizex * 2];
		for (int i = 0; i < sizex; i++) {
			temp[i] = myArr[i];
		}
		delete[] myArr;
		myArr = temp;
		sizex*=2;
	}
		myArr[tepe++] = a;
}

void print() {

	for (int i = 0; i < tepe; i++) {
		cout <<sizex<<". index"<< myArr[i] << endl;
	}
}

int main() {
	push(12);
	push(21);
	push(42);
	push(59);
	push(74);
	print();
	pop();
	pop();
	print();
}
