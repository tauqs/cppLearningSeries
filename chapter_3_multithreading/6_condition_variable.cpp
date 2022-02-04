#include <iostream>
#include <thread>
#include <queue>
using namespace std;

/*
deque<int> q;
mutex mu;

void function_1()
{
	int count = 10;
	while(count > 0)
	{
		unique_lock<mutex> locker(mu);
		q.push_front(count);
		locker.unlock();
		this_thread::sleep_for(chrono::milliseconds(1));
		count--;
	}
}

void function_2()
{
	int data = 0;
	while(data!=1)
	{
		unique_lock<mutex> locker(mu);
		if(!q.empty())
		{
			data =  q.back();
			q.pop_back();
			locker.unlock();
			cout<<"f2 got value from f1: "<<data<<endl;
		}
		else{
			locker.unlock();
			this_thread::sleep_for(chrono::milliseconds(10));
		}
	}
}

int main()
{
	thread t1(function_1);
	thread t2(function_2);
	t1.join();
	t2.join();
	return 0;
}
*/

deque<int> q;
mutex mu;
condition_variable cond;

void function_1()
{
	int count = 10;
	while(count > 0)
	{
		unique_lock<mutex> locker(mu);
		q.push_front(count);
		locker.unlock();
		cond.notify_one();
		// cond.notify_all();
		this_thread::sleep_for(chrono::milliseconds(1));
		count--;
	}
}

void function_2()
{
	int data = 0;
	while(data!=1)
	{
		unique_lock<mutex> locker(mu);

		cond.wait(locker);
		// cond.wait(locker, []() {return !q.empty();});
		
		data =  q.back();
		q.pop_back();
		locker.unlock();
			
		cout<<"f2 got value from f1: "<<data<<endl;
	}
}

int main()
{
	thread t1(function_1);
	thread t2(function_2);
	t1.join();
	t2.join();
	return 0;
}

 
 
