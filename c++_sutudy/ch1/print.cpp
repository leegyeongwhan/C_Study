#include <iostream>
#include <queue>

/**
 * 이 클래스는 작업 ID, 인쇄 요청을 한 사용자 이름,인쇄 페이지 수 등으로 구성됩니다.
 */

class Job {
private:
    std::string user;
    int page;
    int id;

    static int count;


public:
     Job(const std::string& u, int p) : user(u), page(p), id(++count) {     }

// operator<< 연산자 오버로딩 (friend 없이 구현)

	friend std::ostream& operator<<(std::ostream& os, const Job& j)
	{
          //friend 를 통해서 
		os << "id: " << j.id << ", 사용자: " << j.user << ", 페이지수: " << j.page << "장";
		return os;
	}
};


int Job::count = 0;

/**
 * 이 클래스는 새 인쇄 작업을 추가하고, 현재까지 추가된 모든 인쇄 작업을 처리하는 기능을 제공합니다.
 */
template <size_t N>
class Priter{
     std::queue<Job> jobs;

public:
     bool add(const Job& job)
	{
		if (jobs.size() == N)
		{
			std::cout << "인쇄 대기열에 추가 실패: " << job << std::endl;
			return false;
		}

		std::cout << "인쇄 대기열에 추가: " << job << std::endl;
		jobs.push(job);
		return true;
	}

     void print(){
		while (not jobs.empty())
		{
			std::cout << "인쇄 중: " << jobs.front() << std::endl;
			jobs.pop();
		}
     }

};

int main(){
     Priter<5> printer; // 5 번의작업
     
     Job j1("감자", 10);
     printer.add(j1);

     printer.print();
}