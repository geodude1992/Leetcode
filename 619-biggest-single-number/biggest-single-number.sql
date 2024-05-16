-- Write your PostgreSQL query statement below
SELECT max(num) AS num
FROM MyNumbers
WHERE num NOT IN (
    SELECT num
    FROM MyNumbers
    group by num
    having count(num) > 1
)