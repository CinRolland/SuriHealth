#pragma once

#include <chrono>
#include <memory>
#include <string>
#include <vector>

class MedicalRecord;
class HealthMutual;
class Consultation;

// Represents patient biological sex
enum class Sex { Male, Female, Other };

// Represents a patient entity
class Patient {
public:
  // Constructor
  Patient(int patientId, const std::string &ssn, const std::string &lastName,
          const std::string &firstName, Sex sex,
          const std::chrono::system_clock::time_point &birthDate,
          const std::string &address = "", const std::string &phone = "",
          const std::string &email = "");

  // Returns patient identifier
  int getId() const;

  // Returns social security number
  const std::string &getSsn() const;

  // Returns last name
  const std::string &getLastName() const;

  // Returns first name
  const std::string &getFirstName() const;

  // Returns full name
  std::string getFullName() const;

  // Returns biological sex
  Sex getSex() const;

  // Returns birth date
  const std::chrono::system_clock::time_point &getBirthDate() const;

  // Returns phone number
  const std::string &getPhone() const;

  // Returns email address
  const std::string &getEmail() const;

  // Assigns medical record
  void setMedicalRecord(const std::shared_ptr<MedicalRecord> &record);

  // Returns medical record
  const std::shared_ptr<MedicalRecord> &getMedicalRecord() const;

  // Adds consultation
  void addConsultation(const std::shared_ptr<Consultation> &consultation);

  // Returns consultations
  const std::vector<std::shared_ptr<Consultation>> &getConsultations() const;

  // Displays patient summary
  void display() const;

private:
  int m_patientId;
  std::string m_ssn;
  std::string m_lastName;
  std::string m_firstName;
  Sex m_sex;
  std::chrono::system_clock::time_point m_birthDate;
  std::string m_address;
  std::string m_phone;
  std::string m_email;

  std::shared_ptr<MedicalRecord> m_medicalRecord;
  std::shared_ptr<HealthMutual> m_healthMutual;
  std::vector<std::shared_ptr<Consultation>> m_consultations;
};
