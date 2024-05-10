-- Write your PostgreSQL query statement below
SELECT e.name
FROM Employee e
INNER JOIN Employee m
ON e.id = m.managerId -- matches each employee e with their corresponding manager m based on the manager's ID
GROUP BY m.managerId, e.name -- This grouping ensures that each employee's name is grouped by their manager's ID.
HAVING COUNT(m.managerId) >= 5; -- This means it only selects employees who have at least 5 subordinates.