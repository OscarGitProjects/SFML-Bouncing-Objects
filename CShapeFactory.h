#pragma once
#include <memory>
#include "CShapeFactory.h"
#include "CMyBaseShape.h"
#include "enums.h"

/*
	CShapeFactory.h
	CShapeFactory class that handle the creation of shape objects
	@author Oscar Andersson
	@version 1.0 2022-11-09
*/
class CShapeFactory
{
public:
	/* Construktor */
	CShapeFactory() {}

	/* Destructor */
	~CShapeFactory() {}


	/*
		Method that create a new shape object
		@param type enum with type of shape we shall create
		@return CMyBaseShape shared pinter to a new shape object
	*/
	std::shared_ptr<CMyBaseShape> CreateShape(Type_of_Shape type);
};

