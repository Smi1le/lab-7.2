#include <SFML/Graphics.hpp>
#include "figures.h"

using namespace std;
using namespace sf;


void createPieces(pieces * pieces) {
	pieces->window = new RenderWindow(VideoMode(SIZE_WINDOW.x, SIZE_WINDOW.y), "Animation's");

	pieces->firstPieces = new RectangleShape(Vector2f(STANDARD_SIZE_PIECES));
	pieces->firstPieces->setPosition(Vector2f(INITIAL_COORD_FIRTS_PIECES));
	pieces->firstPieces->setFillColor(COLOR_PIECES);
	pieces->firstPieces->setOrigin(STANDARD_SIZE_PIECES.x / 2.0f, STANDARD_SIZE_PIECES.y / 2.0f);

	pieces->secondPieces = new RectangleShape(Vector2f(STANDARD_SIZE_PIECES));
	pieces->secondPieces->setPosition(Vector2f(INITIAL_COORD_SECOND_PIECES));
	pieces->secondPieces->setFillColor(COLOR_PIECES);
	pieces->secondPieces->setOrigin(STANDARD_SIZE_PIECES.x / 2.0f, STANDARD_SIZE_PIECES.y / 2.0f);

	pieces->thirdPieces = new RectangleShape(Vector2f(STANDARD_SIZE_PIECES));
	pieces->thirdPieces->setPosition(Vector2f(INITIAL_COORD_THIRD_PIECES));
	pieces->thirdPieces->setFillColor(COLOR_PIECES);
	pieces->thirdPieces->setOrigin(STANDARD_SIZE_PIECES.x / 2.0f, STANDARD_SIZE_PIECES.y / 2.0f);

	pieces->fourthPieces = new RectangleShape(Vector2f(STANDARD_SIZE_PIECES));
	pieces->fourthPieces->setPosition(Vector2f(INITIAL_COORD_FOURTH_PIECES));
	pieces->fourthPieces->setFillColor(COLOR_PIECES);
	pieces->fourthPieces->setOrigin(STANDARD_SIZE_PIECES.x / 2.0f, STANDARD_SIZE_PIECES.y / 2.0f);

	pieces->fifthPieces = new RectangleShape(Vector2f(STANDARD_SIZE_PIECES));
	pieces->fifthPieces->setPosition(Vector2f(INITIAL_COORD_FIFTH_PIECES));
	pieces->fifthPieces->setFillColor(COLOR_PIECES);
	pieces->fifthPieces->setOrigin(STANDARD_SIZE_PIECES.x / 2.0f, STANDARD_SIZE_PIECES.y / 2.0f);

}

void firstStep(pieces * figures) {
	if (figures->firstPieces->getPosition().x <= RIGHT_BOUNDARY) {
		figures->firstPieces->move(HORIZONTAL_SPEED.x, HORIZONTAL_SPEED.y);
		figures->secondPieces->move(HORIZONTAL_SPEED.x, HORIZONTAL_SPEED.y);
		figures->thirdPieces->move(HORIZONTAL_SPEED.x, HORIZONTAL_SPEED.y);
		figures->fourthPieces->move(HORIZONTAL_SPEED.x, HORIZONTAL_SPEED.y);
		figures->fifthPieces->move(HORIZONTAL_SPEED.x, HORIZONTAL_SPEED.y);
	}
	else {
		figures->breakpoint = { figures->firstPieces->getPosition().x, figures->firstPieces->getPosition().y };
		figures->step = 2;
	}
}

