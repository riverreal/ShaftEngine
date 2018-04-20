#include <bgfx_shader.sh>
#include "DefaultFK.sh"

//Textures-----------------------------------
#if USE_ALBEDO == 1
	SAMPLER2D(t_albedo, ALBEDO_REG_NUM - 1);
#endif
#if USE_NORMAL == 1
	SAMPLER2D(t_normal, NORMAL_REG_NUM - 1);
#endif
#if USE_METALLIC == 1
	SAMPLER2D(t_metallic, METALLIC_REG_NUM - 1);
#endif
#if USE_ROUGHNESS == 1
	SAMPLER2D(t_roughness, ROUGHNESS_REG_NUM - 1);
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