#include "Appointment.hpp"
#include "Cardiologist.hpp"
#include "GeneralPractitioner.hpp"
#include "MedicalRecord.hpp"
#include "Neurologist.hpp"
#include "Patient.hpp"
#include "TimeUtils.hpp"

#include <iostream>
#include <memory>

int main() {
  // Medical Records
  auto recordAlice = std::make_shared<MedicalRecord>(1, "A+", "Penicillin");
  recordAlice->addHistoryEntry(1, "Hypertension diagnosed",
                               TimeUtils::makeDate(2018, 3, 10));
  recordAlice->addHistoryEntry(2, "Coronary angioplasty",
                               TimeUtils::makeDate(2021, 7, 22));

  auto recordBob = std::make_shared<MedicalRecord>(2, "O+", "");

  auto recordCarol = std::make_shared<MedicalRecord>(3, "B-", "Aspirin");
  recordCarol->addHistoryEntry(3, "Migraines since age 40",
                               TimeUtils::makeDate(2010, 1, 15));
  recordCarol->addHistoryEntry(4, "Epileptic episode",
                               TimeUtils::makeDate(2023, 9, 5));

  // Patients
  auto alice = std::make_shared<Patient>(
      1, "2 75 05 75 123 456 78", "Martin", "Alice", Sex::Female,
      TimeUtils::makeDate(1980, 5, 14), "12 rue de la Paix, Paris",
      "0612345678", "alice@mail.com");

  alice->setMedicalRecord(recordAlice);

  auto bob = std::make_shared<Patient>(
      2, "1 14 12 13 456 789 01", "Dupont", "Bob", Sex::Male,
      TimeUtils::makeDate(2015, 12, 1), "5 av. Voltaire, Lyon", "0698765432",
      "bob@mail.com");

  bob->setMedicalRecord(recordBob);

  auto carol = std::make_shared<Patient>(
      3, "2 63 08 69 321 654 90", "Lefebvre", "Carol", Sex::Female,
      TimeUtils::makeDate(1963, 8, 30), "8 bd Haussmann, Paris", "0655443322",
      "carol@mail.com");

  carol->setMedicalRecord(recordCarol);

  // Practitioners
  auto gp =
      std::make_shared<GeneralPractitioner>(1, "Bernard", "Sophie", "10001");

  auto cardio = std::make_shared<Cardiologist>(2, "Dubois", "Marc", "20002");

  auto neuro = std::make_shared<Neurologist>(3, "Petit", "Elena", "30003",
                                             ImagingCapability::Both);

  std::cout << "Practitioners:" << std::endl;
  gp->display();
  cardio->display();
  neuro->display();
  std::cout << "***" << std::endl;

  // Appointments
  auto appt1 = std::make_shared<Appointment>(
      1, alice->getId(), gp->getId(), TimeUtils::makeDate(2026, 2, 10, 9, 0));

  auto appt2 =
      std::make_shared<Appointment>(2, alice->getId(), cardio->getId(),
                                    TimeUtils::makeDate(2026, 2, 12, 14, 30));

  auto appt3 =
      std::make_shared<Appointment>(3, carol->getId(), neuro->getId(),
                                    TimeUtils::makeDate(2026, 2, 15, 11, 0));

  std::cout << "Running consultations..." << std::endl;

  // GP sees Alice
  gp->conductConsultation(alice, "Annual checkup",
                          TimeUtils::makeDate(2026, 2, 10), appt1);

  // GP sees Bob
  gp->conductConsultation(bob, "Fever and sore throat",
                          TimeUtils::makeDate(2026, 2, 11));

  // Cardiologist sees Alice
  cardio->conductConsultation(alice, "Chest pain follow-up",
                              TimeUtils::makeDate(2026, 2, 12), appt2);

  // Neurologist sees Carol
  neuro->conductConsultation(carol, "Epilepsy follow-up",
                             TimeUtils::makeDate(2026, 2, 15), appt3);

  std::cout << "Patient Records:" << std::endl;

  alice->display();
  std::cout << "***" << std::endl;

  bob->display();
  std::cout << "***" << std::endl;

  carol->display();

  return 0;
}
