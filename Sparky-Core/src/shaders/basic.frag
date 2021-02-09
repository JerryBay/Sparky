#version 330 core

layout (location=0) out vec4 color;

uniform vec2 light_pos;
uniform sampler2D tex;

in DATA
{
	vec4 position;
	vec4 color;
}fs_in;

varying vec2 tc;

void main()
{
	
	//float intensity=1.0/length(fs_in.position.xy-light_pos);
	//color=fs_in.color*intensity;
	gl_FragColor=texture2D(tex,gl_TexCoord[0].st);
	gl_FragColor=vec4(tc.x,0,0,1);
}