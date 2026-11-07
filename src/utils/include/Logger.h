#ifndef LOGGER_H
#define LOGGER_H

#include <string>

namespace tsm
{

  enum class LoggerType
  {
    DEBUG,
    ERROR,
    INFO
  };

  class Logger
  {
  private:
    static std::string getLoggerLabel(LoggerType type);

  public:
    static void getLog(
        LoggerType type, const std::string &text);

    static void getLog(
        LoggerType type, const char *text);
  };

} // namespace tsm

#endif