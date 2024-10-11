#ifndef KIS_EXAM_APP_H
#define KIS_EXAM_APP_H

#include "Task.h"

class App {
private:
    bool is_exit_;
    Task task;

public:
    App();
    void run();
    void main_loop();
};


#endif //KIS_EXAM_APP_H
