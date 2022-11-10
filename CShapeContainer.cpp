#include "CShapeContainer.h"
#include "CCircleShape.h"

/*
	Method add a new shape to the container
	@param std::shared_ptr pointer to a new shape
*/
void CShapeContainer::AddShape(std::shared_ptr<CMyBaseShape> pShape)
{
	m_vecShapes.push_back(pShape);
}


/*
	Destructor
*/
CShapeContainer::~CShapeContainer()
{
	std::cout << "~CShapeContainer" << std::endl;
}