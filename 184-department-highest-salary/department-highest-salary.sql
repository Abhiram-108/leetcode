-- # Write your MySQL query statement below
-- select d.name as Department ,e.name as Employee,e.Salary
-- from Employee e
-- join department d on  d.id=e.id 
-- where (e.id,e.salary) in
-- (select e.id,max(e.salary) from employee e group by e. );

# Write your MySQL query statement below
SELECT d.name AS Department, e.name AS Employee, e.salary AS Salary 
FROM Employee e 
JOIN Department d ON e.departmentId = d.id
WHERE (e.salary, e.departmentId) IN (
    SELECT MAX(salary), departmentId 
    FROM Employee 
    GROUP BY departmentId
);