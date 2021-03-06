//#include<iostream>
//
//// 구조체 정의
//typedef struct node_type {
//	int data;
//	node_type* link;
//} Node;
//
//// 리스트 헤드 구조체 정의
//typedef struct {
//	Node* firstNode;
//	Node* tail;
//}ListHead;
//
//
//// 한 개의 노드를 가지는 리스트 생성
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
////리스트의 가장 앞에 노드 삽입
//void insertFirst(ListHead* listHead, int n) {
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->data = n;
//
//	newNode->link = listHead->firstNode;
//	listHead->firstNode = newNode;
//	listHead->tail->link = newNode;
//}
//
////리스트의 가장 뒤에 노드 삽입
//void insertLast(ListHead* listHead, int n) {
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->data = n;
//
//	newNode->link = listHead->firstNode;
//	listHead->tail->link = newNode;
//	listHead->tail = newNode;
//}
//
////리스트에서 노드 삭제
//void deleteNode(ListHead* listHead, int n) {
//
//	Node* preNode = listHead->tail;
//	Node* ptr = listHead->firstNode;
//
//	while (ptr->data != n) {
//		if (ptr != listHead->tail) {
//			printf_s("데이터가 없습니다.");
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
////노드 출력
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