#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "CMyBaseShape.h"

/*
	CShapeContainer.h
	CShapeContainer class that has a vector with all shape objects
	@author Oscar Andersson
	@version 1.0 2022-11-09
*/
class CShapeContainer
{
public:
	/* The public vector of shapes */
	std::vector<std::shared_ptr<CMyBaseShape>> m_vecShapes;

	/*
		Constructor
	*/
	CShapeContainer() {};

	/*
		Destructor
	*/
	~CShapeContainer();

	// get/set methods

	/*
		Method return number of objects in the container
		@return Number of objects in the container
	*/
	size_t getNumberOfShapes() { return m_vecShapes.size(); }

	// methods


	/*
		Method add a new shape to the container
		@param std::shared_ptr pointer to a new shape
	*/
	void AddShape(std::shared_ptr<CMyBaseShape> pShape);
};
