#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <vector>
#include <string>

#include "include/task/Task.h"

namespace tm
{

  class TaskManager
  {
  private:
    std::vector<tm::Task> tasks;

  public:
    TaskManager();

    bool addTask(
        const std::string &id,
        const std::string &title,
        const std::string &description);

    bool removeTask(const std::string &id);

    bool editTask(const std::string &id,
                  const std::string &title,
                  const std::string &description);

    bool updateTaskProgress(const std::string &id);

    bool cancelTask(const std::string &id);

    const tm::Task *findTask(const std::string &id) const;

    const std::vector<tm::Task> &getAllTasks() const;

    std::vector<tm::Task> getTaskByProgress(const tm::TaskProgress progress) const;
  };

} // namespace tm

#endif
