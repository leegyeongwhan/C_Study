#include <iostream>


/**
 * BigO
 *  평균: O(log n)
    최악: O(N)
    최선: O(1)
   보통은 0log n 으로 끝난다 트리가 극단적으로 한줄로 되어있지 않은 이상

  기본적인 컨셉은 각 노드가 최대 두 개의 자식 노드를 가지며, 왼쪽 자식 노드는 부모 노드보다 작은 값을,
  오른쪽 자식 노드는 부모 노드보다 큰 값을 가진다. 이진 탐색 트리는 효율적인 검색, 삽입, 삭제를 가능하게 합니다.


   장점: 어떤 요소를 넣는다고했을때 3가의 스텝으로 진행될 것이다 1)검색, 2)비교, 3)삽입
   선형적인 배열, 힙은 불리하다 하지만 이진 탐색 트리는 0(log n)으로 유리하다
   만약 특정 데이터를 삭제해야 하더라도 삭제한 부분을 제거하고 Node들 끼리의 연결을 적절히 잘 이어주면 된다.

    단점: 위에서 말했 듯 최악의 경우에는 O(N)가능 -> But 극단적인 상황

  이진트리와 이진탐색트리의 같은점 다른점:
  이진탐색트리는 기본적으로 왼쪽 자식노드와 오른쪽 자식노드를 가질수 있다는 점에서 이진트리와 같은 구조
  이진탐색트리에서 루트노드를 기준으로 왼쪽서브트리는 루트노드보다 작은값들로만 이루어져있고,
  오른쪽 서브트리는 루트노드보다 큰 값들로만 이루어져 있다. 이것이 이 둘의 차이입니다. 

  정의 : 좌우 하위 트리는 각각이 다시 이진 탐색 트리여야 한다.
 */
struct node
{
	int data;
	node* left;
	node* right;
};

struct bst
{
   node* root = nullptr;

   //탐색
   /**
    * 루트 노드부터 시작하여 찾을 값과 크기를 비교하며 내려오면서 찾으면 된다.
      찾으려는 값 < 현재 트리의 루트 노드의 값
     왼쪽 서브트리로 내려간다. (-> 해당 노드보다 작은 값들 범위로) -> 여기서 알 수 있는 사실은 이진 탐색 트리를 자르더라도
     그부분은 에서 부터 트리 구조는 이어진다
     
     찾으려는 값 > 현재 트리의 루트 노드의 값
     오른쪽 서브트리로 내려간다. (-> 해당 노드보다 큰 값들 범위로)

    일치하는 값을 찾을 때까지 위 과정을 재귀적으로 반복한다.
    */
public:  
    node* find(int value){
		return find_impl(root, value);
	}

private:
	node* find_impl(node* current, int value){
		if(!current){
            std::cout << std::endl;
			return NULL;
        }

        if(current->data == value){
			std::cout << value << "을(를) 찾았습니다." << std::endl;
			return current;
        }

        if (value < current->data) // value 값이 현재 노드 왼쪽에 있는 경우
		{
			std::cout << current->data << "에서 왼쪽으로 이동: ";
			return find_impl(current->left, value);
		}

		// value 값이 현재 노드 오른쪽에 있는 경우
		std::cout << current->data << "에서 오른쪽으로 이동: ";
		return find_impl(current->right, value);
	}


   //삽입
   /**
    * 새 노드가 삽입될 적합한 위치 또한 이진 탐색으로 찾아야 한다. 그래서 위의 탐색 함수와 비슷하다.
     이진 탐색 트리에 “추가” 된다는 것은 곧 조상부터 크기를 비교며 내려오면서 누군가의 왼쪽, 오른쪽 자식으로 세팅된다는 것이다.
  이진 탐색 트리 규칙을 만족하면서 각 레벨 마다 왼쪽 혹은 오른쪽 서브트리를 선택하면서  내려오다가 자식이 없는 Leaf 노드에 도달하면 그 곳에 추가된다.
    */
public:
    void insert(int value){
        if(!root){
            root = new node {value, NULL, NULL};
        }else{
            insert_impl(root,value);
        }
    }

private:
	void insert_impl(node* current, int value)
	{
		if(value < current->data){
            if(!current->left){  //계속해서 좌측 Node가 비어있다면 이곳이 Leaf 
              current->left = new node{value, NULL,NULL};
            }else{
                insert_impl(current->left,value); //재귀
            }
        }else{
            if(!current->right){
				current->right = new node {value, NULL, NULL};
            }else{
                insert_impl(current->right, value);
            }
        }
	}

