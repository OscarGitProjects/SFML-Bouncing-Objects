#include "CShapeFactory.h"
#include "CCircleShape.h"
#include "CRectangleShape.h"
#include "enums.h"

/*
	Method that create a new shape object
	@param type enum with type of shape we shall create
	@return CMyBaseShape shared pinter to a new shape object
*/
std::shared_ptr<CMyBaseShape> CShapeFactory::CreateShape(Type_of_Shape type)
{
	std::shared_ptr<CMyBaseShape> pShape = nullptr;

	if (type == CIRCLE)
	{
		pShape = std::make_shared<CCircleShape>(25.0f);
		pShape->setTypeOfShape(CIRCLE);
	}
	else if (type == RECTANGLE)
	{
		pShape = std::make_shared<CRectangleShape>(sf::Vector2f(0.f, 0.f));
		pShape->setTypeOfShape(RECTANGLE);
	}

	return pShape;
}
