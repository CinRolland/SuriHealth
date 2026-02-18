#include "Consultation.hpp"
#include "Exam.hpp"
#include "TimeUtils.hpp"

#include <iostream>

Consultation::Consultation(int consultationId, int medicalRecordId,
                           int practitionerId,
                           std::chrono::system_clock::time_point date,
                           const std::string &reason, int appointmentId)
    : m_consultationId(consultationId), m_medicalRecordId(medicalRecordId),
      m_practitionerId(practitionerId), m_appointmentId(appointmentId),
      m_date(date), m_reason(reason) {}

int Consultation::getId() const { return m_consultationId; }

int Consultation::getMedicalRecordId() const { return m_medicalRecordId; }

int Consultation::getPractitionerId() const { return m_practitionerId; }

int Consultation::getAppointmentId() const { return m_appointmentId; }

std::chrono::system_clock::time_point Consultation::getDate() const {
  return m_date;
}

const std::string &Consultation::getReason() const { return m_reason; }

const std::string &Consultation::getReport() const { return m_report; }

const std::vector<std::shared_ptr<Exam>> &Consultation::getExams() const {
  return m_exams;
}

const std::vector<std::shared_ptr<Prescription>> &
Consultation::getPrescriptions() const {
  return m_prescriptions;
}

void Consultation::setReport(const std::string &report) { m_report = report; }

void Consultation::addExam(const std::shared_ptr<Exam> &exam) {
  m_exams.push_back(exam);
}

void Consultation::addPrescription(const std::shared_ptr<Prescription> &p) {
  m_prescriptions.push_back(p);
}

void Consultation::display() const {
  std::cout << "Consultation #" << m_consultationId << " | "
            << TimeUtils::formatDate(m_date) << " | " << m_reason << std::endl;

  if (!m_report.empty())
    std::cout << "Report: " << m_report << std::endl;

  for (const auto &e : m_exams)
    e->display();
}
