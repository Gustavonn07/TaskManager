#include "TaskManager.h"

#include <string>
#include <vector>

#include "Task.h"

tsm::TaskManager::TaskManager() {}

tsm::ErrorType tsm::TaskManager::addTask(
    const std::string &id,
    const std::string &title,
    const std::string &description)
{
  if (this->findTask(id) != nullptr)
  {
    return tsm::ErrorType::FILE_NOT_FOUND;
  }

  tsm::Task new_task(
      id,
      title,
      description,
      tsm::TaskProgress::TO_DO);

  tsm::TaskManager::tasks.push_back(std::move(new_task));
  return tsm::ErrorType::SUCCESS;
}

tsm::ErrorType tsm::TaskManager::removeTask(const std::string &id)
{
  if (std::erase_if(
          tasks,
          [&id](const tsm::Task &task)
          {
            return task.getId() == id;
          }) > 0)
  {
    return tsm::ErrorType::SUCCESS;
  }

  return tsm::ErrorType::FILE_NOT_FOUND;
}

tsm::ErrorType tsm::TaskManager::editTask(
    const std::string &id,
    const std::string &title,
    const std::string &description)
{
  tsm::Task *task = this->findTask(id);

  if (task != nullptr)
  {
    if (task->getTitle() != title)
    {
      task->setTitle(title);
    }
    if (task->getDescription() != description)
    {
      task->setDescription(description);
    }
    return tsm::ErrorType::SUCCESS;
  }
  return tsm::ErrorType::FILE_NOT_FOUND;
}

tsm::ErrorType tsm::TaskManager::updateTaskProgress(const std::string &id)
{
  tsm::Task *task = this->findTask(id);

  if (task)
  {
    switch (task->getProgress())
    {
    case tsm::TaskProgress::TO_DO:
      task->setProgress(tsm::TaskProgress::IN_PROGRESS);
      return tsm::ErrorType::SUCCESS;

    case tsm::TaskProgress::IN_PROGRESS:
      task->setProgress(tsm::TaskProgress::CONCLUDED);
      return tsm::ErrorType::SUCCESS;

    default:
      return tsm::ErrorType::TASK_INVALID_TRANSITION;
    }
  }
  return tsm::ErrorType::FILE_NOT_FOUND;
}

tsm::ErrorType tsm::TaskManager::cancelTask(const std::string &id)
{
  tsm::Task *task = this->findTask(id);

  if (task)
  {
    if (task->getProgress() == tsm::TaskProgress::CANCELLED)
    {
      return tsm::ErrorType::TASK_ALREADY_CANCELLED;
    }

    task->setProgress(tsm::TaskProgress::CANCELLED);
    return tsm::ErrorType::SUCCESS;
  }
  return tsm::ErrorType::FILE_NOT_FOUND;
}

const tsm::Task *tsm::TaskManager::findTask(const std::string &id) const
{
  for (const tsm::Task &task : tsm::TaskManager::tasks)
  {
    if (task.getId() == id)
    {
      return &task;
    }
  }
  return nullptr;
}

tsm::Task *tsm::TaskManager::findTask(const std::string &id)
{
  for (tsm::Task &task : tsm::TaskManager::tasks)
  {
    if (task.getId() == id)
    {
      return &task;
    }
  }
  return nullptr;
}

const std::vector<tsm::Task> &tsm::TaskManager::getAllTasks() const
{
  return tsm::TaskManager::tasks;
}

std::vector<tsm::Task> tsm::TaskManager::getTaskByProgress(const tsm::TaskProgress progress) const
{
  std::vector<tsm::Task> tasks_by_progress{};

  for (const tsm::Task &task : tasks)
  {
    if (task.getProgress() == progress)
    {
      tasks_by_progress.push_back(task);
    }
  }
  return tasks_by_progress;
}
