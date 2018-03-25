$input a_position, a_normal, a_tex, a_tangent
$output v_color0

uniform mat4  u_modelViewProj;

void main()
{
	vec3 pos = a_position;
	gl_Position = mul(u_modelViewProj, vec4(pos, 1.0) );
	v_color0 = vec4(0.5, 0.5, 0.5, 1.0);
}
