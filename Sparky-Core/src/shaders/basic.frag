#version 330 core

layout (location=0) out vec4 color;

uniform vec2 light_pos;
uniform sampler2D tex;

in DATA
{
	vec4 position;
	vec4 color;
}fs_in;

void main()
{
	
	float intensity=1.0/length(fs_in.position.xy-light_pos);
	gl_FragColor=texture2D(tex,gl_TexCoord[0].st);
}