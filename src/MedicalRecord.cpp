#include "MedicalRecord.hpp"
#include "TimeUtils.hpp"

#include <iostream>

MedicalRecord::MedicalRecord(int recordId, const std::string &bloodType,
                             const std::string &allergies)
    : m_recordId(recordId), m_bloodType(bloodType), m_allergies(allergies) {}

int MedicalRecord::getId() const { return m_recordId; }

const std::string &MedicalRecord::getBloodType() const { return m_bloodType; }

const std::string &MedicalRecord::getAllergies() const { return m_allergies; }

const std::vector<HistoryEntry> &MedicalRecord::getHistory() const {
  return m_history;
}

void MedicalRecord::setAllergies(const std::string &allergies) {
  m_allergies = allergies;
}

void MedicalRecord::addHistoryEntry(
    int historyId, const std::string &description,
    const std::chrono::system_clock::time_point &date) {
  m_history.push_back({historyId, description, date});
}

void MedicalRecord::display() const {
  std::cout << "Medical Record #" << m_recordId << " | Blood: " << m_bloodType
            << " | Allergies: " << (m_allergies.empty() ? "None" : m_allergies)
            << std::endl;

  for (const auto &h : m_history)
    std::cout << "  " << TimeUtils::formatDate(h.m_date) << " - "
              << h.m_description << std::endl;
}
