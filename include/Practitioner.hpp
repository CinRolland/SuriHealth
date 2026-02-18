#pragma once

#include <chrono>
#include <memory>
#include <string>

class Patient;
class Consultation;
class Appointment;

// Defines practitioner specialty
enum class Specialty { GeneralPractitioner, Cardiologist, Neurologist };

// Converts specialty to string
std::string specialtyToString(Specialty s);

// Base class for all practitioners
class Practitioner {
public:
  // Constructor
  Practitioner(int id, const std::string &lastName,
               const std::string &firstName, Specialty specialty,
               const std::string &registrationNumber,
               const std::string &phone = "", const std::string &email = "");

  virtual ~Practitioner() = default;

  // Returns practitioner identifier
  int getId() const;

  // Returns last name
  const std::string &getLastName() const;

  // Returns first name
  const std::string &getFirstName() const;

  // Returns full name
  std::string getFullName() const;

  // Returns specialty
  Specialty getSpecialty() const;

  // Returns specialty as string
  std::string getSpecialtyStr() const;

  // Returns registration number
  const std::string &getRegistrationNumber() const;

  // Returns phone
  const std::string &getPhone() const;

  // Returns email
  const std::string &getEmail() const;

  // Conducts consultation workflow
  virtual std::shared_ptr<Consultation> conductConsultation(
      const std::shared_ptr<Patient> &patient, const std::string &reason,
      const std::chrono::system_clock::time_point &date,
      const std::shared_ptr<Appointment> &appointment = nullptr);

  // Displays practitioner summary
  virtual void display() const;

protected:
  // Applies specialty-specific logic
  virtual void
  applySpecialtyProtocol(const std::shared_ptr<Patient> &patient,
                         const std::shared_ptr<Consultation> &consultation) = 0;

  int m_id;
  std::string m_lastName;
  std::string m_firstName;
  Specialty m_specialty;
  std::string m_registrationNumber;
  std::string m_phone;
  std::string m_email;

private:
  static int m_consultationCounter;
};
