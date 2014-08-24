#include "graphicsystem.h"

GraphicSystem *GraphicSystem::mInstance = NULL;

void DrawFunction()
{
    GraphicSystem::Instance()->Draw();
}

void ReshapeFunction(int width, int height)
{
    GraphicSystem::Instance()->Reshape(width, height);
}

GraphicSystem *GraphicSystem::Instance() throw()
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

void GraphicSystem::Remove() throw()
{
    delete mInstance;
    mInstance = NULL;
}

void GraphicSystem::Draw() throw()
{
    mScene->DrawScene();
    glutMainLoop();
}

void GraphicSystem::Reshape(int &width, int &height) throw()
{
    //TODO;
    (void)width;
    (void)height;
}

GraphicSystem::GraphicSystem() throw() : mScene(NULL), mIsStarted(true)
{
    Init(600, 600);
}

GraphicSystem::~GraphicSystem() throw()
{
    //TODO;
    delete mScene;
    mScene = NULL;
}

bool GraphicSystem::Init(unsigned int width, unsigned int height) throw()
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
    //glutKeyboardFunc(KeyFunction);
    //glutMouseFunc();
    //glutMouseWheelFunc();

    glewInit();

    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);

    glClearColor(0.5f, 0.5f, 0.5f, 0.5f);

    mScene = new (std::nothrow) SceneAbs(mVAO);
    return true;
}
