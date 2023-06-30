#include <stdio.h>
#include <string.h>

struct HospitalRecord {
    char patientName[100];
    int patientID;
    int age;
    char gender[10];
};

int main()
{
	struct HospitalRecord record;
    FILE* file;
	file = fopen("hospital_records.dat", "r+");
	int choice;
	do {
        printf("1. Add Record\n");
        printf("2. View Record\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Patient Name: ");
                scanf("%s", record.patientName);
                printf("Enter Patient ID: ");
                scanf("%d", &record.patientID);
                printf("Enter Age: ");
                scanf("%d", &record.age);
                printf("Enter Gender: ");
                scanf("%s", record.gender);
                printf("Record added successfully.\n");
                break;
            case 2:
                
                printf("Enter Patient ID to view record: ");
                int patientID;
                scanf("%d", &patientID);

                // Search for the record in the file
                fseek(file, 0, SEEK_SET); // Set file pointer to the beginning
                int found = 0;
                while (!feof(file)) {
                    readRecordFromFile(file, &record);
                    if (record.patientID == patientID) {
                        printf("Patient Name: %s\n", record.patientName);
                        printf("Patient ID: %d\n", record.patientID);
                        printf("Age: %d\n", record.age);
                        printf("Gender: %s\n", record.gender);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Record not found.\n");
                }

                break;
            case 3:
                // Exit
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 3);

    // Close the file
    fclose(file);

    return 0;
} //
