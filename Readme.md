This is a C++ program that load configurations from a configuration file.
The program load and creates circle and reactangle shapes. Then it moves them around in the window.
When the shapes reach the borders for the window they bounces back.
I have limited the framerate to 30 frames per second.

I use the SFML graphics library for the rendering to the computer screen.
https://www.sfml-dev.org/

In the configuration file you specifies the size of this programs window.
You specifies where to read the font file and the color of the font.
Then you specifie circles and rectangles that you want to have in your window.
I have som validation of the data from configuration file. If its wrong i use default settings or i dont create the shapes at all.


I have developed this in Microsoft Visual Studio 2022 Community edition.
First you download SFML graphics library from https://www.sfml-dev.org/download/sfml/2.5.1/

Unpack it to a directory on your computer. No spaces in the path. 
Example from my computer C:\libraries\SFML-2.5.1-windows-vc15-64-bit\SFML-2.5.1

The you have to set a Environment Variable with the path to the directory with SFML.
I call it SFML_DIR and the path is C:\libraries\SFML-2.5.1-windows-vc15-64-bit\SFML-2.5.1
The you add a path variable pointing to the bin directory with the dll files. SFML_DIR. 
On my computer i do this %SFML_DIR%\bin

In your Microsoft Visual Studio environment you have to do some settings to. Follow the tutorial at SFML homepage.
https://www.sfml-dev.org/tutorials/2.5/start-vc.php


Each line of the configuration file specifies one of the config settings of the assignment program. 
With the first string in each line being the type of settings that the rest of the line specifies. 
Line in the config file can be of the following types and lines can appear in any order in the file.

Window Program_Name W H 

- This line declares that the SFML window must be constructed with width W and height H. Each value will be integers.

	Program_Name	std::string Name for the program. No spaces in the name

	Width	W		int

	Height H		int

Font F S R G B

- This lines defines the font which is to be used to draw text for this program. The format of the line is as follows.

	Font file 	F 		std::string No spaces

	Font Size 	S 		int

	RGB color	R G B 	int, int, int

Rectangle N X Y SX SY R G B W H
- Defines a rectangle shape with

	Shape name 	N 			std::string

	Initial position X Y 	float, float

	Initial speed 	SX SY 	float, float

	RGB color 	R G B		int, int, int

	Size		W H 		float, float

Circle N X Y SX SY R G B R

- Defines a circle shape with:

	Shape name	N			std::string

	Initial position X Y 	float, float

	Initial speed 	SX SY 	float, float

	RGB color 	R G B		int, int, int

	Radius		R			float



