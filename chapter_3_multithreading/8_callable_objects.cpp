#include <iostream>
#include <thread>
#include <queue>
#include <future>
using namespace std;


class A {
	
public:

	void f(int x, char c)
	{
		cout<<"f called with x:"<<x<<", c:"<<c<<endl;
	}
	
	int operator()(int N)
	{
		cout<<"() called with N:"<<N<<endl;
		return 0;
	}
};


int main() {
	A a;

	std::thread t1(a, 6);
	std::async(a, 6);

	std::thread t2(a, 6);
	std::thread t3(std::ref(a), 6);
	std::thread t4(std::move(a), 6);
	
	std::thread t5([](int x){return x*x;}, 6);

	std::thread t6(&A::f, a, 56, 'z');  // copy_of_a.f(56, 'z')
	std::thread t7(&A::f, &a, 56, 'z');  // a.f(56, 'z')

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	return 0;
}


