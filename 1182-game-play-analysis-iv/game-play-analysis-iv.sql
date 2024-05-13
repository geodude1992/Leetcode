-- Write your PostgreSQL query statement below
SELECT 
    ROUND(SUM(
        CASE
            WHEN (player_id, event_date - INTERVAL '1 DAY') IN (
                SELECT player_id, MIN(event_date)
                FROM Activity
                GROUP BY player_id 
            ) THEN 1
            ELSE 0
        END
    )::NUMERIC / COUNT(DISTINCT player_id), 2) AS fraction
FROM Activity
