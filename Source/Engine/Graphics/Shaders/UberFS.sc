$input v_wpos, v_view, v_normal, v_tangent, v_bitangent, v_texcoord0

#include "InputDefiner.sh"

void main()
{
	vec4 finalColor = vec4(1.0, 1.0, 1.0, 1.0);
#if USE_V_COLOR == 1
	finalColor = u_vColor;
#endif

#if USE_ALBEDO == 1
	finalColor *= t_albedo;
#endif

#if LIGHTING_ON == 1
#endif
	
	gl_FragColor = finalColor;
}