use Assignment5;

-- Q1 --


select department.dname as twoOrMoreCoursePerDept
from department
         natural join (select did, count(*)
                       from course
                       group by did
                       having count(*) >= 2) as dc;


-- Q2 --
select department.dname as twoOrLessCoursePerDept
from department
         natural join (select did, count(*)
                       from course
                       group by did
                       having count(*) <= 2) as dc;

-- Q3 --

create view numberofCoursePerDepartment AS
select did, count(*) as countCourse
from course
group by did;


select department.dname as maxNumberOfCourses
from department
         natural join (select did
                       from numberofCoursePerDepartment
                       where countCourse = (select max(countCourse) from numberofCoursePerDepartment)) as nCPDd;


-- Q4 --
select department.dname as minNumberOfCourses
from department
         natural join (select did
                       from numberofCoursePerDepartment
                       where countCourse = (select min(countCourse) from numberofCoursePerDepartment)) as nCPDd;

-- Q5 --
select course.cname as secondMaxCredit
from course
where credit = (select max(course.credit) from course where credit < (select max(credit) from course));


-- Q6 --
select faculty.fname as facultyAdvisingAI
from faculty
         natural join (select distinct advisor.fid from advisor where title like '%AI%') as af;

-- Q7 --
select fname
from faculty as notTeachingAnyCourse
where fid not in (select distinct fid from teaches);

-- Q8 --
create view facultyID_CourseID_CourseDept AS
select fname, fcc.fid, faculty.did as fdid, fcc.cid, fcc.coursedid as cdid
from faculty
         natural join (select fid, cid, did as coursedid
                       from teaches
                                natural join course) as fcc;



select faculty.fname as teachesOtherCoursesOtherThanTheirDept
from faculty
where fid not in (select fid from facultyID_CourseID_CourseDept where fdid = cdid);


-- Q9 --

DELIMITER //
create function countdistinctCoursesOfFaculty(fid int)
    RETURNS int
    DETERMINISTIC
BEGIN
    declare num INT;
    with temp_table(cid) as (select cid
                             from teaches
                             where teaches.fid = fid)
    select count(*)
    into num
    from (select distinct did
          from temp_table
                   natural join course) as ttcd;


    return num;
end //
DELIMITER ;

select fname as onlyTeachingCoursesOFTheirDepartments
from faculty
where fid in (select fid from facultyID_CourseID_CourseDept where fdid = cdid)
  and countdistinctCoursesOfFaculty(fid) = 1;


-- Q 10 --

DELIMITER //
create function countOfOtherDepartmentsOnly(fid int)
    returns int
    deterministic
begin

    DECLARE num INT;
    with temp_table(fid, fdid, cdid) as (select fid, fdid, did as cdid
                                         from (select fname, fid, did as fdid, cid
                                               from faculty
                                                        natural join teaches
                                               where faculty.fid = fid) as ffc
                                                  natural join course)
    select count(*)
    into num
    from temp_table
    where fdid = cdid;
    return num;
-- This will give the number of courses the faculty is teaching the same department
end //
delimiter ;

select fname as onlyTeachingCoursesOfOtherDepartments
from faculty
where countOfOtherDepartmentsOnly(fid) = 0;

-- Q11 --


create view cidAndAvgAge as
with temp_table(cid, avg_age) as (select cid, avg(age)
                                  from student
                                           natural join course
                                  group by cid)
select *
from temp_table;

select cname
from course
         natural join (select cid
                       from cidAndAvgAge
                       where avg_age = (select min(avg_age) from cidAndAvgAge)) as cAAAc;


-- Creating the new table --
create table marks
(
    sid   int,
    cid   int,
    marks int,
    foreign key (sid) references student (sid),
    foreign key (cid) references course (cid),
    primary key (sid, cid)

);

-- Inserting values into the table --
INSERT INTO Assignment5.marks (sid, cid, marks)
VALUES (1, 1, 50);

INSERT INTO Assignment5.marks (sid, cid, marks)
VALUES (1, 2, 100);

INSERT INTO Assignment5.marks (sid, cid, marks)
VALUES (1, 3, 85);

INSERT INTO Assignment5.marks (sid, cid, marks)
VALUES (1, 5, 34);

INSERT INTO Assignment5.marks (sid, cid, marks)
VALUES (1, 6, 70);

INSERT INTO Assignment5.marks (sid, cid, marks)
VALUES (2, 1, 70);