void secondStep(pieces * figures) {
	if (figures->fifthPieces->getPosition().y + figures->fifthPieces->getSize().y < DOWN_BOUNDARY){
		figures->firstPieces->move(VERTICAL_SPEED.x, VERTICAL_SPEED.y);
		figures->secondPieces->move(VERTICAL_SPEED.x, VERTICAL_SPEED.y);
		figures->thirdPieces->move(VERTICAL_SPEED.x, VERTICAL_SPEED.y);
		figures->fourthPieces->move(VERTICAL_SPEED.x, VERTICAL_SPEED.y);
		figures->fifthPieces->move(VERTICAL_SPEED.x, VERTICAL_SPEED.y);
		figures->firstPieces->setFillColor(Color::Color(21, 21, 247, 255 * figures->capacity));
		figures->secondPieces->setFillColor(Color::Color(21, 21, 247, 255 * figures->capacity));
		figures->thirdPieces->setFillColor(Color::Color(21, 21, 247, 255 * figures->capacity));
		figures->fourthPieces->setFillColor(Color::Color(21, 21, 247, 255 * figures->capacity));
		figures->fifthPieces->setFillColor(Color::Color(21, 21, 247, 255 * figures->capacity));
		figures->thirdPieces->rotate(0.5f);
		figures->firstPieces->rotate(0.5f);
		figures->secondPieces->rotate(-0.5f);
		figures->fifthPieces->rotate(0.5f);
		figures->fourthPieces->rotate(-0.5f);
		figures->capacity -= 0.00003f;
	}
	else {
		figures->firstPieces->setRotation(0.0f);
		figures->secondPieces->setRotation(0.0f);
		figures->thirdPieces->setRotation(0.0f);
		figures->fourthPieces->setRotation(0.0f);
		figures->fifthPieces->setRotation(0.0f);
		figures->step = 3;
	}
}

void thirdStep(pieces * figures) {
	if (figures->firstPieces->getPosition().x > LEFT_BOUNDARY) {
		figures->firstPieces->setScale(figures->firstPieces->getScale().x - figures->reductionFactor, figures->firstPieces->getScale().y - figures->reductionFactor);
		figures->firstPieces->move(HORIZONTAL_SPEED.x * -1.0f, HORIZONTAL_SPEED.y);
		figures->secondPieces->setScale(figures->firstPieces->getScale().x - figures->reductionFactor, figures->firstPieces->getScale().y - figures->reductionFactor);
		figures->secondPieces->move(HORIZONTAL_SPEED.x * -1.0f, HORIZONTAL_SPEED.y);
		figures->thirdPieces->setScale(figures->firstPieces->getScale().x - figures->reductionFactor, figures->firstPieces->getScale().y - figures->reductionFactor);
		figures->thirdPieces->move(HORIZONTAL_SPEED.x * -1.0f, HORIZONTAL_SPEED.y);
		figures->fourthPieces->setScale(figures->firstPieces->getScale().x - figures->reductionFactor, figures->firstPieces->getScale().y - figures->reductionFactor);
		figures->fourthPieces->move(HORIZONTAL_SPEED.x * -1.0f, HORIZONTAL_SPEED.y);
		figures->fifthPieces->setScale(figures->firstPieces->getScale().x - figures->reductionFactor, figures->firstPieces->getScale().y - figures->reductionFactor);
		figures->fifthPieces->move(HORIZONTAL_SPEED.x * -1.0f, HORIZONTAL_SPEED.y);
	}
	else {
		figures->step = 4;
	}
}

