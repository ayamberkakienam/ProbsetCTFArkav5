USE fancafe_db;

DROP TABLE IF EXISTS posts;
CREATE TABLE posts (
    id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    is_deleted BOOL NOT NULL DEFAULT false,
    title TEXT NOT NULL,
    content TEXT NOT NULL
) CHARACTER SET utf8mb4;

SET NAMES 'utf8mb4';
INSERT INTO posts (title, content) VALUES ("fromis_9", "fromis_9 (프로미스나인) is a South Korean girl group formed by CJ E&M through the 2017 reality show Idol School.");
INSERT INTO posts (title, content) VALUES ("Saerom", "Lee Saerom (이새롬). Position: Team Captain (term used for Leader), Lead Dancer, Vocalist, Rapper, Visual");
INSERT INTO posts (title, content) VALUES ("Hayoung", "Song Hayoung (송하영). Position: Vice-Captain, Main Vocalist, Main Dancer");
INSERT INTO posts (title, content) VALUES ("Gyuri", "Jang Gyuri (장규리). Position: Lead Vocalist, Face of The Group");
INSERT INTO posts (title, content) VALUES ("Jiwon", "Park Jiwon (박지원). Position: Main Vocalist");
INSERT INTO posts (title, content) VALUES ("Jisun", "Roh Jisun (노지선). Position: Vocalist, Center");
INSERT INTO posts (title, content) VALUES ("Seoyeon", "Lee Seoyeon (이서연). Position: Main Rapper, Lead Vocalist, Lead Dancer");
INSERT INTO posts (title, content) VALUES ("Chaeyeoung", "Lee Chaeyoung (이채영). Position: Main Dancer, Lead Rapper, Vocalist");
INSERT INTO posts (title, content) VALUES ("Nakyung", "Lee Nakyung (이나경). Position: Lead Vocalist, Visual");
INSERT INTO posts (title, content) VALUES ("Jiheon", "Baek Jiheon (백지헌). Position: Vocalist, Maknae");

INSERT INTO posts (is_deleted, title, content) VALUES (true, "Flag", "flag{SQLi_adalah_jalan_ninjaku}");