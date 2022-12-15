#include "pch.h"
#include "Ball.h"

using namespace utils;

void Ball::Draw() const
{
	SetColor(1.0f, 0.5f, 0.0f);
	FillEllipse(m_Position.x, m_Position.y, m_Radius * 2, m_Radius * 2);
}

void Ball::Update(float dTime)
{
	m_Velocity.y -=  9.81f * 50.f* dTime;
	m_Position += m_Velocity * dTime;

	//collision detection
	bool hit = false;
	if (m_Position.y + m_Radius >= m_windowHeight)
	{
		m_Velocity.y *= -1.f;
		m_Position.y = m_windowHeight - m_Radius;
		hit = true;
	}
	if (m_Position.y - m_Radius <= 0.f)
	{
		m_Velocity.y *= -1.f;
		m_Position.y = m_Radius;
		hit = true;
	}

	if (m_Position.x - m_Radius <= 0.f)
	{
		m_Velocity.x *= -1.f;
		m_Position.x = m_Radius;
		hit = true;
	}

	if (m_Position.x + m_Radius >= m_windowWidth)
	{
		m_Velocity.x *= -1.f;
		m_Position.x = m_windowWidth - m_Radius;
		hit = true;
	}

	if (hit)
	{
		m_Velocity *= 0.95f;
	}
}
