cmake_minimum_required(VERSION 3.16)
project(SuriHealth VERSION 2.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/main.cpp
    src/Patient.cpp
    src/MedicalRecord.cpp
    src/Appointment.cpp
    src/Exam.cpp
    src/Consultation.cpp
    src/Practitioner.cpp
    src/GeneralPractitioner.cpp
    src/Cardiologist.cpp
    src/Neurologist.cpp
    src/TimeUtils.cpp
)

add_executable(suri_health ${SOURCES})
target_include_directories(suri_health PRIVATE include)

target_compile_options(suri_health PRIVATE
    $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
)
