#include <iostream>
#include <thread>
using namespace std;

int limit = 100;

void f1()
{
	for (int i=1; i<limit; i+=2)
	{
		cout << "f1: "<< i << endl;
	}
}

int main1()
{
	thread t(f1);
	
	for (int i=2; i<limit; i+=2)
	{
		cout << "main: "<< i << endl;
	}
	
	t.join();
	
	return 0;
}

mutex mu;

void print(const string &msg)
{
	mu.lock();
	cout << msg <<endl;
	mu.unlock();
}

void print(const string &msg)
{
	lock_guard<mutex> lock(mu);
	cout << msg <<endl;
}

void f2()
{
	for (int i=1; i<limit; i+=2)
	{
		print("f1: " + to_string(i));
	}
}

int main()
{
	thread t(f2);
	
	for (int i=2; i<limit; i+=2)
	{
		print("main: " + to_string(i));
	}
	
	t.join();
	
	return 0;
}

