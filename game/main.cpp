#include <iostream>
#include "DriftsGameApplication.h"

int main(int argc, char **argv) {

    DriftsGameApplication game;

    if (!game.initInstance()) {
        game.shutDown();
        exit(EXIT_FAILURE);
    }

    game.run();

    game.shutDown();

    return 0;
}
