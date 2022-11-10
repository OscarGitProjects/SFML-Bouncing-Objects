#include <iostream>
#include <fstream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "CFramerate.h"
#include "CConfiguration.h"
#include "CShapeFactory.h"
#include "CRectangleShape.h"
#include "CCircleShape.h"
#include "CShapeContainer.h"
#include "CMyBaseShape.h"
#include "enums.h"


#pragma region Load data from config file

/*
    Method check if invalue is between 0 and 255. Inclusive 0 and 255
    @param Value that we want to validate
    @return true if value is ok. Otherwise return false
*/
bool IsValidColorValue(int iColorValue)
{
    bool bIsValid = false;

    if (iColorValue >= 0 && iColorValue <= 255)
        bIsValid = true;

    return bIsValid;
}


/*
    Method read configurations from the config.txt file.
    Min dimension of the window has to be 800*600. Otherwise we use the default values.
    If the font color value is invalid. We chooses a default value red
    Save information in a configuration object
    @param configuration Reference to a configuration object where we save information fom config file
*/
void LoadConfiguration(CConfiguration& configuration)
{
    try
    {
        std::string strObjectName;          // Type of object. In this method i handle Window and Font
        int iWindowHeight, iWindowWidth;    // Window height and width
        std::string strWindowName;          // Name of the program
        std::string strFontFileName;        // Name and path for the font file
        int iFontSize;                      // Font size
        int iRed, iGreen, iBlue;            // RGB color values

        configuration.CantLoadConfigurations(true);
        configuration.HasFont(false);

        std::ifstream fin("config.txt");

        while (fin >> strObjectName)
        {
            configuration.CantLoadConfigurations(false);

            // If we dont have info about the window in config file. We use default values
            if (strObjectName == "Window")      // Window Program 800 600
            {// Read data about the application
            // Format of data is. Window Name Width Height

                fin >> strWindowName;
                fin >> iWindowWidth;
                fin >> iWindowHeight;

                configuration.setWindowName(strWindowName);

                if (iWindowHeight >= 800 && iWindowWidth >= 600)
                {
                    configuration.setWindowWidth(iWindowWidth);
                    configuration.setWindowHeight(iWindowHeight);
                }
            }
            else if (strObjectName == "Font")   // Font Fonts/sansation.ttf 24 244 21 55
            {// Read data about the font
            // Format of data is. Font Font_File Size Red Green Blue
            // Red, Green and Blue is RGB values for Color

                fin >> strFontFileName;
                fin >> iFontSize;
                fin >> iRed;
                fin >> iGreen;
                fin >> iBlue;

                configuration.setFontFileName(strFontFileName);
                configuration.setFontSize(iFontSize);

                // Color of the text
                if (!IsValidColorValue(iRed) || !IsValidColorValue(iBlue) || !IsValidColorValue(iGreen))
                {// Invalid values for the color. We select a default value font color
                    configuration.setFontColor(sf::Color::Red);
                }
                else
                {
                    configuration.setFontColor(sf::Color(iRed, iGreen, iBlue));
                }


                // Load font from harddrive and save in configuration object
                sf::Font font;
                if (font.loadFromFile(configuration.getFontFileName()))
                {
                    configuration.setFont(font);
                    configuration.HasFont(true);
                }
                else
                {// If we dont have a font. We shall exit the program
                    configuration.CantLoadConfigurations(true);
                    configuration.HasFont(false);
                }
            }
        }
    }
    catch (...)
    {
        configuration.HasFont(false);
        configuration.CantLoadConfigurations(true);
        std::cout << "LoadConfiguration(). Exception" << std::endl;
    }
}


