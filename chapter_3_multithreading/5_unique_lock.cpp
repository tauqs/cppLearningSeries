#include <iostream>
#include <thread>
using namespace std;

int limit = 10;
mutex mu;

void factorial(int n)
{
	unique_lock<mutex> lock1(mu);
	cout << "Factorial of: "<<n<<endl;
	lock1.unlock();
	
	long long fact = 1;
	for (int i=1; i<=n; i++)
	{
		fact *= i;
	}
	
	lock1.lock();
	cout <<fact<<endl;
	lock1.unlock();
}

void factorial1(int n)
{
	unique_lock<mutex> lock1(mu, defer_lock);
	
	long long fact = 1;
	for (int i=1; i<=n; i++)
	{
		fact *= i;
	}
	
	lock1.lock();
	cout <<fact<<endl;
	lock1.unlock();
}


void f1()
{
	for (int i=1; i<limit; i+=2)
	{
		factorial(i);;
	}
}

int main()
{
	thread t(f1);
	
	for (int i=2; i<limit; i+=2)
	{
		factorial(i);
	}
	
	t.join();
	
	return 0;
}
