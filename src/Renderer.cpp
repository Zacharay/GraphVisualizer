#include "Renderer.hpp"

#include <iostream>

#include "Config.hpp"
#include  "Window.hpp"




Renderer::Renderer():m_shader("vertexShader.vert","fragmentShader.frag"),m_animatedShader("animatedEdge.vert", "animatedEdge.frag") {
    const unsigned int windowWidth = Config::getInstance().getWindowWidth();
    const unsigned int windowHeight = Config::getInstance().getWindowHeight();
    m_projMatrix = glm::ortho(0.0f, static_cast<float>(windowWidth), static_cast<float>(windowHeight),0.0f);
}
void Renderer::getNodeVertices(int x,int y,std::vector<Vertex>&vertices,std::vector<unsigned int>&indices) {

    const float radius = Config::getInstance().getNodeRadius();
    int numberOfTriangles = 36;
    float theta = 0.0f;
    float thetaStep = 360.0f /  (float)numberOfTriangles;

    vertices.push_back({{x,y,0.0f},{0.0f,1.0f,0.0f}});
    for (int i=0;i<numberOfTriangles;i++) {
        float xx = static_cast<float>(x + radius * cosf(theta*M_PI/180.0f));
        float yy = static_cast<float>(y + radius * sinf(theta*M_PI/180.0f));

        vertices.push_back({{xx,yy,0.0f},{0.0f,1.0f,0.0f}});
        theta += thetaStep;
    }
    float xx = static_cast<float>(x + radius * cosf(theta*M_PI/180.0f));
    float yy = static_cast<float>(y + radius * sinf(theta*M_PI/180.0f));

    vertices.push_back({{xx,yy,0.0f},{0.0f,1.0f,0.0f}});
    for (int i=1;i<=numberOfTriangles;i++) {
        indices.push_back(0);
        indices.push_back(i);
        indices.push_back(i+1);
    }

}
void Renderer::drawNode(int x, int y,glm::vec3 color)  {
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    getNodeVertices(x,y,vertices,indices);

    // Generate buffers
    unsigned int VBO, VAO, IBO;
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &IBO);
    glGenVertexArrays(1, &VAO);

    // Bind and set up the VAO
    glBindVertexArray(VAO);

    // Bind and upload vertex data to the VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

    // Bind and upload index data to the IBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    // Enable vertex attribute for position (location = 0)
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, pos));

    // Enable vertex attribute for color (location = 1)
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));

    m_shader.useProgram();
    m_shader.setMat4(m_projMatrix, "projection");
    m_shader.setMat4(glm::mat4(1.0f), "view");
    m_shader.setMat4(glm::mat4(1.0f), "model");
    m_shader.setVec3(color,"color");

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
    glDeleteBuffers(1, &IBO);
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}
void Renderer::drawLine(glm::vec3 start,glm::vec3 end,glm::vec3 color) {
    std::vector<float>vertexPositions={
        start.x,start.y,start.z,
        end.x,end.y,end.z,
    };

    // OpenGL Buffer Setup
    unsigned int VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    // Upload vertex data
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexPositions.size() * sizeof(float), vertexPositions.data(), GL_DYNAMIC_DRAW);

    // Set vertex attributes
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float)*3, (void*)0);

    // Use Shader
    m_shader.useProgram();
    m_shader.setMat4(m_projMatrix, "projection");
    m_shader.setMat4(glm::mat4(1.0f), "view");  // Identity view matrix
    m_shader.setMat4(glm::mat4(1.0f), "model"); // No transformation
    m_shader.setVec3(color,"color");
    // Draw line
    glLineWidth(4.0f);  // Set line width
    glDrawArrays(GL_LINES, 0, 2);

    glBindVertexArray(0);

    glBindVertexArray(0);
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}
void Renderer::drawAnimatedEdge(glm::vec3 start, glm::vec3 end,float progress) {
    std::vector<float>vertexPositions={
        start.x,start.y,start.z,
        end.x,end.y,end.z,
    };

    // OpenGL Buffer Setup
    unsigned int VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    // Upload vertex data
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexPositions.size() * sizeof(float), vertexPositions.data(), GL_DYNAMIC_DRAW);

    // Set vertex attributes
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float)*3, (void*)0);


    m_animatedShader.useProgram();
    m_animatedShader.setMat4(m_projMatrix, "projection");
    m_animatedShader.setMat4(glm::mat4(1.0f), "view");  // Identity view matrix
    m_animatedShader.setMat4(glm::mat4(1.0f), "model"); // No transformation
    m_animatedShader.setVec3(start,"edgeStart");
    m_animatedShader.setVec3(end,"edgeEnd");
    m_animatedShader.setFloat(progress,"progress");
    // Draw line
    glLineWidth(4.0f);  // Set line width
    glDrawArrays(GL_LINES, 0, 2);

    glBindVertexArray(0);
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}
