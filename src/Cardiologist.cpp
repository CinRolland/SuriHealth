#include "Cardiologist.hpp"
#include "Consultation.hpp"
#include "Exam.hpp"

Cardiologist::Cardiologist(int id, const std::string &lastName,
                           const std::string &firstName,
                           const std::string &registrationNumber,
                           CardioEquipment equipment)
    : Practitioner(id, lastName, firstName, Specialty::Cardiologist,
                   registrationNumber),
      m_equipment(equipment) {}

void Cardiologist::applySpecialtyProtocol(
    const std::shared_ptr<Patient> &,
    const std::shared_ptr<Consultation> &consultation) {
  static int examId = 100;

  auto exam =
      std::make_shared<Exam>(examId++, consultation->getId(),
                             ExamType::Cardiology, consultation->getDate());

  exam->addCardioMetrics(80, 130, 85);

  if (m_equipment == CardioEquipment::Advanced)
    exam->addResult("Echocardiography", "Normal cardiac function");

  exam->setDiagnosis("Mild blood pressure elevation.");
  exam->complete();
  consultation->addExam(exam);

  consultation->setReport("Cardiology consultation completed.");
}

void Cardiologist::display() const { Practitioner::display(); }
