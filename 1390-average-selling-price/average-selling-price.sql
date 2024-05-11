-- Write your PostgreSQL query statement below
SELECT p.product_id,
-- To handle the case where there are no sales for a product, we'll use the COALESCE function to replace the denominator with 1 if it's zero.
COALESCE( ROUND(SUM(p.price*us.units)::NUMERIC / SUM(us.units), 2), 0) AS average_price
FROM Prices AS p
LEFT JOIN UnitsSold AS us
ON p.product_id = us.product_id
AND us.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY p.product_id;