/*
    Method read objects from the configuration file
    The definítion of a object has to have correct values for the color and the object has to be positioned inside the window
    @param iShapeCounter Number of objects created. I also use this number as id for every object
    @param configuration Reference to a configuration object where we have information fom config file
    @param shapeContainer Reference to a container for the Shape objects
    @return Number of created shape objects
*/
int LoadObjects(int iShapeCounter, CConfiguration& configuration, CShapeContainer& shapeContainer)
{
    // Factory that create Shape objects
    CShapeFactory shapeFactory;

    try
    {
        bool bHasLoadedFont = false;
        std::string strObjectName;  // Type of object. In this method i handle Circle and Rectangle
        std::string strShapeName;   // The shapes name. Circle or Rectangle
        float fX, fY;               // Initial position
        float fDX, fDY;             // Initial speed
        int iRed, iGreen, iBlue;    // RGB color values
        float fRadius;              // Radius of a circle
        float fWidth, fHeight;      // Width and height of a rectangle        

        //CMyBaseShape* pBaseShape = nullptr;
        std::shared_ptr<CMyBaseShape> pBaseShape = nullptr;

        configuration.CantLoadConfigurations(true);

        // Get ifstream to config file
        std::ifstream fin("config.txt");

        while (fin >> strObjectName)
        {
            configuration.CantLoadConfigurations(false);

            if (strObjectName == "Circle")          // Circle CGreen 100 100 -0.03 0.02 0 255 0 50
            {
                fin >> strShapeName;
                fin >> fX;
                fin >> fY;
                fin >> fDX;
                fin >> fDY;
                fin >> iRed;
                fin >> iGreen;
                fin >> iBlue;
                fin >> fRadius;

                if (fX > 0 && (fX + (2 * fRadius)) < configuration.getWindowWidth())
                {
                    if (fY > 0 && (fY + (2 * fRadius)) < configuration.getWindowHeight())
                    {// The Circle is inside the window

                        if (IsValidColorValue(iRed) || IsValidColorValue(iBlue) || IsValidColorValue(iGreen))
                        {// We have valid color values
                            pBaseShape = shapeFactory.CreateShape(CIRCLE);
                            pBaseShape->setId(++iShapeCounter);
                            pBaseShape->setName(strShapeName);
                            pBaseShape->setStartPosition(sf::Vector2f(fX, fY));
                            pBaseShape->setCurrentPosition(sf::Vector2f(fX, fY));
                            pBaseShape->setSpeed(sf::Vector2f(fDX, fDX));
                            pBaseShape->setFillColor(sf::Color(iRed, iGreen, iBlue));
                            pBaseShape->setRadius(fRadius);

                            // Font stuff
                            std::shared_ptr<sf::Text>pText = std::make_shared<sf::Text>(strShapeName, configuration.getFont(), configuration.getFontSize());
                            pText->setFillColor(configuration.getFontColor());
                            pText->setPosition(pBaseShape->getCurrentPosition());
                            pBaseShape->setTextLabel(pText);

                            // Update the shape with data
                            pBaseShape->UpdateShape();

                            shapeContainer.AddShape(pBaseShape);
                        }
                    }
                }
            }
            else if (strObjectName == "Rectangle")  // Rectangle RRed 200 200 0.1 0.15 255 0 0 50 25
            {
                fin >> strShapeName;
                fin >> fX;
                fin >> fY;
                fin >> fDX;
                fin >> fDY;
                fin >> iRed;
                fin >> iGreen;
                fin >> iBlue;
                fin >> fWidth;
                fin >> fHeight;

                if (fX > 0 && (fX + fWidth) < configuration.getWindowWidth())
                {
                    if (fY > 0 && (fY + fHeight) < configuration.getWindowHeight())
                    {// The Rectangle is inside the window

                        if (IsValidColorValue(iRed) || IsValidColorValue(iBlue) || IsValidColorValue(iGreen))
                        {// We have valid color values
                            pBaseShape = shapeFactory.CreateShape(RECTANGLE);
                            pBaseShape->setId(++iShapeCounter);
                            pBaseShape->setName(strShapeName);
                            pBaseShape->setStartPosition(sf::Vector2f(fX, fY));
                            pBaseShape->setCurrentPosition(sf::Vector2f(fX, fY));
                            pBaseShape->setSpeed(sf::Vector2f(fDX, fDX));
                            pBaseShape->setFillColor(sf::Color(iRed, iGreen, iBlue));
                            pBaseShape->setSize(sf::Vector2f(fWidth, fHeight));

                            // Font stuff
                            std::shared_ptr<sf::Text> pText1 = std::make_shared<sf::Text>(strShapeName, configuration.getFont(), configuration.getFontSize());
                            pText1->setFillColor(configuration.getFontColor());
                            pText1->setPosition(pBaseShape->getCurrentPosition());
                            pBaseShape->setTextLabel(pText1);

                            // Update the shape with data
                            pBaseShape->UpdateShape();

                            shapeContainer.AddShape(pBaseShape);
                        }
                    }
                }
            }
        }
    }
    catch (...)
    {
        configuration.CantLoadConfigurations(true);
        std::cout << "LoadObjects(). Exception" << std::endl;
    }

    return iShapeCounter;
}

