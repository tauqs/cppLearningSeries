#include <iostream>
#include <thread>
using namespace std;

int limit = 100;
mutex mu1;
mutex mu2;

void print1(const string &msg)
{
	lock_guard<mutex> lock1(mu1);
	lock_guard<mutex> lock2(mu2);
	cout << msg <<endl;
}


void print2(const string &msg)
{
	lock_guard<mutex> lock1(mu2);
	lock_guard<mutex> lock2(mu1);
	cout << msg <<endl;
}


void f1()
{
	for (int i=1; i<limit; i+=2)
	{
		print1("f1: " + to_string(i));
	}
}

int main1()
{
	thread t(f1);
	
	for (int i=2; i<limit; i+=2)
	{
		print2("main: " + to_string(i));
	}
	
	t.join();
	
	return 0;
}


void print3(const string &msg)
{
	lock(mu1,mu2);
	lock_guard<mutex> lock1(mu1, adopt_lock);
	lock_guard<mutex> lock2(mu2, adopt_lock);

	cout << msg <<endl;
}

void print4(const string &msg)
{
	lock(mu1,mu2);
	lock_guard<mutex> lock1(mu1, adopt_lock);
	lock_guard<mutex> lock2(mu2, adopt_lock);

	cout << msg <<endl;
}


void f2()
{
	for (int i=1; i<limit; i+=2)
	{
		print3("f1: " + to_string(i));
	}
}

int main()
{
	thread t(f2);
	
	for (int i=2; i<limit; i+=2)
	{
		print4("main: " + to_string(i));
	}
	
	t.join();
	
	return 0;
}
