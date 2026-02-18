#pragma once

#include <chrono>

// Represents a scheduled appointment between patient and practitioner
class Appointment {
public:
  // Constructor
  Appointment(int appointmentId, int patientId, int practitionerId,
              std::chrono::system_clock::time_point datetime);

  // Returns appointment identifier
  int getId() const;

  // Returns patient identifier
  int getPatientId() const;

  // Returns practitioner identifier
  int getPractitionerId() const;

  // Returns appointment datetime
  std::chrono::system_clock::time_point getDatetime() const;

  // Displays appointment information
  void display() const;

private:
  int m_appointmentId;
  int m_patientId;
  int m_practitionerId;

  std::chrono::system_clock::time_point m_datetime;
};
