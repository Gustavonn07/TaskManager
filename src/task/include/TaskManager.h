#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <vector>
#include <string>

#include "Task.h"

namespace tsm
{

  class TaskManager
  {
  private:
    std::vector<tsm::Task> tasks;

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

    const tsm::Task *findTask(const std::string &id) const;
    tsm::Task *findTask(const std::string &id);

    const std::vector<tsm::Task> &getAllTasks() const;

    std::vector<tsm::Task> getTaskByProgress(const tsm::TaskProgress progress) const;
  };

} // namespace tm

#endif
