#创建数据库

create database demo default character set utf8 collate utf8_general_ci;

use demo;

create table demo.customer (
  id bigint(20) not null AUTO_INCREMENT,
  name varchar(255) default null,
  contact varchar(255) default null,
  telephone varchar(255) default null,
  email varchar(255) default null,
  remark text,
  PRIMARY KEY (id)
) ENGINE=InnoDB default charset=utf8;

INSERT INTO demo.customer VALUES ('1', 'customer1', 'jack', '13512345678',
'jack@gmail.com', NULL );

INSERT INTO demo.customer VALUES ('2', 'customer2', 'Rose', '13623456789',
'rose@gmail.com', NULL );
