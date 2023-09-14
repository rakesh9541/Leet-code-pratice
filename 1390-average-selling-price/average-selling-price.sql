# Write your MySQL query statement below
SELECT t1.product_id, 
ROUND(SUM(t1.price * t2.units) / SUM(t2.units), 2) AS average_price
FROM Prices AS t1
inner JOIN UnitsSold AS t2
ON t1.product_id = t2.product_id 
AND t2.purchase_date BETWEEN t1.start_date AND t1.end_date
GROUP BY t1.product_id;
