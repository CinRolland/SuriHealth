#include "Practitioner.hpp"
#include "Appointment.hpp"
#include "Consultation.hpp"
#include "MedicalRecord.hpp"
#include "Patient.hpp"

#include <iostream>

int Practitioner::m_consultationCounter = 1;

std::string specialtyToString(Specialty s) {
  switch (s) {
  case Specialty::GeneralPractitioner:
    return "General Practitioner";
  case Specialty::Cardiologist:
    return "Cardiologist";
  case Specialty::Neurologist:
    return "Neurologist";
  }
  return "Unknown";
}

Practitioner::Practitioner(int id, const std::string &lastName,
                           const std::string &firstName, Specialty specialty,
                           const std::string &registrationNumber,
                           const std::string &phone, const std::string &email)
    : m_id(id), m_lastName(lastName), m_firstName(firstName),
      m_specialty(specialty), m_registrationNumber(registrationNumber),
      m_phone(phone), m_email(email) {}

int Practitioner::getId() const { return m_id; }

const std::string &Practitioner::getLastName() const { return m_lastName; }

const std::string &Practitioner::getFirstName() const { return m_firstName; }

std::string Practitioner::getFullName() const {
  return m_firstName + " " + m_lastName;
}

Specialty Practitioner::getSpecialty() const { return m_specialty; }

std::string Practitioner::getSpecialtyStr() const {
  return specialtyToString(m_specialty);
}

const std::string &Practitioner::getRegistrationNumber() const {
  return m_registrationNumber;
}

const std::string &Practitioner::getPhone() const { return m_phone; }

const std::string &Practitioner::getEmail() const { return m_email; }

std::shared_ptr<Consultation> Practitioner::conductConsultation(
    const std::shared_ptr<Patient> &patient, const std::string &reason,
    const std::chrono::system_clock::time_point &date,
    const std::shared_ptr<Appointment> &appointment) {
  int recordId =
      patient->getMedicalRecord() ? patient->getMedicalRecord()->getId() : -1;

  int apptId = appointment ? appointment->getId() : -1;

  auto consultation = std::make_shared<Consultation>(
      m_consultationCounter++, recordId, m_id, date, reason, apptId);

  applySpecialtyProtocol(patient, consultation);

  patient->addConsultation(consultation);
  return consultation;
}

void Practitioner::display() const {
  std::cout << "Dr " << getFullName() << " (" << getSpecialtyStr() << ")"
            << " | RPPS: " << m_registrationNumber << std::endl;
}
