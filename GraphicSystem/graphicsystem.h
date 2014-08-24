#ifndef GRAPHICSYSTEM_H
#define GRAPHICSYSTEM_H

#include "pregraphic.h"

#include "Scenes/sceneabs.h"

class GraphicSystem
{
public:
    static GraphicSystem *Instance() throw();
    void Remove() throw();

    void Draw() throw();
    void Reshape(int &width, int &height) throw();

private:
    GraphicSystem() throw();
    ~GraphicSystem() throw();

    bool Init(unsigned int width, unsigned int height) throw();

    friend void DrawFunction();
    friend void ReshapeFunction();
    friend void DrawFunction();

private:
    static GraphicSystem *mInstance;

    GLuint mVAO;

    SceneAbs *mScene;
    bool mIsStarted;
};

#endif // GRAPHICSYSTEM_H