   //순회
public:   
    void preorder()
	{
		BST_PreOrder(root);
	}

   void inorder()
	{
		BST_InOrder(root);
	}

   void postorder()
	{
		BST_PostOrder(root);
	}

private:
   //1.전위:내려가기 전 출력 (두 서브트리 순회 전)
void BST_PreOrder(node* tree)
{
    if (tree == NULL)
        return;
    std::cout << tree->data << " ";	// 현재 노드 출력
     BST_InOrder(tree->left);
    BST_InOrder(tree->right);
}
   //2.중위 :왼쪽 서브트리 순회 전부 마치고 돌아온 후 출력 후 오른쪽 서브트리 순회
   //  이진 검색 트리를 “중위 순회” 하면 정렬된 순서대로 출력이 된다.

void BST_InOrder(node* tree)
{
    if (tree == NULL)
        return;
    BST_InOrder(tree->left);
    std::cout << tree->data << " ";	// 현재 노드 출력
    BST_InOrder(tree->right);
    
}
   //3.후위 :왼쪽 서브트리 순회, 오른쪽 서브트리 순회 전부 다 마치고 돌아온 후에 출력
   void BST_PostOrder(node* tree)
{
    if (tree == NULL)
        return;
    BST_InOrder(tree->left);
    BST_InOrder(tree->right);
   std::cout << tree->data << " ";	// 현재 노드 출력

}

   //삭제
/**
 * 진 탐색 트리에서의 노드 삭제는 삭제하려는 노드의 자식이 몇 개냐에 따라 삭제 방법이 다르다.

Case
1. 삭제할 노드의 서브트리가 0 개일 때  -> 둘다 없는 경우
2. 삭제할 노드의 서브트리가 1 개일 때  -> 왼쪽 또는 오른쪽
3. 삭제할 노드의 서브트리가 2 개일 때 -> 자식노드 둘다 있는경우
삭제할 노드의 부모와 삭제할 노드의 자식을 연결지어 주어야 하기 때문에 삭제할 노드의 부모가 누군지에 대한 정보도 가지고 있어야 한다.
 */


public:

    node* successor(node* start)
	{
		auto current = start->right;
		while (current && current->left)
			current = current->left;
		return current;
	}
/*
successor(start)는 현재 노드(start)의 오른쪽 서브트리에서
가장 왼쪽에 있는 노드를 찾습니다. 이 노드는 start보다 큰 값 중에서 가장 작은 값입니다.
 */

	void deleteValue(int value)
	{
		root = delete_impl(root, value);
	}

private:
	node* delete_impl(node* start, int value)
	{
		if (!start)
			return NULL;

        if(value < start-> data){
            start->left = delete_impl(start->left, value);
        }else if (value > start->data){
            start->right = delete_impl(start->right, value);
        }else{ //일치
        
			if (!start->left) // 자식 노드가 전혀 없거나, 왼쪽 자식 노드만 없는 경우
            {
                auto tmp = start->right; //자식이 둘다없으면 여기서 null로 처리
                delete start;
                return tmp;
            }
            if(!start->right){ //오른쪽만 없는 경우
                auto tmp = start->left;
				delete start;
				return tmp;
            }

            // 자식 노드가 둘 다 있는 경우
			auto succNode = successor(start); //삭제할 오른쪽 서브트리의 노드중 가장 작은값 호출
			start->data = succNode->data; //현재 노드의 값을 후계자의 값으로 대체

            // 오른쪽 하위 트리에서 후계자(successor)를 찾아 삭제
			start->right = delete_impl(start->right, succNode->data);
        }

		return start;
	}
};


int main(){
    bst tree;
    tree.insert(5);
	tree.insert(8);
	tree.insert(12);
	tree.insert(3);
	tree.insert(9);


	std::cout << "중위 순회: ";
	tree.inorder();
	std::cout << std::endl;

	tree.deleteValue(12);
	std::cout << "12를 삭제한 후 중위 순회: ";
	tree.inorder();
	std::cout << std::endl;

    if(tree.find(3)){
        std::cout << "원소 3은 트리에 있습니다" << std::endl;
    }else
		std::cout << "원소 12는 트리에 없습니다." << std::endl;
}
