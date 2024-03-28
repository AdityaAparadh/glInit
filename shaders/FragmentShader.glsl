#version 330 core

//in vec3 ourColor;
in vec2 texCoordinates;

out vec4 color;

uniform sampler2D ourTexture;
uniform vec4 someColor;

void main() {
    color = texture(ourTexture, texCoordinates)  ;
    // color = vec4(ourColor, 1.0)  ;
      // color = texture(ourTexture, texCoordinates) * vec4(ourColor, 1.0) ;
     //color = someColor;
}