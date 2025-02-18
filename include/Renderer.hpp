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
      glm::mat4 m_projMatrix;
public:
      Renderer();
      void drawLine(glm::vec3 start, glm::vec3 end);
      void drawNode(int x,int y);
      void getNodeVertices(int x,int y,std::vector<Vertex>&vertices,std::vector<unsigned int>&indices);
};