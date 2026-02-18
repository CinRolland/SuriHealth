#pragma once

#include <chrono>
#include <string>

class TimeUtils {
public:
  TimeUtils(const TimeUtils &) = default;
  TimeUtils(TimeUtils &&) = default;
  TimeUtils &operator=(const TimeUtils &) = default;
  TimeUtils &operator=(TimeUtils &&) = default;
  static std::string
  formatDate(const std::chrono::system_clock::time_point &tp);

  static std::string
  formatDateTime(const std::chrono::system_clock::time_point &tp);

  // Helper to create a date easily (YYYY, MM, DD, optional HH, MM)
  static std::chrono::system_clock::time_point
  makeDate(int year, int month, int day, int hour = 0, int minute = 0);
};
