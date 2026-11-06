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

void tm::Task::setTitle(const std::string &title)
{
  this->title = title;
}

void tm::Task::setDescription(const std::string &description)
{
  this->description = description;
}

void tm::Task::setProgress(TaskProgress progress)
{
  this->progress = progress;
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