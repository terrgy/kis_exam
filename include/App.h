#ifndef KIS_EXAM_APP_H
#define KIS_EXAM_APP_H

#include "Task.h"

class App {
private:
    bool is_exit_;
    Task task_;

    void commandText_();
    void commandRequest_();
    void commandAppend_();
    void commandHelp_();
    void commandExit_();
    void unknownCommand_();

public:
    App();
    void run();
    void mainLoop();
};


#endif //KIS_EXAM_APP_H
