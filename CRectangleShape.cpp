#include "CRectangleShape.h"

/*
	Method position textlabel in the center of the object.
	If the textlabel dosent have a background shape. We will create that to.
*/
void CRectangleShape::PositionTextLabel()
{
	if (m_pTextBackgroundShape == nullptr)
	{// We have no shape to show behind the textlabel. Create one
		m_pTextBackgroundShape = std::make_shared<sf::RectangleShape>();
		m_pTextBackgroundShape->setFillColor(sf::Color(225, 232, 225));
	}

	// Calculate center of rectangle object
	sf::Vector2f vec2fCurrentPosition = this->getCurrentPosition();
	float fCenterX = vec2fCurrentPosition.x + (m_Vec2fSize.x / 2.0f);
	float fCenterY = vec2fCurrentPosition.y + (m_Vec2fSize.y / 2.0f);

	// Get boundingbox for the textlabel
	sf::FloatRect fRectBackgroundBounds = m_pTextLabel->getLocalBounds();

	// Set size of the background shape for the textlabel
	m_pTextBackgroundShape->setSize(sf::Vector2f(fRectBackgroundBounds.width + 6.0f, fRectBackgroundBounds.height + 10.0f));

	float fWidth = fRectBackgroundBounds.width;
	float fHeight = fRectBackgroundBounds.height;

	float fNewX = fCenterX - (fWidth / 2.0f);
	float fNewY = fCenterY - (fHeight / 2.0f);

	m_pTextLabel->setPosition(fNewX, fNewY);
}


/* Virtual method that update settings in the object */
void CRectangleShape::UpdateShape()
{
	m_Shape.setPosition(this->getCurrentPosition());
	m_Shape.setFillColor(this->getFillColor());
	m_Shape.setSize(this->getSize());

	PositionTextLabel();
}


/* Virtual method that update position of the object */
void CRectangleShape::UpdatePosition()
{
	// Move the shape
	m_fVec2fCurrentPosition += m_fVec2fSpeed;
	m_Shape.setPosition(m_fVec2fCurrentPosition);

	// Move the textlabel
	sf::Vector2f fVec2fTextLabelPosition = m_pTextLabel->getPosition();
	fVec2fTextLabelPosition += m_fVec2fSpeed;
	m_pTextLabel->setPosition(fVec2fTextLabelPosition);
}


/*
	Method detect collisions with the windows borders. If collision is detected the speeds direction is changed
	@param iWindowWidth Width of the window
	@param iWindowHeight Height of the window
	@return Number of collisions detected
*/
int CRectangleShape::CollisionDetection(int iWindowWidth, int iWindowHeight)
{
	int iNumberOfCollisions = 0;
	sf::Vector2f vec2fSize = m_Shape.getSize();

	if (m_fVec2fCurrentPosition.x < 0.0f)										// Check if collision to the left side of the window
	{
		m_fVec2fSpeed.x *= -1.0f;
		iNumberOfCollisions++;
	}
	else if ((m_fVec2fCurrentPosition.x + vec2fSize.x) > (float)iWindowWidth)	// Check if collision to the right side of the window
	{
		m_fVec2fSpeed.x *= -1.0f;
		iNumberOfCollisions++;
	}


	if (m_fVec2fCurrentPosition.y < 0.0f)										// Check if collision to the top of the window
	{
		m_fVec2fSpeed.y *= -1.0f;
		iNumberOfCollisions++;
	}
	else if ((m_fVec2fCurrentPosition.y + vec2fSize.y) > (float)iWindowHeight)	// Check if collision to bottom of the window
	{
		m_fVec2fSpeed.y *= -1.0f;
		iNumberOfCollisions++;
	}

	return iNumberOfCollisions;
}
