#include "ReadAloudCore.h"

ReadAloudCore::ReadAloudCore(std::shared_ptr<IVoiceElement> voiceElement)
{
	m_voiceElement = voiceElement;
}

std::string ReadAloudCore::GetText()
{
	return "This is the text to be played";
}


void ReadAloudCore::Play()
{
	std::string text = GetText();
	m_voiceElement->Play(text);
//	m_voiceElement->Log("ReadAloudCore::Play Invoked");
//	m_voiceElement->Stop();
}

