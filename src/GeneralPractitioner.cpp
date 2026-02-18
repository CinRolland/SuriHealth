#include "GeneralPractitioner.hpp"
#include "Consultation.hpp"
#include "Exam.hpp"
#include "MedicalRecord.hpp"
#include "Patient.hpp"

GeneralPractitioner::GeneralPractitioner(int id, const std::string &lastName,
                                         const std::string &firstName,
                                         const std::string &registrationNumber)
    : Practitioner(id, lastName, firstName, Specialty::GeneralPractitioner,
                   registrationNumber) {}

void GeneralPractitioner::applySpecialtyProtocol(
    const std::shared_ptr<Patient> &patient,
    const std::shared_ptr<Consultation> &consultation) {
  static int examId = 1;

  auto exam =
      std::make_shared<Exam>(examId++, consultation->getId(),
                             ExamType::GeneralCheckup, consultation->getDate());

  exam->addGeneralMetrics(36.8f, 72.f, 175.f);

  if (patient->getMedicalRecord()) {
    const auto &allergies = patient->getMedicalRecord()->getAllergies();
    if (!allergies.empty())
      exam->addResult("Allergies", allergies);
  }

  exam->setDiagnosis("Routine check completed.");
  exam->complete();
  consultation->addExam(exam);

  consultation->setReport("General consultation completed.");
}

void GeneralPractitioner::display() const { Practitioner::display(); }
