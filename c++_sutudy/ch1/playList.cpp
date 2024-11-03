#include <iostream>

//원형 리스트 정의
/**
 * 리스트의 원소에 차례대로 접근할 경우, 마지막 노드의 다음은 다시 첫
번째 노드가 되어야 한다. 이러한 구조를 원형 연결 리스트라 한다.
 
 기능은 다음과 같다.
1. 여러 개의 음악을 이용하여 재생 목록을 생성할수 있습니다.
2. 재생 목록에 음악을 추가할 수 있어야 합니다.
3. 재생 목록에서 음악을 제거할 수 있어야 합니다.
4. 음악을 순환적으로 재생할 수 있어야 합니다(이 기능의 구현은 노래 제목 출력으로 대신합니다)
 
 
 응용 프로그램 개발 순서는 다음과 같습니다.
1. 먼저 원형 데이터 표현을 지원하는 기본 구조를 설계합니다.
2. 앞에서 만든 구조에 데이터 삽입 및 삭제 기능을 구현합니다.
3. 사용자 정의 반복자를 작성합니다. 이 부분이 조금 까다로울 수 있습니다. 범위 기반 for 반복
문을 사용하여 모든 원소에 접근할 수 있도록 반복자를 설계해야 합니다. 그러므로 자료 구조
는 원형이지만 begin()과 end() 함수는 각각 다른 주소를 반환해야 합니다.
4. 기본 컨테이너를 만든 후, 이 컨테이너를 기반으로 재생 목록에 여러 음악을 저장하고 nextO,
previousO, printallO, insertO, removeO 같은 함수를 작성합니다.
 */
template <typename T>
struct Node
{
	T* data;
	Node* next;
	Node* prev;

/**
 *  생성자는 초기화 소멸자는 청소
 */
	~cir_list_node()
	{
		delete data;
	}
};

template <typename T>
struct cir_list
{

public:
	using node = Node<T>;
	using node_ptr = node*; //node pointer

//구조체 맴버 변수 설정
private:
	node_ptr head;
	//부호 없는 정수형 보통 메모리 크기나 배열의 인덱스와 같은 값의 저장
	size_t n;

public:
//초기화 블럭
	cir_list() : n(0)
	{
		head = new node {NULLint& countRef = count;, NULL, NULL}; // 모두 NULL로 구성된 기본 노드
		head->next = head;
		head->prev = head;
	}

	size_t size() const
	{
		return n;
	}

//참조로 값 전달하기
	void insert(const T& value)
	{
		node_ptr newNode = new node {
			new T(value), NULL, NULL
		};

		n++;
		//타입 추록 auto
		auto dummy = this.head->prev; //여기서 prev 이전 node를 가리키는 pointer
		dummy->next = newNode; //이전 node 를 새로운 노드에 연결
		newNode->prev = dummy; //
		if (head == dummy)
		{
			dummy->prev = newNode;
			newNode->next = dummy;
			head = newNode;
			return;
		}
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}


	void erase(const T& value)
	{
		auto cur = head, dummy = head->prev;
		while (cur != dummy)
		{
			if (*(cur->data) == value)
			{
				cur->prev->next = cur->next;
				cur->next->prev = cur->prev;
				if (cur == head)
					head = head->next;
				delete cur;
				n--;
				return;
			}
			cur = cur->next;
		}
	}
}

struct playlist
{
	cir_list<int> list;

	void insert(int song)
	{
		list.insert(song);
	}

	void erase(int song)
	{
		list.erase(song);
	}

	void loopOnce()
	{
		for (auto& song : list)
			std::cout << song << " ";
		std::cout << std::endl;
	}
};

int main()
{
	playlist pl;
	pl.insert(1);
	pl.insert(2);
	std::cout << "재생 목록 : ";
	pl.loopOnce();

	playlist pl2 = pl;
	pl2.erase(2);
	pl2.insert(3);
	std::cout << "두 번째 재생 목록 : ";
	pl2.loopOnce();
}
