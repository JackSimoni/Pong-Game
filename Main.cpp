#include <raylib.h>
#include <cmath>
#include <string>

using namespace std;

struct Ball
{
	float x, y;
	float radius;
	float speedx, speedy;

	void Draw()
	{
		DrawCircle((int)x, (int)y, radius, WHITE);
	}
};

struct Rect
{
	float x, y;
	float width;
	float height;
	float speedy;

	void Draw()
	{
		DrawRectangle((int)x, (int)y, (int)width, (int)height, WHITE);
	}
};

int main()
{

	InitWindow(800, 600, "Pong - Jack Simoni");
	SetWindowState(FLAG_VSYNC_HINT);

	Ball ball1;
	ball1.x = GetScreenWidth() / 2;
	ball1.y = GetScreenHeight() / 2;
	ball1.radius = 10.0f;
	ball1.speedx = -400.0f;
	ball1.speedy = -300.0f;
	// Declaring Characteristics of Ball Using Struct
	Rect rect1;
	rect1.x = GetScreenWidth() / 2 - 350;
	rect1.y = GetScreenHeight() / 2 - 50;
	rect1.width = 10.0f;
	rect1.height = 100.0f;
	rect1.speedy = 500.0f;
	// Declaring Characteristics of Rectangles Using Structs
	Rect rect2;
	rect2.x = GetScreenWidth() / 2 + 350;
	rect2.y = GetScreenHeight() / 2 - 50;
	rect2.width = 10.0f;
	rect2.height = 100.0f;
	rect2.speedy = 500.0f;

	const char* counter1 = 0;
	const char* counter2 = 0;

	while (!WindowShouldClose())
	{

		ball1.x += ball1.speedx * GetFrameTime();
		ball1.y += ball1.speedy * GetFrameTime();


		if ((ball1.y + ball1.radius) >= GetScreenHeight() || (ball1.y - ball1.radius) <= 0)
		{
			ball1.speedy *= -1;
		}

		if (ball1.x <= rect1.x && ball1.y >= rect1.y && ball1.y <= rect1.y + rect1.height && ball1.x > 50 - ball1.radius)
		{
			ball1.speedx *= -1.1;
		}

		if (ball1.x >= rect2.x && ball1.y >= rect2.y && ball1.y <= rect2.y + rect2.height && ball1.x > 750 + ball1.radius)
		{
			ball1.speedx *= -1.1;
		}

		if (IsKeyDown(KEY_W))
		{
			rect1.y -= rect1.speedy * GetFrameTime();
		}

		if (IsKeyDown(KEY_S))
		{
			rect1.y += rect1.speedy * GetFrameTime();
		}

		if (IsKeyDown(KEY_UP))
		{
			rect2.y -= rect2.speedy * GetFrameTime();
		}

		if (IsKeyDown(KEY_DOWN))
		{
			rect2.y += rect2.speedy * GetFrameTime();
		}

		const char* winner = "null";

		BeginDrawing();

		ClearBackground(BLACK);
		ball1.Draw();
		rect1.Draw();
		rect2.Draw();

		if (ball1.x < 0)
		{
			winner = "Right Player Wins!";
		}

		else if (ball1.x > GetScreenWidth())
		{
			winner = "Left Player Wins!";
		}

		if (ball1.x < 0 && IsKeyPressed(KEY_SPACE))
		{
			counter2++;
		}

		else if (ball1.x > GetScreenWidth() && IsKeyPressed(KEY_SPACE))
		{
			counter1++;
		}


		DrawText(TextFormat("Score: %i %i", counter1, counter2), GetScreenWidth() / 2 - 50, 10, 20, GREEN);

		if (winner != "null")
		{
			DrawText(winner, GetScreenWidth() / 2 - (MeasureText(winner, 50) / 2), GetScreenHeight() / 2, 50, GREEN);
		}

		if (winner == "Right Player Wins!" && IsKeyPressed(KEY_SPACE))
		{
			ball1.x = GetScreenWidth() / 2;
			ball1.y = GetScreenHeight() / 2;
			ball1.radius = 10.0f;
			ball1.speedx = -1000.0f;
			ball1.speedy = -200.0f;
			rect1.x = GetScreenWidth() / 2 - 350;
			rect1.y = GetScreenHeight() / 2 - 50;
			rect2.x = GetScreenWidth() / 2 + 350;
			rect2.y = GetScreenHeight() / 2 - 50;
			winner = "null";
		}

		if (winner == "Left Player Wins!" && IsKeyPressed(KEY_SPACE))
		{
			ball1.x = GetScreenWidth() / 2;
			ball1.y = GetScreenHeight() / 2;
			ball1.radius = 10.0f;
			ball1.speedx = -1000.0f;
			ball1.speedy = -200.0f;
			rect1.x = GetScreenWidth() / 2 - 350;
			rect1.y = GetScreenHeight() / 2 - 50;
			rect2.x = GetScreenWidth() / 2 + 350;
			rect2.y = GetScreenHeight() / 2 - 50;
			winner = "null";
		}


		EndDrawing();


	}

	CloseWindow();

	return 0;

}