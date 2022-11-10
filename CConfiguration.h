#pragma once

#include <SFML/Graphics.hpp>
#include <string>

/*
	CConfiguration.h
	CConfiguration class for saving configurations from a config file
	@author Oscar Andersson
	@version 1.0 2022-11-05
*/
class CConfiguration
{
private:
	bool m_bCantLoadConfigurations = false;	// If we cant load config file, this is true

	// Window configuration
	std::string m_strName = "Default name";	// Name of the program
	int m_iWindowHeight = 768;				// Window height
	int m_iWindowWidth = 1024;				// Window width

	// Font configuration
	std::string m_strFontFileName = "";		// Name and path to the font file
	int m_iFontSize = 24;					// Font size
	sf::Font m_Font;						// The font
	sf::Color m_FontColor;					// Color of the text that uses this font
	bool m_bHasFont = true;					// true if we have a font in this class. Otherwise false

public:
	/*
		Constructor
	*/
	CConfiguration()
		: m_FontColor(0, 255, 0)
	{}

	// get/set methods

	/*
		Method return true if we could not read cconfig file
		@return true if we could not read the file. Otherwise we return false
	*/
	bool CantLoadConfigurations() { return m_bCantLoadConfigurations; }

	/*
		Method set bool that indicate if we could read config file or not
		@param bCantLoadConfigurations set to true if we could not read the fil. Otherwise false. Default is false
	*/
	void CantLoadConfigurations(bool bCantLoadConfigurations) { m_bCantLoadConfigurations = bCantLoadConfigurations; }

	// Window configuration 
	// get/set methods 

	/*
		Method return the name of the window
		@return Name of window
	*/
	const std::string& getWindowName() { return m_strName; }

	/*
		Method return the height of the window
		@return Height of the window
	*/
	int getWindowHeight() { return m_iWindowHeight; }

	/*
		Method return the width of the window
		@return Width of the window
	*/
	int getWindowWidth() { return m_iWindowWidth; }

	/*
		Method set the name of the window
		@param strName of window
	*/
	void setWindowName(std::string strName) { m_strName = strName; }

	/*
		Method set the height of the window
		@param iHeight of the window
	*/
	void setWindowHeight(int iHeight) { m_iWindowHeight = iHeight; }

	/*
		Method set the width of the window
		@return iWidth of the window
	*/
	void setWindowWidth(int iWidth) { m_iWindowWidth = iWidth; }



	// Font configuration 
	// get/set methods 

	/*
		Method return reference to string path and filenamn of the font
		@return Reference to string with Path and filename of the font
	*/
	const std::string& getFontFileName() { return m_strFontFileName; }

	/*
		Method return the font size
		@return Font size
	*/
	int getFontSize() { return m_iFontSize; }

	/*
		Method return a reference to the color of text that use this font
		@return Reference to a Color of text that uses font
	*/
	const sf::Color& getFontColor() { return m_FontColor; }

	/*
		Method return a reference to the font
		@return Reference to the font
	*/
	sf::Font& getFont() { return m_Font; }

	/*
		Method return true if we data about a font saved in this class. Otherwise false
		@return true if we have data about a font. Otherwise we return false
	*/
	bool HasFont() { return m_bHasFont; }


	// set methods

	/*
		Method set string path and filenamn of the font
		@param strFileName string with Path and filename of the font
	*/
	void setFontFileName(std::string strFileName) { m_strFontFileName = strFileName; }

	/*
		Method set the font size
		@param iFontSize Font size
	*/
	void setFontSize(int iFontSize) { m_iFontSize = iFontSize; }

	/*
		Method set a sf::Color with the color
		@param fontColor sf::Color with the color
	*/
	void setFontColor(sf::Color fontColor) { m_FontColor = fontColor; }

	/*
		Method set a reference to the font
		@param font Reference to the font
	*/
	void setFont(sf::Font& font) { m_Font = font; }

	/*
		Method set true if we data about a font saved in this class. Otherwise false
		@param bHasFont true if we have data about a font. Otherwise we return false
	*/
	void HasFont(bool bHasFont) { m_bHasFont = bHasFont; }
};

