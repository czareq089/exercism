#include <algorithm>
#include <array>
#include <cmath>
#include <math.h>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> rounded_scores;
    for (auto rounded_score : student_scores)
    {
        rounded_scores.push_back(floor(rounded_score));
    }
    return rounded_scores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    // TODO: Implement count_failed_students
    int count = 0;
    for (auto score : student_scores)
    {
        if (score < 41)
        {
            count++;
        }
    }
    return count;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    int range = (highest_score - 40) / 4;
    std::array<int, 4> grades;
    for (int i = 0; i < 4; i++)
    {
        grades[i] = 41 + range * i;
    }
    return grades;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking( std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> result;
    for (int i = 0; i < student_names.size(); ++i)
    {
        std::string score = std::to_string(student_scores[i]);
        result.push_back(std::to_string(i+1) + ". " + student_names[i] + ": " + score);
    }
    return result;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    int index = 0;
    for (int i = 0; i < student_names.size(); ++i)
    {
        if (student_scores[i] == 100){
            index = i;
            return student_names[index];
        }
    }
    return "";
}
