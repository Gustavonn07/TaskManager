#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <vector>
#include <string>

#include "Task.h"
#include "ErrorType.h"

namespace tsm
{

  class TaskManager
  {
  private:
    std::vector<tsm::Task> tasks;

  public:
    TaskManager();

    tsm::ErrorType addTask(
        const std::string &id,
        const std::string &title,
        const std::string &description);

    tsm::ErrorType removeTask(const std::string &id);

    tsm::ErrorType editTask(const std::string &id,
                  const std::string &title,
                  const std::string &description);

    tsm::ErrorType updateTaskProgress(const std::string &id);

    tsm::ErrorType cancelTask(const std::string &id);

    const tsm::Task *findTask(const std::string &id) const;
    tsm::Task *findTask(const std::string &id);

    const std::vector<tsm::Task> &getAllTasks() const;

    std::vector<tsm::Task> getTaskByProgress(const tsm::TaskProgress progress) const;
  };

} // namespace tm

#endif
