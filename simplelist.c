#include <iostream>
#include <cstdlib>
#define NULL 0

using namespace std;
niyo* a;

struct niyo {
	int x;
	niyo *next;
};

niyo* node_ekle(niyo* a) {
	
	if (a == NULL) {
		a = new niyo;
		a->x = 5;
		a->next = NULL;
		return a;
	}
	else {
		niyo* iter = a;
		while (iter->next != NULL) {
			iter = iter->next;
			
		}
		iter->next = new niyo;
		iter->next->x = 59;
		iter->next->next = NULL;
		return a;
	}



}

niyo* node_cikar(niyo* a) {
	niyo* iter = a;
	if (iter == NULL) {
		cout << "Henuz Node Yok" << endl;
		return NULL;
	}
	else if (iter->next == NULL) {
		cout << " 1 node vardı o da siliniyor" << endl;
		delete iter;
		iter = NULL;
		return NULL;
	}
	else {
		while (iter->next->next != NULL) {
			iter = iter->next;
		}
		delete iter->next;
		iter->next = NULL;
		return a;
	}
}
int i=1;
void node_yazdir() {
	while (a != NULL) {
		cout <<i<<". Node'nin degeri : "<< a->x << endl;;
		a = a->next;
		i++;
	}
}

int main()
{	
	node_yazdir();
	node_cikar(a);
	node_ekle(a);
}
 
