#version 330 core
in vec3 fragmentColor;
in vec3 UV;

out vec3 color;

uniform sampler2D textureSampler;
uniform bool useTexture;

void main()
{
    if (!useTexture)
    {
        color = fragmentColor;
    }
    else
    {
        vec2 actualUV;
        actualUV.x = UV.x;
        actualUV.y = UV.y;
        color = texture2D(textureSampler, actualUV).rgb;
    }
}
