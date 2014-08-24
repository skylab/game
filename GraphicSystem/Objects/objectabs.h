#ifndef OBJECTABS_H
#define OBJECTABS_H

#include "../pregraphic.h"

class GraphicSystem;

class ObjectAbs
{
public:
    ObjectAbs(glm::vec3 position);
    ~ObjectAbs();

    GLuint &GetVertexVBO();
    GLuint &GetColorVBO();

    const glm::vec3 *GetVertexes();
    const glm::vec3 *GetColor();

    const GLuint &GetVertexArraySize();
    const GLuint &GetVertexQuantity();

    inline glm::vec3 &Position();

protected:
    GLuint mVertexVBO;
    GLuint mColorVBO;

    glm::vec3 *mObjectVertexes;
    glm::vec3 *mObjectColor;

    GLuint mVertexQuantity;
    GLuint mVertexArraySize;

    glm::vec3 mObjectScale;
    glm::vec3 mObjectCoordinate;

private:
    virtual void FillVertexArray() = 0;
    virtual void FillColorArray() = 0;    
};

#endif // OBJECTABS_H
