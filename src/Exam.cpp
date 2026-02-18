#include "Exam.hpp"
#include "TimeUtils.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>

std::string examTypeToString(ExamType type) {
  switch (type) {
  case ExamType::GeneralCheckup:
    return "General Checkup";
  case ExamType::Cardiology:
    return "Cardiology";
  case ExamType::Neurology:
    return "Neurology";
  }
  return "Unknown";
}

Exam::Exam(int examId, int consultationId, ExamType type,
           const std::chrono::system_clock::time_point &date)
    : m_examId(examId), m_consultationId(consultationId), m_type(type),
      m_date(date), m_completed(false) {}

int Exam::getId() const { return m_examId; }

int Exam::getConsultationId() const { return m_consultationId; }

ExamType Exam::getType() const { return m_type; }

const std::chrono::system_clock::time_point &Exam::getDate() const {
  return m_date;
}

const std::string &Exam::getDiagnosis() const { return m_diagnosis; }

bool Exam::isCompleted() const { return m_completed; }

const std::map<std::string, std::string> &Exam::getResults() const {
  return m_results;
}

void Exam::addResult(const std::string &key, const std::string &value) {
  m_results[key] = value;
}

void Exam::setDiagnosis(const std::string &diagnosis) {
  m_diagnosis = diagnosis;
}

void Exam::complete() { m_completed = true; }

void Exam::addGeneralMetrics(float temp, float weight, float height) {
  auto fmt = [](float v, int p = 1) {
    std::ostringstream o;
    o << std::fixed << std::setprecision(p) << v;
    return o.str();
  };

  addResult("Temperature (°C)", fmt(temp));
  addResult("Weight (kg)", fmt(weight));
  addResult("Height (cm)", fmt(height, 0));

  float bmi = weight / ((height / 100.f) * (height / 100.f));
  addResult("BMI", fmt(bmi));
}

void Exam::addCardioMetrics(int hr, int sys, int dia) {
  addResult("Heart Rate (bpm)", std::to_string(hr));
  addResult("Blood Pressure",
            std::to_string(sys) + "/" + std::to_string(dia) + " mmHg");
}

void Exam::addNeuroMetrics(int reflexScore, const std::string &cognitiveNotes) {
  addResult("Reflex Score (/10)", std::to_string(reflexScore));
  addResult("Cognitive Assessment", cognitiveNotes);
}

void Exam::display() const {
  std::cout << "Exam #" << m_examId << " | " << examTypeToString(m_type)
            << " | " << TimeUtils::formatDate(m_date) << " | "
            << (m_completed ? "Done" : "Pending") << std::endl;

  for (const auto &[k, v] : m_results)
    std::cout << "  " << k << ": " << v << std::endl;

  if (!m_diagnosis.empty())
    std::cout << "  Diagnosis: " << m_diagnosis << std::endl;
}
