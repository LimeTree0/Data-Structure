#include<iostream>

typedef struct Node {
	char data;
	Node* leftNode, * rightNode;
}Node;

// ����� ���� Ž��
Node* RecursiveBinarySearch(Node* node, char data) {
	if (!node) return NULL;
	if (data == node->data) return node;
	if (data > node->data) return RecursiveBinarySearch(node->rightNode, data);
	return RecursiveBinarySearch(node->leftNode, data);
}

//�ݺ��� ���� Ž��
Node* IterativeBinarySearch(Node* node, char data) {
	Node* parent, * temp; // parent: �θ� ���, temp: �˻��ϴ� ���
	temp = node;
	parent = node;

	// ����� NULL ��ȯ
	if (temp == NULL)
		return NULL;

	while (temp != NULL) {
		parent = temp;

		// �����Ͱ� �����ϸ� NULL ��ȯ
		if (data == temp->data)
			return NULL;

		//�������� ũ�⿡ ���� �ڽĳ�� ����
		if (data > temp->data)
			temp = temp->rightNode;
		else
			temp = temp->leftNode;
	}

	//������ �θ��� ��ȯ
	return parent;
}

// ��� ����
void InsertBST(Node** rootNode, char data) {
	Node* temp, * ptr;
	temp = IterativeBinarySearch(*rootNode, data);

	//���� Ʈ���̰ų� Ž���� ������ ���( = ��� ������ �ʿ��� ���)
	if (!(*rootNode) || temp) {
		ptr = (Node*)malloc(sizeof(Node));
		ptr->data = data;
		ptr->rightNode = NULL;
		ptr->leftNode = NULL;

		//���� Ʈ���� �ƴ� ���
		if (*rootNode) {
			if (data > temp->data)
				temp->rightNode = ptr;
			else
				temp->leftNode = ptr;
		}
		//���� Ʈ���� ���
		else
			*rootNode = ptr;
	}
}

// ���� ��ȸ
void Preorder(Node* node) {
	if (node) {
		printf_s("%c ->", node->data);
		Preorder(node->leftNode);
		Preorder(node->rightNode);
	}
}

// ���� ��ȸ
void Inorder(Node* node) {
	if (node) {
		Inorder(node->leftNode);
		printf_s("%c ->", node->data);
		Inorder(node->rightNode);
	}
}

// ���� ��ȸ
void Postorder(Node* node) {
	if (node) {
		Postorder(node->leftNode);
		Postorder(node->rightNode);
		printf_s("%c ->", node->data);
	}
}

void DeleteBST(Node** rootNode, char data) {
	Node* delNode = *rootNode;
	Node* parent = NULL, * temp = NULL, * tempParent = NULL;
	int childCount = 0;

	// ������ ��� �˻�
	while (delNode->data != data) {
		parent = delNode;
		if (!delNode) printf_s("%c does not exist in tree");//������ ��带 ã�� ���� ���

		if (delNode->data < data) delNode = delNode->rightNode;
		else delNode = delNode->leftNode;
	}

	//������ ����� �ڽ� ��� ���� ����
	if (delNode->leftNode) childCount++;
	if (delNode->rightNode) childCount++;

	//�ܸ� ����� ���
	if (childCount == 0) {

		//�θ� ��� ����
		if (parent) {
			if (parent->leftNode == delNode) parent->leftNode = NULL;
			else parent->rightNode = NULL;
			free(temp);
		}

		//�������� �ʴ� ��� : ��Ʈ��常 ����
		else {
			*rootNode = NULL;
			free(delNode);
		}
	}

	else if (childCount == 1) {

		if (delNode->leftNode) temp = delNode->leftNode;// ���� ��尡 ���� �ڽ��� ������ ���
		else temp = delNode->rightNode;// ���� ��尡 ���� �ڽ��� ������ ���

		delNode->data = temp->data;
		delNode->rightNode = temp->rightNode;
		delNode->leftNode = temp->leftNode;

		free(temp);
	}

	else {

		// �������� ��ĭ
		temp = delNode->leftNode;

		//�����ʿ��� ���� ū ��� �˻�
		while (temp->rightNode) {
			tempParent = temp;
			temp = temp->rightNode;
		}

		delNode->data = temp->data;


		// ������ ��尡 ���ʿ� �ڽ��� ������ ���
		if (temp->leftNode) {
			if (tempParent == delNode) delNode->leftNode = temp->leftNode; // ���� ����� ���ʿ��� ������ ������ ��
			else tempParent->rightNode = temp->leftNode; // ���� ����� �����ʿ��� ��尡 ������ ��

			free(temp);
		}

		//������ ��尡 ���ʿ� �ڽ��� ������ �ʴ� ���
		else {
			if (tempParent == delNode) delNode->leftNode = NULL; // ���� ����� ���� ��尡 ���� ����� ���
			else tempParent->rightNode = NULL; // ��ü�Ǵ� ��尡 ���� ����� ���

			free(temp);
		}
	}
}

char search(Node* rootNode, char data) {
	Node* searchData = RecursiveBinarySearch(rootNode, data);
	if (searchData) return searchData->data;
	return NULL;
}

int main() {
	
	Node* rootNode = NULL;


	//������ ����
	InsertBST(&rootNode, 'H');
	InsertBST(&rootNode, 'I');
	InsertBST(&rootNode, 'A');
	InsertBST(&rootNode, 'C');
	InsertBST(&rootNode, 'D');
	InsertBST(&rootNode, 'E');

	DeleteBST(&rootNode, 'D');

	//��, ��, ���� ��ȸ
	Preorder(rootNode); printf_s("\n");
	Inorder(rootNode); printf_s("\n");
	Postorder(rootNode); printf_s("\n");


	//������ �˻�
	printf_s("result : %c", search(rootNode, 'C'));



}