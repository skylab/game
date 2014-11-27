#include "graphiclevel.h"
#include "pregraphic.h"
#include "../../Managers/shadermanager.h"
#include "../../Managers/scenemanager.h"

GraphicLevel::GraphicLevel() : mVBO(0), mScene(nullptr), mVisible(true), mShaderProgramm(nullptr), mDrawPrimitives(GL_TRIANGLES), mTextureName(nullptr)
{
    mShaderProgramm = ShaderManager::Instance()->GetShaderProgramm("Resources/Shaders/VertexShader.vsh","Resources/Shaders/FragmentShader.fsh");

    glGenBuffers(1, &mVBO);
}

GraphicLevel::~GraphicLevel()
{
    if (0 != mVBO)
        glDeleteBuffers(1, &mVBO);
}

void GraphicLevel::SetScene(Scene *scene)
{
    mScene = scene;
}

void GraphicLevel::Draw()
{
    if (mVisible && 0 < GetVertexArrayQuantity() && nullptr != mScene)
    {
        glUseProgram((int)*mShaderProgramm);

        GLuint PVMTRSM = mShaderProgramm->GetUniform("PVMTranslationRotationScaleMatrix");

        mPVMTranslationRotationScaleMatrix = mScene->GetCamera()->GetPVMMatrix()
                * GetPositionRotationScaleMatrix();

        glUniformMatrix4fv( PVMTRSM, 1, false, &mPVMTranslationRotationScaleMatrix[0][0]);

        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, mVBO);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glDrawArrays(mDrawPrimitives, 0, mVertexQuantity);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glDisableVertexAttribArray(0);
        glUseProgram(0);
    }
}

void GraphicLevel::LoadToGraphicMemory()
{
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, (mVertexQuantity * sizeof(glm::vec3)), *GetVertexArray(), GL_STREAM_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
