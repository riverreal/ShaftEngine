#pragma once

#include <Shaft/Core.h>
#include <glm/matrix.hpp>

namespace Shaft
{
	struct Matrix
	{
		Matrix()
		{}

		Matrix(float s)
		{
			values[0] = Vec4f(s, 0, 0, 0);
			values[1] = Vec4f(0, s, 0, 0);
			values[2] = Vec4f(0, 0, s, 0);
			values[3] = Vec4f(0, 0, 0, s);
		}

		glm::mat4 GetMat()
		{
			glm::mat4 mat;
			mat[0][0] = values[0].x;
			mat[0][1] = values[0].y;
			mat[0][2] = values[0].z;
			mat[0][3] = values[0].w;

			mat[1][0] = values[1].x;
			mat[1][1] = values[1].y;
			mat[1][2] = values[1].z;
			mat[1][3] = values[1].w;

			mat[2][0] = values[2].x;
			mat[2][1] = values[2].y;
			mat[2][2] = values[2].z;
			mat[2][3] = values[2].w;

			mat[3][0] = values[3].x;
			mat[3][1] = values[3].y;
			mat[3][2] = values[3].z;
			mat[3][3] = values[3].w;
			return mat;
		}

		void SetMat(const glm::mat4& mat)
		{
			values[0].x = mat[0][0];
			values[0].y = mat[0][1];
			values[0].z = mat[0][2];
			values[0].w = mat[0][3];

			values[1].x = mat[1][0];
			values[1].y = mat[1][1];
			values[1].z = mat[1][2];
			values[1].w = mat[1][3];

			values[2].x = mat[2][0];
			values[2].y = mat[2][1];
			values[2].z = mat[2][2];
			values[2].w = mat[2][3];

			values[3].x = mat[3][0];
			values[3].y = mat[3][1];
			values[3].z = mat[3][2];
			values[3].w = mat[3][3];
		}

		Vec4f values[4];
	};
}