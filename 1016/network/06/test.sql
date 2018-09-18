PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE user ( id int , name text ,pass text);
INSERT INTO "user" VALUES(1,'zhangsan','123456');
INSERT INTO "user" VALUES(2,'lisi','45678');
INSERT INTO "user" VALUES(3,'wangwu','11111');
INSERT INTO "user" VALUES(4,'wangwu1','11111');
INSERT INTO "user" VALUES(5,'wangwu2','11111');
INSERT INTO "user" VALUES(6,'wangwu3','11111');
INSERT INTO "user" VALUES(7,'wangwu4','11111');
INSERT INTO "user" VALUES(8,'wangwu5','11111');

CREATE TABLE login (id INTEGER PRIMARY KEY AUTOINCREMENT, name text);
INSERT INTO "login" VALUES(1,'zhangsan');
INSERT INTO "login" VALUES(2,'lisi');
INSERT INTO "login" VALUES(3,'aaa');
DELETE FROM sqlite_sequence;
INSERT INTO "sqlite_sequence" VALUES('login',3);
COMMIT;
