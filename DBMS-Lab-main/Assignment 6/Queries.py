import mysql.connector

connection = mysql.connector.connect(user="root", password="password", host="localhost", database="Assignment2")
cursor = connection.cursor()

cursor.execute("select distinct faculty.fname from faculty;")
print(cursor.fetchall())

cursor.execute("select distinct department.dname from department;")
print(cursor.fetchall())

cursor.execute("select faculty.fname from faculty, teaches where faculty.fid = teaches.fid and teaches.cid = 1;")
print(cursor.fetchall())

cursor.execute(
    "select student.sname, count(cid) as noOfCourses from student,      takes where student.sid = takes.sid group by takes.sid having count(cid) >= 1;")
print(cursor.fetchall())

cursor.execute(
    "select student.sname, count(cid) as noOfCourses from student,      takes where student.sid = takes.sid group by takes.sid having count(cid) > 1;")
print(cursor.fetchall())

# Q6
cursor.execute(
    "select student.sname, count(cid) as noOfCourses from student,      takes where student.sid = takes.sid group by takes.sid having count(cid) = 3;")
print(cursor.fetchall())

cursor.execute(
    "select student.sname, count(cid) as noOfCourses from student,      takes where student.sid = takes.sid group by takes.sid having count(cid) = 0; ")
print(cursor.fetchall())

cursor.execute(
    "select department.dname, department.Budget from department where Budget = (select max(Budget) from department)    or Budget = (select min(Budget) from department); ")
print(cursor.fetchall())

cursor.execute(
    "select fid, faculty.fname from faculty where fid = (select fid from teaches group by fid order by count(fid) desc limit 1) Union select fid, faculty.fname from faculty where fid = (select fid from teaches group by fid order by count(fid) asc limit 1);")
print(cursor.fetchall())

cursor.execute(
    "select department.Building from department group by department.Building order by count(*) desc limit 1;")
print(cursor.fetchall())

cursor.close()
connection.close()
