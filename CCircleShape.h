#pragma once

#include <iostream>
#include<array>
#include <memory>
#include <SFML/Graphics.hpp>
#include "CMyBaseShape.h"
#include "CShapeFactory.h"
#include "enums.h"

/*
	CCircleShape.h
	CCircleShape class inherits from CMyBaseShape.
	It is a circle shaped object
	@author Oscar Andersson
	@version 1.0 2022-11-09
*/
class CCircleShape : public CMyBaseShape
{
public:
	/* The public circle shape */
	sf::CircleShape m_Shape = sf::CircleShape();

	/*
		Constructor
	*/
	CCircleShape() { this->setTypeOfShape(CIRCLE); }

	/*
	 Constructor
	 @param fRadius Radius of the circle shape
	*/
	CCircleShape(float fRadius)
	{
		m_Shape.setRadius(fRadius);
		this->setRadius(fRadius);
		this->setTypeOfShape(CIRCLE);
	}

	/*
		Destructor
	*/
	~CCircleShape() {
		std::cout << "~CCircleShape" << std::endl;
	};


	// get/set methods

	/*
		Method return a pointer to this CircleShape
		@return Pointer to this CircleShape
	*/
	const sf::CircleShape* getShape() const { return &m_Shape; }

	/* Method position textlabel in the center of the object */
	void PositionTextLabel();

	/* Method that update settings in the object */
	void UpdateShape();

	/* Method that update position of the object */
	void UpdatePosition();

	/*
		Method detect collisions with the windows borders. If collision is detected the speeds direction is changed
		@param iWindowWidth Width of the window
		@param iWindowHeight Height of the window
		@return Number of collisions detected
	*/
	int CollisionDetection(int iWindowWidth, int iWindowHeight);
};


