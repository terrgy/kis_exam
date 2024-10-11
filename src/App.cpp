#include <iostream>

#include "App.h"

App::App() : is_exit_(false) {}

void App::mainLoop() {
    std::string command;
    std::cout << "Type command: ";
    std::cin >> command;

    if (command.empty()) {
        std::cerr << "Warning: empty command" << std::endl;
        return;
    }

    if (command == "text") {
        std::string text;
        std::cout << "Text: ";
        std::cin.get();
        std::getline(std::cin, text);
        task_.addText(text);
        std::cout << "OK!" << std::endl;
    } else if (command == "request") {
        std::string str;
        std::cout << "Request: ";
        std::cin >> str;
        std::cout << "Response: " << task_.request(str) << std::endl;
    } else if (command == "append") {
        std::string str;
        std::cout << "Request: ";
        std::cin >> str;
        std::cout << "Response: " << task_.appendToRequest(str) << std::endl;
    } else if (command == "help") {
        std::cout << "This is help text\n";
    } else if (command == "exit") {
        std::cout << "Bye-bye" << std::endl;
        is_exit_ = true;
    } else {
        std::cout << "Unknown command" << std::endl;
    }
}

void App::run() {
    is_exit_ = false;
    while (!is_exit_) {
        mainLoop();
    }
}