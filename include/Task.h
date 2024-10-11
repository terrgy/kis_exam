#ifndef KIS_EXAM_TASK_H
#define KIS_EXAM_TASK_H

#include <string>

class Task {
public:
    Task();
    void AddText(const std::string& str);
    std::string Request(const std::string& str);
    std::string AppendToRequest(const std::string& str);

};

#endif //KIS_EXAM_TASK_H
