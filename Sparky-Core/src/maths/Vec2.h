#pragma once

namespace Sparky
{
	namespace Maths
	{
		struct Vec2
		{
			friend std::ostream& operator<<(std::ostream& stream, const Vec2& vector);
			friend Vec2 operator+(Vec2 left,const Vec2& right);
			friend Vec2 operator-(Vec2 left,const Vec2& right);
			friend Vec2 operator*(Vec2 left,const Vec2& right);
			friend Vec2 operator/(Vec2 left,const Vec2& right);

			float x, y;

			Vec2();
			Vec2(const float& x,const float& y);

			Vec2& add(const Vec2& other);
			Vec2& substract(const Vec2& other);
			Vec2& multiply(const Vec2& other);
			Vec2& divide(const Vec2& other);

			Vec2& operator+=(const Vec2& other);
			Vec2& operator-=(const Vec2& other);
			Vec2& operator*=(const Vec2& other);
			Vec2& operator/=(const Vec2& other);
			bool operator==(const Vec2& other);
			bool operator!=(const Vec2& other);
		};
	}
}