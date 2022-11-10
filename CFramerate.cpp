#include "CFramerate.h"

/*
	Method calculate framerate
	@return Framerate as float
*/
float CFramerate::CalculateFramerate()
{
	sf::Time currenTime = m_Clock.getElapsedTime();
	float fFps = 1.0f / (currenTime.asSeconds() - m_PreviousTime.asSeconds());
	m_PreviousTime = currenTime;
	return fFps;
}


/*
	Method return a text and the framerate with  0 decimals
	ex. if strText = Framerate and fFps = 30.354647. Method return Framerate 30
	@param strText Text before the framerate
	@param fFps Framerate
	@return Framerate and text
*/
std::string CFramerate::GetFramerateText(std::string strText, float fFps)
{
	char chArrText[20];
	sprintf_s(chArrText, "%.0f", fFps);
	return strText + " " + std::string(chArrText);
}


/*
	Method calculate framerate and returns text and the framerate with 0 decimals
	ex. if strText = Framerate. Method return Framerate 30
	@param strText Text before the framerate
	@return Framerate and text
*/
std::string CFramerate::CalculateFramerate(std::string strText)
{
	float fFps = this->CalculateFramerate();

	char chArrText[20];
	sprintf_s(chArrText, "%.0f", fFps);
	return strText + " " + std::string(chArrText);
}

