#pragma once

#include <Shaft/Core.h>

namespace Shaft
{
	struct Vec2f
	{
		Vec2f()
			:x(0.0f), y(0.0f)
		{};

		Vec2f(float x, float y)
			:x(x), y(y)
		{};

		Vec2f(float xy)
			:x(xy), y(xy)
		{};

		float x;
		float y;
	};

	struct Vec3f
	{
		Vec3f()
			:x(0.0f), y(0.0f), z(0.0f)
		{};

		Vec3f(float x, float y, float z)
			:x(x), y(y), z(z)
		{};

		Vec3f(float xyz)
			:x(xyz), y(xyz), z(xyz)
		{};

		Vec3f FastNormalize() const
		{
			float lengSqr = x * x + y * y + z * z;

			int leng = *(int*)&lengSqr;

			if (leng == 0)
			{
				return 0.0f;
			}
			else
			{
				float xhalf = 0.5f * lengSqr;
				leng = 0x5f375a86 - (leng >> 1);
				lengSqr = *(float*)&leng;
				lengSqr = lengSqr * (1.5f - xhalf * lengSqr * lengSqr);
			}

			Vec3f normalized(x, y, z);

			normalized.x *= lengSqr;
			normalized.y *= lengSqr;
			normalized.z *= lengSqr;

			return normalized;
		}

		Vec3f Cross(const Vec3f& v) const
		{
			Vec3f result;
			result.x = y * v.z - v.y * z;
			result.y = v.x * z - x * v.z;
			result.z = x * v.y - v.x * y;

			return result;
		}

		float Dot(const Vec3f& d) const
		{
			float product = 0;
			product += x * d.x;
			product += y * d.y;
			product += z * d.z;

			return product;
		}

		float x;
		float y;
		float z;
	};

	struct Vec4f
	{
		Vec4f()
			:x(0.0f), y(0.0f), z(0.0f), w(0.0f)
		{};

		Vec4f(float x, float y, float z, float w)
			:x(x), y(y), z(z), w(w)
		{};

		Vec4f(float xyzw)
			:x(xyzw), y(xyzw), z(xyzw), w(xyzw)
		{};

		float x;
		float y;
		float z;
		float w;
	};

	struct Color
	{
		Color()
			:r(0.0f), g(0.0f), b(0.0f), a(0.0f)
		{};

		Color(float x, float y, float z, float w)
			:r(x), g(y), b(z), a(w)
		{};

		Color(float rgba)
			:r(rgba), g(rgba), b(rgba), a(rgba)
		{};

		//RGBA format
		uint32 GetBitColor()
		{
			//convert to 8bits and return packed
			uint8 r8 = static_cast<uint8>(r * 255.0f);
			uint8 g8 = static_cast<uint8>(g * 255.0f);
			uint8 b8 = static_cast<uint8>(b * 255.0f);
			uint8 a8 = static_cast<uint8>(a * 255.0f);
			return ((r8 << 24) & 0xff + (g8<<16) & 0xff + (b8 << 8) & 0xff + a8 & 0xff);
		}

		float r;
		float g;
		float b;
		float a;
	};
}