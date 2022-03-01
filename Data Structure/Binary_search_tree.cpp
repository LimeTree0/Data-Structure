#include<iostream>

typedef struct Node {
	char data;
	Node* leftNode, * rightNode;
}Node;

// 재귀적 이진 탐색
Node* RecursiveBinarySearch(Node* node, char data) {
	if (!node) return NULL;
	if (data == node->data) return node;
	if (data > node->data) return RecursiveBinarySearch(node->rightNode, data);
	return RecursiveBinarySearch(node->leftNode, data);
}

//반복적 이진 탐색
Node* IterativeBinarySearch(Node* node, char data) {
	Node* parent, * temp; // parent: 부모 노드, temp: 검색하는 노드
	temp = node;
	parent = node;

	// 공백시 NULL 반환
	if (temp == NULL)
		return NULL;

	while (temp != NULL) {
		parent = temp;

		// 데이터가 존재하면 NULL 반환
		if (data == temp->data)
			return NULL;

		//데이터의 크기에 따라 자식노드 선택
		if (data > temp->data)
			temp = temp->rightNode;
		else
			temp = temp->leftNode;
	}

	//삽입할 부모노드 반환
	return parent;
}

// 노드 삽입
void InsertBST(Node** rootNode, char data) {
	Node* temp, * ptr;
	temp = IterativeBinarySearch(*rootNode, data);

	//공백 트리이거나 탐색에 실패한 경우( = 노드 삽입이 필요한 경우)
	if (!(*rootNode) || temp) {
		ptr = (Node*)malloc(sizeof(Node));
		ptr->data = data;
		ptr->rightNode = NULL;
		ptr->leftNode = NULL;

		//공백 트리가 아닌 경우
		if (*rootNode) {
			if (data > temp->data)
				temp->rightNode = ptr;
			else
				temp->leftNode = ptr;
		}
		//공백 트리인 경우
		else
			*rootNode = ptr;
	}
}

// 전위 순회
void Preorder(Node* node) {
	if (node) {
		printf_s("%c ->", node->data);
		Preorder(node->leftNode);
		Preorder(node->rightNode);
	}
}

// 중위 순회
void Inorder(Node* node) {
	if (node) {
		Inorder(node->leftNode);
		printf_s("%c ->", node->data);
		Inorder(node->rightNode);
	}
}

// 후위 순회
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

	// 삭제할 노드 검색
	while (delNode->data != data) {
		parent = delNode;
		if (!delNode) printf_s("%c does not exist in tree");//삭제할 노드를 찾지 못한 경우

		if (delNode->data < data) delNode = delNode->rightNode;
		else delNode = delNode->leftNode;
	}

	//삭제할 노드의 자식 노드 개수 세기
	if (delNode->leftNode) childCount++;
	if (delNode->rightNode) childCount++;

	//단말 노드인 경우
	if (childCount == 0) {

		//부모 노드 존재
		if (parent) {
			if (parent->leftNode == delNode) parent->leftNode = NULL;
			else parent->rightNode = NULL;
			free(temp);
		}

		//존재하지 않는 경우 : 루트노드만 존재
		else {
			*rootNode = NULL;
			free(delNode);
		}
	}

	else if (childCount == 1) {

		if (delNode->leftNode) temp = delNode->leftNode;// 삭제 노드가 왼쪽 자식을 가지는 경우
		else temp = delNode->rightNode;// 삭제 노드가 왼쪽 자식을 가지는 경우

		delNode->data = temp->data;
		delNode->rightNode = temp->rightNode;
		delNode->leftNode = temp->leftNode;

		free(temp);
	}

	else {

		// 왼쪽으로 한칸
		temp = delNode->leftNode;

		//오른쪽에서 가장 큰 노드 검색
		while (temp->rightNode) {
			tempParent = temp;
			temp = temp->rightNode;
		}

		delNode->data = temp->data;


		// 삭제할 노드가 왼쪽에 자식을 가지는 경우
		if (temp->leftNode) {
			if (tempParent == delNode) delNode->leftNode = temp->leftNode; // 삭제 노드의 왼쪽에만 노드들이 존재할 때
			else tempParent->rightNode = temp->leftNode; // 삭제 노드의 오른쪽에도 노드가 존재할 때

			free(temp);
		}

		//삭제할 노드가 왼쪽에 자식을 가지지 않는 경우
		else {
			if (tempParent == delNode) delNode->leftNode = NULL; // 삭제 노드의 왼쪽 노드가 말단 노드인 경우
			else tempParent->rightNode = NULL; // 대체되는 노드가 말단 노드인 경우

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


	//데이터 삽입
	InsertBST(&rootNode, 'H');
	InsertBST(&rootNode, 'I');
	InsertBST(&rootNode, 'A');
	InsertBST(&rootNode, 'C');
	InsertBST(&rootNode, 'D');
	InsertBST(&rootNode, 'E');

	DeleteBST(&rootNode, 'D');

	//전, 중, 후위 순회
	Preorder(rootNode); printf_s("\n");
	Inorder(rootNode); printf_s("\n");
	Postorder(rootNode); printf_s("\n");


	//데이터 검색
	printf_s("result : %c", search(rootNode, 'C'));



}