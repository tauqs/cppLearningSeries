#pragma once
#include <string>
#include <iostream>

class IVoiceElement
{
public:
	virtual void Play(std::string txt) = 0;
	virtual void Pause() = 0;
	void Stop() {std::cout<<"Stop"<<std::endl;}
	virtual void Log(std::string log)
	{
		std::cout<<log<<std::endl;
	}
	//virtual ~IVoiceElement() = default;
};
