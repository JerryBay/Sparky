#include "MathsH.h"
#include "Mat4.h"

namespace Sparky
{
	namespace Maths
	{
		std::ostream& operator<<(std::ostream& stream, const Mat4& mat)
		{
			stream << "Mat4: (" << std::endl
				<< mat.columns[0] << std::endl
				<< mat.columns[1] << std::endl
				<< mat.columns[2] << std::endl
				<< mat.columns[3] << std::endl 
				<<")"<< std::endl;
			return stream;
		}

		Vec3 operator*(const Mat4& left, const Vec3& right)
		{
			return left.multiply(right);
		}

		Vec4 operator*(const Mat4& left, const Vec4& right)
		{
			return left.multiply(right);
		}

		Mat4::Mat4()
		{
			for (int i = 0; i < 4 * 4; i++)
			{
				elements[i] = 0.0f;
			}
		}

		Mat4::Mat4(float diagonal)
		{
			for (int i = 0; i < 4 * 4; i++)
			{
				elements[i] = 0.0f;
			}
			elements[0 + 0 * 4] = diagonal;
			elements[1 + 1 * 4] = diagonal;
			elements[2 + 2 * 4] = diagonal;
			elements[3 + 3 * 4] = diagonal;
		}

		Mat4::Mat4(float* datas, int size)
		{
			for (int i = 0; i < 4 * 4; i++)
			{
				elements[i] = 0.0f;
			}
			memcpy(elements,datas,size*sizeof(float));
		}

		Mat4 Mat4::identity()
		{
			return Mat4(1.0f);
		}

		Mat4 Mat4::multiply(const Mat4& other) const
		{
			float datas[16];
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					float sum = 0.0f;
					for (int e = 0; e < 4; e++)
					{
						sum += elements[x + e * 4] * other.elements[e + y * 4];
					}
					datas[x + y * 4] = sum;
				}
			}
			Mat4 result(datas, 16);
			return result;
		}

		Vec3 Mat4::multiply(const Vec3& other) const
		{
			return Vec3(
				columns[0].x * other.x + columns[1].x * other.y + columns[2].x * other.z ,
				columns[0].y * other.x + columns[1].y * other.y + columns[2].y * other.z ,
				columns[0].z * other.x + columns[1].z * other.y + columns[2].z * other.z 
			);
		}

		Vec4 Mat4::multiply(const Vec4& other) const
		{
			return Vec4(
				columns[0].x * other.x+columns[1].x*other.y+columns[2].x*other.z+columns[3].x*other.w,
				columns[0].y * other.x+columns[1].y*other.y+columns[2].y*other.z+columns[3].y*other.w,
				columns[0].z * other.x+columns[1].z*other.y+columns[2].z*other.z+columns[3].z*other.w,
				columns[0].w * other.x+columns[1].w*other.y+columns[2].w*other.z+columns[3].w*other.w
			);
		}

		Mat4 operator*(Mat4 left, const Mat4& right)
		{
			return left.multiply(right);
		}

		Mat4& Mat4::operator*=(const Mat4& other)
		{
			float datas[16];
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					float sum = 0.0f;
					for (int e = 0; e < 4; e++)
					{
						sum += elements[x + e * 4] * other.elements[e + y * 4];
					}
					datas[x + y * 4] = sum;
				}
			}
			memcpy(elements, datas, 4 * 4 * sizeof(float));
			return *this;
		}

		Mat4 Mat4::orthographic(float left, float right, float buttom, float top, float near, float far)
		{
			Mat4 result(1.0f);

			result.elements[0 + 0 * 4] = 2.0f / (right - left);
			result.elements[1 + 1 * 4] = 2.0f / (top - buttom);
			result.elements[2 + 2 * 4] = 2.0f / (near - far);

			result.elements[0 + 3 * 4] = (left + right) / (left - right);
			result.elements[1 + 3 * 4] = (buttom + top) / (buttom - top);
			result.elements[2 + 3 * 4] = (far + near) / (far - near);

			return result;
		}

		Mat4 Mat4::perspective(float fov, float aspectratio, float near, float far)
		{
			Mat4 result(1.0f);

			float q = 1.0f / (float)tan(toRadian(fov * 0.5f));
			float a = q / aspectratio;
			float b = (near + far) / (near - far);
			float c = (2.0f * near * far) / (near - far);

			result.elements[0 + 0 * 4] = a;
			result.elements[1 + 1 * 4] = q;
			result.elements[2 + 2 * 4] = b;
			result.elements[3 + 2 * 4] = -1.0f;
			result.elements[2 + 3 * 4] = c;

			return result;
		}

		Mat4 Mat4::translation(const Vec3& translation)
		{
			Mat4 result(1.0f);

			result.elements[0 + 3 * 4] = translation.x;
			result.elements[1 + 3 * 4] = translation.y;
			result.elements[2 + 3 * 4] = translation.z;

			return result;
		}

		Mat4 Mat4::rotation(float angle, const Vec3& axis)
		{
			Mat4 result(1.0f);

			float r = toRadian(angle);
			float c = cos(r);
			float s = sin(r);
			float omc = 1.0f - c;

			float x = axis.x;
			float y = axis.y;
			float z = axis.z;

			result.elements[0 + 0 * 4] = x * omc + c;
			result.elements[1 + 0 * 4] = y * x * omc + z * s;
			result.elements[2 + 0 * 4] = x * z * omc - y * s;

			result.elements[0 + 1 * 4] = x * y * omc - z * s;
			result.elements[1 + 1 * 4] = y * omc + c;
			result.elements[2 + 1 * 4] = y * z * omc + x * s;

			result.elements[0 + 2 * 4] = x * z * omc + y * s;
			result.elements[1 + 2 * 4] = y * z * omc - x * s;
			result.elements[2 + 2 * 4] = z * omc + c;

			return result;
		}

		Mat4 Mat4::scale(const Vec3& scale)
		{
			Mat4 result(1.0f);

			result.elements[0 + 0 * 4] = scale.x;
			result.elements[1 + 1 * 4] = scale.y;
			result.elements[2 + 2 * 4] = scale.z;

			return result;
		}
	}
}