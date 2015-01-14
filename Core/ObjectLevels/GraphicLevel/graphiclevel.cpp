#include "graphiclevel.h"
#include "pregraphic.h"
#include "../../Managers/shadermanager.h"
#include "../../Managers/scenemanager.h"

GraphicLevel::GraphicLevel() : mScene(nullptr), mVBO(0), mUVBO(0), mShaderProgramm(nullptr), mDrawPrimitives(GL_TRIANGLES)
{
    mShaderProgramm = ShaderManager::Instance()->GetShaderProgramm("Resources/Shaders/VertexShader.vsh","Resources/Shaders/FragmentShader.fsh");

    glGenBuffers(1, &mVBO); // Vertexes
    glGenBuffers(1, &mUVBO); // UVs
}

GraphicLevel::~GraphicLevel()
{
    if (0 != mVBO)
        glDeleteBuffers(1, &mVBO);
    mVBO = 0;

    if (0 != mUVBO)
        glDeleteBuffers(1, &mUVBO);
    mUVBO = 0;
}

void GraphicLevel::SetScene(Scene *scene)
{
    mScene = scene;
}

void GraphicLevel::Draw()
{
    if (0 < GetVertexArrayQuantity() && nullptr != mScene)
    {
        glUseProgram(mShaderProgramm->ID());

        GLuint PVMTRSM = mShaderProgramm->GetUniform("PVMTranslationRotationScaleMatrix");
        mPVMTranslationRotationScaleMatrix = mScene->GetCamera()->GetPVMMatrix()
                * GetPositionRotationScaleMatrix();
        glUniformMatrix4fv( PVMTRSM, 1, false, &mPVMTranslationRotationScaleMatrix[0][0]);

        // TODO : remove after
        if (0 != mTextureList.size())
        {
            GLuint useTextureUniform = mShaderProgramm->GetUniform("useTexture");
            glUniform1d(useTextureUniform, true);

            GLuint textureSamplerUniform = mShaderProgramm->GetUniform("textureSampler");
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, ((Texture*)mTextureList[0])->ID());
            glUniform1i(textureSamplerUniform, 0);
        }
        else
        {
            GLuint useTextureUniform = mShaderProgramm->GetUniform("useTexture");
            glUniform1d(useTextureUniform, false);
        }

        // vertixes
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, mVBO);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

        // UV
        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, mUVBO);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

        // Draw object
        glDrawArrays(mDrawPrimitives, 0, mVertexQuantity);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(2);

        glUseProgram(0);
    }
}

void GraphicLevel::SetVertexQuantity(unsigned int quantity)
{
    (void)quantity;
    try
    {
        mUV = new glm::vec3[mVertexQuantity];
    }
    catch(std::bad_alloc &ba)
    {
        std::cerr << __PRETTY_FUNCTION__ << " " << ba.what() << ": Can't allocate UV array" << std::endl;
        mUV = nullptr;
    }
}

glm::vec3 **GraphicLevel::GetUVArray(void)
{
    return &mUV;
}


bool GraphicLevel::AddTexture(Texture *texture)
{
    if (nullptr != texture)
    {
        mTextureList.push_back(texture);
        return true;
    }
    else
    {
        std::cerr << __PRETTY_FUNCTION__ << ": texture is nullptr" << std::endl;
    }
    return false;
}

int GraphicLevel::GetTextureNumberInObject(Texture *texture)
{
    if (nullptr == texture)
    {
        std::cerr << __PRETTY_FUNCTION__ << ": texture is nullptr" << std::endl;
        return -1;
    }

    for (unsigned int i = 0; i < mTextureList.size(); ++i)
    {
        if (mTextureList[i] == texture)
        {
            return i;
        }
    }

    std::cerr << __PRETTY_FUNCTION__ << ": Not found texture" << texture->GetTextureFileName() << std::endl;
    return -1;
}

void GraphicLevel::LoadToGraphicMemory()
{
    if (0 != mVertexQuantity)
    {
        // Load vertexes
        glBindBuffer(GL_ARRAY_BUFFER, mVBO);
        glBufferData(GL_ARRAY_BUFFER, (mVertexQuantity * sizeof(glm::vec3)), mVertex, GL_STREAM_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        // Load UV coordinates
        glBindBuffer(GL_ARRAY_BUFFER, mUVBO);
        glBufferData(GL_ARRAY_BUFFER, (mVertexQuantity * sizeof(glm::vec3)), mUV, GL_STREAM_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}
