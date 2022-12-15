#pragma once
#include "structs.h"

class Ball
{
public:

	Ball(Vector2 pos, float radius, float windowWidth, float windowHeight) 
		:m_Position{pos}
		,m_Velocity{0,0}
		,m_Radius{radius}
		,m_windowWidth{windowWidth}
		,m_windowHeight{windowHeight}
	{}

	inline Vector2 GetPosition() const { return m_Position; }
	inline Vector2 GetVelocity() const { return m_Velocity; }
	inline void SetVelocity(Vector2 velocity) { m_Velocity = velocity; }
	void Draw() const;
	void Update( float dTime);
	
private:
	
	Vector2 m_Position{};
	Vector2 m_Velocity{};
	float m_Radius{1.f};
	float m_windowWidth{};
	float m_windowHeight{};
};

