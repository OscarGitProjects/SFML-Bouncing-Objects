#pragma once
#include <iostream>
#include<array>
#include <memory>
#include <SFML/Graphics.hpp>
#include "CMyBaseShape.h"
#include "enums.h"

/*
	CRectangleShape.h
	CRectangleShape class inherits from CMyBaseShape.
	It is a rectangle shaped object
	@author Oscar Andersson
	@version 1.0 2022-11-09
*/
class CRectangleShape : public CMyBaseShape
{
public:
	/* The public Rectangle shape */
	sf::RectangleShape m_Shape = sf::RectangleShape();


	/*
		Constructor
	*/
	CRectangleShape() { this->setTypeOfShape(RECTANGLE); }

	/*
	 Constructor
	 @param size Widht and Height of the rectangle
	*/
	CRectangleShape(sf::Vector2f size)
	{
		m_Shape.setSize(size);
		this->setSize(size);
		this->setTypeOfShape(RECTANGLE);
	}

	/*
		Destructor
	*/
	~CRectangleShape() {
		std::cout << "~CRectangleShape" << std::endl;
	};


	// get/set methods

	/*
		Method return a pointer to this RectangleShape
		@return Pointer to this RectangleShape
	*/
	const sf::RectangleShape* getShape() const { return &m_Shape; }

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

