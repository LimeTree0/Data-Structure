#include<iostream>

// ����ü ����
typedef struct node_type {
	int data;
	node_type* link;
} Node;


// ��� ��� ����
Node* CreateSinglyLinkedList() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->link = NULL;
	return head;
}

//����Ʈ ���ڸ��� ��� ����
void insertFirst(Node* head, int n) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = n;
	newNode->link = head->link;
	head->link = newNode;
}

//����Ʈ ������ �ڸ��� ��� ����
void insertLast(Node* head, int n) {
	Node* preNode = head;
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = n;
	newNode->link = NULL;
	
	while (preNode->link != NULL)
		preNode = preNode->link;

	preNode->link = newNode;
}

//����Ʈ �߰��� ��� ����
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
			printf_s("ã�� �����Ͱ� �����ϴ�.\n");
			return;
		}
	}


	preNode->link = newNode;
	newNode->link = ptr;

}

//��� ����
void deleteNode(Node* head, int n) {
	Node* ptr = head->link;
	Node* preNode = head;
	while (ptr->data!= n)
	{
		preNode = ptr;
		ptr = ptr->link;
		if (ptr == NULL) {
			printf_s("ã�� �����Ͱ� �����ϴ�.\n");
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
			printf_s("�˻� ��� : ã�� �����Ͱ� �����ϴ�.\n");
			return;
		}
	}

	printf_s("�˻� ��� : %d \n", ptr->data);
}

// ��� ���
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