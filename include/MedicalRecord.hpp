#pragma once

#include <chrono>
#include <string>
#include <vector>

// Represents one medical history entry
struct HistoryEntry {
  int m_historyId;
  std::string m_description;
  std::chrono::system_clock::time_point m_date;
};

// Represents patient's medical record
class MedicalRecord {
public:
  // Constructor
  MedicalRecord(int recordId, const std::string &bloodType,
                const std::string &allergies = "");

  // Returns record identifier
  int getId() const;

  // Returns blood type
  const std::string &getBloodType() const;

  // Returns allergies
  const std::string &getAllergies() const;

  // Returns medical history entries
  const std::vector<HistoryEntry> &getHistory() const;

  // Updates allergies
  void setAllergies(const std::string &allergies);

  // Adds history entry
  void addHistoryEntry(int historyId, const std::string &description,
                       const std::chrono::system_clock::time_point &date);

  // Displays medical record
  void display() const;

private:
  int m_recordId;
  std::string m_bloodType;
  std::string m_allergies;
  std::vector<HistoryEntry> m_history;
};
