#include <string>

#include "include/task/Task.h"

tm::Task::Task(
    const std::string &id,
    const std::string &title,
    const std::string &description,
    TaskProgress progress) : id(id),
                             title(title),
                             description(description),
                             progress(progress) {};

bool tm::Task::setTitle(const std::string &title)
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

bool tm::Task::setDescription(const std::string &description)
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

bool tm::Task::setProgress(TaskProgress progress)
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

std::string tm::Task::getId() const
{
  return this->id;
};

std::string tm::Task::getTitle() const
{
  return this->title;
}

std::string tm::Task::getDescription() const
{
  return this->description;
}

tm::TaskProgress tm::Task::getProgress() const
{
  return this->progress;
}