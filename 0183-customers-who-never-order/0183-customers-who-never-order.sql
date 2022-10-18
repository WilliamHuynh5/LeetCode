# Write your MySQL query statement below


select 
    c.name as Customers
from 
    Customers as c
where 
    c.id NOT IN (select customerId from Orders);