#include <bgfx_shader.sh>
#include "DefaultFK.sh"

//Textures-----------------------------------
#if USE_TEX_00 == 1
	SAMPLER2D(t_tex00, TEX_00_REG_NUM - 1);
#endif
#if USE_TEX_01 == 1
	SAMPLER2D(t_tex01, TEX_01_REG_NUM - 1);
#endif
#if USE_TEX_02 == 1
	SAMPLER2D(t_tex02, TEX_02_REG_NUM - 1);
#endif
#if USE_TEX_03 == 1
	SAMPLER2D(t_tex03, TEX_03_REG_NUM - 1);
#endif
#if USE_TEX_04 == 1
	SAMPLER2D(t_tex04, TEX_04_REG_NUM - 1);
#endif
#if USE_TEX_05 == 1
	SAMPLER2D(t_tex05, TEX_05_REG_NUM - 1);
#endif
#if USE_TEX_06 == 1
	SAMPLER2D(t_tex06, TEX_06_REG_NUM - 1);
#endif
#if USE_TEX_07 == 1
	SAMPLER2D(t_tex07, TEX_07_REG_NUM - 1);
#endif
#if USE_TEX_08 == 1
	SAMPLER2D(t_tex08, TEX_08_REG_NUM - 1);
#endif
#if USE_TEX_09 == 1
	SAMPLER2D(t_tex09, TEX_09_REG_NUM - 1);
#endif
#if USE_TEX_10 == 1
	SAMPLER2D(t_tex10, TEX_10_REG_NUM - 1);
#endif
#if USE_TEX_11 == 1
	SAMPLER2D(t_tex11, TEX_11_REG_NUM - 1);
#endif
#if USE_TEX_12 == 1
	SAMPLER2D(t_tex12, TEX_12_REG_NUM - 1);
#endif
#if USE_TEX_13 == 1
	SAMPLER2D(t_tex13, TEX_13_REG_NUM - 1);
#endif
#if USE_TEX_14 == 1
	SAMPLER2D(t_tex14, TEX_14_REG_NUM - 1);
#endif
#if USE_TEX_15 == 1
	SAMPLER2D(t_tex15, TEX_15_REG_NUM - 1);
#endif

//Vector constants
#if USE_CONST_VEC_00 == 1
	uniform vec4 u_constVec00;
#endif
#if USE_CONST_VEC_01 == 1
	uniform vec4 u_constVec01;
#endif
#if USE_CONST_VEC_02 == 1
	uniform vec4 u_constVec02;
#endif
#if USE_CONST_VEC_03 == 1
	uniform vec4 u_constVec03;
#endif
#if USE_CONST_VEC_04 == 1
	uniform vec4 u_constVec04;
#endif
#if USE_CONST_VEC_05 == 1
	uniform vec4 u_constVec05;
#endif
#if USE_CONST_VEC_06 == 1
	uniform vec4 u_constVec06;
#endif
#if USE_CONST_VEC_07 == 1
	uniform vec4 u_constVec07;
#endif
#if USE_CONST_VEC_08 == 1
	uniform vec4 u_constVec08;
#endif
#if USE_CONST_VEC_09 == 1
	uniform vec4 u_constVec09;
#endif
#if USE_CONST_VEC_10 == 1
	uniform vec4 u_constVec10;
#endif
#if USE_CONST_VEC_11 == 1
	uniform vec4 u_constVec11;
#endif
#if USE_CONST_VEC_12 == 1
	uniform vec4 u_constVec12;
#endif
#if USE_CONST_VEC_13 == 1
	uniform vec4 u_constVec13;
#endif
#if USE_CONST_VEC_14 == 1
	uniform vec4 u_constVec14;
#endif
#if USE_CONST_VEC_15 == 1
	uniform vec4 u_constVec15;
#endif

//Lighting-----------------------------------
#if LIGHTING_ON == 1
	uniform vec4 u_packedLightCount; // x = directional light, y = point light, z = spot light
	uniform vec4 u_pointLightRadius[MAX_NUM_POINT_LIGHTS];
	uniform vec4 u_pointLightColor[MAX_NUM_POINT_LIGHTS];
#endif

#if USE_COLOR == 1
	uniform vec4 u_color;
#endif