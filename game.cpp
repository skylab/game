#include "game.h"

#include "GraphicSystem/pregraphic.h"

#include "Scenes/scenemanager.h"

#include "Scenes/loadingscene.h"

Game *Game::mInstance = nullptr;

void KeyCallBackFunction(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    SceneManager::Instance()->Keyboard(key);
}

void CursorPositionFunction(GLFWwindow *window, double xpos, double ypos)
{
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
    //TODO Another thread
    mSceneManager->SimulateScene();

    mSceneManager->DrawScene();
}

Game::Game() : mSceneManager(nullptr)
{
    if(!glfwInit())
    {
        //TODO
        return;
    }

    window = glfwCreateWindow( 1024, 768, "Game", NULL, NULL);
    if (NULL == window)
    {
        //TODO
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);
    SceneManager::Instance()->SetWindow(window);

    glewExperimental = true; // Needed for core profile

    if (glewInit() != GLEW_OK) {
        //TODO
        return;
    }

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    glfwSetCursorPos(window, 1024/2, 768/2);

    glfwSetKeyCallback(window, KeyCallBackFunction);
    glfwSetCursorPosCallback(window, CursorPositionFunction);

    glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
    mSceneManager = SceneManager::Instance();
    SceneManager::Instance()->ChangeScene(new LoadingScene());

    while (!glfwWindowShouldClose(window) && !SceneManager::Instance()->GetReceivedExit())
    {
        SceneManager::Instance()->DrawScene();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

Game::~Game()
{
    delete mSceneManager;
}
