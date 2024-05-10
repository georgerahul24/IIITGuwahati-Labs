use Assignment2;
show tables;

-- Q1 --
select count(cid)
from course;

-- Q2 --

create view numberOfStudentsPerCourse AS
select cid, count(*) as numberOfStudents
from takes
group by cid;

select count(cid) as totalNumberOfCourses
from numberOfStudentsPerCourse
where numberOfStudents > 2;

-- Q3 --
select cid
from numberOfStudentsPerCourse
where numberOfStudents = (select max(numberOfStudents) from numberOfStudentsPerCourse);

-- Q4 --
create view numberOfCoursesFacultyTeaches AS
select fid, count(*) as numberOfCourses
from teaches
group by fid;

select fname
from faculty
         natural join numberOfCoursesFacultyTeaches
where numberOfCourses > 2;

-- Q5 --
create view numberOfAdvisorialRoles AS
select fid, count(*) as numberOfAdvisorials
from advisor
group by fid;

select fname
from faculty
         natural join numberOfAdvisorialRoles
where numberOfAdvisorialRoles.numberOfAdvisorials > 4;

-- Q6 --

create view maxCreditCourseFaculty AS
select fid
from teaches
where cid = (select cid from course where credit = (select max(course.credit) from course));

select fname
from faculty
         natural join maxCreditCourseFaculty;


-- Q7 --

create view sumOfCreditsForFaculty AS
select teaches.fid, sum(credit) as totalCredits
from course
         natural join teaches
group by teaches.fid;

select faculty.fname
from faculty
         natural join sumOfCreditsForFaculty
where fid = (select fid
             from sumOfCreditsForFaculty
             where totalCredits = (select max(totalCredits) from sumOfCreditsForFaculty));

-- Q8 --

-- As per the scheme of the table, this is not possible since student id is a primary key


-- Q9 --

select fname
from faculty
         natural join (select fid
                       from numberOfAdvisorialRoles
                       where numberOfAdvisorials = ((select max(numberOfAdvisorialRoles.numberOfAdvisorials)
                                                     from numberOfAdvisorialRoles))) as nOARf;


-- Q 10 --
create view numberOfDepartmentsPerStudent AS
select takes.sid, count(distinct course.did) as numberOfDepartments
from takes
         natural join course
group by sid;

select student.sname
from student
         natural join numberOfDepartmentsPerStudent
where numberOfDepartmentsPerStudent.numberOfDepartments >= 2;

-- Q 11 --

select student.sname
from student
         natural join numberOfDepartmentsPerStudent
where numberOfDepartmentsPerStudent.numberOfDepartments = 1;


-- Q12 --
create table studentCourseAndFacultyTeaching AS
select sid, cid, fid
from teaches
         natural join takes;

create view sameFacultyAndAdvisor as
select distinct sid
from (select scaft.sid, scaft.cid, scaft.fid as sfid, advisor.fid as afid
      from studentCourseAndFacultyTeaching as scaft
               join Assignment2.advisor advisor on scaft.sid = advisor.sid and scaft.fid = advisor.fid) as sa;

-- Q 12 main query
select student.sname
from student
         natural join sameFacultyAndAdvisor;

-- Q 13 --
select sname
from student
         left outer join sameFacultyAndAdvisor on student.sid = sameFacultyAndAdvisor.sid
where sameFacultyAndAdvisor.sid is NULL;

-- Q 14 --

create view numberOfStudentsPerDepartment as
select did, count(sid) as numberOfStudents
from takes
         natural join course
group by did;

select did
from numberOfStudentsPerDepartment
where numberOfStudents = (select max(numberOfStudents)
                          from numberOfStudentsPerDepartment);

-- Q 15 --
create view numberOfFacultiesPerDepartment as
select did, count(fid) as numberOfFaculty
from teaches
         natural join course
group by did;

select did
from numberOfFacultiesPerDepartment
where numberOfFaculty = (select max(numberOfFaculty)
                         from numberOfFacultiesPerDepartment);

-- Q 16 --
create view cidAndDid as
select cid, did
from teaches
         natural join faculty;

select a.cid
from cidAndDid as a,
     cidAndDid as b
where a.cid = b.cid
  and a.did = 1
  and b.did = 2;

-- Q17 --
select a.sid as sid
from takes as a,
     takes as b
where a.sid = b.sid
  and a.cid = 1
  and b.cid = 2;

-- Q18 --

create view avgSalaryPerDepartment as
select did, avg(salary) as avg_salary
from faculty
         natural join department
group by did;

select did from avgSalaryPerDepartment where avg_salary = (select max(avgSalaryPerDepartment.avg_salary) from avgSalaryPerDepartment);

-- Q 19 --
select did from avgSalaryPerDepartment where avgSalaryPerDepartment.avg_salary = (select min(avgSalaryPerDepartment.avg_salary) from avgSalaryPerDepartment);

-- Q 20 --
select did from student natural join department where age = (select min(age) from student);