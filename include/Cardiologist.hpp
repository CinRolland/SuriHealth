#pragma once

#include "Practitioner.hpp"

// Defines cardiology equipment level
enum class CardioEquipment { Standard, Advanced };

// Represents a cardiologist practitioner
class Cardiologist : public Practitioner {
public:
  // Constructor
  Cardiologist(int id, const std::string &lastName,
               const std::string &firstName,
               const std::string &registrationNumber,
               CardioEquipment equipment = CardioEquipment::Standard);

  // Displays cardiologist information
  void display() const override;

protected:
  // Applies cardiology exam protocol
  void applySpecialtyProtocol(
      const std::shared_ptr<Patient> &patient,
      const std::shared_ptr<Consultation> &consultation) override;

private:
  CardioEquipment m_equipment;
};
