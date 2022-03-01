//#include<iostream>
//#define SIZE 15
//
//typedef struct TreeNode{
//	int data;
//	bool check = false;
//}Tree;
//
//// 배열로 된 트리
//Tree tree[SIZE];
//
////루트 노드 삽입
//void insertRoot(int n) {
//	if (tree[0].check) {
//		printf_s("데이터 존재\n");
//		return;
//	}
//	tree[0].data = n;
//	tree[0].check = true;
//}
//
//// 부모 노드 왼쪽에 삽입
//void insertLeft(int n, int parentIndex) {
//	int index = parentIndex * 2 + 1;
//	if (tree[index].check) {
//		printf_s("데이터 존재\n");
//		return;
//	}
//	tree[index].data = n;
//	tree[index].check = true;
//}
//
//// 부모 노드 오른쪽에 삽입
//void insertRight(int n, int parentIndex) {
//	int index = parentIndex * 2 + 2;
//	if (tree[index].check) {
//		printf_s("데이터 존재\n");
//		return;
//	}
//	tree[index].data = n;
//	tree[index].check = true;
//}
//
////노드 삽입(순서대로)
//void orderedInsert() {
//	int num = 2;
//	insertRoot(1);
//	for (int i = 0; i < SIZE / 2 + 1; i++) {
//		insertLeft(num++, i);
//		insertRight(num++, i);
//	}
//}
//
//// 노드 출력
//void printFor() {
//	for (int i = 0; i < SIZE; i++)
//		tree[i].check ? printf_s("%d ", tree[i].data) : NULL;
//}
//
////전위 순회
//void preorder(int parentNode) {
//	if (parentNode < SIZE) {
//		printf_s(" %d ->", tree[parentNode].data);
//		preorder(parentNode * 2 + 1);
//		preorder(parentNode * 2 + 2);
//	}
//}
//
////중위 순회
//void inorder(int parentNode) {
//	if (parentNode < SIZE) {
//		inorder(parentNode * 2 + 1);
//		printf_s(" %d ->", tree[parentNode].data);
//		inorder(parentNode * 2 + 2);
//	}
//}
//
////후위 순회
//void postorder(int parentNode) {
//	if (parentNode < SIZE) {
//		postorder(parentNode * 2 + 1);
//		postorder(parentNode * 2 + 2);
//		printf_s(" %d ->", tree[parentNode].data);
//	}
//}
//
//// 트리로 출력하려다 망한 함수1
//void test(int spaceCount, int space, int *index, bool* elementprint) {
//	if (spaceCount%space == 0) {
//		if (*elementprint) {
//			printf_s("%-4d", tree[(*index)++].data);
//			*elementprint = false;
//		}
//		else {
//			printf_s("s");
//			*elementprint = true;
//		}
//	}
//	else
//		printf_s("s");
//}
//
//// 트리로 출력하려다 망한 함수2
//void test2() {
//	bool elementPrint = true;
//	int index = 0;
//	int space = (SIZE + 1) / 2;
//	for (int i = 0; i < 4; i++) {
//		for (int j = 1; j < SIZE+1; j++)
//			if(index <SIZE)
//				test(j, space, &index, &elementPrint);
//		printf_s("\n");
//		elementPrint = true;
//		space /= 2;
//	}
//}
//
//
//int main() {
//
//	orderedInsert();
//	printf_s("preorder  : "); preorder(0); printf_s("\n");
//	printf_s("inorder   : "); inorder(0); printf_s("\n");
//	printf_s("postorder : "); postorder(0); printf_s("\n");
//	printFor();
//}