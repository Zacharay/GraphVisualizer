#version 330 core
in vec3 fragPos; // Fragment position along edge

out vec4 FragColor;

uniform float progress;   // Progress (0.0 = start, 1.0 = full)
uniform vec3 edgeStart;
uniform vec3 edgeEnd;

float computeProgress(vec3 fragPos,vec3 edgeStart,vec3 edgeEnd)
{
    vec3 edgeVector = edgeEnd - edgeStart;
    vec3 fragVec = fragPos - edgeStart;

    float edgeLength = length(edgeVector);
    float fragLength = dot(fragVec,normalize(edgeVector));

    return fragLength/edgeLength;
}

void main() {
    // Normalize position along edge (assumes edge is from (0,0) to (1,0))
    float t = computeProgress(fragPos,edgeStart,edgeEnd);

    // If fragment is beyond the progress, discard it (clip effect)
    if (t > progress) {
        // Color based on progress
        FragColor = vec4(0.0f,0.0f,1.0f, 1.0);

    }
    else{
        // Color based on progress
        FragColor = vec4(1.0f,0.0f,0.0f, 1.0);
    }


}