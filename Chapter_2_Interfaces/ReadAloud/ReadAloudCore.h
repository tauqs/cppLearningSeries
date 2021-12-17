#pragma once
#include "IVoiceElement.h"

class ReadAloudCore
{
	std::string GetText();
	std::shared_ptr<IVoiceElement> m_voiceElement;
	
public:
	ReadAloudCore(std::shared_ptr<IVoiceElement> voiceElement);
	void Play();
};
