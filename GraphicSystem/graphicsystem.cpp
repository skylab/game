#include "graphicsystem.h"

#include "Scenes/menuscene.h"

GraphicSystem *GraphicSystem::mInstance = NULL;

void DrawFunction()
{
    GraphicSystem::Instance()->Draw();
}

void ReshapeFunction(int width, int height)
{
    GraphicSystem::Instance()->Reshape(width, height);
}

void KeyboardFunction(unsigned char key, int x, int y)
{
    GraphicSystem::Instance()->Keyboard(key, x, y);
}

GraphicSystem *GraphicSystem::Instance()
{
    if (NULL == mInstance)
    {
        mInstance = new (std::nothrow) GraphicSystem();
        if (NULL == mInstance)
        {
            std::cerr << "Can't allocate GraphicSystem object" << std::endl;
        }
    }
    return mInstance;
}

void GraphicSystem::Remove()
{
    delete mInstance;
    mInstance = NULL;
}

void GraphicSystem::Draw()
{
    mScene->DrawScene();
    glutMainLoop();
}

void GraphicSystem::Reshape(int &width, int &height)
{
    //TODO;
    (void)width;
    (void)height;
}

void GraphicSystem::Keyboard(unsigned char &key, int &x, int &y)
{
    mScene->KeyBoard(key, x, y);
}

GraphicSystem::GraphicSystem() : mScene(NULL), mIsStarted(true)
{
    Init(600, 600);
}

GraphicSystem::~GraphicSystem()
{
    //TODO;
    delete mScene;
    mScene = NULL;
}

bool GraphicSystem::Init(unsigned int width, unsigned int height)
{
    int fakeArgc = 1;
    char **fakeArgv;
    fakeArgv = new (std::nothrow) char*[2];
    fakeArgv[fakeArgc] = static_cast<char*>("GraphicSystem");

    glutInit(&fakeArgc, fakeArgv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(width,height);
    //glutInitWindowPosition();
    glutCreateWindow("Game");
    //glutFullScreen();

    glutDisplayFunc(DrawFunction);
    glutReshapeFunc(ReshapeFunction);
    glutKeyboardFunc(KeyboardFunction);
    //glutMouseFunc();
    //glutMouseWheelFunc();

    glewInit();

    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);

    glClearColor(0.5f, 0.5f, 0.5f, 0.5f);


    ChangeScene(new (std::nothrow) MenuScene());
    return true;
}

void GraphicSystem::ChangeScene(SceneAbs *scene)
{
    SceneAbs *oldScene = mScene;
    mScene = scene;
    delete oldScene;
}
