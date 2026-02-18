#pragma once

#include <chrono>
#include <memory>
#include <string>
#include <vector>

class Exam;
class Prescription;

// Represents a medical consultation linked to a MedicalRecord
class Consultation {
public:
  // Constructor
  Consultation(int consultationId, int medicalRecordId, int practitionerId,
               std::chrono::system_clock::time_point date,
               const std::string &reason, int appointmentId = -1);

  // Returns consultation unique identifier
  int getId() const;

  // Returns linked MedicalRecord identifier
  int getMedicalRecordId() const;

  // Returns practitioner identifier
  int getPractitionerId() const;

  // Returns related appointment identifier (-1 if none)
  int getAppointmentId() const;

  // Returns consultation date
  std::chrono::system_clock::time_point getDate() const;

  // Returns consultation reason
  const std::string &getReason() const;

  // Returns consultation report
  const std::string &getReport() const;

  // Returns all associated exams
  const std::vector<std::shared_ptr<Exam>> &getExams() const;

  // Returns all associated prescriptions
  const std::vector<std::shared_ptr<Prescription>> &getPrescriptions() const;

  // Sets consultation report
  void setReport(const std::string &report);

  // Adds an exam
  void addExam(const std::shared_ptr<Exam> &exam);

  // Adds a prescription
  void addPrescription(const std::shared_ptr<Prescription> &prescription);

  // Displays consultation details
  void display() const;

private:
  int m_consultationId;
  int m_medicalRecordId;
  int m_practitionerId;
  int m_appointmentId;

  std::chrono::system_clock::time_point m_date;

  std::string m_reason;
  std::string m_report;

  std::vector<std::shared_ptr<Exam>> m_exams;
  std::vector<std::shared_ptr<Prescription>> m_prescriptions;
};
