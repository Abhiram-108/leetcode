-- # Write your MySQL query statement below
select e.name 
from Employee e
where e.id in
(select e.managerId 
from Employee e group by e.managerId
having count(DISTINCT e.id)>=5


);


-- select e.managerId, count(DISTINCT e.id) from employee e  group by e.managerId;