#include "Task.h"

#include <string>

#include "ErrorType.h"

tsm::Task::Task(
    const std::string &id,
    const std::string &title,
    const std::string &description,
    TaskProgress progress) : id(id),
                             title(title),
                             description(description),
                             progress(progress) {};

tsm::ErrorType tsm::Task::setTitle(const std::string &title)
{
  try
  {
    this->title = title;
    return tsm::ErrorType::SUCCESS;
  }
  catch (const std::exception &_)
  {
    return tsm::ErrorType::UNKNOWN;
  }
}

tsm::ErrorType tsm::Task::setDescription(const std::string &description)
{
  try
  {
    this->description = description;
    return tsm::ErrorType::SUCCESS;
  }
  catch (const std::exception &_)
  {
    return tsm::ErrorType::UNKNOWN;
  }
}

tsm::ErrorType tsm::Task::setProgress(TaskProgress progress)
{
  try
  {
    this->progress = progress;
    return tsm::ErrorType::SUCCESS;
  }
  catch (const std::exception &_)
  {
    return tsm::ErrorType::UNKNOWN;
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