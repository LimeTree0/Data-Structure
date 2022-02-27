#include<iostream>
#define SIZE 5

typedef struct TreeNode{
	int data;
	bool check = false;
}Tree;

// �迭�� �� Ʈ��
Tree tree[SIZE];

//��Ʈ ��� ����
void insertRoot(int n) {
	if (tree[0].check) {
		printf_s("������ ����\n");
		return;
	}
	tree[0].data = n;
	tree[0].check = true;
}

// �θ� ��� ���ʿ� ����
void insertLeft(int n, int parentIndex) {
	int index = parentIndex * 2 + 1;
	if (tree[index].check) {
		printf_s("������ ����\n");
		return;
	}
	tree[index].data = n;
	tree[index].check = true;
}

// �θ� ��� �����ʿ� ����
void insertRight(int n, int parentIndex) {
	int index = parentIndex * 2 + 2;
	if (tree[index].check) {
		printf_s("������ ����\n");
		return;
	}
	tree[index].data = n;
	tree[index].check = true;
}

//��� ����(�������)
void orderedInsert() {
	int num = 2;
	insertRoot(1);
	for (int i = 0; i < SIZE / 2 + 1; i++) {
		insertLeft(num++, i);
		insertRight(num++, i);
	}
}

// ��� ���
void printFor() {
	for (int i = 0; i < SIZE; i++)
		tree[i].check ? printf_s("%d ", tree[i].data) : NULL;
}

//���� ��ȸ
void preorder(int parentNode) {
	if (parentNode < SIZE) {
		printf_s("%d ", tree[parentNode].data);
		preorder(parentNode * 2 + 1);
		preorder(parentNode * 2 + 2);
	}
}

//���� ��ȸ
void inorder(int parentNode) {
	if (parentNode < SIZE) {
		inorder(parentNode * 2 + 1);
		printf_s("%d ", tree[parentNode].data);
		inorder(parentNode * 2 + 2);
	}
}

//���� ��ȸ
void postorder(int parentNode) {
	if (parentNode < SIZE) {
		postorder(parentNode * 2 + 1);
		postorder(parentNode * 2 + 2);
		printf_s("%d ", tree[parentNode].data);
	}
}

int main() {

	orderedInsert();
	printf_s("preorder  : "); preorder(0); printf_s("\n");
	printf_s("inorder   : "); inorder(0); printf_s("\n");
	printf_s("postorder : "); postorder(0); printf_s("\n");
	//printFor();
}