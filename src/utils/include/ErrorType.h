#ifndef ERROR_H
#define ERROR_H

namespace tsm
{
  enum class ErrorType
  {
    SUCCESS,

    // Task
    TASK_NOT_FOUND,
    TASK_ALREADY_EXISTS,
    TASK_INVALID_ID,
    TASK_INVALID_TITLE,

    // Task state
    TASK_ALREADY_CONCLUDED,
    TASK_ALREADY_CANCELLED,
    TASK_INVALID_TRANSITION,

    // Storage
    FILE_NOT_FOUND,
    FILE_READ_ERROR,
    FILE_WRITE_ERROR,
    FILE_PARSE_ERROR,

    // General
    INVALID_ARGUMENT,
    UNKNOWN
  };
}

#endif