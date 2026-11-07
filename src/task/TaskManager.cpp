#include "TaskManager.h"

#include <string>
#include <vector>
#include <stdexcept>

#include "include/task/Task.h"

// TODO: UMA FORMA MELHOR DE MAPEAR OS ERROS COM UM ENUM DE ERROS
// TODO: CRIAR UMA FUNÇÃO DE VERIFICAR SE A TASK REALMENTE EXISTE POR ID (PRIVATE)

tm::TaskManager::TaskManager() {}

bool tm::TaskManager::addTask(
    const std::string &id,
    const std::string &title,
    const std::string &description)
{
  for (const tm::Task &task : tm::TaskManager::tasks)
  {
    if (task.getId() == id)
    {
      return false;
    }
  }

  tm::Task new_task = tm::Task(
      id,
      title,
      description,
      tm::TaskProgress::TO_DO);

  tm::TaskManager::tasks.push_back(new_task);
  return true;
}

bool tm::TaskManager::removeTask(const std::string &id)
{
  return std::erase_if(
             tasks,
             [&id](const tm::Task &task)
             {
               return task.getId() == id;
             }) > 0;
}

bool tm::TaskManager::editTask(
    const std::string &id,
    const std::string &title,
    const std::string &description)
{
  for (tm::Task &task : tm::TaskManager::tasks)
  {
    if (task.getId() == id)
    {
      if (task.getTitle() != title)
      {
        task.setTitle(title);
      }
      if (task.getDescription() != description)
      {
        task.setDescription(description);
      }
      return true;
    }
  }
  return false;
}

bool tm::TaskManager::updateTaskProgress(const std::string &id)
{
  for (tm::Task &task : tm::TaskManager::tasks)
  {
    if (task.getId() == id)
    {
      switch (task.getProgress())
      {
      case tm::TaskProgress::TO_DO:
        task.setProgress(tm::TaskProgress::IN_PROGRESS);
        return true;

      case tm::TaskProgress::IN_PROGRESS:
        task.setProgress(tm::TaskProgress::CONCLUDED);
        return true;

      default:
        return false;
      }
    }
  }
  return false;
}

bool tm::TaskManager::cancelTask(const std::string &id)
{
  for (tm::Task &task : tm::TaskManager::tasks)
  {
    if (task.getId() == id)
    {
      if (task.getProgress() == tm::TaskProgress::CANCELLED)
      {
        return false;
      }

      task.setProgress(tm::TaskProgress::CANCELLED);
      return true;
    }
  }
  return false;
}

const tm::Task *tm::TaskManager::findTask(const std::string &id) const
{
  for (const tm::Task &task : tm::TaskManager::tasks)
  {
    if (task.getId() == id)
    {
      return &task;
    }
  }
  return nullptr;
}

const std::vector<tm::Task> &tm::TaskManager::getAllTasks() const
{
  return tm::TaskManager::tasks;
}

std::vector<tm::Task> tm::TaskManager::getTaskByProgress(const tm::TaskProgress progress) const
{
  std::vector<tm::Task> tasks_by_progress{};

  for (const tm::Task &task : tasks)
  {
    if (task.getProgress() == progress)
    {
      tasks_by_progress.push_back(task);
    }
  }
  return tasks_by_progress;
}
