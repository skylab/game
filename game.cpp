#include "game.h"

#include "GraphicSystem/pregraphic.h"

#include "Main/scenemanager.h"

Game *Game::mInstance = nullptr;

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

void KeyCallBackFunction(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    // TODO!!!
    (void)window;
    (void)scancode;
    (void)action;
    (void)mods;
    SceneManager::Instance()->Keyboard(key);
}

void CursorPositionFunction(GLFWwindow *window, double xpos, double ypos)
{
    // TODO
    (void)window;
    SceneManager::Instance()->MousePosition(xpos, ypos);
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
    if (true == mbStartNormal)
    {
        //TODO Another thread graphic
        while (!glfwWindowShouldClose(window) && !SceneManager::Instance()->GetReceivedExit())
        {
            SceneManager::Instance()->DrawScene();
            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        //TODO Another thread physic
    }
    else
    {
        std::cerr << "Initialization failed. Can't execute" << std::endl;
    }
}

Game::Game() : mSceneManager(nullptr), mbStartNormal(false)
{
    if(!glfwInit())
    {
        // TODO
        return;
    }

    window = glfwCreateWindow( WINDOW_WIDTH, WINDOW_HEIGHT, "Game", NULL, NULL);
    if (NULL == window)
    {
        // TODO
        glfwTerminate();
        return;
    }

    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        // TODO
        return;
    }

    glfwMakeContextCurrent(window);
    mSceneManager = SceneManager::Instance()->SetWindow(window);
    SceneManager::Instance()->SetWindowWidth(WINDOW_WIDTH);
    SceneManager::Instance()->SetWindowHeight(WINDOW_HEIGHT);

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glfwSetCursorPos(window, WINDOW_WIDTH/2, WINDOW_HEIGHT/2);

    glfwSetKeyCallback(window, KeyCallBackFunction);
    glfwSetCursorPosCallback(window, CursorPositionFunction);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    mbStartNormal = true;
}

Game::~Game()
{
    delete mSceneManager;
    mSceneManager = nullptr;
}
