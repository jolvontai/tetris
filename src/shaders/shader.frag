#version 300 es

precision highp float;

in vec3 ourColor;
in vec2 TexCoord;

out vec4 color;

uniform sampler2D ourTexture;

void main()
{
color = texture(ourTexture, TexCoord);
}
