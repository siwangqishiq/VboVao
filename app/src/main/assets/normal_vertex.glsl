#version es 300
precision mediump float;

in layout(location = 0) vec4 a_color;
in layout(location = 1) vec3 a_pos;
out vec4 f_color;
void main(){
    f_color = a_color;
    gl_position = a_pos;
}

