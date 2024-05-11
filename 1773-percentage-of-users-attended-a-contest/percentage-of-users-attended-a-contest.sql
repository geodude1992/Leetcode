-- Write your PostgreSQL query statement below
SELECT contest_id, 
    ROUND(COUNT(user_id)::NUMERIC * 100 / ( -- total distin
        SELECT COUNT(*) -- Total # of unique users
        FROM Users), 2) AS percentage -- percentage of the users registered in each contest
FROM Register
GROUP BY contest_id
ORDER BY percentage DESC, contest_id;