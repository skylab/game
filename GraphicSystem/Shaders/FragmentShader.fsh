#version 330 core
in vec3 fragmentColor;
out vec3 color;
void main()
{
  //gl_FragColor = color;
    color = fragmentColor;
}
