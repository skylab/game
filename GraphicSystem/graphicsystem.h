#ifndef GRAPHICSYSTEM_H
#define GRAPHICSYSTEM_H

#include "pregraphic.h"

#include "Scenes/sceneabs.h"

class GraphicSystem
{
public:
    static GraphicSystem *Instance();
    void Remove();

    void Draw();
    void Reshape(int &width, int &height);
    void Keyboard(unsigned char &key, int &x, int &y);


    void ChangeScene(SceneAbs *scene);
private:
    GraphicSystem();
    ~GraphicSystem();

    bool Init(unsigned int width, unsigned int height);

    friend void DrawFunction();
    friend void ReshapeFunction();
    friend void KeyboardFunction(unsigned char key, int x, int y);

private:
    static GraphicSystem *mInstance;

    GLuint mVAO;

    SceneAbs *mScene;
    bool mIsStarted;
};

#endif // GRAPHICSYSTEM_H
