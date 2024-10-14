#include <array>
#include <iostream>
#include <type_traits>

template<typename ... Args>
//auto란 tpye 추론 lamda할 때도 유용하게 사용

//std::common_type 여러 타입의 공통 타입을 결정 std::common_type<Args...>::type 이부분이 인자들의 공통 타입을 찾는다.
// 이 함수는 결국 arg(가변인자)를 받아 std::arraty를 return한다.
                                                                                    //<여기까지가 반환 타입>
auto build_array(Args&&... args) -> std::array<typename std::common_type<Args...> 
::type, sizeof...(args)>
{
	using commonType = typename std::common_type<Args...>::type;
	return {std::forward<commonType>((Args&&)args)...};
}

int main()
{
	auto data = build_array(1, 0u, 'a', 3.2f, false);

	for (auto i : data)
		std::cout << i << " ";
	std::cout << std::endl;

	// 하나의 공통 타입으로 변환할 수 없으므로 
	// 아래 코드는 에러가 발생합니다.
	// auto data2 = build_array(1, "Packt", 2.0);
}
