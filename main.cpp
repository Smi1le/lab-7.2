#include <SFML/Graphics.hpp>
#include "figures.h"
#include <iostream>


using namespace std;
using namespace sf;

void determinationReduction(pieces * figures) {
	figures->reductionFactor = (1 - (RESIZING_PIECES.x / STANDARD_SIZE_PIECES.x)) / (figures->firstPieces->getPosition().x / HORIZONTAL_SPEED.x);
	figures->determineReductionFactor = false;
}

void delaysDefinitionHorizAccel(pieces * figures) {
	figures->accelerationDiagonally = { (float(SIZE_WINDOW.x) - 100.0f - LEFT_BOUNDARY) / (float(SIZE_WINDOW.y) - LEFT_BOUNDARY - (SIZE_WINDOW.y - figures->firstPieces->getPosition().y)), 1.0f };
}

void usingBreakpoint(pieces * figures) {
	figures->breakpoint = { figures->firstPieces->getPosition().x, figures->firstPieces->getPosition().y };
	figures->useBreakpoint = false;
}

void drawing(RenderWindow &window, pieces *figures) {
	window.clear(Color::White);
	window.draw(*figures->firstPieces);
	window.draw(*figures->secondPieces);
	window.draw(*figures->thirdPieces);
	window.draw(*figures->fourthPieces);
	window.draw(*figures->fifthPieces);
	window.display();
}

void basicCycle(pieces * figures, RenderWindow &window) {
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (figures->step == 1) {
			if (!figures->useBreakpoint) {
				figures->useBreakpoint = true;
			}
			firstStep(figures);
		}
		else if (figures->step == 2) {
			secondStep(figures);
		}
		else if (figures->step == 3) {
			if (figures->determineReductionFactor) {
				determinationReduction(figures);
			}
			thirdStep(figures);
		}
		else if (figures->step == 4) {
			if (!figures->determineReductionFactor) {
				figures->determineReductionFactor = true;
				delaysDefinitionHorizAccel(figures);
			}
			fourthStep(figures);
		}
		else if (figures->step == 5) {
			if (figures->useBreakpoint) {
				usingBreakpoint(figures);
			}
			fifthStep(figures);
		}
		drawing(window, figures);
	}
}

void removal(pieces * figures) {
	delete figures->firstPieces;
	delete figures->secondPieces;
	delete figures->thirdPieces;
	delete figures->fourthPieces;
	delete figures->fifthPieces;
	delete figures->window;
}

int main()
{
	pieces *figures = new pieces;
	createPieces(figures);
	RenderWindow & window = *figures->window;
	figures->distanceBetweenFigures = (figures->secondPieces->getPosition().x - figures->firstPieces->getPosition().x - figures->firstPieces->getSize().x);
	basicCycle(figures, window);
	removal(figures);
	delete figures;
	return 0;
}