INSERT INTO Assignment5.marks (sid, cid, marks)
VALUES (2, 2, 100);

INSERT INTO Assignment5.marks (sid, cid, marks)
VALUES (2, 5, 60);

INSERT INTO Assignment5.marks (sid, cid, marks)
VALUES (3, 4, 10);

INSERT INTO Assignment5.marks (sid, cid, marks)
VALUES (3, 6, 50);

INSERT INTO Assignment5.marks (sid, cid, marks)
VALUES (4, 1, 30);

INSERT INTO Assignment5.marks (sid, cid, marks)
VALUES (4, 3, 40);

INSERT INTO Assignment5.marks (sid, cid, marks)
VALUES (4, 5, 70);

INSERT INTO Assignment5.marks (sid, cid, marks)
VALUES (5, 2, 80);

INSERT INTO Assignment5.marks (sid, cid, marks)
VALUES (5, 3, 20);

INSERT INTO Assignment5.marks (sid, cid, marks)
VALUES (5, 6, 80);

INSERT INTO Assignment5.marks (sid, cid, marks)
VALUES (6, 4, 100);

-- Q 12 --


select student.sname as Topper
from Assignment5.student
         natural join (select sid
                       from (select sid, sum(marks) as m from marks group by sid) as sm
                       where m = (select max(mark)
                                  from (select sum(marks.marks) as mark from marks group by sid) as ms)) as ss;


-- Q13 --

drop view if exists sidAndMarksG50;

create view sidAndMarksG50 as
select cid, count(*) as numberOfStudentsAbove50
from marks
where marks > 50
group by cid;


select cname as numberOfStudentsGreaterThan50
from course
         natural join (select *
                       from sidandmarksg50
                       where numberOfStudentsAbove50 =
                             (select max(numberOfStudentsAbove50) from sidAndMarksG50)) as sAMG50c;
-- Q14 --


DELIMITER //
create function countNumberOfStudentsPerCourse(cid int)
    returns int
    deterministic
begin
    declare cnt int;
    select count(*) into cnt from marks where marks.cid = cid;
    return cnt;
end //
DELIMITER ;


with temp_table(cid) as (select cid
                         from (select distinct cid, countNumberOfStudentsPerCourse(cid) as totalNumberOfStudentsInCourse
                               from marks) as ctNOSIC
                                  natural join (select cid, count(*) as numberofstudentsG70
                                                from marks
                                                where marks.marks = 70
                                                group by cid) as cc
                         where numberofstudentsG70 = totalNumberOfStudentsInCourse)
select cname
from temp_table
         natural join course;


-- Q15 --
DELIMITER //
CREATE FUNCTION GRADE(sid INT)
    RETURNS VARCHAR(3)
    DETERMINISTIC
BEGIN
    DECLARE avg_mark INT;
    DECLARE grade VARCHAR(3);

    SELECT AVG(marks) INTO avg_mark FROM marks WHERE marks.sid = sid;

    IF avg_mark >= 80 THEN
        SET grade = 'AA';
    ELSEIF avg_mark >= 70 THEN
        SET grade = 'AB';
    ELSEIF avg_mark >= 60 THEN
        SET grade = 'BB';
    ELSEIF avg_mark >= 40 THEN
        SET grade = 'BC';
    ELSEIF avg_mark >= 20 THEN
        SET grade = 'CD';
    ELSE
        SET grade = 'DD';
    END IF;

    RETURN grade;
END//
DELIMITER ;

select sid, GRADE(sid) as Grade
from student
order by sid;

-- Q16 --
DELIMITER //
CREATE FUNCTION countOfDepartment(did int)
    RETURNS int
    DETERMINISTIC
BEGIN
    DECLARE cnt INT;
    select count(*) into cnt from faculty where faculty.did = did;
    return cnt;
END//
DELIMITER ;

-- Q17 --
select distinct did as departmentsWithMoreThanOrEqualToTwoFaculty
from faculty
where countOfDepartment(did) >= 2;

-- Q18 --
DELIMITER //
CREATE FUNCTION sameSalary(salary int)
    RETURNS int
    DETERMINISTIC
BEGIN
    DECLARE cnt INT;
    select count(*) into cnt from faculty where faculty.salary = salary;
    return cnt;
END//
DELIMITER ;

-- Q 19 --
select sameSalary(100) as numberOfFacultyGreaterThan100;

-- Q20 --

select *
from faculty
where sameSalary(faculty.salary) >= 2;
