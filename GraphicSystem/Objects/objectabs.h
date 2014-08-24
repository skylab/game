#ifndef OBJECTABS_H
#define OBJECTABS_H

#include "../pregraphic.h"

class ObjectAbs
{
public:
    ObjectAbs(glm::vec3 position) throw();
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

private:
    virtual void FillVertexArray() = 0;
    virtual void FillColorArray() = 0;
    glm::vec3 mPosition;
};

#endif // OBJECTABS_H
