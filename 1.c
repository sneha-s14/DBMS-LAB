/*
Consider a structure named Student with attributes as SID, NAME, BRANCH, SEMESTER, ADDRESS.  
Write a program in C/C++/ and perform the following operations using the concept of files. 
  a. Insert a new student 
  b. Modify the address of the student based on SID
  c. Delete a student 
  d. List all the students 
  e. List all the students of CSE branch. 
  f. List all the students of CSE branch and reside in Kuvempunagar. 
  */
#include <stdio.h>
#include <string.h>

struct Student {
    int SID;
    char NAME[30], BRANCH[10], ADDRESS[50];
    int SEMESTER;
};

void insert() {
    struct Student s;
    FILE *fp = fopen("student.dat", "ab");

    printf("Enter SID Name Branch Semester Address:\n");
    scanf("%d %s %s %d %s", &s.SID, s.NAME, s.BRANCH,
          &s.SEMESTER, s.ADDRESS);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
}

void modify() {
    struct Student s;
    int id;
    FILE *fp = fopen("student.dat", "rb+");

    printf("Enter SID: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.SID == id) {
            printf("Enter new Address: ");
            scanf("%s", s.ADDRESS);

            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);
            break;
        }
    }
    fclose(fp);
}

void deleteStudent() {
    struct Student s;
    int id;
    FILE *fp = fopen("student.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    printf("Enter SID: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(s), 1, fp))
        if (s.SID != id)
            fwrite(&s, sizeof(s), 1, temp);

    fclose(fp);
    fclose(temp);

    remove("student.dat");
    rename("temp.dat", "student.dat");
}

void list(int option) {
    struct Student s;
    FILE *fp = fopen("student.dat", "rb");

    while (fread(&s, sizeof(s), 1, fp)) {
        if (option == 4 ||
            (option == 5 && strcmp(s.BRANCH, "CSE") == 0) ||
            (option == 6 && strcmp(s.BRANCH, "CSE") == 0 &&
             strcmp(s.ADDRESS, "Kuvempunagar") == 0))

            printf("\n%d %s %s %d %s",
                   s.SID, s.NAME, s.BRANCH,
                   s.SEMESTER, s.ADDRESS);
    }
    fclose(fp);
}

int main() {
    int ch;

    do {
        printf("\n\n1.Insert\n2.Modify Address\n3.Delete\n");
        printf("4.List All\n5.List CSE\n6.CSE in Kuvempunagar\n7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: insert(); break;
            case 2: modify(); break;
            case 3: deleteStudent(); break;
            case 4:
            case 5:
            case 6: list(ch); break;
        }
    } while(ch != 7);

    return 0;
}
