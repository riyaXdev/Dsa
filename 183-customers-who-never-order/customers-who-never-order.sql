# Write your MySQL query statement below
SELECT name AS Customers
FROM Customers
WHERE id NOT IN (
    SELECT customerId
    FROM Orders
);
-- select Customers.name as Customers
-- from Orders
-- inner join  Customers on Customers.id = Orders.customerId;