//대형 프로젝트에서 여러사람들이
// 같은 함수,클래스 이름이 중복되어 사용될수있음
//이름 해결하고자 나온 것이
//namespace (이름 공간)
#include <iostream>

//당연히 이런 상황에서는 에러가난다

 namespace Mysapce1
{
    namespace inner_myspace
    {
        //이것도 가능
    }
    int doFunction(int a)
    {
    return a;
    }
}

 namespace Mysapce2
{
    int doFunction(int a)
    {
    return a;
    }
}

using namespace std;
using namespace Mysapce1;
int main()
{
    doFunction(5); // myspace1
    cout << Mysapce1::doFunction(3) << endl;
    cout << Mysapce2::doFunction(5) << endl;
    return 0;
}

