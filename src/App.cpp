#include "../include/App.h"

App::App() : is_exit_(false) {}

void App::mainLoop() {
    // TODO: implement
    is_exit_ = true;
}

void App::run() {
    is_exit_ = false;
    while (!is_exit_) {
        mainLoop();
    }
}