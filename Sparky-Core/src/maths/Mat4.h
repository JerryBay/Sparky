#pragma once

namespace Sparky
{
	namespace Maths
	{
		struct Mat4
		{
			union 
			{
				float elements[4 * 4];
				Vec4 columns[4];
			};


			Mat4();
			Mat4(float diagonal);

			Vec4 getcolumn(int index)
			{
				index *= 4;
				return Vec4(elements[index], elements[index + 1], elements[index + 2], elements[index + 3]);
			}

			Mat4& multiply(const Mat4& other);
			Mat4& operator*=(const Mat4& other);
			friend Mat4 operator*(Mat4 left, const Mat4& right);


			static Mat4 identity();
			static Mat4 orthographic(float left,float right,float buttom,float top,float near,float far);
			static Mat4 perspective(float fov, float aspectratio, float near, float far);
			static Mat4 translation(const Vec3& translation);
			static Mat4 rotation(float angle, const Vec3& axis);
			static Mat4 scale(const Vec3& scale);
		};
	}
}

