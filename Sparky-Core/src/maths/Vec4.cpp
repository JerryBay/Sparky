#include "Vec4.h"

namespace Sparky
{
	namespace Maths
	{
		std::ostream& operator<<(std::ostream& stream, const Vec4& vector)
		{
			stream << "Vec4:(" << vector.x << "," << vector.y << "," << vector.z << "," << vector.w << ")";
			return stream;
		}

		Vec4 operator+(Vec4 left, const Vec4& right)
		{
			return left.add(right);
		}

		Vec4 operator-(Vec4 left, const Vec4& right)
		{
			return left.substract(right);
		}

		Vec4 operator*(Vec4 left, const Vec4& right)
		{
			return left.multiply(right);
		}

		Vec4 operator/(Vec4 left, const Vec4& right)
		{
			return left.divide(right);
		}

		Vec4::Vec4()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
			w = 0.0f;
		}

		Vec4::Vec4(const float& x, const float& y, const float& z, const float& w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		Vec4& Vec4::add(const Vec4& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;
			return *this;
		}

		Vec4& Vec4::substract(const Vec4& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;
			return *this;
		}

		Vec4& Vec4::multiply(const Vec4& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;
			return *this;
		}

		Vec4& Vec4::divide(const Vec4& other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
			w /= other.w;
			return *this;
		}

		Vec4& Vec4::operator+=(const Vec4& other)
		{
			add(other);
			return *this;
		}

		Vec4& Vec4::operator-=(const Vec4& other)
		{
			substract(other);
			return *this;
		}

		Vec4& Vec4::operator*=(const Vec4& other)
		{
			multiply(other);
			return *this;
		}

		Vec4& Vec4::operator/=(const Vec4& other)
		{
			divide(other);
			return *this;
		}

		bool Vec4::operator==(const Vec4& other)
		{
			return x == other.x && y == other.y&& z == other.z && w == other.w;
		}

		bool Vec4::operator!=(const Vec4& other)
		{
			return !(*this == other);
		}
	}
}