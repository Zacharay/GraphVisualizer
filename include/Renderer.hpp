#pragma once
#include "Shader.hpp"
#include <vector>


struct Vertex {
      glm::vec3 pos;
      glm::vec3 color;
};
class Renderer{
private:
      Shader m_shader;
      Shader m_animatedShader;
      glm::mat4 m_projMatrix;
public:
      Renderer();
      void drawLine(glm::vec3 start, glm::vec3 end,glm::vec3 color);
      void drawNode(int x,int y,glm::vec3 color);
      void drawAnimatedEdge(glm::vec3 start, glm::vec3 end,float progress);
      void getNodeVertices(int x,int y,std::vector<Vertex>&vertices,std::vector<unsigned int>&indices);
};