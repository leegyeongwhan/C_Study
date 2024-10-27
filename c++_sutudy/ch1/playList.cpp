#include <iostream>

template <typename T>
struct cir_list_node
{
	T* data;
	cir_list_node* next;
	cir_list_node* prev;

	~cir_list_node()
	{
		delete data;
	}
};

//마지막 Node 가 첫 번째 Node를 가리키는게 핵심
template <typename T>
struct circle_list
{
public:
	using node = circle_list_node<T>;
	using node_ptr = node*;

private:
	node_ptr head;
	size_t n;

};


struct playList
{
    circle_list<int> list;

	void insert(int song)
	{

	}

	void erase(int song)
	{

	}

	void loopOnce()
	{

	}
};


int main()
{
	playList pl;
	pl.insert(1);
	pl.insert(2);
	std::cout << "재생 목록 : ";
	pl.loopOnce();
}
