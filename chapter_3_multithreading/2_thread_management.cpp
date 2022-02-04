#include <iostream>
#include <thread>
using namespace std;

void f1()
{
	cout<<"this is f1"<<endl;
}

int main1()
{
	thread t(f1);
	// Using RAII - Resource Allocation in Initialisation
	Wrapper w(t1)
	
	try
	{
		for(int i=0; i<100; i++)
		{
			cout<<"main says - "<<i*10<<endl;
			// throw std::invalid_argument( "received negative value" );
		}
	} catch (...) {
		t.join();
	}
	
	if (t.joinable())
		t.join();
	
	return 0;
}

void f2(string msg)
{
	msg = "F1 msg";
	cout<<msg<<endl;
}

int main2()
{
	string msg = "main msg";
	thread t(f2, msg);
	//thread t(f2, std::ref(msg));
	//thread t(f2, std::move(msg));
	
	t.join();
	
	cout<<msg<<endl;

	return 0;
}

void f3(string msg)
{
	msg = "F1 msg";
	cout<<msg<<endl;
}

int main()
{
	string msg = "main msg";
	thread t(f3, std::move(msg));
	
	t.join();
	
	cout<<msg<<endl;

	return 0;
}
