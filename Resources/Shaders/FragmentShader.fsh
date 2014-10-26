#version 330 core
in vec3 fragmentColor;
in vec2 UV;
out vec3 color;
uniform sampler2D textureSampler;
void main()
{
    if (UV.x == 0 && UV.y == 0)
        color = fragmentColor;
    else
        color = texture2D(textureSampler, UV).rgb;
}
