#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

/*
	CFramerate.h
	CFramerate class for calculating framerate and get text that you can show as a label about the framerate
	@author Oscar Andersson
	@version 1.0 2022-11-05
*/
class CFramerate
{
private:
	sf::Clock m_Clock;			// SFML clock object
	sf::Time m_PreviousTime;	// SFML time object with previous time

public:
	/*
		Constructor
	*/
	CFramerate() {};

	/*
		Method restart the clock
	*/
	void RestartClock() { m_Clock.restart(); }

	/*
		Method calculate framerate
		@return Framerate
	*/
	float CalculateFramerate();

	/*
		Method return a text and the framerate with  0 decimals
		ex. if strText = Framerate and fFps = 30.354647. Method return Framerate 30
		@param strText Text before the framerate
		@param fFps Framerate
		@return Framerate and text
	*/
	std::string GetFramerateText(std::string strText, float fFps);

	/*
		Method calculate framerate and returns text and the framerate with 0 decimals
		@param strText Text before the framerate
		@return Framerate and text
	*/
	std::string CalculateFramerate(std::string strText);
};
