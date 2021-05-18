//Thayna Gomes da Silva TIA:32092229
//Claudionor Domingues da Silva TIA:32086784
#include "ListaCDE.h"

LinkedList* Create() {
	LinkedList* list = new LinkedList;

	list->count = 0;
	list->head = nullptr;
	list->tail = nullptr;

	return list;
}

void Destroy(LinkedList* list) {

	Clear(list);
	delete list;
}

void Insert(LinkedList* list, int pos, std::string elem){

	Node* n = new Node;

	n->name = elem;
	n->id = pos;
	n->previous = n->next;
	n->next = GetHead(list);

	if (IsEmpty(list)) {
		list->tail = n;
		list->head = n;
	}

	else if (list->count == 1) {
		list->head->next = n;
		list->head->previous = n;
		n->previous = list->head;
		n->next = list->head;
	}
	else {
		list->head->previous = n;
		n->next = list->head;
		n->previous = list->tail;
		list->tail->next = n;
	}

	list->head = n;

	++list->count;
}

void Append(LinkedList* list, int pos, std::string elem) {
	Node* n = new Node;

	n->name = elem;
	n->id = pos;

	if (IsEmpty(list))
	{
		list->head = n;
		list->tail = n;
	}
	else
	{	
		n->previous = list->tail;
		list->tail->next = n;
		list->tail = n;
		list->head->previous = n;
	}
	n->next = list->head;
	++list->count;
}

Node* RemoveHead(LinkedList* list) {

	Node* toRemove = list->head;
	if ((list->head) == (list->tail)) {
		list->head = nullptr;
		list->tail = nullptr;
	}
	else {
		list->head = list->head->next;
	}
	--list->count;

	toRemove->previous = nullptr;
	toRemove->next = nullptr;

	return toRemove;
}

Node* RemoveTail(LinkedList* list)
{


	if ((list->head) == (list->tail))
	{

		return RemoveHead(list);
	}

	Node* toRemove = list->head;
	Node* previous = nullptr;
	while (toRemove != (list->tail))
	{
		previous = toRemove;
		toRemove = toRemove->next;
	}
	previous->next = nullptr;
	list->tail = previous;
	--list->count;

	toRemove->previous = nullptr;
	toRemove->next = nullptr;

	return toRemove;
}

Node* RemoveNode(LinkedList* list, int value) {

	Node* toRemove = list->head;
	for (int i = 0; i < list->count; i++) {
		if (toRemove->id == value) {
			break;
		}
		toRemove = toRemove->next;
	}
	if (toRemove->id != value) return nullptr;
	if (toRemove == list->head) return RemoveHead(list);
	if (toRemove == list->tail) return RemoveTail(list);
	else {
		toRemove->previous->next = toRemove->next;
		toRemove->next->previous = toRemove->previous;
		--list->count;
		toRemove->previous = nullptr;
		toRemove->next = nullptr;
		return toRemove;
	}
}

Node* RemoveMiddle(LinkedList* list, int pos, int value) {
	return nullptr;
}

Node* GetHead(LinkedList* list) {
	return list->head;
}

Node* GetTail(LinkedList* list) {
	return list->tail;
}

Node* GetNode(LinkedList* list, int  value) {

	Node* toRemove = list->head;
	while (toRemove != nullptr) {
		if (toRemove->id == value) return toRemove;
		toRemove = toRemove->next;
	}
	return nullptr;
}

int Count(LinkedList* list) {
	return list->count;
}

bool IsEmpty(const LinkedList* list) {
	return list->count == 0;
}

void Clear(LinkedList* list){
	Node* toRemove = list->head;
	Node* next = nullptr;
	for (int i = 0; i < list->count; i++){
		next = toRemove->next;
		delete toRemove;
		toRemove = next;
	}
	list->head = nullptr;
	list->tail = nullptr;
	list->count = 0;
}

void DestroyNode(Node* node){
	delete node;
	node = nullptr;
}