#pragma endregion // End of region for Load data from config file

#pragma region Render function

/*
    Method draw shape objects in the shapeContainer to the screen
    @param window Reference to the window
    @param shapeContainer Reference to a container with Shape objects
    @param configuration Reference to a configuration object where we have information fom config file
*/
void DrawObjectsToWindow(sf::RenderWindow& window, CShapeContainer& shapeContainer, CConfiguration& configuration)
{
    for (auto& shape : shapeContainer.m_vecShapes)
    {
        // Draw the shape
        window.draw(*shape->getShape());

        // Draw a textlabel for a object
        window.draw(*shape->getTextLabelBackgroundShape(), shape->getTextLabel()->getTransform());
        window.draw(*shape->getTextLabel());
    }
}

#pragma endregion   // End of region for Render function

#pragma region Move objects

/*
    Method move objects
    @param shapeContainer Reference to a container with Shape objects
*/
void MoveObjects(CShapeContainer& shapeContainer)
{
    for (auto& shape : shapeContainer.m_vecShapes)
        shape->UpdatePosition();
}

#pragma endregion   // End of region for Move objects

#pragma region Collision detection with the border of the window

/*
    Method detect collisions with the border of the window. If a object detects a collision it changes direction of its speed
    @param shapeContainer Reference to a container with Shape objects
    @param configuration Reference to a configuration object where we have information fom config file
*/
int CollisionDetection(CShapeContainer& shapeContainer, CConfiguration& configuration)
{
    int iNumberOfCollisions = 0;

    for (auto& shape : shapeContainer.m_vecShapes)
        iNumberOfCollisions += shape->CollisionDetection(configuration.getWindowWidth(), configuration.getWindowHeight());

    return iNumberOfCollisions;
}

#pragma endregion   // End of region Collision detection with the border of the window


/* main function */
int main(int argc, char* argv[])
{
    // Object with configurations
    CConfiguration configuration;

    // Object for the framerate calculations
    CFramerate framerate;

    CShapeContainer shapeContainer;

    // This is id for a shape. Before add id to shape update with ++
    int iShapeCounter = 0;

    int iCircleRadius = 50;
    float fCircleMoveSpeed = 0.01f;

    // Load configurations from the config file
    LoadConfiguration(configuration);
    if (configuration.CantLoadConfigurations() || !configuration.HasFont())
    {
        std::cout << "Cant load configurations or configuration file" << std::endl;
        return 1;
    }

    // Load objects from config file
    iShapeCounter = LoadObjects(iShapeCounter, configuration, shapeContainer);

    std::cout << "Number of shapes in container is " << std::to_string(shapeContainer.getNumberOfShapes()) << std::endl;


    // Set up text for framerate
    sf::Text textFramerate;
    textFramerate.setString("Hello world");
    textFramerate.setFont(configuration.getFont());
    textFramerate.setFillColor(sf::Color::Red); // Set a red color
    textFramerate.setCharacterSize(configuration.getFontSize());
    textFramerate.setPosition(5, 5);


    // Create a new window of size w*h pixels
    // top left of the window is (0, 0) and bottom right is (w, h)
    sf::RenderWindow window(sf::VideoMode(configuration.getWindowWidth(), configuration.getWindowHeight()), configuration.getWindowName());
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);       // Limit framerate to 30

    // Restart clock for Framerate counting
    framerate.RestartClock();

    // main loop
    sf::Event event;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    window.close();
            }
        }

        // Check for collisions. If a collision is detected then the speed direction changes for that object
        int iNumberOfCollisions = CollisionDetection(shapeContainer, configuration);
        if (iNumberOfCollisions > 0)
            std::cout << "Number of collision detected " << std::to_string(iNumberOfCollisions) << std::endl;

        // Move the objects
        MoveObjects(shapeContainer);

        // Update text with new framerate information
        float fFps = framerate.CalculateFramerate();
        textFramerate.setString(framerate.GetFramerateText("Framerate", fFps));

        window.clear();

        // Now we draw updated objects in to the backbuffer
        DrawObjectsToWindow(window, shapeContainer, configuration);

        window.draw(textFramerate);

        // Show the backbuffer
        window.display();
    }

    return 0;
}