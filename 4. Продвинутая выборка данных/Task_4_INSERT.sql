insert into genre (genre_name) 
values ('Рок'),
('Поп'),
('Джаз'),
('Блюз'),
('Классика');

insert into executor (executor_name)
values ('Исполнитель_1'),
('Исполни тель_2'),
('Исполнитель_3'),
('Исполни тель_4'),
('Исполни тель_5'),
('Исполни тель_6'),
('Исполни тель_7'),
('Исполнитель_9'),
('Исполнитель_10'),
('Исполнитель_11'),
('Исполни тель_12'),
('Исполнитель_13'),
('Исполнитель_14');

insert into genre_executor (id, id_genre, id_executor) 
values (1,1,1),
(2,1,2),
(3,2,2),
(4,2,3),
(5,2,4),
(6,2,5),
(7,1,6),
(8,3,6),
(9,3,7),
(10,4,8),
(11,3,9),
(12,4,10),
(13,1,10),
(14,3,11),
(15,5,12),
(16,5,13);

insert into album (album_name, album_date) 
values ('Альбом_1',1990),
('Альбом_2',2018),
('Альбом_3',2019),
('Альбом_4',2020),
('Альбом_5',1998),
('Альбом_6',2023),
('Альбом_7',2021),
('Альбом_8',2022),
('Альбом_9',1992),
('Альбом_10',2015),
('Альбом_11',2007),
('Альбом_12',2013),
('Альбом_13',2012);

insert into "executor_album"  (id, id_executor , id_album) 
values (1,1,1),
(2,2,2),
(3,3,3),
(4,4,4),
(5,5,5),
(6,6,6),
(7,7,7),
(8,8,8),
(9,9,9),
(10,10,10),
(11,11,11),
(12,12,12),
(13,13,13);

insert into track (id_album, track_name, track_time) 
values (1,'Трек_1','00:04:05'),
(2,'Трек_2','00:02:10'),
(3,'Трек_3_мой','00:03:15'),
(3,'Трек_4','00:01:55'),
(5,'Трек_5','00:05:44'),
(2,'Трек_6','00:02:54'),
(6,'Трек_7 мой','00:00:55'),
(4,'Трек_8','00:03:56'),
(7,'Трек_9','00:02:56'),
(8,'Трек_10','00:03:07'),
(9,'Трек_11','00:02:22'),
(10,'Трек_12','00:02:23'),
(11,'Трек_13 мой','00:02:56'),
(4,'Трек_14','00:02:59'),
(9,'Трек_15','00:02:29');

insert into collection (collection_name, collection_date) 
values ('Cборник_1',2015),
('Cборник_2',2021),
('Cборник_3',1999),
('Cборник_4',2018),
('Cборник_5',2019),
('Cборник_6',2005),
('Cборник_7',2020),
('Cборник_8',2013);

insert into track_collection (id, id_collection , id_track) 
values (1,1,2),
(2,1,5),
(3,1,7),
(4,2,6),
(5,2,4),
(6,2,8),
(7,3,11),
(8,3,12),
(9,3,13),
(10,4,1),
(11,4,14),
(12,4,15),
(13,5,3),
(14,5,4),
(15,5,13),
(16,6,15),
(17,6,1),
(18,6,6),
(19,7,9),
(20,7,8),
(21,7,12),
(22,8,10),
(23,8,3),
(24,8,1);