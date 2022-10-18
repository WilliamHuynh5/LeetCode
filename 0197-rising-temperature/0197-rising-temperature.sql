# Write your MySQL query statement below
select B.id from Weather as A, Weather as B where datediff(B.recordDate, A.recordDate) = 1 and B.temperature > A.temperature;