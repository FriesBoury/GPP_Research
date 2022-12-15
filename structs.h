#pragma once
#include <string>

struct Window
{
	explicit Window( const std::string& title = "Title", float width = 320.0f, 
		float height = 180.0f, bool isVSyncOn = true );

	std::string title;
	float width;
	float height;
	bool isVSyncOn;
};

struct Point2f
{
	Point2f( );
	explicit Point2f( float x, float y );

	float x;
	float y;
};



struct Rectf
{
	Rectf( );
	explicit Rectf( float left, float bottom, float width, float height );
	
	float left;
	float bottom;
	float width;
	float height;

};


struct Color4f
{
	Color4f( );
	explicit Color4f( float r, float g, float b, float a );
	
	float r;
	float g;
	float b;
	float a;
};

struct Circlef
{
	Circlef( );
	explicit Circlef( const Point2f& center, float radius );
	explicit Circlef( float centerX, float centerY, float radius );

	Point2f center;
	float radius;
};


struct Ellipsef
{
	Ellipsef( );
	explicit Ellipsef( const Point2f& center, float radiusX, float radiusY );
	explicit Ellipsef( float centerX, float centerY, float radiusX, float radiusY );

	Point2f center;
	float radiusX;
	float radiusY;
};

struct Vector2
{
	Vector2(){}

	Vector2(float _x, float _y): x{_x}, y{_y}
	{
	}

	float x;
	float y;

	inline auto operator-(const Vector2& v) const
	{
		return Vector2(x - v.x, y - v.y);
	}
	inline auto operator-() const
	{
		return Vector2(-x, -y);
	}
	inline auto operator*(float scale) const
	{
		return Vector2(x * scale, y * scale);
	}
	inline auto operator/(float scale) const
	{
		const auto revScale = 1.0f / scale;
		return Vector2(x * revScale, y * revScale);
	}

	//=== Compound Assignment Operators === //auto& for type deduction
	inline auto& operator+=(const Vector2& v)
	{
		x += v.x; y += v.y; return *this;
	}
	inline auto& operator-=(const Vector2& v)
	{
		x -= v.x; y -= v.y; return *this;
	}
	inline auto& operator*=(float scale)
	{
		x *= scale; y *= scale; return *this;
	}
	inline auto& operator/=(float scale)
	{
		const auto revScale = 1.0f / scale;
		x *= revScale; y *= revScale; return *this;
	}



	//=== Relational Operators ===
	inline auto operator==(const Vector2& v) const /*Check if both components are equal*/
	{
		return x == v.x && y == v.y;
	}
	inline auto operator!=(const Vector2& v) const /*Check if one or both components are NOT equal*/
	{
		return !(*this == v);
	}

	//=== Member Access Operators ===
	inline float operator[](unsigned int i) const
	{
		return ((i == 0) ? x : y);
		//if (i >= 0 && i < 2)
		//	return ((i == 0) ? x : y);
		//throw; /*TODO : specify error thrown;*/
	}
	inline float& operator[](unsigned int i)
	{
		return ((i == 0) ? x : y);
		//if (i >= 0 && i < 2)
		//	return ((i == 0) ? x : y);
		//throw; /*TODO : specify error thrown;*/
	}

	//=== Internal Vector Functions ===
	inline auto Dot(const Vector2& v) const
	{
		return x * v.x + y * v.y;
	}

	inline auto Cross(const Vector2& v) const
	{
		return x * v.y - y * v.x;
	}

	inline auto GetAbs() const
	{
		return Vector2(abs(x), abs(y));
	}

	inline auto MagnitudeSquared() const
	{
		return x * x + y * y;
	}

	inline auto Magnitude() const
	{
		return sqrtf(MagnitudeSquared());
	}

	inline float Normalize()
	{
		auto m = Magnitude();
		if (m == 0.f)
		{
			*this = Vector2{0.f,0.f};
			return 0.f;
		}

		auto invM = 1.f / m;
		x *= invM;
		y *= invM;

		return m;
	}

	inline Vector2 GetNormalized() const /*! Returns a normalized copy of this vector. This vector does not change.*/
	{
		auto v = Vector2(*this);
		v.Normalize();
		return v;
	}

	inline auto DistanceSquared(const Vector2& v) const
	{
		float dX = v.x - x;
		float dY = v.y - y;

		return dX * dX + dY * dY;
	}

	inline auto Distance(const Vector2& v) const
	{
		return sqrtf(DistanceSquared(v));
	}

	inline auto Clamp(float max)
	{
		auto scale = max / Magnitude();
		scale = scale < 1.f ? scale : 1.f;
		return *this * scale;
	}
};



