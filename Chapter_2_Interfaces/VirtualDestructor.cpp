#include <iostream>
 
using namespace std;
 
class base {
  public:
	base()
	{ cout << "Constructing base\n"; }
	void fun() { cout<<"Fun Base\n";}
	~base()
	{ cout<< "Destructing base\n"; }
};
 
class derived: public base {
  public:
	derived()
	 { cout << "Constructing derived\n"; }
	//void fun() { cout<<"Fun Derived\n";}
	~derived()
	   { cout << "Destructing derived\n"; }
};
 
int main()
{
  derived *d = new derived();
  base *b = d;
  delete b;
  
  return 0;
}
