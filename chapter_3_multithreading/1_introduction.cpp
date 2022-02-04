#include <iostream>
#include <thread>
using namespace std;

void func1()
{
	cout << "This is func1"<<endl;
}

void func2(int a, int b)
{
	cout <<"Sum: "<< a + b <<endl;
}

/* Introduction */
int main1()
{
	thread t1(func1);
	
	t1.join(); // main thread waits for t1 to finish
	
	return 0;
}

int main11()
{
	thread t1(func2, 4, 5); // t1 starts running
	
	t1.join(); // main thread waits for t1 to finish
	
	return 0;
}


int main()
{
	thread t1(func1); // t1 starts running
	t1.detach(); // t1 will run freely on its own (daemon process)
	//t1.join(); // main thread waits for t1 to finish
	
	if (t1.joinable())
	{
		t1.join();
	}
	
	return 0;
}


int main13()
{
	int a=-4, b=5;
	thread t1([a,b](){
		cout << a + b <<endl;
	}); // t1 starts running
	
	t1.join();
	return 0;
}

int main14()
{
	int a=-4, b=5;
	thread t1([a,b](int c){
		cout << a + b + c<<endl;
	}, 10); // t1 starts running
	
	t1.join();
	return 0;
}


int main2()
{
	thread t(func1);
	this_thread::sleep_for(chrono::milliseconds(1000));
	cout<<"main"<<endl;
	//t.detach();
	
	if (t.joinable())
	{
		t.join();
	}
	 t.join();
	return 0;
}


/* Thread Mangaement */
void f1()
{
	cout<<"f1"<<endl;
}

int main3()
{
	thread t(f1);

	for(int i=0; i<100; i++)
	{
		cout<<"main says - "<<i*10<<endl;
	}

	t.join();
	return 0;
}


int main4()
{
	thread t(f1);
	
	try
	{
		for(int i=0; i<100; i++)
		{
			cout<<"main says - "<<i*10<<endl;
		}
	} catch (...) {
		t.join();
		throw;
	}

	t.join();
	return 0;
}
