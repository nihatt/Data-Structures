// node.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include  <cstdlib>
#define NULL 0
using namespace std;





struct nodeler
{
	int x;
	nodeler* next;

};
nodeler* kok=NULL;

void node_Add() {
	if (kok == NULL) {

		kok = new nodeler;
		cout << "node ici degeri giriniz (bu ilk nodedir) : " << endl;
		int b = 0;
		cin >> b;
		kok->x = b;
		kok->next = NULL;
	}
	else {
		int b = 0;
		nodeler* iter = kok;
		while (iter->next != NULL) {
			iter = iter->next;
		}
		iter->next = new nodeler;
		cout << "node ici degeri giriniz : " << endl;
		cin >> b;
		iter->next->x = b;
		iter->next->next = NULL;

	}
}



int i = 1;
void node_yazdir() {
	
	while (kok != NULL) {
		cout << i << ". Node'nin degeri : " << kok->x << endl;;
		kok = kok->next;
		i++;
	}

}

void node_delete() {
	nodeler* iter = kok;
	if (kok->next == NULL) {
		delete(kok);
		kok = NULL;
	}
	else {
		while (iter->next->next != NULL) {
			iter = iter->next;
		}
		delete (iter->next);
		iter->next = NULL;
	}
	
}



int main()
{
	int niyop = 3;
	nodeler* kok=NULL;
	while (niyop<7)
	{
		node_Add();
		niyop++;
	}


	node_yazdir();


}
