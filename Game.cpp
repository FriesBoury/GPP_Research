#include "pch.h"
#include "Game.h"
#include "Ball.h"
//Basic game functions
#pragma region gameFunctions											
void Start()
{
	m_pBall = new Ball({ g_WindowWidth / 2.f, g_WindowHeight / 2.f }, 5.f, g_WindowWidth, g_WindowHeight);
	// initialize game resources here
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);

	// Put your own draw statements here
	m_pBall->Draw();
}

void Update(float elapsedSec)
{
	m_pBall->Update(elapsedSec);
}

void End()
{
	// free game resources here
	delete m_pBall;
	m_pBall = nullptr;
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	const float multiPlier = 10.f;
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	Vector2 mousePos{ float(e.x), float(g_WindowHeight - e.y) };
	m_pBall->SetVelocity((mousePos - m_pBall->GetPosition()) * multiPlier);
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	////std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//{
	//	//std::cout << "Left mouse button released\n";
	//	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	//	break;
	//}
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

#pragma endregion ownDefinitions