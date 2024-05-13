-- Write your PostgreSQL query statement below
SELECT query_name, 
    ROUND(AVG(rating::NUMERIC / position), 2) AS quality,
    ROUND(
        SUM(
            CASE   
                WHEN rating < 3 THEN 1
                ELSE 0
            END
        ) * 100.0 / count(*), 2
    ) AS poor_query_percentage
    --ROUND(SUM((rating < 3)::INT) * 100.0 / COUNT(*), 2) AS poor_query_percentage
FROM Queries
WHERE query_name IS NOT NULL
GROUP BY query_name;

