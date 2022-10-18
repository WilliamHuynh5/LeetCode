# Write your MySQL query statement below
select DISTINCT A.class from Courses as A where 4 < (select count(B.class) from Courses as B where B.class = A.class);