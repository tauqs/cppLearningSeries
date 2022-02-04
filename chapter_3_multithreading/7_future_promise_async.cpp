#include <iostream>
#include <thread>
#include <queue>
#include <future>
using namespace std;

int limit = 10;

int func1()
{
	int res=1;
	for (int i = 1; i < 10; i+=2)
	{
		res*=i;
	}
	return res;
}

int func2()
{
	int res=1;
	for (int i = 2; i <= 10; i+=2)
	{
		res*=i;
	}
	return res;
}


int main1()
{
	future<int> f1 = async(func1);
	future<int> f2 = async(func2);
	
	int res1 = f1.get();
	int res2 = f2.get();
	int factorial = res1*res2;
	
	cout<<"Factorial: "<<factorial<<endl;
	
	return 0;
}

int main2()
{
	future<int> f1 = async(std::launch::deferred,func1);
	// future<int> f1 = async(std::launch::async,func1);
	// future<int> f1 = async(std::launch::async | std::launch::deferred,func1);
	
	future<int> f2 = async(func2);
	
	int res1 = f1.get();
	int res2 = f2.get();
	int factorial = res1*res2;
	
	cout<<"Factorial: "<<factorial<<endl;
	
	return 0;
}

int func3(std::future<int> &f)
{
	int res=1;
	int n = f.get(); // exceptiom: std::future_errc::broken_promise
	for (int i = 1; i < n; i+=2)
	{
		res*=i;
	}
	return res;
}

int func4()
{
	int res=1;
	for (int i = 2; i <= 10; i+=2)
	{
		res*=i;
	}
	return res;
}

int main3()
{
	std::promise<int> p;
	std::future<int> f = p.get_future();
	
	std::future<int> f1 = std::async(func3, std::ref(f));
	std::future<int> f2 = std::async(func4);
		
	p.set_value(10);
	// p.set_exception(std::make_exception_ptr(std::runtime_error("Error setting promised value"));
	
	int res1 = f1.get();
	int res2 = f2.get();
	int factorial = res1*res2;
	
	cout<<"Factorial: "<<factorial<<endl;
	
	return 0;
}

int func5(std::shared_future<int> f)
{
	int res=1;
	int n = f.get(); // exceptiom: std::future_errc::broken_promise
	for (int i = 1; i < n; i+=2)
	{
		res*=i;
	}
	return res;
}

int func6(std::shared_future<int> f)
{
	int res=1;
	int n = f.get();
	for (int i = 2; i <= n; i+=2)
	{
		res*=i;
	}
	return res;
}

int main()
{
	std::promise<int> p;
	std::future<int> f = p.get_future();
	std::shared_future<int> sf = f.share();
	
	std::future<int> f1 = std::async(func5, sf);
	std::future<int> f2 = std::async(func6, sf);
		
	p.set_value(10);

	
	int res1 = f1.get();
	int res2 = f2.get();
	int factorial = res1*res2;
	
	cout<<"Factorial: "<<factorial<<endl;
	
	return 0;
}

 
 

