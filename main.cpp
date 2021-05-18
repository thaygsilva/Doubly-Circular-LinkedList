//Thayna Gomes da Silva TIA:32092229
//Claudionor Domingues da Silva TIA:32086784

//Referências : https://gist.github.com/tuliopaim/1564aa76080d15608971df288bfe8996

#include <iostream>
#include <clocale>
#include "ListaCDE.h"

using namespace std;

void Print(const LinkedList* list) {
	Node* temp = list->head;
	
	for (int i = 0; i < list->count; i++){
		cout << "[" << temp->id << "]" << temp->name << endl;
		temp = temp->next;
	}
	cout << "\n";
}

void PrintReverse(const LinkedList* list) {
	Node* temp = list->tail;
	for (int i = 0; i < list->count; i++) {
		cout << "[" << temp->id << "]" << temp->name << endl;
		temp = temp->previous;
	}
	cout << "\n";

}

void PrintDoubleListInfo(const LinkedList* list) {
	if (IsEmpty(list))
	{
		cout << "Lista vazia!\n";
	}
	else
	{
		cout << "Lista:\n";
		Print(list);
		cout << "Lista invertida:\n";
		PrintReverse(list);
	}
}

int main() {

	setlocale(LC_ALL, "pt_BR");
	cout << "*** Lista Circular Duplamente Ligada/Encadeada (Doubly Circular LinkedList)*** \n";

	LinkedList* list = Create();

	PrintDoubleListInfo(list);
	Insert(list, 1, "Carol");
	Insert(list, 2, "Eric");
	Insert(list, 3, "John");
	Append(list, 4, "Leo");
	Append(list, 5, "Julia");
	Append(list, 6, "Lisa");

	PrintDoubleListInfo(list);
	Clear(list);

	PrintDoubleListInfo(list);
	Insert(list, 11, "Paulo");
	Append(list, 22, "Thomas");
	Insert(list, 33, "Olga");
	Append(list, 44, "Bia");
	Insert(list, 55, "Angela");
	Append(list, 66, "Karen");
	Insert(list, 77, "Adauto");
	PrintDoubleListInfo(list);

	Node* temp = RemoveNode(list, 44);
	cout << "No removido -> id: " << temp->id << ", name: " << temp->name << '\n';
	DestroyNode(temp);

	PrintDoubleListInfo(list);
	temp = RemoveHead(list);
	cout << "No removido -> id: " << temp->id << ", name: " << temp->name << '\n';
	DestroyNode(temp);

	PrintDoubleListInfo(list);
	temp = RemoveTail(list);
	cout << "No removido -> id: " << temp->id << ", name: " << temp->name << '\n';
	DestroyNode(temp);

	PrintDoubleListInfo(list);
	Destroy(list);
	cout << "Fim.\n";
}
