# Write your MySQL query statement below
/* Write your T-SQL query statement below */
SELECT FirstName, LastName, City, State
FROM Person
LEFT JOIN Address
ON Person.PersonID = Address.PersonID;