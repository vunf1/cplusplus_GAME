--
-- File generated with SQLiteStudio v3.1.1 on Sat Feb 3 01:53:06 2018
--
-- Text encoding used: UTF-8
--
PRAGMA foreign_keys = off;
BEGIN TRANSACTION;

-- Table: itens
CREATE TABLE itens (name VARCHAR (50) PRIMARY KEY, floor INTEGER);
INSERT INTO itens (name, floor) VALUES ('pen', 2);
INSERT INTO itens (name, floor) VALUES ('key', 2);
INSERT INTO itens (name, floor) VALUES ('knife', 2);
INSERT INTO itens (name, floor) VALUES ('sword', 1);

-- Table: player
CREATE TABLE player (id VARCHAR (255) PRIMARY KEY UNIQUE ON CONFLICT FAIL, password VARCHAR (255), level INTEGER (10), score INTEGER (100));
INSERT INTO player (id, password, level, score) VALUES ('joao', '123', 0, 0);
INSERT INTO player (id, password, level, score) VALUES ('', 'mn', 0, 0);
INSERT INTO player (id, password, level, score) VALUES ('87', '87654321', 0, 0);
INSERT INTO player (id, password, level, score) VALUES ('25', '25252525', 0, 0);
INSERT INTO player (id, password, level, score) VALUES ('ko', '87654321', 0, 0);
INSERT INTO player (id, password, level, score) VALUES ('mk', '1222223456789', 0, 0);
INSERT INTO player (id, password, level, score) VALUES ('nb', '12345678', 0, 0);
INSERT INTO player (id, password, level, score) VALUES ('nn', '123456789', 0, 0);
INSERT INTO player (id, password, level, score) VALUES ('vb', '55555555', 0, 0);
INSERT INTO player (id, password, level, score) VALUES ('hg', 's6s6s6s6', 0, 0);
INSERT INTO player (id, password, level, score) VALUES ('fds', '55555555', 0, 0);
INSERT INTO player (id, password, level, score) VALUES ('kk', '12345555555', 0, 0);
INSERT INTO player (id, password, level, score) VALUES ('op', '1234567890', 0, 0);

COMMIT TRANSACTION;
PRAGMA foreign_keys = on;
