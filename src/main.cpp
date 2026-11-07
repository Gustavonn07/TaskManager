#include "Logger.h"
#include "TaskManager.h"

int main(int argc, char const *argv[])
{
  tsm::TaskManager manager;
  tsm::Logger::getLog(tsm::LoggerType::INFO, "Gustavo created a new Task:");

  manager.addTask(
    "1",
    "Task_01",
    "Potato"
  );

  tsm::Logger::getLog(tsm::LoggerType::INFO, "Task 01 Name: " + manager.findTask("1")->getTitle());
  tsm::Logger::getLog(tsm::LoggerType::INFO, "Task 01 Desc: " + manager.findTask("1")->getDescription());
  
  manager.editTask(
    "1",
    "Task_01",
    "Potato legal"
  );

  tsm::Logger::getLog(tsm::LoggerType::INFO, "Task 01 Desc: " + manager.findTask("1")->getDescription());

  manager.removeTask("1");

  return 0;
}
