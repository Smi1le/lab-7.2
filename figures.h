#pragma once
#include "config.h"
#include <vector>

using namespace std;
using namespace sf;

struct pieces {
	RectangleShape *rectangle;
	RenderWindow *window;
	RectangleShape *firstPieces;
	RectangleShape *secondPieces;
	RectangleShape *thirdPieces;
	RectangleShape *fourthPieces;
	RectangleShape *fifthPieces;
	unsigned int step = 1;
	int i = 0;
	bool determineReductionFactor = true;
	float reductionFactor;
	Vector2f breakpoint;
	Vector2f accelerationDiagonally;
	unsigned int distanceBetweenFigures;
	float capacity = 1.0f;
	bool useBreakpoint = true;
	
};

void createPieces(pieces * pieces);
void firstStep(pieces * pieces);
void secondStep(pieces * pieces);
void thirdStep(pieces * pieces);
void fourthStep(pieces * pieces);
void fifthStep(pieces * pieces);