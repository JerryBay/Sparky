#include "Vec2.h"

namespace Sparky
{
	namespace Maths
	{
		std::ostream& operator<<(std::ostream& stream, const Vec2& vector)
		{
			stream<<"Vec2:(" << vector.x << "," << vector.y<<")";
			return stream;
		}

		Vec2 operator+(Vec2 left, const Vec2& right)
		{
			return left.add(right);
		}

		Vec2 operator-(Vec2 left, const Vec2& right)
		{
			return left.substract(right);
		}

		Vec2 operator*(Vec2 left, const Vec2& right)
		{
			return left.multiply(right);
		}

		Vec2 operator/(Vec2 left, const Vec2& right)
		{
			return left.divide(right);
		}

		Vec2::Vec2()
		{
			x = 0.0f;
			y = 0.0f;
		}

		Vec2::Vec2(const float& x, const float& y)
		{
			this->x = x;
			this->y = y;
		}

		Vec2& Vec2::add(const Vec2& other)
		{
			x += other.x;
			y += other.y;
			return *this;
		}

		Vec2& Vec2::substract(const Vec2& other)
		{
			x -= other.x;
			y -= other.y;
			return *this;
		}

		Vec2& Vec2::multiply(const Vec2& other)
		{
			x *= other.x;
			y *= other.y;
			return *this;
		}

		Vec2& Vec2::divide(const Vec2& other)
		{
			x /= other.x;
			y /= other.y;
			return *this;
		}

		Vec2& Vec2::operator+=(const Vec2& other)
		{
			add(other);
			return *this;
		}

		Vec2& Vec2::operator-=(const Vec2& other)
		{
			substract(other);
			return *this;
		}

		Vec2& Vec2::operator*=(const Vec2& other)
		{
			multiply(other);
			return *this;
		}

		Vec2& Vec2::operator/=(const Vec2& other)
		{
			divide(other);
			return *this;
		}

		bool Vec2::operator==(const Vec2& other)
		{
			return x == other.x && y == other.y;
		}

		bool Vec2::operator!=(const Vec2& other)
		{
			return !(*this==other);
		}
	}
}