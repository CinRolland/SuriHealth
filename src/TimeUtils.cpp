#include "TimeUtils.hpp"

#include <ctime>
#include <iomanip>
#include <sstream>

std::string
TimeUtils::formatDate(const std::chrono::system_clock::time_point &tp) {
  std::time_t t = std::chrono::system_clock::to_time_t(tp);
  std::tm tm = *std::localtime(&t);
  std::ostringstream oss;
  oss << std::setfill('0') << std::setw(2) << tm.tm_mday << "/" << std::setw(2)
      << (tm.tm_mon + 1) << "/" << (tm.tm_year + 1900);
  return oss.str();
}

std::string
TimeUtils::formatDateTime(const std::chrono::system_clock::time_point &tp) {
  std::time_t t = std::chrono::system_clock::to_time_t(tp);
  std::tm tm = *std::localtime(&t);

  std::ostringstream oss;
  oss << std::setfill('0') << std::setw(2) << tm.tm_mday << "/" << std::setw(2)
      << (tm.tm_mon + 1) << "/" << (tm.tm_year + 1900) << " " << std::setw(2)
      << tm.tm_hour << ":" << std::setw(2) << tm.tm_min;

  return oss.str();
}

std::chrono::system_clock::time_point
TimeUtils::makeDate(int year, int month, int day, int hour, int minute) {
  std::tm tm{};
  tm.tm_year = year - 1900;
  tm.tm_mon = month - 1;
  tm.tm_mday = day;
  tm.tm_hour = hour;
  tm.tm_min = minute;
  tm.tm_sec = 0;
  tm.tm_isdst = -1;

  return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}
