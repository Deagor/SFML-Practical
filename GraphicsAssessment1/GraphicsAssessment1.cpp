// GraphicsAssessment1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#ifdef _DEBUG
#pragma comment(lib,"sfml-graphics-d.lib")
#pragma comment(lib,"sfml-audio-d.lib")
#pragma comment(lib,"sfml-system-d.lib")
#pragma comment(lib,"sfml-window-d.lib")
#pragma comment(lib,"sfml-network-d.lib")
#else
#pragma comment(lib,"sfml-graphics.lib")
#pragma comment(lib,"sfml-audio.lib")
#pragma comment(lib,"sfml-system.lib")
#pragma comment(lib,"sfml-window.lib")
#pragma comment(lib,"sfml-network.lib")
#endif
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")

#include "BouncingTriangle.h"
#include "BouncingBox.h"

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	const int NUM_TRIANGLES = 10;
	const int NUM_BOXES = 10;

	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "SFML First Program");
	sf::RenderWindow* pWindow = &window;
	window.setFramerateLimit(120);

	BouncingTriangle triangles[NUM_TRIANGLES];
	BouncingBox boxes[NUM_BOXES];


	// Start game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			// Close window : exit
			if (Event.type == sf::Event::Closed)
				window.close();
			// Escape key : exit
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
				window.close();


			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Down))
			{
				for (int i = 0; i < NUM_TRIANGLES; i++)
				{
					if (triangles[i].getRotationAmount() >= 1)
					{
						triangles[i].setRotationAmount(triangles[i].getRotationAmount() - 1);
					}
				}
			}
			else if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Up))
			{
				for (int i = 0; i < NUM_TRIANGLES; i++)
				{
					if (triangles[i].getRotationAmount() <= 20)
					{
						triangles[i].setRotationAmount(triangles[i].getRotationAmount() + 1);
					}
				}
			}
				
		}
		//prepare frame
		window.clear();

		//Draw Frame
		for (int i = 0; i < NUM_TRIANGLES; i++)
		{
			triangles[i].Draw(pWindow);
			triangles[i].Move();
		}
		for (int i = 0; i < NUM_BOXES; i++)
		{
			boxes[i].Draw(pWindow);
			boxes[i].Move();
		}


		// Finally, display rendered frame on screen
		window.display();
	} //loop back for next frame
	return 0;
}

