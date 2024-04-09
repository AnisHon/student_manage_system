# 这是一个简易的学生管理系统
本学生管理系统需要使用mysql数据库，使用C++Qt编写
支持：
+ 增删改查学生信息
+ 添加学生头像
+ 登陆
+ 导入导出（仅支持CSV）
+ 数据统计
+ 可变的科目

## 数据库表情况

account
```sql
create table account
(
    id         int auto_increment
        primary key,
    teacher_id varchar(255) not null,
    password   varchar(255) not null,
    name       varchar(255) not null,
    constraint account_pk
        unique (teacher_id)
);
```

student
```sql
create table student
(
    id         int auto_increment
        primary key,
    student_id varchar(255)      not null,
    name       varchar(255)      not null,
    gender     enum ('男', '女') not null,
    age        int               not null,
    address    varchar(255)      not null,
    portrait   varchar(255)      null,
    constraint student_pk_2
        unique (student_id)
);
```

score
```sql
create table score
(
    id         int auto_increment
        primary key,
    stu_id     int    not null,
    subject_id int    not null,
    score      double not null,
    constraint score_student_id_fk
        foreign key (stu_id) references student (id),
    constraint score_subject_id_fk
        foreign key (subject_id) references subject (id)
);
```

subject
```sql
create table subject
(
    id   int auto_increment
        primary key,
    name varchar(255) not null
);
```





