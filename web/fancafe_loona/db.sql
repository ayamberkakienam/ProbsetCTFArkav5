USE fancafe_loona_db;

DROP TABLE IF EXISTS posts;
CREATE TABLE posts (
    id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    is_deleted BOOL NOT NULL DEFAULT false,
    is_sticky BOOL NOT NULL DEFAULT false,
    title TEXT NOT NULL,
    content TEXT NOT NULL,
    video TEXT NOT NULL,
    image TEXT NOT NULL
) CHARACTER SET utf8mb4;

DROP TABLE IF EXISTS flag;
CREATE TABLE flag (
    fLaGz_15_HERE TEXT NOT NULL
) CHARACTER SET utf8mb4;

SET NAMES 'utf8mb4';

INSERT INTO flag (fLaGz_15_HERE) VALUES ("Arkav5{w0w_y0u_4re_SQLi_MASTER}");

INSERT INTO posts (is_sticky, title, content, video, image) VALUES (
    true,
    "LOOΠΔ",
    "LOOΠΔ (read: Loona) is a girl group formed by Blockberry Creative. Their Korean name, Idalui Sonyeo (이달의 소녀), translates to \"Girl of the Month\".",
    "https://www.youtube.com/watch?v=846cjX0ZTrk",
    "https://vignette.wikia.nocookie.net/loonatheworld/images/7/71/LOONA_%2B%2B_group_photo.png/revision/latest/scale-to-width-down/1110"
);
INSERT INTO posts (title, content, video, image) VALUES (
    "Heejin",
    "Jeon Hee-jin (전희진). Position: Main Dancer, Lead Vocalist, Center. Birthday: October 19, 2000",
    "https://www.youtube.com/watch?v=-FCYE87P5L0",
    "https://vignette.wikia.nocookie.net/loonatheworld/images/a/ad/HeeJin_debut_photo_7.png/revision/latest/scale-to-width-down/355"
);
INSERT INTO posts (title, content, video, image) VALUES (
    "Hyunjin",
    "Kim Hyun-jin (김현진). Position: Lead Dancer, Vocalist, Visual. Birthday: November 15, 2000",
    "https://www.youtube.com/watch?v=mybsDDymrsc",
    "https://vignette.wikia.nocookie.net/loonatheworld/images/a/af/HyunJin_debut_photo_2.PNG/revision/latest/scale-to-width-down/355"
);
INSERT INTO posts (title, content, video, image) VALUES (
    "Haseul",
    "Jo Haseul (조하슬). Position: Leader, Main Vocalist. Birthday: August 18, 1997",
    "https://www.youtube.com/watch?v=6a4BWpBJppI",
    "https://vignette.wikia.nocookie.net/loonatheworld/images/e/e1/HaSeul_debut_photo_3.PNG/revision/latest/scale-to-width-down/355"
);
INSERT INTO posts (title, content, video, image) VALUES (
    "Yeojin",
    "Im Yeo-jin (임여진). Position: Lead Rapper, Vocalist, Maknae. Birthday: November 11, 2002",
    "https://www.youtube.com/watch?v=thpTOAS1Vgg",
    "https://vignette.wikia.nocookie.net/loonatheworld/images/2/26/YeoJin_debut_photo_4.png/revision/latest/scale-to-width-down/355"
);
INSERT INTO posts (title, content, video, image) VALUES (
    "Vivi",
    "Wong Gaahei (黃珈熙). Position: Vocalist, Visual. Birthday: December 9, 1996",
    "https://www.youtube.com/watch?v=ZNcBZM5SvbY",
    "https://vignette.wikia.nocookie.net/loonatheworld/images/7/75/ViVi_debut_photo_3.PNG/revision/latest/scale-to-width-down/355"
);
INSERT INTO posts (title, content, video, image) VALUES (
    "Kim Lip",
    "Kim Jung-eun (김정은). Position: Lead Vocalist, Lead Dancer. Birthday: February 10, 1999",
    "https://www.youtube.com/watch?v=_qJEoSa3Ie0",
    "https://vignette.wikia.nocookie.net/loonatheworld/images/7/73/KimLip_debut_photo_4.PNG/revision/latest/scale-to-width-down/355"
);
INSERT INTO posts (title, content, video, image) VALUES (
    "Jinsoul",
    "Jung Jin-soul (정진솔). Position: Main Rapper, Lead Vocalist, Visual. Birthday: June 13, 1997",
    "https://www.youtube.com/watch?v=RWeyOyY_puQ",
    "https://vignette.wikia.nocookie.net/loonatheworld/images/a/aa/JinSoul_debut_photo_2.png/revision/latest/scale-to-width-down/355"
);
INSERT INTO posts (title, content, video, image) VALUES (
    "Choerry",
    "Choi Ye-rim (최예림). Position: Lead Rapper, Vocalist. Birthday: June 4, 2001",
    "https://www.youtube.com/watch?v=VBbeuXW8Nko",
    "https://vignette.wikia.nocookie.net/loonatheworld/images/3/30/Choerry_debut_photo_2.png/revision/latest/scale-to-width-down/355"
);
INSERT INTO posts (title, content, video, image) VALUES (
    "Yves",
    "Ha Soo-young (하수영). Position: Main Dancer, Lead Vocalist, Visual. Birthday: May 24th, 1997",
    "https://www.youtube.com/watch?v=LIDe-yTxda0",
    "https://vignette.wikia.nocookie.net/loonatheworld/images/b/b6/Yves_debut_photo.png/revision/latest/scale-to-width-down/355"
);
INSERT INTO posts (title, content, video, image) VALUES (
    "Chuu",
    "Kim Ji-woo (김지우). Position: Main Vocalist. Birthday: October 20, 1999",
    "https://www.youtube.com/watch?v=BVVfMFS3mgc",
    "https://vignette.wikia.nocookie.net/loonatheworld/images/c/c1/Chuu_debut_photo_4.png/revision/latest/scale-to-width-down/355"
);
INSERT INTO posts (title, content, video, image) VALUES (
    "Go Won",
    "Park Chae-won (박채원). Position: Lead Rapper, Lead Dancer, Vocalist. Birthday: November 19th, 2000",
    "https://www.youtube.com/watch?v=m5qwcYL8a0o",
    "https://vignette.wikia.nocookie.net/loonatheworld/images/e/ed/GoWon_debut_photo_5.png/revision/latest/scale-to-width-down/355"
);
INSERT INTO posts (title, content, video, image) VALUES (
    "Olivia Hye",
    "Son Hye-joo (손혜주). Position: Lead Dancer, Vocalist. Birthday: November 13, 2001",
    "https://www.youtube.com/watch?v=UkY8HvgvBJ8",
    "https://vignette.wikia.nocookie.net/loonatheworld/images/f/f5/Olivia_Hye_debut_photo.png/revision/latest/scale-to-width-down/355"
);
INSERT INTO posts (is_deleted, title, content, video, image) VALUES (
    true,
    "Flag",
    "Sorry but flag is not here!",
    "https://www.youtube.com/watch?v=dQw4w9WgXcQ",
    "https://i.kym-cdn.com/entries/icons/original/000/000/007/bd6.jpg"
);