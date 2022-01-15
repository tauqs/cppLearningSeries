#include <iostream>
#include "ReadAloudCore.h"
#include "IVoiceElement.h"

using namespace std;

class ReadAloudIOS : public IVoiceElement
{
public:
	void Play(std::string txt)
	{
		cout<<"..... Playing ......"<<endl<<txt<<endl<<"........."<<endl;
	}
	
	void Pause()
	{

	}
	
	void Stop()
	{
		cout<<"ReadAloudIOS: ";
		cout<<"Stop"<<endl;
	}
	
//	void Log(std::string log)
//	{
//		cout<<"ReadAloudIOS: ";
//		cout<<log<<endl;
//	}
};

int main()
{
	shared_ptr<ReadAloudIOS> raIOS = make_shared<ReadAloudIOS>();
	
	ReadAloudCore rac(raIOS);

	rac.Play();
	
	return 0;
}
