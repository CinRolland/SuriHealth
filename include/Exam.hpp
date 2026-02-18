#pragma once

#include <chrono>
#include <map>
#include <string>

// Defines available exam categories
enum class ExamType { GeneralCheckup, Cardiology, Neurology };

// Converts exam type to readable string
std::string examTypeToString(ExamType type);

// Represents a medical exam linked to a consultation
class Exam {
public:
  // Constructor
  Exam(int examId, int consultationId, ExamType type,
       const std::chrono::system_clock::time_point &date);

  // Returns exam identifier
  int getId() const;

  // Returns related consultation identifier
  int getConsultationId() const;

  // Returns exam type
  ExamType getType() const;

  // Returns exam date
  const std::chrono::system_clock::time_point &getDate() const;

  // Returns diagnosis text
  const std::string &getDiagnosis() const;

  // Returns completion state
  bool isCompleted() const;

  // Returns exam results
  const std::map<std::string, std::string> &getResults() const;

  // Adds result entry
  void addResult(const std::string &key, const std::string &value);

  // Sets diagnosis
  void setDiagnosis(const std::string &diagnosis);

  // Marks exam as completed
  void complete();

  // Adds general health metrics
  void addGeneralMetrics(float temperatureCelsius, float weightKg,
                         float heightCm);

  // Adds cardiology metrics
  void addCardioMetrics(int heartRateBpm, int systolicMmhg, int diastolicMmhg);

  // Adds neurology metrics
  void addNeuroMetrics(int reflexScore, const std::string &cognitiveNotes);

  // Displays exam summary
  void display() const;

private:
  int m_examId;
  int m_consultationId;
  ExamType m_type;
  std::chrono::system_clock::time_point m_date;
  std::string m_diagnosis;
  bool m_completed;
  std::map<std::string, std::string> m_results;
};
