#version 330 core
layout (location = 0) in vec3 coord;
layout (location = 1) in vec3 color;
out vec3 fragmentColor;
uniform mat4 PVM;
void main() {
    if (PVM[0][0] != 0)
        gl_Position = PVM * vec4(coord, 1.0);
    else
        gl_Position = vec4(coord, 1.0);
    fragmentColor = color;
}
