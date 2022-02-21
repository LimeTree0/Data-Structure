#include<iostream>

// 구조체 정의
typedef struct node_type {
	int data;
	node_type* link;
} Node;


// 헤드 노드 생성
Node* CreateSinglyLinkedList() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->link = NULL;
	return head;
}

//리스트 앞자리에 노드 삽입
void insertFirst(Node* head, int n) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = n;
	newNode->link = head->link;
	head->link = newNode;
}

//리스트 마지막 자리에 노드 삽입
void insertLast(Node* head, int n) {
	Node* preNode = head;
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = n;
	newNode->link = NULL;
	
	while (preNode->link != NULL)
		preNode = preNode->link;

	preNode->link = newNode;
}

//리스트 중간에 노드 삽입
void insertMiddle(Node* head, int front,int n) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = n;

	Node* ptr = head->link;
	Node* preNode = head;
	while (ptr->data != front)
	{
		preNode = ptr;
		ptr = ptr->link;
		if (ptr == NULL) {
			printf_s("찾는 데이터가 없습니다.\n");
			return;
		}
	}


	preNode->link = newNode;
	newNode->link = ptr;

}

//노드 삭제
void deleteNode(Node* head, int n) {
	Node* ptr = head->link;
	Node* preNode = head;
	while (ptr->data!= n)
	{
		preNode = ptr;
		ptr = ptr->link;
		if (ptr == NULL) {
			printf_s("찾는 데이터가 없습니다.\n");
			return;
		}
	}

	preNode->link = ptr->link;
	free(ptr);
}

void search(Node* head, int n) {
	Node* ptr = head->link;
	Node* preNode = head;
	while (ptr->data != n)
	{
		preNode = ptr;
		ptr = ptr->link;
		if (ptr == NULL) {
			printf_s("검색 결과 : 찾는 데이터가 없습니다.\n");
			return;
		}
	}

	printf_s("검색 결과 : %d \n", ptr->data);
}

// 노드 출력
void printLinkedList(Node* head) {
	Node* ptr = head->link;
	while (ptr != NULL) {
		printf_s(" %d ->", ptr->data);
		ptr = ptr->link;
	}
	printf_s(" NULL\n");
}


int main() {
	Node* head = CreateSinglyLinkedList();
	insertFirst(head, -10);
	insertLast(head, 10);
	insertLast(head, 20);
	insertLast(head, 30);
	printLinkedList(head);
	deleteNode(head, 90);
	insertMiddle(head, 20, 50);
	printLinkedList(head);
	search(head, 700);
}