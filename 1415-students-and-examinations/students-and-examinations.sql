-- Write your PostgreSQL query statement below
SELECT S.student_id, S.student_name, B.subject_name, COUNT(E.student_Id) AS attended_exams
FROM Students S
CROSS JOIN Subjects B
-- The LEFT JOIN keyword returns all records from the left table (table1), and the matching records (if any) from the right table (table2).
LEFT JOIN Examinations E 
ON S.student_id = E.student_id AND B.subject_name = E.subject_name
GROUP BY S.student_id, S.student_name, B.subject_name;
