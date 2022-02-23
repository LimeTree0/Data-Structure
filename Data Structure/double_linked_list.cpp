#include<iostream>

//구조체 선언
typedef struct NodeType {
	int data;
	NodeType* leftLink, *rightLink, *tailNode;
}Node;

Node* createDoublyLinkedList() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->leftLink = NULL;
	head->rightLink = NULL;
	head->tailNode = head;

	return head;
}

//첫번째 노드에 삽입
void insertFirst(Node* head, int n) {
	if (!head->rightLink) {
		printf_s("use insertLast() at least once");
		return;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = n;
	newNode->rightLink = head->rightLink;
	head->rightLink = newNode;
	newNode->leftLink = head;
	newNode->rightLink->leftLink = newNode;
}

// 마지막 노드 삽입
void insertLast(Node* head, int n) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = n;
	newNode->rightLink = NULL;
	head->tailNode->rightLink = newNode;
	newNode->leftLink = head->tailNode;
	head->tailNode = newNode;


}


// 링크드 리스트 출력(inverse가 true면 역순으로 출력)
void printLinkedList(Node* head, bool inverse = false) {
	Node* ptr;
	if (inverse) {
		ptr = head->tailNode;
		while (ptr != head) {
			printf_s(" %d <->", ptr->data);
			ptr = ptr->leftLink;
		}
		printf_s(" head\n");
		return;
	}

	ptr = head->rightLink;
	while (ptr != NULL) {
		printf_s(" %d <->", ptr->data);
		ptr = ptr->rightLink;
	}
	printf_s(" NULL\n");
}

int main() {
	Node* head = createDoublyLinkedList();
	insertLast(head, 10);
	insertLast(head, 20);
	insertLast(head, 30);
	insertLast(head, 40);
	insertFirst(head, 0);
	printLinkedList(head,true);
	printLinkedList(head);
}