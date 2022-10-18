# Write your MySQL query statement below

# select distinct A.player_id, A.event_date as first_login from Activity as A where event_date in (select min(B.event_date) from Activity as B where B.player_id = A.player_id);

SELECT player_id, MIN(event_date) as first_login
FROM Activity
GROUP BY player_id