#include<iostream>

//https://foxtrotin.tistory.com/191?category=635012 이 분 코드를 참조해서 작성함

typedef struct Node {
	int data;
	Node* left, * right;
}Node;

//노드의 높이 반환 함수
int getHeight(Node* node) {
	int height = 0;
	if (node != NULL) {
		int leftHeight = getHeight(node->left); 
		int rightHeight = getHeight(node->right);
		height = ((leftHeight > rightHeight) ? leftHeight : rightHeight) + 1;
	}

	return height;
}


//노드의 균형인수 반환 함수
int getBalanceFactor(Node* node) {
	return getHeight(node->left) - getHeight(node->right);
}


//새로운 노드 생성
Node* CreateNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;

	return newNode;
}

//LL 회전
Node* SingleRightRotation(Node* node) {
	Node* temp = node->left;
	node->left = temp->right;
	temp->right = node;
	return temp;
}

//RR 회전
Node* SingleLeftRotation(Node* node) {
	Node* temp = node->right;
	node->right = temp->left;
	temp->left = node;
	return temp;
}

//RL회전
Node* RLRotation(Node* node) {
	node->right = SingleRightRotation(node->right);
	return SingleLeftRotation(node);
}

//LR회전
Node* LRRotation(Node* node) {
	node->right = SingleLeftRotation(node->left);
	return SingleRightRotation(node);
}

//재균형 함수
Node* RebalanceTree(int balanceFactor, Node* node) {
	if (balanceFactor < -1) {
		if (getBalanceFactor(node->right) > 0)
			return RLRotation(node);
		else
			return SingleLeftRotation(node);
	}
	else if (balanceFactor > 1) {
		if (getBalanceFactor(node->left) < 0)
			return LRRotation(node);
		else
			return SingleRightRotation(node);
	}

	return node;
}

// 노드 삽입
void InsertAVLTree(Node** node, int data) {
	if (*node == NULL) *node = CreateNode(data);
	else if ((*node)->data > data)InsertAVLTree(&((*node)->left), data);
	else if ((*node)->data < data)InsertAVLTree(&((*node)->right), data);

	int balanceFactor = getBalanceFactor(*node);

	(*node) = RebalanceTree(balanceFactor, *node);
}

// 전위 순회
void Preorder(Node* node) {
	if (node) {
		printf_s("%d ->", node->data);
		Preorder(node->left);
		Preorder(node->right);
	}
}

int main() {
	Node* root = NULL;

	InsertAVLTree(&root, 2);
	InsertAVLTree(&root, 1);
	InsertAVLTree(&root, 5);
	InsertAVLTree(&root, 3);
	InsertAVLTree(&root, 7);
	InsertAVLTree(&root, 4);

	Preorder(root);
}