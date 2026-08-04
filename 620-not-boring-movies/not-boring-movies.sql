# Write your MySQL query statement below
SELECT
* FROM
CINEMA
WHERE description <> 'boring' && id%2!=0
ORDER BY rating DESC