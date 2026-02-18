#pragma once

#include "Practitioner.hpp"

// Represents a general practitioner
class GeneralPractitioner : public Practitioner {
public:
  // Constructor
  GeneralPractitioner(int id, const std::string &lastName,
                      const std::string &firstName,
                      const std::string &registrationNumber);

  // Displays practitioner information
  void display() const override;

protected:
  // Applies general checkup protocol
  void applySpecialtyProtocol(
      const std::shared_ptr<Patient> &patient,
      const std::shared_ptr<Consultation> &consultation) override;
};
