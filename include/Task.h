#ifndef KIS_EXAM_TASK_H
#define KIS_EXAM_TASK_H

#include <string>

class Task {
public:
    Task();
    void addText(const std::string& str);
    std::string request(const std::string& str);
    std::string appendToRequest(const std::string& str);

};

#endif //KIS_EXAM_TASK_H
