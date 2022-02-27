//#include<iostream>
//
//// ����ü ����
//typedef struct node_type {
//	int data;
//	node_type* link;
//} Node;
//
//// ����Ʈ ��� ����ü ����
//typedef struct {
//	Node* firstNode;
//	Node* tail;
//}ListHead;
//
//
//// �� ���� ��带 ������ ����Ʈ ����
//ListHead* createCircularList(int n) {
//	ListHead* listHead = (ListHead*)malloc(sizeof(ListHead*));
//	Node* head = (Node*)malloc(sizeof(Node));
//	head->data = n;
//	head->link = head;
//	listHead->firstNode = head;
//	listHead->tail = head;
//
//	return listHead;
//}
//
////����Ʈ�� ���� �տ� ��� ����
//void insertFirst(ListHead* listHead, int n) {
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->data = n;
//
//	newNode->link = listHead->firstNode;
//	listHead->firstNode = newNode;
//	listHead->tail->link = newNode;
//}
//
////����Ʈ�� ���� �ڿ� ��� ����
//void insertLast(ListHead* listHead, int n) {
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->data = n;
//
//	newNode->link = listHead->firstNode;
//	listHead->tail->link = newNode;
//	listHead->tail = newNode;
//}
//
////����Ʈ���� ��� ����
//void deleteNode(ListHead* listHead, int n) {
//
//	Node* preNode = listHead->tail;
//	Node* ptr = listHead->firstNode;
//
//	while (ptr->data != n) {
//		if (ptr != listHead->tail) {
//			printf_s("�����Ͱ� �����ϴ�.");
//			return;
//		}
//		preNode = ptr;
//		ptr = ptr->link;
//	}
//
//	if (ptr == listHead->firstNode) {
//		listHead->firstNode = ptr->link;
//		listHead->tail->link = listHead->firstNode;
//	}
//
//	if (ptr == listHead->tail)
//		listHead->tail = preNode;
//
//	preNode->link = ptr->link;
//	free(ptr);
//}
//
////��� ���
//void printList(ListHead* listHead) {
//	Node* node = listHead->firstNode;
//
//	while (node != listHead->tail) {
//		printf_s(" %d ->", node->data);
//		node = node->link;
//	}
//
//	printf_s(" %d -> %d\n", listHead->tail->data, listHead->firstNode->data);
//}
//
//int main() {
//	
//	ListHead* listHead = createCircularList(10);
//	insertFirst(listHead, 20);
//	insertFirst(listHead, 40);
//	insertLast(listHead, 30);
//	printList(listHead);
//	deleteNode(listHead, 40);
//	printList(listHead);
//
//}