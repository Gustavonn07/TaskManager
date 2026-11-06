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

    void setTitle(const std::string &title);
    void setDescription(const std::string &description);
    void setProgress(TaskProgress progress);

    std::string getId() const;
    std::string getTitle() const;
    std::string getDescription() const;
    TaskProgress getProgress() const;
  };

} // namespace task

#endif

// VAI TUDO PRO TASK_MANAGER_H
// void createTask(
//         std::string id,
//         std::string title,
//         std::string description,

//         // TODO: ADICIONAR USUARIO DA TASK.
//         // User user;
//         task::TaskProgress progress
//       );

//       void deleteTask(Task &task);
//       void editTask(Task &task);
//       Task getTask(std::string id);
//       std::vector<Task> getAllTasks();