#ifndef TASK_H
#define TASK_H

#include <string>

#include "ErrorType.h"

namespace tsm
{

  enum class TaskProgress
  {
    TO_DO,
    IN_PROGRESS,
    CANCELLED,
    CONCLUDED
  };

  class Task
  {
  private:
    std::string id;
    std::string title;
    std::string description;
    TaskProgress progress;

  public:
    Task(
        const std::string &id,
        const std::string &title,
        const std::string &description,

        // TODO: ADICIONAR USUARIO DA TASK.
        // User user;
        tsm::TaskProgress progress);

    tsm::ErrorType setTitle(const std::string &title);
    tsm::ErrorType setDescription(const std::string &description);
    tsm::ErrorType setProgress(TaskProgress progress);

    std::string getId() const;
    std::string getTitle() const;
    std::string getDescription() const;
    TaskProgress getProgress() const;
  };

} // namespace task

#endif
