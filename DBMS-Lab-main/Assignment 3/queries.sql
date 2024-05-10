show databases;
use Assignment2;

-- Q1
select distinct faculty.fname
from faculty;

-- Q2
select distinct department.dname
from department;

-- Q3
select faculty.fname
from faculty,
     teaches
where faculty.fid = teaches.fid
  and teaches.cid = 1;

-- Q4
select student.sname, count(cid) as noOfCourses
from student,
     takes
where student.sid = takes.sid
group by takes.sid
having count(cid) >= 1;

-- Q5
select student.sname, count(cid) as noOfCourses
from student,
     takes
where student.sid = takes.sid
group by takes.sid
having count(cid) > 1;

-- Q6
select student.sname, count(cid) as noOfCourses
from student,
     takes
where student.sid = takes.sid
group by takes.sid
having count(cid) = 3;

-- Q7
select student.sname, count(cid) as noOfCourses
from student,
     takes
where student.sid = takes.sid
group by takes.sid
having count(cid) = 0;

-- Q8
select department.dname, department.Budget
from department
where Budget = (select max(Budget) from department)
   or Budget = (select min(Budget) from department);

-- Q9
select fid, faculty.fname
from faculty
where fid = (select fid from teaches group by fid order by count(fid) desc limit 1)
Union
select fid, faculty.fname
from faculty
where fid = (select fid from teaches group by fid order by count(fid) asc limit 1);
-- TODO: Need a better query for this

-- Q10
select department.Building
from department
group by department.Building
order by count(*) desc
limit 1;
