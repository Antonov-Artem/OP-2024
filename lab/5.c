#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int day;
  int month;
  int year;
} Date;

typedef struct {
  char* city;
  char* street;
  char* house;
} Address;

typedef struct {
  char* last_name;
  char* first_name;
  char* middle_name;
} FullName;

typedef struct {
  char* title;
  double grade;
} Subject;

typedef struct {
  FullName* full_name;
  Date* birth_date;
  Address* address;
  Subject* subjects;
  int experience;
  char* faculty;
} Applicant;

typedef struct {
  char* faculty;
  char* last_name;
} MostExp;

constexpr int faculties_amount = 3;

char* faculties[] = { "ICS", "IISRT", "IAIR" };

MostExp* faculty_most_exp(const Applicant* applicants, const int applicants_amount, const char* faculty) {
  if (applicants == NULL) return nullptr;

  const auto most_exp = (MostExp*)malloc(sizeof(MostExp));

  most_exp->faculty = (char*)malloc(5 * sizeof(char));
  most_exp->last_name = (char*)malloc(16 * sizeof(char));

  strcpy(most_exp->faculty, faculty);
  strcpy(most_exp->last_name, "-");

  int max_exp = applicants[0].experience;

  for (int i = 0; i < applicants_amount; i++) {
    if (strcmp(faculty, applicants[i].faculty) == 0 && applicants[i].experience >= max_exp) {
      max_exp = applicants[i].experience;
      strcpy(most_exp->last_name, applicants[i].full_name->last_name);
    }
  }

  return most_exp;
}

int main() {
  int applicants_amount;
  printf("Enter amount of applicants:");
  scanf("%d", &applicants_amount);

  int subjects_amount;
  printf("Enter amount of subjects:");
  scanf("%d", &subjects_amount);

  const auto applicants = (Applicant*)malloc(applicants_amount * sizeof(Applicant));

  // Initialization
  for (int i = 0; i < applicants_amount; i++) {
    applicants[i].birth_date = (Date*)malloc(sizeof(Date));
    applicants[i].address = (Address*)malloc(sizeof(Address));
    applicants[i].full_name = (FullName*)malloc(sizeof(FullName));
    applicants[i].subjects = (Subject*)malloc(subjects_amount * sizeof(Subject));

    applicants[i].full_name->first_name = (char*)malloc(16 * sizeof(char));
    applicants[i].full_name->last_name = (char*)malloc(16 * sizeof(char));
    applicants[i].full_name->middle_name = (char*)malloc(16 * sizeof(char));
    applicants[i].address->city = (char*)malloc(16 * sizeof(char));
    applicants[i].address->street = (char*)malloc(5 * sizeof(char));
    applicants[i].address->house = (char*)malloc(16 * sizeof(char));
    applicants[i].faculty = (char*)malloc(5 * sizeof(char));

    printf("Applicant #%d\n", i + 1);
    printf("Enter last name:");
    scanf("%s", applicants[i].full_name->last_name);
    printf("Enter first name:");
    scanf("%s", applicants[i].full_name->first_name);
    printf("Enter middle name:");
    scanf("%s", applicants[i].full_name->middle_name);
    printf("Enter birth day:");
    scanf("%d", &applicants[i].birth_date->day);
    printf("Enter birth month:");
    scanf("%d", &applicants[i].birth_date->month);
    printf("Enter birth year:");
    scanf("%d", &applicants[i].birth_date->year);
    printf("Enter city:");
    scanf("%s", applicants[i].address->city);
    printf("Enter street:");
    scanf("%s", applicants[i].address->street);
    printf("Enter house:");
    scanf("%s", applicants[i].address->house);

    for (int j = 0; j < subjects_amount; j++) {
      applicants[i].subjects[j].title = (char*)malloc(16 * sizeof(char));

      printf("Enter subject title:");
      scanf("%s", applicants[i].subjects[j].title);
      printf("Enter %s grade:", applicants[i].subjects[j].title);
      scanf("%d", &applicants[i].subjects[j].grade);
    }

    printf("Enter experience:");
    scanf("%d", &applicants[i].experience);
    printf("Enter faculty:");
    scanf("%s", applicants[i].faculty);
  }

  // Main
  for (int i = 0; i < faculties_amount; i++) {
    const auto most_exp = faculty_most_exp(applicants, applicants_amount, faculties[i]);

    printf("%s: %s\n", most_exp->faculty, most_exp->last_name);

    free(most_exp);
  }

  // Free memory
  for (int i = 0; i < applicants_amount; i++) {
    free(applicants[i].full_name->first_name);
    free(applicants[i].full_name->last_name);
    free(applicants[i].full_name->middle_name);
    free(applicants[i].full_name);
    free(applicants[i].birth_date);
    free(applicants[i].address->city);
    free(applicants[i].address->street);
    free(applicants[i].address->house);
    free(applicants[i].address);

    for (int j = 0; j < subjects_amount; j++)
      free(applicants[i].subjects[j].title);

    free(applicants[i].subjects);
    free(applicants[i].faculty);
  }

  free(applicants);

  return 0;
}
