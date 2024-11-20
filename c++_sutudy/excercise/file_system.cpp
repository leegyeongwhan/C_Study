#include <iostream>
#include <vector>
#include <algorithm>

/*
N-항 트리를 이용하여 디렉터리 이동, 파일/디렉터리 검색. 파일/디렉터리 추가, 파일/디렉터리
목록 출력 등의 기능을 지원하는 파일 시스템 자료 구조를 구성하세요. 이 트리는 파일 시스템의
모든 원소(파일 또는 디렉터리)에 대한 계층 구조(경로)와 정보를 가지고 있어야합니다
*/
using namespace std;

struct Node
{
	string name;
	bool is_dir;
	vector<Node*> children;
};


struct FileSystem
{
	using node = Node;
	using node_ptr = node*;

private:
	node_ptr root;
	node_ptr cwd; //currentDir

public:
    FileSystem()
    {
        root = new node{"/", true,{}}; //단일 디렉터리 루트(/)로 트리를 초기화합니다.
        cwd = root; // 처음에는 루트를 현재 디렉토리로 설정
    }


    node_ptr find()
    {

    }   

private:
    node_ptr find_impl()
    {

    }

public:
    bool add(const string& path, bool is_dir)
    {
        if (path[0] == '/')
		{
			return add_impl(root, path.substr(1), is_dir); //루트 디렉토리부터
		}
		else
		{
			return add_impl(cwd, path, is_dir);
		}
    }   

 private:
	bool add_impl(node_ptr directory, const string& path, bool is_dir)
    {
        if (not directory->is_dir)
		{
			cout << directory->name << "은(는) 파일입니다." << endl;
			return false;
		}

        auto sep = path.find('/');

        if (sep == string::npos)
		{
			auto found = find_if(directory->children.begin(), directory->children.end(), [&](const node_ptr child) {
				return child->name == path;
				});

			if (found != directory->children.end())
			{
				cout << directory->name << "에 이미 " << path << " 이름의 파일/디렉토리가 있습니다." << endl;
				return false;
			}
                //push back 잠깐 저장
			directory->children.push_back(new node {path, is_dir, {}});
			return true;
		}

        // path에 '/'가 있는 경우, 즉, 디렉토리 이름을 포함하고 있는 경우.
		std::string next_dir = path.substr(0, sep);
		auto found = find_if(directory->children.begin(), directory->children.end(), [&](const node_ptr child) {
			return child->name == next_dir && child->is_dir;
			});

		if (found != directory->children.end())
		{
			return add_impl(*found, path.substr(sep + 1), is_dir);
		}

		// path에 디렉토리 이름이 포함되어 있지만, 해당 디렉토리가 없는 경우.
		std::cout << directory->name << "에 " << next_dir << " 이름의 디렉토리가 없습니다." << std::endl;
		return false;
    }


public:
	bool change_dir()
    {

    }


public:
	void show_path()
    {

    }
};

int main()
{
    FileSystem fs;
    fs.add("user",true);
    fs.add("user_file",false); // false 는 파일
}