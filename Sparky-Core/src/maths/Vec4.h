#pragma once

namespace Sparky
{
	namespace Maths
	{
		struct Vec4
		{
			friend std::ostream& operator<<(std::ostream& stream, const Vec4& vector);
			friend Vec4 operator+(Vec4 left,const Vec4& right);
			friend Vec4 operator-(Vec4 left,const Vec4& right);
			friend Vec4 operator*(Vec4 left,const Vec4& right);
			friend Vec4 operator/(Vec4 left,const Vec4& right);

			float x, y, z, w;

			Vec4();
			Vec4(const float& x,const float& y, const float& z, const float& w);

			Vec4& add(const Vec4& other);
			Vec4& substract(const Vec4& other);
			Vec4& multiply(const Vec4& other);
			Vec4& divide(const Vec4& other);

			Vec4& operator+=(const Vec4& other);
			Vec4& operator-=(const Vec4& other);
			Vec4& operator*=(const Vec4& other);
			Vec4& operator/=(const Vec4& other);
			bool operator==(const Vec4& other);
			bool operator!=(const Vec4& other);
		};
	}
}