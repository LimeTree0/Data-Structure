//#include<iostream>
//#define SIZE 5
//int front = -1, rear = -1;
//int circularQueue[SIZE];
//
////ť�� ����
//void enqueue(int n) {
//	int tempRear = (rear + 1) % SIZE;
//	if (tempRear != front) {
//		circularQueue[rear = tempRear] = n;
//	}
//	else
//		printf_s("queue is full\n");
//};
//
////ť���� ����
//void dequeue() {
//	if (front != rear) {
//		front = (front + 1) % SIZE;
//		printf_s("dequeue %d in queue\n", circularQueue[front]);
//	}
//	else
//		printf_s("queue is empty\n\n");
//};
//
//
//int main() {
//	enqueue(1);
//	enqueue(2);
//	dequeue();
//	dequeue();
//	dequeue();
//
//	//ť ���� ������ �˻�
//	for (int i = 0; i < 5; i++) {
//		printf_s("%d ", circularQueue[i]);
//	}
//}