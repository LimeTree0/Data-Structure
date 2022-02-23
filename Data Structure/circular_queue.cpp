#include<iostream>
#define SIZE 5
int front = -1, rear = -1;
int circularQueue[SIZE];

void enqueue(int n) {
	if (rear + 1!= front) {
		rear = (rear + 1) % SIZE;
		circularQueue[rear] = n;
		printf_s("enqueue %d in queue\n\n", n);
	}
	else
		printf_s("\nqueue is full\n");

	printf_s("front : %d , rear : %d\n", front, rear);
};
void dequeue() {
	if (front != rear) {
		front = (front + 1) % SIZE;
		printf_s("%d\n", circularQueue[front]);
	}
	else
		printf_s("\nqueue is empty\n\n");

	printf_s("front : %d , rear : %d\n", front, rear);
};


int main() {
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	dequeue();
	dequeue();
	enqueue(1);
	enqueue(2);
	enqueue(3);
	
	dequeue();
	dequeue();
	enqueue(1);
	enqueue(2);
	dequeue();
	dequeue();
	enqueue(1);
	enqueue(2);
	dequeue();
	dequeue();
	dequeue();

}