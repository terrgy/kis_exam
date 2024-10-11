#ifndef KIS_EXAM_APP_H
#define KIS_EXAM_APP_H

#include "Task.h"

class App {
private:
    bool is_exit_;
    Task task_;

public:
    App();
    void run();
    void mainLoop();
};


#endif //KIS_EXAM_APP_H
