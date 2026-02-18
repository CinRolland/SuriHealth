#pragma once

#include <chrono>
#include <string>

// Utility class providing helper functions for date and time formatting
class TimeUtils {
public:
  TimeUtils(const TimeUtils &) = default;
  TimeUtils(TimeUtils &&) = default;
  TimeUtils &operator=(const TimeUtils &) = default;
  TimeUtils &operator=(TimeUtils &&) = default;

  // Formats a time_point into a date string (DD/MM/YYYY)
  static std::string
  formatDate(const std::chrono::system_clock::time_point &tp);

  // Formats a time_point into a date-time string (DD/MM/YYYY HH:MM)
  static std::string
  formatDateTime(const std::chrono::system_clock::time_point &tp);

  // Creates a time_point from given date and optional time
  static std::chrono::system_clock::time_point
  makeDate(int year, int month, int day, int hour = 0, int minute = 0);
};
