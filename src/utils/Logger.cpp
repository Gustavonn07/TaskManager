#include "Logger.h"

#include <iostream>
#include <string>

std::string tsm::Logger::getLoggerLabel(LoggerType type)
{
  switch (type)
  {
  case tsm::LoggerType::DEBUG:
    return "DEBUG";

  case tsm::LoggerType::ERROR:
    return "ERROR";

  case tsm::LoggerType::INFO:
    return "INFO";

  default:
    return "INFO";
  }
}

void tsm::Logger::getLog(
    LoggerType type,
    const std::string &text)
{
  std::cout
      << "[" << tsm::Logger::getLoggerLabel(type) << "] "
      << text
      << '\n';
}

void tsm::Logger::getLog(
    LoggerType type,
    const char *text)
{
  std::cout
      << "[" << tsm::Logger::getLoggerLabel(type) << "] "
      << text
      << '\n';
}
