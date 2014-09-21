#include "game.h"

#include "GraphicSystem/pregraphic.h"

#include "Scenes/scenemanager.h"

Game *Game::mInstance = nullptr;

void DrawFunction()
{
    SceneManager::Instance()->DrawScene();
    glutMainLoop();
}

void ReshapeFunction(int width, int height)
{
    SceneManager::Instance()->Reshape(width, height);
}

void KeyboardFunction(unsigned char key, int x, int y)
{
    SceneManager::Instance()->Keyboard(key, x, y);
}

void MouseFunction(int key, int state, int x, int y)
{
    SceneManager::Instance()->Mouse(key, state, x, y);
}

Game *Game::Instance()
{
    if (NULL == mInstance)
    {
        mInstance = new (std::nothrow) Game();
        if (NULL == mInstance)
        {
            std::cerr << "Can't allocate Game object" << std::endl;
        }
    }
    return mInstance;
}

void Game::Execute()
{
    //TODO Another thread
    mSceneManager->SimulateScene();

    mSceneManager->DrawScene();
    glutMainLoop();
}

Game::Game() : mSceneManager(nullptr)
{
    int fakeArgc = 1;
    char *fakeArgv[] = {"Game"};

    glutInit(&fakeArgc, fakeArgv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    //glutInitWindowPosition();
    glutCreateWindow("Game");
    //glutFullScreen();

    glutDisplayFunc(DrawFunction);
    glutReshapeFunc(ReshapeFunction);
    glutKeyboardFunc(KeyboardFunction);
    glutMouseFunc(MouseFunction);
    //glutMouseWheelFunc();

    glewInit();

    glGenVertexArrays(1, &mVisualArrayObject);
    glBindVertexArray(mVisualArrayObject);

    glClearColor(0.5f, 0.5f, 0.5f, 0.5f);

    mSceneManager = SceneManager::Instance();
}

Game::~Game()
{
    delete mSceneManager;
}
