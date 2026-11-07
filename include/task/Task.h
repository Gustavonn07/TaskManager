#ifndef TASK_H
#define TASK_H

#include <string>

namespace tm
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
        tm::TaskProgress progress);

    bool setTitle(const std::string &title);
    bool setDescription(const std::string &description);
    bool setProgress(TaskProgress progress);

    std::string getId() const;
    std::string getTitle() const;
    std::string getDescription() const;
    TaskProgress getProgress() const;
  };

} // namespace task

#endif
