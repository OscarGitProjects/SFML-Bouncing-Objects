#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics.hpp>
#include "enums.h"

/*
	CMyBaseShape.h
	CMyBaseClass is the base class for shape classes
	This class have data about the sf::Shape object
	@author Oscar Andersson
	@version 1.0 2022-11-09
*/
class CMyBaseShape
{
protected:
	int m_iId = 0;										// Id for this object
	std::string m_strName;								// Name for object ex CGreen
	sf::Vector2f m_fVec2fStartPosition;					// Objects start position
	sf::Vector2f m_fVec2fCurrentPosition;			    // Objects current position
	sf::Vector2f m_fVec2fSpeed;							// Objects current moving speed
	sf::Color m_FillColor;								// Fill Color of object

	std::shared_ptr<sf::Text> m_pTextLabel = nullptr;	// Text label that show the name of the object in the center of the object

	std::shared_ptr<sf::RectangleShape> m_pTextBackgroundShape = nullptr;	// En backgrund till textlabel

	float m_fRadius = 0;								// Radius. Only used in CCircleShape objects
	sf::Vector2f m_Vec2fSize = sf::Vector2f(0.f, 0.f);	// Width and Height. Only used in CRectangeShape objects

	Type_of_Shape m_EnumTypeOfShape = NA;				// enum Type_of_Shape with the Type of shape

public:
	/* Constructor */
	CMyBaseShape() {}

	/* Destructor */
	~CMyBaseShape();

	// get/set methods

	/*
		Method return the id for this object
		@return Id
	*/
	int getId() { return m_iId; }

	/*
		Method return namn of object ex. CGreen
		@return Name of object
	*/
	std::string& getName() { return m_strName; }

	/*
		Method return current position of the object
		@return Current position
	*/
	sf::Vector2f& getCurrentPosition() { return m_fVec2fCurrentPosition; }

	/*
		Method return start position of the object
		@return Start position
	*/
	sf::Vector2f& getStartPosition() { return m_fVec2fStartPosition; }

	/*
		Method return current speed of object
		@return Current speed
	*/
	sf::Vector2f& getSpeed() { return m_fVec2fSpeed; }

	/*
		Method return fill color of the shape
		@return Fill color of the shape
	*/
	sf::Color& getFillColor() { return m_FillColor; }

	/*
		Method return enum with type of shape/object.
		Can be NA, CIRCLE or RECTANGLE
		@return eneum with type of shape/object
	*/
	Type_of_Shape getTypeOfShape() { return m_EnumTypeOfShape; }

	/*
		Method return shared_ptr with sf::Text with the name of the object
		@return shared_ptr with sf::Text with the name of the object
	*/
	std::shared_ptr<sf::Text> getTextLabel() { return m_pTextLabel; }

	/*
		Method return a std::shared_ptr to background shape for the textlabel
		@return std::shared_ptr to sf::RectangleShape pointer to background shape for the textlabel
	*/
	std::shared_ptr<sf::RectangleShape> getTextLabelBackgroundShape() { return m_pTextBackgroundShape; }

	/*
		Method return radius of the object. It is only valid for circle objects
		@return Radius for the object
	*/
	float getRadius() { return m_fRadius; }

	/*
		Method return size (Width and Height) of the object. It is only valid for rectangle objects
		@return size (Width and Height) of the object
	*/
	sf::Vector2f& getSize() { return m_Vec2fSize; }

	/***** ***** ***** ***** *****/

	// set methods 

	/*
		Method set id for this object
		@param iId Id for object
	*/
	void setId(int iId) { m_iId = iId; }

	/*
		Method set the name of object ex. CGreen
		@param strName Name of object
	*/
	void setName(std::string strName) { m_strName = strName; }

	/*
		Method set current position of the object
		@param fVec2fPosition Current position
	*/
	void setCurrentPosition(sf::Vector2f fVec2fPosition) { m_fVec2fCurrentPosition = fVec2fPosition; }

	/*
		Method set start position of the object
		@param fVec2fPosition Start position
	*/
	void setStartPosition(sf::Vector2f fVec2fPosition) { m_fVec2fStartPosition = fVec2fPosition; }

	/*
		Method set current speed of object
		@param fVec2fSpeed Curent speed
	*/
	void setSpeed(sf::Vector2f fVec2fSpeed) { m_fVec2fSpeed = fVec2fSpeed; }

	/*
		Method set fill color of the shape
		@param Fill color of the shape
	*/
	void setFillColor(sf::Color fillColor) { m_FillColor = fillColor; }

	/*
		Method set enum with type of shape/object. Can be NA, CIRCLE or RECTANGLE
		@param enumTypeOfShape eneum with type of shape/object
	*/
	void setTypeOfShape(Type_of_Shape enumTypeOfShape) { m_EnumTypeOfShape = enumTypeOfShape; }

	/*
		Method set std::shared_ptr sf::Text with the name of the object
		@param std::shared_ptr pTextLabel sf::Text with the name of the object
	*/
	void setTextLabel(std::shared_ptr<sf::Text> pTextLabel) {
		m_pTextLabel = pTextLabel;
	}

	/*
		Method set radius of the object. It is only valid for circle objects
		@param fRadius Radius for the object
	*/
	void setRadius(float fRadius) { m_fRadius = fRadius; }

	/*
		Method set size (Width and Height) of the object. It is only valid for rectangle objects
		@param vec2fSize size (Width and Height) of the object
	*/
	void setSize(sf::Vector2f vec2fSize) { m_Vec2fSize = vec2fSize; }

	// virtual methods 

	/*
		Virtual method that return a ponter to sf::Shape
		@return Pointer to this sf::Shape
	*/
	virtual const sf::Shape* getShape() const { return nullptr; }

	/* Virtual method that position textlabel in the center of the object */
	virtual void PositionTextLabel() {};

	/* Virtual method that update settings in the object */
	virtual void UpdateShape() {};

	/* Virtual method that update position of the object */
	virtual void UpdatePosition() {};

	/*
		Method detect collisions with the windows borders. If collision is detected the speeds direction is changed
		@param iWindowWidth Width of the window
		@param iWindowHeight Height of the window
		@return Number of collisions detected
	*/
	virtual int CollisionDetection(int iWindowWidth, int iWindowHeight) { return -1; };
};