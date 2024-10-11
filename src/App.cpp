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
        commandText_();
    } else if (command == "request") {
        commandRequest_();
    } else if (command == "append") {
        commandAppend_();
    } else if (command == "help") {
        commandHelp_();
    } else if (command == "exit") {
        commandExit_();
    } else {
        unknownCommand_();
    }
}

void App::run() {
    is_exit_ = false;
    while (!is_exit_) {
        mainLoop();
    }
}

void App::commandText_() {
    std::string text;
    std::cout << "Text: ";
    std::cin.get();
    std::getline(std::cin, text);
    task_.addText(text);
    std::cout << "OK!" << std::endl;
}

void App::commandRequest_() {
    std::string str;
    std::cout << "Request: ";
    std::cin >> str;
    std::cout << "Response: " << task_.request(str) << std::endl;
}

void App::commandAppend_() {
    std::string str;
    std::cout << "Append request: ";
    std::cin >> str;
    std::cout << "Response: " << task_.appendToRequest(str) << std::endl;
}

void App::commandHelp_() {
    std::cout << "Commands:\ntext - add text;\nrequest - start new request;\n";
    std::cout << "append - append to the previous request;\nhelp - print this message;\n";
    std::cout << "exit - close application;\n";
}

void App::commandExit_() {
    std::cout << "Bye-bye" << std::endl;
    is_exit_ = true;
}

void App::unknownCommand_() {
    std::cout << "Unknown command" << std::endl;
}
