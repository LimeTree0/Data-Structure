#include<iostream>

//https://foxtrotin.tistory.com/191?category=635012 �� �� �ڵ带 �����ؼ� �ۼ���

typedef struct Node {
	int data;
	Node* left, * right;
}Node;

//����� ���� ��ȯ �Լ�
int getHeight(Node* node) {
	int height = 0;
	if (node != NULL) {
		int leftHeight = getHeight(node->left); 
		int rightHeight = getHeight(node->right);
		height = ((leftHeight > rightHeight) ? leftHeight : rightHeight) + 1;
	}

	return height;
}


//����� �����μ� ��ȯ �Լ�
int getBalanceFactor(Node* node) {
	return getHeight(node->left) - getHeight(node->right);
}


//���ο� ��� ����
Node* CreateNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;

	return newNode;
}

//LL ȸ��
Node* SingleRightRotation(Node* node) {
	Node* temp = node->left;
	node->left = temp->right;
	temp->right = node;
	return temp;
}

//RR ȸ��
Node* SingleLeftRotation(Node* node) {
	Node* temp = node->right;
	node->right = temp->left;
	temp->left = node;
	return temp;
}

//RLȸ��
Node* RLRotation(Node* node) {
	node->right = SingleRightRotation(node->right);
	return SingleLeftRotation(node);
}

//LRȸ��
Node* LRRotation(Node* node) {
	node->right = SingleLeftRotation(node->left);
	return SingleRightRotation(node);
}

//����� �Լ�
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

// ��� ����
void InsertAVLTree(Node** node, int data) {
	if (*node == NULL) *node = CreateNode(data);
	else if ((*node)->data > data)InsertAVLTree(&((*node)->left), data);
	else if ((*node)->data < data)InsertAVLTree(&((*node)->right), data);

	int balanceFactor = getBalanceFactor(*node);

	(*node) = RebalanceTree(balanceFactor, *node);
}

// ���� ��ȸ
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