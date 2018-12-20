#version 330

// Entrées du shader
in vec3 vPosition_vs; // Position du sommet transformé dans l'espace View
in vec3 vNormal_vs; // Normale du sommet transformé dans l'espace View
in vec2 vTexCoords; // Coordonnées de texture du sommet

out vec3 fFragColor;

uniform sampler2D uEarthTexture;
uniform sampler2D uCloudTexture;

void main() {
//  fFragColor = normalize(vNormal_vs);
  vec3 tx1 = texture(uEarthTexture, vTexCoords).xyz;
  vec3 tx2 = texture(uCloudTexture, vTexCoords).xyz;
  fFragColor = tx1+tx2;
}
