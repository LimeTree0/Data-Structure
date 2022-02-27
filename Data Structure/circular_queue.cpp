//#include<iostream>
//#define SIZE 5
//int front = -1, rear = -1;
//int circularQueue[SIZE];
//
////큐에 삽입
//void enqueue(int n) {
//	int tempRear = (rear + 1) % SIZE;
//	if (tempRear != front) {
//		circularQueue[rear = tempRear] = n;
//	}
//	else
//		printf_s("queue is full\n");
//};
//
////큐에서 삭제
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
//	//큐 내부 데이터 검사
//	for (int i = 0; i < 5; i++) {
//		printf_s("%d ", circularQueue[i]);
//	}
//}