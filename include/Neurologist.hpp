#pragma once

#include "Practitioner.hpp"

// Defines imaging capabilities available to neurologist
enum class ImagingCapability { None, MRI, CT, Both };

// Represents a neurologist practitioner
class Neurologist : public Practitioner {
public:
  // Constructor
  Neurologist(int id, const std::string &lastName, const std::string &firstName,
              const std::string &registrationNumber,
              ImagingCapability imaging = ImagingCapability::None);

  // Returns imaging capability
  ImagingCapability getImagingCapability() const;

  // Displays neurologist information
  void display() const override;

protected:
  // Applies neurologic exam protocol
  void applySpecialtyProtocol(
      const std::shared_ptr<Patient> &patient,
      const std::shared_ptr<Consultation> &consultation) override;

private:
  ImagingCapability m_imaging;
};
