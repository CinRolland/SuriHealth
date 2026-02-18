#include "Appointment.hpp"
#include "TimeUtils.hpp"

#include <iostream>

Appointment::Appointment(int appointmentId, int patientId, int practitionerId,
                         std::chrono::system_clock::time_point datetime)
    : m_appointmentId(appointmentId), m_patientId(patientId),
      m_practitionerId(practitionerId), m_datetime(datetime) {}

int Appointment::getId() const { return m_appointmentId; }

int Appointment::getPatientId() const { return m_patientId; }

int Appointment::getPractitionerId() const { return m_practitionerId; }

std::chrono::system_clock::time_point Appointment::getDatetime() const {
  return m_datetime;
}

void Appointment::display() const {
  std::cout << "Appointment #" << m_appointmentId << " | Patient "
            << m_patientId << " | Practitioner " << m_practitionerId << " | "
            << TimeUtils::formatDateTime(m_datetime) << std::endl;
}
