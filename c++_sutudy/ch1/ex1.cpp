#include <iostream>
#include <algorithm>
#include <sstream>

//동적 배열

//템플릿 지네릭스와 비슷한 역할
template <typename T>
class dynamic_array
{
	T* data;
    // 어떤 타입의 사이즈든지 나타낼 수 있는 충분한 bytes를 가진 unsigned integer
	size_t n;

public:
    //생성자
	dynamic_array(int n)
	{
		this->n = n;
		data = new T[n];
	}
    
    //복사 생성자  깊은 복사 depp copy
	dynamic_array(const dynamic_array<T>& other)
	{
		n = other.n;
		data = new T[n];

		for (int i = 0; i < n; i++)
			data[i] = other[i];
	}

    //operator 연산자를 통해 클래스의 객체를 배열처럼 사용할 수 있도록 한다.
    //ex
    //          dynamic_array<int> arr(5);
    //          arr[0] = 10;  // 배열처럼 사용 가능
    //          int x = arr[0];  // 배열처럼 값 읽기 가능
    //
	T& operator[](int index)
	{
		return data[index];
	}

	const T& operator[](int index) const
	{
		return data[index];
	}

	T& at(int index)
	{
		if (index < n)
			return data[index];
		throw "Index out of range";
	}

	size_t size() const
	{
		return n;
	}

    //소멸자 메모리를 해제하는 역할  delete[]를 사용해서한다.
    //객체의 수명이 끝나면 자동으로 호출
	~dynamic_array()
	{
		delete[] data; // 메모리 릭 방지
	}

	T* begin() { return data; }
	const T* begin() const { return data; }
	T* end() { return data + n; }
	const T* end() const { return data + n; }
 
    //친구 함수   친구 함수는 비공개 멤버에 접근할 수 있다.
	friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2)
	{
		dynamic_array<T> result(arr1.size() + arr2.size());
		std::copy(arr1.begin(), arr1.end(), result.begin());
		std::copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

		return result;
	}

	std::string to_string(const std::string& sep = ", ")
	{
		if (n == 0)
			return "";

		std::ostringstream os;
		os << data[0];

		for (int i = 1; i < n; i++)
			os << sep << data[i];

		return os.str();
	}
};

struct student
{
	std::string name;
	int standard;
};

std::ostream& operator<<(std::ostream& os, const student& s)
{
	return (os << "[" << s.name << ", " << s.standard << "]");
}

int main()
{
	int nStudents;
	std::cout << "1반 학생 수를 입력하세요: ";
	std::cin >> nStudents;

	dynamic_array<student> class1(nStudents);
	for (int i = 0; i < nStudents; i++)
	{
		std::string name;
		int standard;
		std::cout << i + 1 << "번째 학생 이름과 나이를 입력하세요: ";
		std::cin >> name >> standard;
		class1[i] = student{name, standard};
	}

	// 배열 크기보다 큰 인덱스의 학생에 접근
	try
	{
		// 아래 주석을 해제하면 프로그램이 비정상 종료합니다.
		// class1[nStudents] = student {"John", 8}; // 예상할 수 없는 동작
        // 범위를 벗어날경우
		class1.at(nStudents) = student{"John", 8}; // 예외 발생
	}
	catch (...)
	{
		std::cout << "예외 발생!" << std::endl;
	}

	// 깊은 복사
	auto class2 = class1;
	std::cout << "1반을 복사하여 2반 생성: " << class2.to_string() << std::endl;

	// 두 학급을 합쳐서 새로운 큰 학급을 생성
	auto class3 = class1 + class2;
	std::cout << "1반과 2반을 합쳐 3반 생성 : " << class3.to_string() << std::endl;

	return 0;
}
