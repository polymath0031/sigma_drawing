#include "circle.h"

#include <vector>
#include <string>

int main()
{
	int r = 20;
	Color color = {255, 0, 0, 255};
	std::vector<Circle> circles;

	Color backgrounds[] = {RAYWHITE, LIGHTGRAY, DARKGRAY};
	int backgroundIndex = 0;
	Color background = backgrounds[backgroundIndex];
	std::string backgroundName = "ray white";
	int backgroundCount = sizeof(backgrounds) / sizeof(Color);// 3

	//TraceLog(LOG_INFO, TextFormat("no of backgrounds: %i", backgroundCount));

	InitWindow(1280, 800, "SIGMA DRAWING");
	SetTargetFPS(60);

	while(!WindowShouldClose())
	{
		//TraceLog(LOG_INFO, TextFormat("background Index: %i", backgroundIndex));
		//TraceLog(LOG_INFO, TextFormat("background Count: %i", backgroundCount));

		// inputs
		if(IsMouseButtonDown(MOUSE_LEFT_BUTTON))
		{// create object and store in vector
			Vector2 m = GetMousePosition();
			circles.push_back({m.x, m.y, r, color});
		}

		// increase or decrease radius
		if(IsKeyPressed(KEY_R)) r += 2;
		if(IsKeyPressed(KEY_T)) r -= 2;

		// increase or decrease red value
		if(IsKeyDown(KEY_ONE)) color.r -= 1;
		if(IsKeyDown(KEY_TWO)) color.r += 1;

		// increase or decrease green value
		if(IsKeyDown(KEY_THREE)) color.g -= 1;
		if(IsKeyDown(KEY_FOUR)) color.g += 1;

		// increase or decrease blue value
		if(IsKeyDown(KEY_FIVE)) color.b -= 1;
		if(IsKeyDown(KEY_SIX)) color.b += 1;

		// increase or decrease alpha value
		if(IsKeyDown(KEY_SEVEN)) color.a -= 1;
		if(IsKeyDown(KEY_EIGHT)) color.a += 1;

		// change background
		if (IsKeyPressed(KEY_Z))
		{
			// backgroundIndex starts from 0 cuz its array index
			if (backgroundIndex + 1 >= backgroundCount)
			{
				backgroundIndex = 0;
			}else
			{
				backgroundIndex++;
			}

			background = backgrounds[backgroundIndex];

			switch(backgroundIndex)
			{
			case 0: backgroundName = "ray white"; break;
			case 1: backgroundName = "light gray"; break;
			case 2: backgroundName = "dark gray"; break;
			}
		}

		BeginDrawing();
		ClearBackground(background);

		// draw circles
		for(const Circle& c : circles)
		{
			c.draw();
		}

		DrawText(TextFormat("no of circles: %i", circles.size()), 10, 10, 40, DARKGRAY);
		DrawText(TextFormat("radius: %i [R & T]", r), 10, 50, 40, DARKGRAY);
		DrawText(TextFormat("red value: %i [1 & 2]", color.r), 10, 90, 40, DARKGRAY);
		DrawText(TextFormat("green value: %i [3 & 4]", color.g), 10, 130, 40, DARKGRAY);
		DrawText(TextFormat("blue value: %i [5 & 6]", color.b), 10, 170, 40, DARKGRAY);
		DrawText(TextFormat("alpha value: %i [7 & 8]", color.a), 10, 210, 40, DARKGRAY);
		DrawText(TextFormat("background: %s [Z]", backgroundName.c_str()), 10, 250, 40, DARKGRAY);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