void fourthStep(pieces * figures) {
	if (figures->firstPieces->getPosition().y > UP_BOUNDARY) {
		figures->firstPieces->move(figures->accelerationDiagonally.x * DELAY_IN_HORIZONTAL_ACCELERATION, (figures->accelerationDiagonally.y * -1.0f) * DELAY_IN_HORIZONTAL_ACCELERATION);
		figures->secondPieces->move(figures->accelerationDiagonally.x * DELAY_IN_HORIZONTAL_ACCELERATION, (figures->accelerationDiagonally.y * -1.0f) * DELAY_IN_HORIZONTAL_ACCELERATION);
		figures->thirdPieces->move(figures->accelerationDiagonally.x * DELAY_IN_HORIZONTAL_ACCELERATION, (figures->accelerationDiagonally.y * -1.0f) * DELAY_IN_HORIZONTAL_ACCELERATION);
		figures->fourthPieces->move(figures->accelerationDiagonally.x * DELAY_IN_HORIZONTAL_ACCELERATION, (figures->accelerationDiagonally.y * -1.0f) * DELAY_IN_HORIZONTAL_ACCELERATION);
		figures->fifthPieces->move(figures->accelerationDiagonally.x * DELAY_IN_HORIZONTAL_ACCELERATION, (figures->accelerationDiagonally.y * -1.0f) * DELAY_IN_HORIZONTAL_ACCELERATION);
		figures->firstPieces->setFillColor(Color::Color(21, 21, 247, 255 * figures->capacity));
		figures->secondPieces->setFillColor(Color::Color(21, 21, 247, 255 * figures->capacity));
		figures->thirdPieces->setFillColor(Color::Color(21, 21, 247, 255 * figures->capacity));
		figures->fourthPieces->setFillColor(Color::Color(21, 21, 247, 255 * figures->capacity));
		figures->fifthPieces->setFillColor(Color::Color(21, 21, 247, 255 * figures->capacity));
		figures->firstPieces->setScale(figures->firstPieces->getScale().x + figures->reductionFactor, figures->firstPieces->getScale().y + figures->reductionFactor);
		figures->secondPieces->setScale(figures->firstPieces->getScale().x + figures->reductionFactor, figures->firstPieces->getScale().y + figures->reductionFactor);
		figures->thirdPieces->setScale(figures->firstPieces->getScale().x + figures->reductionFactor, figures->firstPieces->getScale().y + figures->reductionFactor);
		figures->fourthPieces->setScale(figures->firstPieces->getScale().x + figures->reductionFactor, figures->firstPieces->getScale().y + figures->reductionFactor);
		figures->fifthPieces->setScale(figures->firstPieces->getScale().x + figures->reductionFactor, figures->firstPieces->getScale().y + figures->reductionFactor);
		figures->capacity += 0.00005f;
	}
	else {
		figures->step = 5;
	}
}

void fifthStep(pieces * figures) {
	if (figures->firstPieces->getPosition().x > LEFT_BOUNDARY) {
		if (figures->firstPieces->getPosition().x > (SIZE_WINDOW.x - 100.0f + LEFT_BOUNDARY) / 2.0f) {
			figures->firstPieces->move(HORIZONTAL_SPEED.x * -1.0f, HORIZONTAL_SPEED.y + RATE_DISPLACEMENT * 2.0f);
			figures->secondPieces->move(HORIZONTAL_SPEED.x * -1.0f, HORIZONTAL_SPEED.y + RATE_DISPLACEMENT * 1.0f);
			figures->thirdPieces->move(HORIZONTAL_SPEED.x * -1.0f, HORIZONTAL_SPEED.y + RATE_DISPLACEMENT * 0.0f);
			figures->fourthPieces->move(HORIZONTAL_SPEED.x * -1.0f, HORIZONTAL_SPEED.y - RATE_DISPLACEMENT * 1.0f);
			figures->fifthPieces->move(HORIZONTAL_SPEED.x * -1.0f, HORIZONTAL_SPEED.y - RATE_DISPLACEMENT * 2.0f);
		}
		else if ((figures->firstPieces->getPosition().x <= (SIZE_WINDOW.x - 100.0f + LEFT_BOUNDARY) / 2.0f) && figures->firstPieces->getPosition().x > LEFT_BOUNDARY) {
			figures->firstPieces->move(HORIZONTAL_SPEED.x * -1.0f, HORIZONTAL_SPEED.y - RATE_DISPLACEMENT * 2.0f);
			figures->secondPieces->move(HORIZONTAL_SPEED.x * -1.0f, HORIZONTAL_SPEED.y - RATE_DISPLACEMENT * 1.0f);
			figures->thirdPieces->move(HORIZONTAL_SPEED.x * -1.0f, HORIZONTAL_SPEED.y + RATE_DISPLACEMENT * 0.0f);
			figures->fourthPieces->move(HORIZONTAL_SPEED.x * -1.0f, HORIZONTAL_SPEED.y + RATE_DISPLACEMENT * 1.0f);
			figures->fifthPieces->move(HORIZONTAL_SPEED.x * -1.0f, HORIZONTAL_SPEED.y + RATE_DISPLACEMENT * 2.0f);
		}

	}
	else {
		figures->step = 1;
	}

}

