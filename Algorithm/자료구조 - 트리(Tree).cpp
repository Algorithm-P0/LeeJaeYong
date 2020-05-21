//트리 용어 정리
//노드(node)와 가지(edge)
//루트(root): 트리의 가장 윗부분에 위치하는 노드
//리프(leaf): 트리의 가장 아랫부분에 위치하는 노드
//안쪽 노드: 루트를 포함하여 리프를 제외한 노드
//자식(child): 어떤 노드로부터 가지로 연결된 아래쪽 노드
//부모(parent): 어떤 노드에서 가지로 연결된 위쪽 노드
//형제(sibling): 같은 부모를 가지는 노드
//조상(ancestor): 어떤 노드에서 가지로 연결된 위쪽 노드 모두
//자손(descendant): 어떤 노드에서 가지로 연결된 아래쪽 노드 모두
//레벨(level): 루트로부터 얼마나 떨어져 있는지에 대한 값
//차수(degree): 노드가 갖는 자식의 수
//높이: 루트로부터 가장 멀리 떨어진 리프까지의 거리
//서브 트리: 트리 안에서 다시 어떤 노드를 루트로 정하고 그 자손으로 이루어진 트리
//널 트리(null tree): 노드,가지가 없는 트리
//순서 트리와 무순서 트리: 형제 노드의 순서가 잇는지 없는지에 따라 트리를 두 종류로 분리합니다. 형제 노드의 순서를 따지면 순서, 안 따지면 무순서 트리라고 합니다.

//이진 트리(binary tree): 노드가 왼쪽 자식과 오른쪽 자식을 갖는 트리
//완전이진트리(complete binary tree): 루트로부터 노드가 채워져 있으면서 같은 레벨에서는 왼쪽에서 오르쪽으로 노드가 채워져 있는 이진트리
//포화이진트리(full binary tree): 리프노드를 제외한 모든 노드가 두 자식을 가지고 있는 트리
//이진검색트리(binary search tree): 아래 세가지 조건을 만족합니다.
//1. 어떤 노드N을 기준으로 왼쪽 서브 트리 노드의 모든 키 값은 노드 N의 키 값보다 작아야 합니다.
//2. 오른쪽 서브 트리 노드의 키 값은 노드 N의 키 값보다 커야 합니다.
//3. 같은 키 값을 갖는 노드는 없습니다.
//3가지 조건을 모두 만족하게 되면, 중위순회를 통해 키 값의 오름차순으로 노드를 얻을 수 있습니다.
//또한 이분탐색과 비슷한 방식으로 검색이 가능하고, 노드의 삽입이 쉽다는 점 등의 특징이 있어 폭넓게 사용됩니다.

// 순서 트리 탐색 방법 (이진트리를 예로 들어봅니다.)
// 1. 너비우선탐색(bfs): 낮은 레벨에서 시작해 왼쪽에서 오른쪽 방향으로 검색하고 한레벨에서의 검색이 끝나면 다음레벨로 내려갑니다.
// 2. 깊이우선탐색(dfs): 리프까지 내려가면서 검색하는 것을 우선순위로 하는 탐색방법입니다. 리프에 도달해 더 이상 검색을 진행할 곳이 없는 경우에는 부모에게 돌아갑니다. 그런 다음 다시 자식 노드로 내려갑니다. 그 후 다시 부모에게 돌아갑니다. 이러한 과정을 반복합니다. 결국 탐색을 하며 한 노드당 최대 3번을 지나갈 수 있습니다. 출발하면서 노드X를 방문하는경우, 지나가면서 노드A를 방문하는 경우, 되돌아오면서 노드A를 방문하는 경우. 깊이 우선 탐색을 진행하면서 '언제 노드를 방문할지'는 다음과 같이 세 종류로 구분합니다.
//  - 전위순회(preorder): 노드 방문 -> 왼쪽 노드 -> 오른쪽 노드
//  - 중위순회(inorder): 왼쪽 노드 -> 노드 방문 -> 오른쪽 노드
//  - 후위순회(postorder): 왼쪽 노드 -> 오른쪽 노드 -> 노드 방분


// c++ 구현
#include <iostream>
using namespace std;

typedef struct node{
    int data;
    node *leftChild;
    node *rightChild;
} Node;

Node *initNode(int data, Node *leftChild, Node *rightChild) {
    Node *node = new Node;
    node->data = data;
    node->leftChild = leftChild;
    node->rightChild = rightChild;
    return node;
}
//전위순회
void preorder(Node *root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->leftChild);
        preorder(root->rightChild);
    }
}
//중위순회
void inorder(Node *root) {
    if (root) {
        inorder(root->leftChild);
        cout << root->data << " ";
        inorder(root->rightChild);
    }
}
//후위순회
void postorder(Node *root) {
    if (root) {
        postorder(root->leftChild);
        postorder(root->rightChild);
        cout << root->data << " ";
    }
}
int main(void) {
    Node *n7 = initNode(50, NULL, NULL);
    Node *n6 = initNode(37, NULL, NULL);
    Node *n5 = initNode(23, NULL, NULL);
    Node *n4 = initNode(5, NULL, NULL);
    Node *n3 = initNode(48, n6, n7);
    Node *n2 = initNode(17, n4, n5);
    Node *n1 = initNode(30, n2, n3);
    
    preorder(n1);
    cout << "\n";
    inorder(n1);
    cout << "\n";
    postorder(n1);
    cout << "\n";
    
}
