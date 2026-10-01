CREATE DATABASE IF NOT EXISTS STUDENT;
USE STUDENT;
CREATE TABLE IF NOT EXISTS Student(
  SID INT PRIMARY KEY,
  NAME VARCHAR(50),
  BRANCH VARCHAR(10),
  SEMESTER INT,
  ADDRESS VARCHAR(100),
  PHONE VARCHAR(15),
  EMAIL VARCHAR(50));
INSERT INTO STUDENT(SID, NAME, BRANCH, SEMESTER, ADDRESS, PHONE, EMAIL)
VALUES
(1,'John Doe','CSE',3,'Kuvempunagar','123456789','johnexample.com'),
(2,'Jane Smith','ECE',2,'Saraswathipuram','0987533','jane@example.com'),
(3,'Sam William','CSE',4,'Vijayanagar','2345678907','sam@example.com'),
(5,'Anna Brown','MECH',1,'Hebbal','567890234','anne@example.com'),
(6,'Mark Taylor','CSE',4,'Saraswathipuram','4758632019','mark@example.com'),
(7,'Tom Lie','CSE',3,'Kuvempunagar','6789012345','tom@example.com'),
(8,'Emily Clark','CSE',3,'Kuvempunagar','6789012345','emily@example.com'),
(9,'James Bond','CIVIL',4,'Jayalakshmipuram','89012345','james@example.com'),
(10,'Sarah Counor','CSE',2,'Hebbal','9012345678','sarah@example.com');

//Insert new Student
INSERT INTO STUDENT(SID, NAME, BRANCH, SEMESTER, ADDRESS, PHONE, EMAIL)
VALUES(11,'Gagana','CSE',2,'Kuvempunagar','9712866730','gagana@example.com');

//Modify Address
UPDATE Student SET Address='Gokulam' WHERE SID=3;

//Delete a student
DELETE FROM Student WHERE SID=2;

//List all students
SELECT *FROM Student;

//List all CSE students
SELECT *FROM Student WHERE Branch='CSE';

//List all CSE students reciding in Kuvempunagar
SELECT *FROM Student WHERE Branch='CSE' AND ADDRESS='Kuvempunagar';


