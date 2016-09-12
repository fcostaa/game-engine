#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include "AwesomeGameApplication.h"

//#include "engine/Interfaces.h"
//#include "engine/GameApplication.h"

//class MyGameView : public IGameView {
//public:
//    virtual void onUpdate(double elapsedTime) {
//        // std::cout << "Hello World Update with time: " << &time << std::endl; }
//
//    virtual void onRender(const Time &time) {
//        // std::cout << "Hello World Render" << std::endl;
//    }
//};

//class MyGameApplication : public GameApplication {
//public:
//    virtual std::string *getGameTitle() {
//        std::string *title = NEW
//                std::string("Cross Platform engine");
//        return title;
//    }
//
//    virtual BaseGameLogic *createGameAndView() {
//        BaseGameLogic *game = NEW
//                BaseGameLogic();
//
//        boost::shared_ptr<IGameView> gameVIew(new MyGameView());
//        game->addGameView(gameVIew);
//
//        return game;
//    }
//
//
//    virtual bool loadGame() {
//        return true;
//    }
//};

int main(int argc, char **argv) {

    AwesomeGameApplication game;

    if (!game.initInstance()) {
        game.shutDown();
        exit(EXIT_FAILURE);
    }

    game.run();

    game.shutDown();

//    boost::shared_ptr<std::string> x = boost::make_shared<std::string>("hello, world Boost!");
//    // std::cout << *x;
//
//    GLFWwindow* window;
//
//    /* Initialize the library */
//    if (!glfwInit())
//        return -1;
//
//    /* Create a windowed mode window and its OpenGL context */
//    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
//    if (!window)
//    {
//        glfwTerminate();
//        return -1;
//    }
//
//    /* Make the window's context current */
//    glfwMakeContextCurrent(window);
//
//    /* Loop until the user closes the window */
//    while (!glfwWindowShouldClose(window))
//    {
//        /* Render here */
//
//        /* Swap front and back buffers */
//        glfwSwapBuffers(window);
//
//        /* Poll for and process events */
//        glfwPollEvents();
//    }
//
//    glfwTerminate();

    return 0;
}
