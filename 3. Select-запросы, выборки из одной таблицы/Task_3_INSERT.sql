INSERT INTO genre(genre_name)
VALUES('Рок'),
('Поп'),
('Джаз'),
('Блюз'),
('Классика');

INSERT INTO executor(executor_name)
VALUES('Исполнитель_1'),
('Исполни тель_2'),
('Исполнитель_3'),
('Исполни тель_4'),
('Исполни тель_5'),
('Исполни тель_6'),
('Исполни тель_7'),
('Исполнитель_8');

INSERT INTO album(album_name, album_date)
VALUES('Альбом_1', '1990'),
('Альбом_2', '2018'),
('Альбом_3', '2019'),
('Альбом_4', '2020'),
('Альбом_5', '1998'),
('Альбом_6', '2021'),
('Альбом_7', '1992'),
('Альбом_8', '2015');

INSERT INTO track(track_name, track_time)
VALUES('Трек_1', '00:04:05'),
('Трек_2', '00:02:10'),
('Трек_3_мой', '00:03:15'),
('Трек_4', '00:01:55'),
('Трек_5', '00:04:25'),
('Трек_6', '00:03:35'),
('Трек_7_мой', '00:02:45'),
('Трек_8', '00:01:05'),
('Трек_9', '00:00:55'),
('Трек_10', '00:02:15'),
('Трек_11', '00:03:25'),
('Трек_12', '00:01:45'),
('Трек_13_мой', '00:02:08'),
('Трек_14', '00:04:26'),
('Трек_15', '00:02:29');

INSERT INTO collection(collection_name, collection_date)
VALUES('Cборник_1', '1980'),
('Cборник_2', '1090'),
('Cборник_3', '2000'),
('Cборник_4', '2010'),
('Cборник_5', '2020'),
('Cборник_6', '2005'),
('Cборник_7', '2015'),
('Cборник_8', '2023');

INSERT INTO genre_executor(genre_id, executor_id)
VALUES(1,1),
(1,2),
(1,3),
(2,4),
(2,5),
(3,6),
(3,7),
(3,8),
(4,1),
(4,2),
(5,3),
(5,4),
(5,5);

INSERT INTO album_executor(album_id, executor_id)
VALUES(1,1),
(2,2),
(3,3),
(4,4),
(5,5),
(6,6),
(7,7),
(8,8);

INSERT INTO track_album(track_id, album_id)
VALUES(1,1),
(2,1),
(3,2),
(4,2),
(5,3),
(6,3),
(7,4),
(8,4),
(9,5),
(10,5),
(11,6),
(12,6),
(13,7),
(14,7),
(15,8);

INSERT INTO collection_track(collection_id, track_id)
VALUES(1,1),(1,2),(1,3),
(2,4),(2,5),(2,6),
(3,7),(3,8),(3,9),
(4,10),(4,11),(4,12),
(5,13),(5,14),(5,15),
(6,1),(6,3),(6,5),
(7,7),(7,9),(7,11),
(8,13),(8,15),(8,1);