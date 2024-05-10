create database test;
use test;
create table table1(
    a varchar(5),
    b varchar(5)
);

create table table2(
    a varchar(5),
    c varchar(5)
);

create table table3 (
    a varchar(5),
    b varchar(5)
);

create table table4(
    a int,
    c int
);

create table table5(
    b int,
    d int
);

create table student(
    RollNo int,
    name varchar(5)
);

create table marksheet(
    RollNo int,
    CourseCode varchar(10),
    Marks int
);

select * from table1 inner join table2 on table1.b = table2.c;

select * from table1 left outer join   table2 on table1.b = table2.c;

select * from table1 right outer join   table2 on table1.b = table2.c;

select * from table1 natural join table3;

select a from table1 where a = all(select a from table3);

(select * from table1) union (select * from table4);

select * from table4 natural join table5;

SELECT S. Name, sum(M.Marks) FROM Student S, Marksheet M WHERE M.Marks > 84
GROUP BY S. Name;
