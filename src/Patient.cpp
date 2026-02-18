#include "Patient.hpp"
#include "Consultation.hpp"
#include "MedicalRecord.hpp"
#include "TimeUtils.hpp"

#include <iostream>

static std::string sexToString(Sex sex) {
  switch (sex) {
  case Sex::Male:
    return "M";
  case Sex::Female:
    return "F";
  case Sex::Other:
    return "O";
  }
  return "";
}

Patient::Patient(int patientId, const std::string &ssn,
                 const std::string &lastName, const std::string &firstName,
                 Sex sex,
                 const std::chrono::system_clock::time_point &birthDate,
                 const std::string &address, const std::string &phone,
                 const std::string &email)
    : m_patientId(patientId), m_ssn(ssn), m_lastName(lastName),
      m_firstName(firstName), m_sex(sex), m_birthDate(birthDate),
      m_address(address), m_phone(phone), m_email(email) {}

int Patient::getId() const { return m_patientId; }
const std::string &Patient::getSsn() const { return m_ssn; }
const std::string &Patient::getLastName() const { return m_lastName; }
const std::string &Patient::getFirstName() const { return m_firstName; }
std::string Patient::getFullName() const {
  return m_firstName + " " + m_lastName;
}
Sex Patient::getSex() const { return m_sex; }
const std::chrono::system_clock::time_point &Patient::getBirthDate() const {
  return m_birthDate;
}
const std::string &Patient::getPhone() const { return m_phone; }
const std::string &Patient::getEmail() const { return m_email; }

void Patient::setMedicalRecord(const std::shared_ptr<MedicalRecord> &record) {
  m_medicalRecord = record;
}

const std::shared_ptr<MedicalRecord> &Patient::getMedicalRecord() const {
  return m_medicalRecord;
}

void Patient::addConsultation(
    const std::shared_ptr<Consultation> &consultation) {
  m_consultations.push_back(consultation);
}

const std::vector<std::shared_ptr<Consultation>> &
Patient::getConsultations() const {
  return m_consultations;
}

void Patient::display() const {
  std::cout << "Patient #" << m_patientId << std::endl
            << "Name: " << getFullName() << " (" << sexToString(m_sex) << ")"
            << std::endl
            << "Birth date: " << TimeUtils::formatDate(m_birthDate) << std::endl
            << "Phone: " << m_phone << std::endl
            << "Email: " << m_email << std::endl;

  if (m_medicalRecord)
    m_medicalRecord->display();

  for (const auto &c : m_consultations)
    c->display();
}
