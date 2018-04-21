$input v_wpos, v_view, v_normal, v_tangent, v_bitangent, v_texcoord0

#include "InputDefiner.sh"

void main()
{
	vec4 finalColor = vec4(1.0, 1.0, 1.0, 1.0);
#if USE_CONST_VEC_00 == 1
	finalColor = u_constVec00;
#endif

#if LIGHTING_ON == 1
#endif
	
	gl_FragColor = finalColor;
}