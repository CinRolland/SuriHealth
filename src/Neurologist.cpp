#include "Neurologist.hpp"
#include "Consultation.hpp"
#include "Exam.hpp"

#include <iostream>

Neurologist::Neurologist(int id, const std::string &lastName,
                         const std::string &firstName,
                         const std::string &registrationNumber,
                         ImagingCapability imaging)
    : Practitioner(id, lastName, firstName, Specialty::Neurologist,
                   registrationNumber),
      m_imaging(imaging) {}

ImagingCapability Neurologist::getImagingCapability() const {
  return m_imaging;
}

void Neurologist::applySpecialtyProtocol(
    const std::shared_ptr<Patient> &,
    const std::shared_ptr<Consultation> &consultation) {
  static int examId = 200;

  auto exam =
      std::make_shared<Exam>(examId++, consultation->getId(),
                             ExamType::Neurology, consultation->getDate());

  exam->addNeuroMetrics(7, "Mild attention deficit");

  if (m_imaging == ImagingCapability::MRI ||
      m_imaging == ImagingCapability::Both)
    exam->addResult("MRI Brain", "No abnormal findings");

  if (m_imaging == ImagingCapability::CT ||
      m_imaging == ImagingCapability::Both)
    exam->addResult("CT Brain", "Normal structure");

  if (m_imaging == ImagingCapability::None)
    exam->addResult("Imaging", "Not performed");

  exam->setDiagnosis("Stable neurological status.");
  exam->complete();
  consultation->addExam(exam);

  consultation->setReport("Neurological evaluation completed.");
}

void Neurologist::display() const {
  Practitioner::display();

  std::string imagingStr = "None";
  if (m_imaging == ImagingCapability::MRI)
    imagingStr = "MRI";
  else if (m_imaging == ImagingCapability::CT)
    imagingStr = "CT";
  else if (m_imaging == ImagingCapability::Both)
    imagingStr = "MRI + CT";

  std::cout << "  Imaging capability: " << imagingStr << std::endl;
}
