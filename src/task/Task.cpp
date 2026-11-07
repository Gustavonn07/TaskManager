#include "Task.h"

#include <string>

tsm::Task::Task(
    const std::string &id,
    const std::string &title,
    const std::string &description,
    TaskProgress progress) : id(id),
                             title(title),
                             description(description),
                             progress(progress) {};

bool tsm::Task::setTitle(const std::string &title)
{
  try
  {
    this->title = title;
    return true;
  }
  catch (const std::exception &_)
  {
    return false;
  }
}

bool tsm::Task::setDescription(const std::string &description)
{
  try
  {
    this->description = description;
    return true;
  }
  catch (const std::exception &_)
  {
    return false;
  }
}

bool tsm::Task::setProgress(TaskProgress progress)
{
  try
  {
    this->progress = progress;
    return true;
  }
  catch (const std::exception &_)
  {
    return false;
  }
}

std::string tsm::Task::getId() const
{
  return this->id;
};

std::string tsm::Task::getTitle() const
{
  return this->title;
}

std::string tsm::Task::getDescription() const
{
  return this->description;
}

tsm::TaskProgress tsm::Task::getProgress() const
{
  return this->progress;
}